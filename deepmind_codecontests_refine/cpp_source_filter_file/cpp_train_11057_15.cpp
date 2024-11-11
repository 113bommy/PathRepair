#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
ll d[N], sz[N], sz2[N];
ll tot1, tot2;
vector<pair<int, int>> adj[N];
void dfs1(int u, int p = -1, ll now = 0) {
  d[u] = now;
  sz2[u] = 1;
  for (pair<int, int> v : adj[u]) {
    if (v.first == p) continue;
    dfs1(v.first, u, now + v.second);
    sz[u] += sz[v.first];
    sz2[u] += sz2[v.first];
  }
  tot1 += (sz[u] / 2) * d[u];
  sz[u] %= 2;
  if (sz[u]) {
    tot1 += now;
    sz[u]--;
  } else
    sz[u]++;
}
void dfs2(int u, int p = -1, int used = 0) {
  ll mx = 0;
  for (pair<int, int> v : adj[u]) {
    if (v.first == p) continue;
    mx = max(mx, sz2[v.first]);
  }
  ll x = min(sz2[u] - mx + used, (sz2[u] - used) / 2);
  tot2 += x * d[u];
  if (mx - used > ((sz2[u] - used) / 2)) {
    for (pair<int, int> v : adj[u]) {
      if (v.first == p) continue;
      if (sz2[v.first] == mx) {
        dfs2(v.first, u, used + x);
      }
    }
  }
}
void Solve() {
  int n;
  cin >> n;
  n = 2 * n;
  tot1 = 0;
  tot2 = 0;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    sz[i] = 0;
    d[i] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    u--;
    v--;
    adj[u].push_back(make_pair(v, t));
    adj[v].push_back(make_pair(u, t));
  }
  dfs1(0);
  dfs2(0);
  ll ans = 0;
  for (int i = 0; i < n; i++) ans += d[i];
  cout << ans - 2 * tot1 << " " << ans - 2 * tot2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
