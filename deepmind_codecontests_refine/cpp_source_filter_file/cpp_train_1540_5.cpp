#include<iostream>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  int i,sm=0;
  for(i=0;i<m;i++)
  {cin>>j;
   sm+=j;
}
  if(sm>n)
    cout<<-1;
  else
    cout<<n-sm;

}
