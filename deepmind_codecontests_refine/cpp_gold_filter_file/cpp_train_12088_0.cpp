#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, k;
int id[maxn], vertex[maxn];
long long ux[maxn], vy[maxn], f[44][44];
vector<pair<int, int> > adj[maxn];
vector<tuple<int, int, int> > edges, tmp;
class DisjoinsetUnion {
 private:
  int par[maxn];

 public:
  void init(int n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int anc(int p) { return par[p] == p ? p : par[p] = anc(par[p]); }
  bool join(int p, int q) {
    return anc(p) != anc(q) ? par[anc(p)] = anc(q), 1 : 0;
  }
} dsu;
class LowestCommonAncestor {
 private:
  int root[maxn][22], depth[maxn];
  long long dist[maxn];

 public:
  void dfs(int u, int p) {
    root[u][0] = p;
    for (auto &it : adj[u])
      if (it.second != p) {
        root[it.second][0] = u;
        depth[it.second] = depth[u] + 1;
        dist[it.second] = dist[u] + it.first;
        dfs(it.second, u);
      }
  }
  void init() {
    dfs(1, 1);
    for (int i = 1; i < 22; ++i)
      for (int u = 1; u <= n; ++u) {
        root[u][i] = root[root[u][i - 1]][i - 1];
      }
  }
  int lca(int u, int v) {
    for (int i = 20; i >= 0; --i)
      if (depth[root[u][i]] >= depth[v]) {
        u = root[u][i];
      }
    for (int i = 20; i >= 0; --i)
      if (depth[root[v][i]] >= depth[u]) {
        v = root[v][i];
      }
    if (u == v) return u;
    for (int i = 20; i >= 0; --i)
      if (root[u][i] != root[v][i]) {
        u = root[u][i];
        v = root[v][i];
      }
    return root[u][0];
  }
  long long distance(int u, int v) {
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
  }
} lca;
long long minDist(int u, int v) {
  long long res = lca.distance(u, v);
  for (int i = 1; i <= k; ++i) ux[i] = lca.distance(u, vertex[i]);
  for (int i = 1; i <= k; ++i) vy[i] = lca.distance(v, vertex[i]);
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= k; ++j) {
      res = min(res, ux[i] + f[i][j] + vy[j]);
    }
  return res;
}
void load() {
  cin >> n >> m;
  dsu.init(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(u, v, w);
    if (dsu.join(u, v)) {
      adj[u].push_back({w, v});
      adj[v].push_back({w, u});
    } else
      tmp.emplace_back(u, v, w);
  }
}
void process() {
  lca.init();
  for (auto &it : tmp) {
    int u, v, w;
    tie(u, v, w) = it;
    if (!id[u]) id[u] = ++k, vertex[k] = u;
    if (!id[v]) id[v] = ++k, vertex[k] = v;
  }
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= k; ++j) {
      f[i][j] = lca.distance(vertex[i], vertex[j]);
    }
  for (auto &it : tmp) {
    int u, v, w;
    tie(u, v, w) = it;
    f[id[u]][id[v]] = min(f[id[u]][id[v]], 1ll * w);
    f[id[v]][id[u]] = min(f[id[v]][id[u]], 1ll * w);
  }
  for (int o = 1; o <= k; ++o)
    for (int i = 1; i <= k; ++i)
      for (int j = 1; j <= k; ++j) {
        f[i][j] = min(f[i][j], f[i][o] + f[o][j]);
      }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << minDist(u, v) << "\n";
  }
}
int main() {
  load();
  process();
  return 0;
}
