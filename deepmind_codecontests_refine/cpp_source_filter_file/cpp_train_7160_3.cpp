#include<bits/stdc++.h>
using namespace std;
int main()
{ string s;
 cin>>s;

 int n=s.size();
 if(s.substr(0,(n-1)/2)==s.substr((n+3)/2-1))
    {
        cout<"Yes"<<endl;
    }
    else
    {cout<<"No"<<endl;}
    return 0;
    }

