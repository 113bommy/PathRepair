#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,m;
  cin>>a>>b>>m;
  int mx=INT_MAX;
  int my=INT_MAX;
  int x[a+1],y[b+1];
  for(int i=1;i<=a;i++)
  {
    cin>>x[i];
    mx=min(mx,x[i]);
  }
  for(int i=1;i<=b;i++)
  {
    cin>>y[i];
    my=min(my,y[i]);
  }
  int ans=INT+MAX;
  int p,q,r;
  for(int i=0;i<m;i++)
  {
    cin>>p>>q>>r;
    int h=x[p]+y[q]-r;
    ans=min(ans,h);
  }
  ans=min(ans,mx+my);
  cout<<ans<<"\n";
  return 0;
}