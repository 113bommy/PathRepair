#include <bits/stdc++.h>
using namespace std;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
constexpr int N = 1e6 + 10;
const int MOD = 1e9 + 7;
const int LOG = 25;
const long long INF = 8e18;
struct edge {
  int u, v;
  bool dir;
  int ind;
} edges[N];
vector<edge> g[N];
int h[N], dpdown[N], dpup[N], par[N][LOG], n;
void dfs(int v, int p) {
  par[v][0] = p;
  for (int i = 1; i < LOG; ++i) {
    par[v][i] = par[par[v][i - 1]][i - 1];
  }
  for (auto e : g[v]) {
    if (e.v == p) continue;
    h[e.v] = h[v] + 1;
    dfs(e.v, v);
  }
  return;
}
int get_par(int v, int k) {
  for (int i = LOG; i--;)
    if ((k >> i) & 1) v = par[v][i];
  return v;
}
int lca(int v, int u) {
  if (h[v] < h[u]) swap(u, v);
  v = get_par(v, h[v] - h[u]);
  if (u == v) return v;
  for (int i = LOG; i--;) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[v][0];
}
void dfs2(int v, int p) {
  for (auto e : g[v]) {
    if (e.v == p) continue;
    dfs2(e.v, v);
    dpdown[v] += dpdown[e.v];
    dpup[v] += dpup[e.v];
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    bool dir;
    cin >> dir;
    edges[i] = {u, v, dir, i};
    g[u].push_back({u, v, dir, i});
    g[v].push_back({v, u, dir, i});
  }
  dfs(0, 0);
  int lst = 0, q;
  cin >> q;
  while (q--) {
    int v;
    cin >> v;
    v--;
    int l = lca(lst, v);
    dpdown[v]++;
    dpdown[l]--;
    dpup[lst]++;
    dpup[l]--;
    lst = v;
  }
  dfs2(0, 0);
  long long ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (!edges[i].dir) continue;
    int u = edges[i].u, v = edges[i].v;
    int t = ((h[u] < h[v]) ? dpup[v] : dpdown[u]);
    ans += poww(2, t, MOD) - 1;
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
