#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class entry_to_exit
{
    public:
    char name[30];
    void header()
    {
        cout<<"\t\t=============================================================================================="<<endl;
        cout<<"\t\t##################-----------# | Q U I Z  C O N T E S T | #------------########################"<<endl;
        cout<<"\t\t=============================================================================================="<<endl;
        cout<<"\n\t\t\t\t-- E N T E R   Y O U R   N A M E   P L E A S E -- \n\t\t\t\t\t ";
        cin>>name;
        cout<<"\n\t\t\t Hello "<<name<<"\n"<<endl;
    
    }
    void footer()
    {
        cout<<"\t------------------------------------- | T H A N K Y O U | ---------------------------------------"<<endl;
    }
    void instn()
    {
        cout<<"\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ | I N S T R U C T I O N S | +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"<<endl;
        cout<<"\t\t|-----------------------------------------------------------------------------------------------|"<<endl;
        cout<<"\t\t|..............|  You have to attempt 10 questions.You have to enter your option  |.............|"<<endl;
        cout<<"\t\t|..........................|  For every correct answer you got 4 points. |......................|"<<endl;
        cout<<"\t\t|-----------------------------------------------------------------------------------------------|\n"<<endl;
}
    void nxt_ques()
    {
        cout<<"\n\t\t|------------------------------| N E X T   Q U E S T I O N |-----------------------------------|"<<endl;
    }
    
}; 
class quiz : public entry_to_exit
{
    public:
    string ques;
    char answer;
    float x =0;
    bool b = true;
    char a;
    int i=1, c_ans=0,w_ans=0; 
    void disp_ques(string str)
    {
        instn();
        
        ifstream fin;
        fin.open(str);
        while(fin.eof()==0)
        {
             
            getline(fin,ques);
            cout<<endl<<"\t\t"<<ques;
            if(i==5)
            {
                fin.get(a);
                i=-1;
                for(;b;)
                { 
                    cout<<"\n\n\t\t\tEnter Your answer : ";
                    cin>>answer;
                    if (answer == 'a'||answer =='b'||answer =='c'||answer =='d')
                    {

                        //cout<<"Hello";
                        if(answer == a)
                        {
                            c_ans++;
                            cout<<"\t\t\t\t\tHEYYYY !!!!! \n\t\t\t\tYOUR ANSWER IS       C O R R E C T.\n";
                           
                            
                        }
                        else
                        {
                            cout<<"\n\t\t\t\t\t SORRY ....!!!!!  \n\t\t\t\t YOUR ANSWER IS           I N C O R R E C T \n \t\t\t\tTHE CORRECT ANSWER IS "<<a<<"\n";
                            w_ans++;
                            
                        }
                        break;
                    }
                    else
                    {
                        cout<<"\t\t\t\tYou entered wrong option \n \t\t\t Please Enter choice \'a\', \'b\', \'c\' or \'d\' :-) ";
                        
                    }             
                }
                if (x<9) {nxt_ques();} 
                x++;
            }

            i++;
        }
        fin.close();
        footer();
    };
};
class contest : public quiz
{
    public:
    int choice;
    string s;
    void entry()
    {
        header();
        cout<<"\t\t\t\t.... Which category do you want to play quiz .."<<"\n";
        cout<<"\t\t\t\tEnter your choice :\n \n\t\t\t\t\t1. A R T I F I C I A L   I N T E L L I G E N C E \n\t\t\t\t\t2. M A C H I N E   L E A R N I N G  \n\t\t\t\t\t3. D E E P   L E A R N I N G \n\t\t\t\t\t0. for exit"<<endl<<"\t\t\t\t\t ";
        
        
            cout<<"\n\t\t\t\t..ENTER 1, 2 or 3 ...\n\t\t\t\t";
            cin>>choice;
            if (choice == 1) 
            {
                s = "artificial_intelligence.txt";
                disp_ques(s);
            }
            else if (choice == 2) 
            {
                s = "machine_learning.txt";
                disp_ques(s);
            }
            else if (choice == 3) 
            {
                s = "deep_learning.txt";
                disp_ques(s);
            }
            else if (choice == 0)
            {
                exit(0);
            }
            else
            {
                cout<<"\n\t\t\t\tYou entered wrong choice,\n\t\t\t\t please restart your contest.\n";
            }
        
    }
    void points()
    {
        int t_points = c_ans*4 ;
        cout<<"\t\t\t\t\t\t"<<name<<" GOT  "<<t_points<<" POINTS OUT OF 40."<<endl;
        cout<<"\t\t\t\t|-----------------|\t\t\t\t|-----------------|"<<endl;
        cout<<"\t\t\t\t| CORRECT ANS : "<<c_ans<<" |\t\t\t\t|  WRONG ANS : "<<w_ans<<"  |";
        cout<<"\n\t\t\t\t|-----------------|\t\t\t\t|-----------------|"<<endl;
    }
};
int main()
{
    contest obj1;
    obj1.entry();
    obj1.points();
    return 0;
}

 