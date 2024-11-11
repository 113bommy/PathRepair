#include<bits/stdc++.h>
using namespace std;
int main()
{
  int k,n;
  cin>>k>>n;
  int a[n];
  for(int i=0;i<n;++i)
    cin>>a[i];
  int ans=99999999;
  for(int i=0;i<n-1;++i)
    ans=min(ans,k-(a[i+1]-a[i]));
  ans=min(ans,a[n-1]-a[0]);
  cout<<ans;
  return 0;
}
  
