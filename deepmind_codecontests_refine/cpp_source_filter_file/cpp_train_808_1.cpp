#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+9;
ll a[N];
ll cnt[89];
ll ans;
const int mod=1e9+7；
int n;
int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    for(int j=0;j<60;j++)if((a[i]>>j)&1)cnt[j]++;
  }
  for(int i=0;i<60;i++)ans=(ans+(1ll<<i)%mod*cnt[i]%mod*(n-cnt[i])%mod)%mod;
  cout<<ans<<endl;
  return 0;
}