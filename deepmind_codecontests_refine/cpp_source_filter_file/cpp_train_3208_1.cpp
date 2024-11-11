#include<bits/stdc++.h>
using namespace std;
int main()
{
  int  n;
  cin>>n;
  int d=n/2*2;
  vector<pair<int ,int>> vp;
  for(int  i=1;i<=n;i++)
  {for(int j=i+1;j<=n;j++)
    {
    if(i+j==d+1)continue;
    vp.push_back(i,j);
    
    }}
  cout<<(int) vp.size()<<'\n';
  for(auto e:vp)
    cout<<e.first<<" "<<e.second<<'\n';
  return 0;
}