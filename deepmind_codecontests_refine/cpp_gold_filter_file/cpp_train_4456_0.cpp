#include<bits/stdc++.h>
using namespace std;
pair<int,bool> A[16][16];
int a[16];
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    for(int j=0;j<a[i];j++)
      cin>>A[i][j].first>>A[i][j].second,
    A[i][j].first--;
  }
  int ans=0;
  for(int i=0;i<(1<<n);i++)
  {
    bool ok=true;
    for(int j=0;j<n;j++)
      if(i&(1<<j))
        for(int k=0;k<a[j];k++)
          if(((i>>A[j][k].first)&1)!=A[j][k].second)
            ok=false;
    if(ok)
      ans=max(ans,__builtin_popcount(i));
  }
  cout<<ans<<endl;
  return 0;
}