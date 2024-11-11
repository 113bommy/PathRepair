#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
ll GCD(ll a,ll b) { return b ? GCD(b, a%b) : a; }
int main(){
  ll n;cin>>n;
  vector<ll> v(n);
  rep(i,n) cin>>v[i];
  vector<ll> left(n+1,0),right(n+1,0);
  rep(i,n) left[i+1]=GCD(left[i],v[i]);
  for(ll i=n-1;i>=0;i--) right[i]=GCD(right[i+1],v[i]);
  ll ans=0;
  rep(i,n) chmax(ans,GCD(left[i],right[i+1]));
  cout<<ans<<endl;
}