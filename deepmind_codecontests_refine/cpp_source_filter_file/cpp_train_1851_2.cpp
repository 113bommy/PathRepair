#include<iostream>
#define int long long 

using namespace std;

int32_t main ()
  
int n,d;
int count;
cin>>n>>d;
int x,y;
while(n--)
{cin>>x>>y;
if ((x*x+y*y)<=d*d)
{count++;}
}  

cout<<count<<endl;

return 0;
}
  