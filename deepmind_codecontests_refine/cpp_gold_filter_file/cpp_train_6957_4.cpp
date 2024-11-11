#include<bits/stdc++.h>
using namespace std;
int main()
{int a,b;
 cin>>a>>b;
 int x=1,t=b;
 while(t>0)
   {x*=10;
    t/=10;
   }
 t=sqrt(a*x+b); 
 if(t*t==a*x+b)
    cout<<"Yes"<<endl;
 else
    cout<<"No"<<endl;
}