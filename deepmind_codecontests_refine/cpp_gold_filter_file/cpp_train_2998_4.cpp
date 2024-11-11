#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } return 0; }

ll k = 0;
vector<vector<pll>> g;
vector<ll> ans;
void dfs(ll from, ll at, ll color){
  for(auto& i : g[at]) if(i.first != from){
    color++;
    if(color >= k) color -= k;
    ans[i.second] = color;
    dfs(at, i.first, color);
  }
}
int main(){
  ll n;
  cin >> n;
  g.resize(n);
  ans.resize(n - 1);
  for(ll i = 0; i < n - 1; i++){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
  }
  for(auto& i : g) chmax<ll>(k, i.size());
  dfs(-1, 0, 0);
  cout << k << endl;
  for(auto& i : ans) cout << i + 1 << endl;
}
