#include<iostream>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
for(int i=m/n;i>=0;i--)
{
if(m%i==0)
{
cout<<i<<endl;
break;
}
}
return 0;
}