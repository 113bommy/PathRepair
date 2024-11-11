#include <bits/stdc++.h>
using namespace std;
const bool ready = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  return true;
}();
const double PI = acos(-1);
using ll = long long;
using pii = pair<ll, ll>;
using pdd = pair<double, double>;
using vd = vector<double>;
using vb = vector<bool>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
void solve() {
  ll n;
  cin >> n;
  ;
  vvi adj(n);
  for (ll i = 0; i < n - 1; i++) {
    ll a;
    cin >> a;
    ;
    a--;
    ll b;
    cin >> b;
    ;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vi d(n);
  function<void(ll, ll)> dfs = [&](ll v, ll p) {
    if (p >= 0)
      d[v] = d[p] + 1;
    else
      d[v] = 0;
    for (auto chl : adj[v]) {
      if (chl != p) {
        dfs(chl, v);
      }
    }
  };
  for (ll i = 0; i < n; i++) {
    if (adj[i].size() == 1) {
      dfs(0, -1);
      break;
    }
  }
  ll hasOdd = false;
  for (ll i = 0; i < n; i++)
    if (adj[i].size() == 1 && d[i] % 2 == 1) hasOdd = true;
  ll ansmi = 0;
  if (!hasOdd)
    ansmi = 1;
  else
    ansmi = 3;
  ll ansma = 0;
  for (ll i = 0; i < n; i++) {
    if (adj[i].size() > 1) {
      ll cnt = 0;
      for (ll c : adj[i])
        if (adj[c].size() == 1) cnt++;
      ansma += max(0LL, cnt - 1);
    }
  }
  cout << ansmi << " " << n - 1 - ansma << endl;
}
signed main() { solve(); }
