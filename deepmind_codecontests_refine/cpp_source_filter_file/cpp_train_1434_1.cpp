#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int d[n+1][3],cnt=0;
  for(int i=1;i<=n;i++)	
  {
     cin>>d[i][1]<<d[i][2];
    if(d[i][1]==d[i][2]) cnt++;
    else cnt=0;
    if(cnt==3) return cout<<"Yes",0;
  }
  cout<<"No";
  return 0;
}