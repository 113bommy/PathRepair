#include <bits/stdc++.h>
using namespace std;
const long long N = 111111;
long long n, par[N][20], h[N], sz[N];
vector<long long> g[N];
void dfs(long long v, long long p) {
  par[v][0] = p;
  h[v] = h[p] + 1;
  sz[v] = 1;
  for (long long i = 1; i < 20; ++i) par[v][i] = par[par[v][i - 1]][i - 1];
  for (long long u : g[v])
    if (u != p) {
      dfs(u, v);
      sz[v] += sz[u];
    }
}
long long up(long long v, long long d) {
  for (long long i = 19; i >= 0; i--)
    if (d & (1ll << i)) v = par[v][i];
  return v;
}
long long lca(long long v, long long u) {
  if (h[v] > h[u]) swap(v, u);
  u = up(u, h[u] - h[v]);
  for (long long i = 19; i >= 0; i--) {
    if (par[v][i] != par[u][i]) {
      v = par[v][i];
      u = par[u][i];
    }
  }
  if (v == u) return v;
  return par[v][0];
}
long long dist(long long v, long long u) {
  return h[v] + h[u] - 2 * h[lca(v, u)] + 1;
}
long long ans(long long v, long long u) {
  if (h[v] < h[u]) swap(v, u);
  long long D = dist(v, u) / 2;
  long long k = up(v, D), l = lca(v, u);
  if (k != l)
    return sz[k] - sz[up(v, D - 1)];
  else
    return n - sz[up(v, D - 1)] - sz[up(u, D - 1)];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i < n; ++i) {
    long long v, u;
    cin >> v >> u;
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(0, 0);
  long long q;
  cin >> q;
  while (q--) {
    long long v, u;
    cin >> v >> u;
    v--;
    u--;
    if (dist(v, u) % 2 == 0) {
      cout << "0\n";
      continue;
    }
    if (v == u) {
      cout << n << '\n';
      continue;
    }
    cout << ans(v, u) << '\n';
  }
}
