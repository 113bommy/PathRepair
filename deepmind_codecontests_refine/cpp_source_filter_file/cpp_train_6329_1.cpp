#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

int main(){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  
  ll ans1=0;
  rep(j,n)rep(i,j)
    if(a[i]>a[j]) ans1++;
  
  ll ans2=0;
  rep(i,n)rep(j,n)
    if(a[i]>a[j]) ans2++;
  
  ll ans=(((ans1%mod)*(k%mod))%mod + (ans2%mod)*((k*(k-1)/2l)%mod)%mod)%mod;
  
  cout << ans<< endl;