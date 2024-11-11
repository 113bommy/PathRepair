#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
  ll N,T;
  cin>>N>>T;
  vll t(N);
  for (ll i=0;i<N;i++) cin>>t[i];
  ans=T;
  for (ll i=0;i<N-1;i++) {
    ll x=t[i]+T-t[i+1];
    ans += T-max((ll)0,x);
  }
  cout<<ans;
}