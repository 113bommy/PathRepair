#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

int main() {
  ll n,m;
  cin >> n >> m;
  vector<map<ll,ll>> E(n);
  for(ll i=1;i<n;i++) E[i][i-1]=0;
  for(ll i=0;i<m;i++) {
    ll l,r,c;
    cin >> l >> r >> c;
    l--;r--;
    if(E[l][r]) {
      E[l][r]=min(E[l][r]);
    }
    else {
      E[l][r]=c;
    }
  }
  priority_queue<pll,vector<pll>,greater<pll>> q;
  vec d(n,inf);
  q.push(pll(0,0));
  while(q.size()) {
    ll dis=q.top().first;
    ll f=q.top().second;
    q.pop();
    if(d[f]<dis) continue;
    d[f]=dis;
    for(auto p:E[f]) {
      ll ndis=dis+p.second;
      ll t=p.first;
      if(d[t]>ndis) {
        q.push(pll(ndis,t));
      }
    }
  }
  if(d[n-1]==inf) d[n-1]=-1;
  cout << d[n-1] << endl;
}