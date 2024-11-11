#include<bits/stdc++.h>
using namespace std;
typedef long lont int ll;
int main()
{
  int n;
  cin>>n;
  ll a[n];ll sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    sum+=a[i];
  }
  ll ans=LONG_MAX;ll s=0;
  for(int i=0;i<n;i++)
  {
    s+=a[i];
    ll v=abs(sum-s);
    ans=min(ans,abs(v-s));
  }
  cout<<ans<<"\n";
  return 0;
}