#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
struct Node {
  vector<ll> con;
  ll h1, h2;
} g[100010];
ll dfs(ll n, ll p) {
  g[n].h1 = g[n].h2 = 0;
  for (auto &i : g[n].con) {
    if (i == p) continue;
    ll k = dfs(i, n) + 1;
    if (k >= g[n].h1) {
      g[n].h2 = g[n].h1;
      g[n].h1 = k;
    } else if (k >= g[n].h2) {
      g[n].h2 = k;
    }
  }
  return g[n].h1;
}
ll dist(ll n, ll p, ll t) {
  if (n == t) return 0;
  ll ans = (ll)(1e17);
  for (auto &i : g[n].con) {
    if (i == p) continue;
    ans = min(ans, dist(i, n, t) + 1);
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N;
  cin >> N;
  while (N--) {
    ll n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    for (ll i = 0; i <= n - 1; i++) g[i].con.clear();
    a--;
    b--;
    ll s, t;
    for (ll i = 0; i <= n - 2; i++) {
      cin >> s >> t;
      s--;
      t--;
      g[s].con.emplace_back(t);
      g[t].con.emplace_back(s);
    }
    dfs(0, 0);
    ll height = 0;
    for (ll i = 0; i <= n - 1; i++) height = max(height, g[i].h1 + g[i].h2) + 1;
    ll dis = dist(a, a, b);
    if (da * 2 < db && da * 2 < height && dis > da)
      cout << "Bob\n";
    else
      cout << "Alice\n";
  }
  return 0;
}
