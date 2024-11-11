#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct three {
  int u, v, w;
};
struct DSU {
  vector<int> par;
  void kc(int n) { par.assign(n + 5, -1); }
  int root(int u) { return (par[u] < 0 ? u : par[u] = root(par[u])); }
  bool dsu(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return 0;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return 1;
  }
} g;
struct fenwick {
  vector<int> fw;
  int n;
  void kc(int _n) {
    n = _n;
    fw.assign(n + 5, 0);
  }
  void upd(int i, int val) {
    for (; i <= n; i += i & -i) fw[i] += val;
  }
  void upd(int l, int r, int val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  int get(int i) {
    int ans = 0;
    for (; i; i -= i & -i) ans += fw[i];
    return ans;
  }
} fw;
int n, q;
int par[N];
vector<three> edges;
vector<pair<int, int> > dsk[N];
bool used[N * 2], vis[N], useless[N];
int anc[N][20], h[N];
bool weight[N];
int tin[N], tout[N], timer;
void dfs(int u, int pre) {
  tin[u] = ++timer;
  vis[u] = 1;
  for (pair<int, int> node : dsk[u])
    if (!vis[node.first]) {
      int v = node.first, c = node.second;
      anc[v][0] = u;
      weight[v] = (weight[u] ^ c);
      h[v] = h[u] + 1;
      dfs(v, u);
    }
  tout[u] = timer;
}
int LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  int k = log2(h[u]);
  for (int i = k; i >= 0; --i)
    if (h[u] - (1 << i) >= h[v]) u = anc[u][i];
  if (u == v) return u;
  for (int i = k; i >= 0; --i)
    if (anc[u][i] && anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  return anc[u][0];
}
void update(int u, int v) {
  while (u != v) {
    fw.upd(tin[u], tout[u], 1);
    u = anc[u][0];
  }
}
void gogo() {
  cin >> n >> q;
  DSU g;
  g.kc(n);
  for (int i = 1; i <= q; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
    if (g.dsu(u, v)) {
      used[i - 1] = 1;
      dsk[u].push_back(make_pair(v, w));
      dsk[v].push_back(make_pair(u, w));
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i, i);
  for (int j = 1; j <= log2(n); ++j)
    for (int i = 1; i <= n; ++i) anc[i][j] = anc[anc[i][j - 1]][j - 1];
  fw.kc(n);
  for (int i = 0; i < q; ++i) {
    int u = edges[i].u, v = edges[i].v, w = edges[i].w;
    if (used[i]) {
      cout << "YES\n";
      continue;
    }
    int lca = LCA(u, v);
    int val = fw.get(tin[u]) + fw.get(tin[v]) - 2 * fw.get(tin[lca]);
    if (val || (weight[u] ^ weight[v] ^ w) == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    update(u, lca);
    update(v, lca);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("sol"
            ".inp",
            "r")) {
    freopen(
        "sol"
        ".inp",
        "r", stdin);
    freopen(
        "sol"
        ".out",
        "w", stdout);
  }
  gogo();
}
