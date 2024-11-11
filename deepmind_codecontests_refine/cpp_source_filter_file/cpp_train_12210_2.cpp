#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int mxN = 1e3 + 1;
ll n, m, k, d[mxN][mxN];
vector<pll> adj[mxN], edges, routes;
void dij(int src) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vector<bool> vis(n + 1);
  pq.push(pll(0, src));
  while (pq.size()) {
    ll v, d_v;
    tie(d_v, v) = pq.top();
    pq.pop();
    if (vis[v]) continue;
    vis[v] = 1, d[src][v] = d_v;
    for (pll u : adj[v])
      if (!vis[u.first]) pq.push(pll(d_v + u.second, u.first));
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(pll(b, c));
    adj[b].push_back(pll(a, c));
    edges.push_back(pll(a, b));
  }
  for (int i = 1; i <= n; ++i) dij(i);
  while (k--) {
    int a, b;
    cin >> a >> b;
    routes.push_back(pll(a, b));
  }
  ll ans = 0;
  for (pll e : edges) {
    ll cur = 0;
    for (pll r : routes)
      if (r.first ^ r.second)
        cur += min({d[r.first][r.second],
                    d[r.first][e.first] + d[r.second][e.second],
                    d[r.first][e.second] + d[r.second][e.first]});
    ans = min(ans, cur);
  }
  cout << ans << '\n';
}
