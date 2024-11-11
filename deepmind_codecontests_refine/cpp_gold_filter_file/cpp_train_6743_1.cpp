#include<iostream>
using namespace std;
int main()
{long long n,x,t,y;
 cin>>n>>x>>t;
 y=(n/x)*t;
 if(n%x>0)y=y+t;
 cout<<y;
return 0;}