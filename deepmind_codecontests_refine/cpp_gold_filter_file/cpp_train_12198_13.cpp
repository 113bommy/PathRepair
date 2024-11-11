#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<pair<int, int>, pair<int, int> > > edges;
int par[101010], rnk[101010];
int find(int x) { return ((par[x] == x) ? x : par[x] = find(par[x])); }
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return false;
  if (rnk[x] > rnk[y])
    par[y] = x;
  else {
    par[x] = y;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
  return true;
}
bool in_mst[1010101];
vector<pair<int, int> > mst[101010];
int lvl[101010];
int dp_lca[101010][20], dp_mx[101010][20], dp_mn[101010][20];
int result[1010101];
void dfs(int u, int p) {
  for (int i = 1; i < 20; i++) {
    dp_lca[u][i] = dp_lca[dp_lca[u][i - 1]][i - 1];
    dp_mx[u][i] = max(dp_mx[u][i - 1], dp_mx[dp_lca[u][i - 1]][i - 1]);
    dp_mn[u][i] = 1e9;
  }
  for (int i = 0; i < mst[u].size(); i++) {
    int v = mst[u][i].first;
    int w = mst[u][i].second;
    if (v != p) {
      dp_lca[v][0] = u;
      dp_mx[v][0] = w;
      dp_mn[v][0] = 1e9;
      lvl[v] = lvl[u] + 1;
      dfs(v, u);
    }
  }
}
int lca(int u, int v) {
  if (lvl[u] > lvl[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) {
    if (lvl[v] - (1 << i) >= lvl[u]) {
      v = dp_lca[v][i];
    }
  }
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) {
    if (dp_lca[u][i] != dp_lca[v][i]) {
      u = dp_lca[u][i];
      v = dp_lca[v][i];
    }
  }
  return dp_lca[v][0];
}
int get_max_path(int u, int dh) {
  int res = 0;
  for (int i = 0; i <= 19; i++) {
    if (((dh >> i) & 1) == 0) continue;
    res = max(res, dp_mx[u][i]);
    u = dp_lca[u][i];
  }
  return res;
}
void set_min_path(int u, int dh, int val) {
  for (int i = 0; i <= 19; i++) {
    if (((dh >> i) & 1) == 0) continue;
    dp_mn[u][i] = min(dp_mn[u][i], val);
    u = dp_lca[u][i];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges.push_back(make_pair(make_pair(w, i), make_pair(u, v)));
  }
  sort(edges.begin(), edges.end());
  for (int i = 0; i < m; i++) {
    int u = edges[i].second.first, v = edges[i].second.second,
        w = edges[i].first.first;
    if (merge(u, v)) {
      in_mst[i] = true;
      mst[u].push_back(make_pair(v, w));
      mst[v].push_back(make_pair(u, w));
    }
  }
  memset(dp_lca, -1, sizeof dp_lca);
  dfs(0, -1);
  for (int i = 0; i < m; i++) {
    if (in_mst[i]) continue;
    int u = edges[i].second.first, v = edges[i].second.second;
    int w = lca(u, v);
    result[edges[i].first.second] =
        max(get_max_path(u, lvl[u] - lvl[w]), get_max_path(v, lvl[v] - lvl[w]));
    set_min_path(u, lvl[u] - lvl[w], edges[i].first.first);
    set_min_path(v, lvl[v] - lvl[w], edges[i].first.first);
  }
  for (int i = 19; i > 0; i--) {
    for (int v = 0; v < n; v++) {
      dp_mn[v][i - 1] = min(dp_mn[v][i - 1], dp_mn[v][i]);
      int u = dp_lca[v][i - 1];
      if (u != -1) {
        dp_mn[u][i - 1] = min(dp_mn[u][i - 1], dp_mn[v][i]);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (!in_mst[i]) continue;
    int u = edges[i].second.first, v = edges[i].second.second;
    if (lvl[u] > lvl[v]) swap(u, v);
    result[edges[i].first.second] = dp_mn[v][0];
  }
  for (int i = 0; i < m; i++) {
    cout << result[i] << "\n";
  }
}
