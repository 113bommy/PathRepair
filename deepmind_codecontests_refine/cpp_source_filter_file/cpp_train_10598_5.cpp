#include<iostream>
using namespcae std;
int main()
{
  int r,d,x;
  cin>>r>>d>>x;
  int f;
  for(int i=0;i<10;i++)
  {
    f=x*r-d;
    x=f;
    cout<<f<<endl;
  }
  
    