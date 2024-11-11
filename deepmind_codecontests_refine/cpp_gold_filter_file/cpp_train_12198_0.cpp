#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
int n, m, ans[M];
vector<pair<int, pair<long long, int>>> g[N];
struct edge {
  int u, v, w, id;
  bool operator<(const edge& b) const { return w < b.w; }
} e[M];
bool vis[M];
int f[N], fa[N][20], h[N], w[N][20], id[N], nxt[N];
int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
void dfs1(int u, int p) {
  fa[u][0] = p, h[u] = h[p] + 1, nxt[u] = p;
  for (int i = 1; i <= 18; ++i) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1],
    w[u][i] = max(w[u][i - 1], w[fa[u][i - 1]][i - 1]);
  }
  for (auto it : g[u]) {
    if (it.first == p) continue;
    w[it.first][0] = it.second.first;
    id[it.first] = it.second.second;
    dfs1(it.first, u);
  }
}
pair<long long, int> LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  int d = h[u] - h[v], ans = 0;
  for (int i = (0); i < (19); i++)
    if ((d >> i) & 1) ans = max(ans, w[u][i]), u = fa[u][i];
  if (u == v) return pair<long long, int>(u, ans);
  for (int i = 18; i >= 0; --i)
    if (fa[u][i] != fa[v][i]) {
      ans = max(ans, w[u][i]);
      ans = max(ans, w[v][i]);
      u = fa[u][i], v = fa[v][i];
    }
  ans = max(ans, w[u][0]);
  ans = max(ans, w[v][0]);
  return pair<long long, int>(fa[u][0], ans);
}
void solve(int u, int lca, int cost) {
  while (find(u) != find(lca)) {
    ans[id[u]] = min(ans[id[u]], cost);
    int fx = find(u), fy = find(nxt[u]);
    f[fx] = fy;
    u = fy;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = (1); i < (n + 1); i++) f[i] = i;
  for (int i = (1); i < (m + 1); i++) {
    ans[i] = 1e9;
    cin >> e[i].u >> e[i].v >> e[i].w;
    e[i].id = i;
  }
  sort(e + 1, e + m + 1);
  for (int i = (1); i < (m + 1); i++) {
    int fx = find(e[i].u), fy = find(e[i].v);
    if (fx == fy) continue;
    vis[i] = true;
    g[e[i].u].push_back(
        make_pair(e[i].v, pair<long long, int>(e[i].w, e[i].id)));
    g[e[i].v].push_back(
        make_pair(e[i].u, pair<long long, int>(e[i].w, e[i].id)));
    f[fx] = fy;
  }
  for (int i = (1); i < (n + 1); i++) f[i] = i;
  dfs1(1, 0);
  for (int i = (1); i < (m + 1); i++) {
    if (vis[i]) continue;
    pair<long long, int> res = LCA(e[i].u, e[i].v);
    ans[e[i].id] = res.second;
    int lca = res.first;
    solve(e[i].u, lca, e[i].w);
    solve(e[i].v, lca, e[i].w);
  }
  for (int i = (1); i < (m + 1); i++) cout << ans[i] << "\n";
  return 0;
}
