#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

vector<char> build_floor();
void show_floor(vector<char>,int=5);
void moving(vector<char>);
vector<int> create_choices();
void show_choices(vector<int>);
vector<int> modify_choices(int,vector<int>);
void pause();


int main()
{
    int continu;
    do
    {

        vector<char> floor=build_floor();
        moving(floor);

        cout<<"\nTry Again?(0/1)";
        cin>>continu;
        cout<<endl;
    }while(continu);
    return 0;
}


vector<char> build_floor()
{
    vector<char> floor;
    srand(time(NULL));
    floor.push_back(177);
    lp(j,7)
    {
        lp(i,rand()%11+1)
            floor.push_back('_');
        floor.push_back(' ');
    }
    floor.pop_back();
    floor.push_back(36);
    return floor;
    /*
    numberoftests=1,00,000
    max55=0
    min15=0
    avg=33.9707
    */
}


void show_floor(vector<char> floor,int n)
{
    if(n>floor.size())
        n=floor.size();
    lp(i,n)
        cout<<floor[i]<<' ';
}


void moving(vector<char> floor)
{
    vector<int> options=create_choices();
    int position=0;
    long long int steps;
    while(position<floor.size()-1)
    {
        show_choices(options);
        show_floor(floor,position+5);
        cin>>steps;
        if(steps>9||steps<1)
        {
            pause();
            continue;
        }
        floor[position]='_';
        if(options[steps]==0)
            cout<<"Used choice,Be fair!";
        position+=options[steps];

        if(floor[position]==' ')
        {
            floor[position]=167;
            show_floor(floor,floor.size());
            cout<<"\nGAME OVER!!!\n";
            break;
        }
        else if(position>floor.size()-2)
        {
            floor[floor.size()-1]=178;
            show_floor(floor,floor.size());
            cout<<"\nWINNER WINNER RAJMA CHAWAL DINNER\n";
            break;
        }
        else
        {
            floor[position]=177;
        }
        options=modify_choices(options[steps],options);
        cout<<endl;
    }
}


vector<int> create_choices()
{
    vector<int> options;
    lp(i,10)
        options.push_back(i);
    return options;
}


void show_choices(vector<int> options)
{
    for(int i=1;i<=9;i++)
    {
        if(options[i]==0)
            cout<<char(219);
        else
            cout<<options[i];
        cout<<' ';
        if(i%3==0)
            cout<<endl;
    }
}


vector<int> modify_choices(int num,vector<int> options)
{
    options[num]=0;
    return options;
}


void pause()
{
    cout<<"OPTIONS SCREEN"<<endl;
    cout<<"0:End the game"<<endl;
    cout<<"1:Restart the game"<<endl;
    cout<<"2:Back to the game"<<endl;
    int x;
    cin>>x;
    switch(x)
    {
        case 0:exit(0)      ;         break;
        case 1:main()       ;         break;
        case 2:             ;
    }
}
