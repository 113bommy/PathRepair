#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, maxn = 1e5 + 5, maxm = 1e6 + 5, maxlog = 17;
int n, m, dsu[maxn], par[maxn][maxlog], maxx[maxn][maxlog], h[maxn], ind[maxm],
    minn[maxn][maxlog], ans[maxm];
bool mst[maxm];
vector<pair<int, int> > gr[maxn];
struct edge {
  int u, v, w;
} edges[maxm];
bool cmp(int i, int j) { return edges[i].w < edges[j].w; }
void init() {
  for (int i = 1; i <= n; ++i) {
    dsu[i] = -1;
  }
}
int find(int x) {
  if (dsu[x] < 0) return x;
  return dsu[x] = find(dsu[x]);
}
void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) {
    return;
  }
  if (dsu[u] > dsu[v]) swap(u, v);
  dsu[u] += dsu[v];
  dsu[v] = u;
}
void dfs(int u, int p) {
  par[u][0] = p;
  for (auto cac : gr[u]) {
    if (cac.first != p) {
      int v = cac.first, w = cac.second;
      maxx[v][0] = w;
      minn[v][0] = inf;
      h[v] = h[u] + 1;
      dfs(v, u);
    }
  }
}
void build() {
  for (int j = 1; j < maxlog; ++j) {
    for (int i = 1; i <= n; ++i) {
      par[i][j] = par[par[i][j - 1]][j - 1];
      maxx[i][j] = max(maxx[i][j - 1], maxx[par[i][j - 1]][j - 1]);
      minn[i][j] = inf;
    }
  }
}
int get_heavy(int u, int v, int w) {
  int res = 0;
  if (h[u] < h[v]) swap(u, v);
  for (int i = maxlog - 1; i >= 0; --i) {
    if (h[u] - (1 << i) >= h[v]) {
      res = max(res, maxx[u][i]);
      minn[u][i] = min(minn[u][i], w);
      u = par[u][i];
    }
  }
  if (u == v) return res;
  for (int i = maxlog - 1; i >= 0; --i) {
    if (par[u][i] != par[v][i]) {
      res = max(max(res, maxx[u][i]), maxx[v][i]);
      minn[u][i] = min(minn[u][i], w);
      minn[v][i] = min(minn[v][i], w);
      u = par[u][i];
      v = par[v][i];
    }
  }
  minn[u][0] = min(minn[u][0], w);
  minn[v][0] = min(minn[v][0], w);
  res = max(max(res, maxx[u][0]), maxx[v][0]);
  return res;
}
void re_calc() {
  for (int j = maxlog - 1; j >= 0; --j) {
    for (int i = 1; i <= n; ++i) {
      minn[i][j - 1] = min(minn[i][j - 1], minn[i][j]);
      minn[par[i][j - 1]][j - 1] = min(minn[par[i][j - 1]][j - 1], minn[i][j]);
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    ind[i] = i;
  }
  init();
  sort(ind + 1, ind + m + 1, cmp);
  for (int i = 1; i <= m; ++i) {
    int now = ind[i];
    if (find(edges[now].u) == find(edges[now].v)) {
      continue;
    }
    merge(edges[now].u, edges[now].v);
    gr[edges[now].u].push_back(make_pair(edges[now].v, edges[now].w));
    gr[edges[now].v].push_back(make_pair(edges[now].u, edges[now].w));
    mst[now] = 1;
  }
  dfs(1, -1);
  build();
  for (int i = 1; i <= m; ++i) {
    if (!mst[i]) {
      ans[i] = get_heavy(edges[i].u, edges[i].v, edges[i].w);
    }
  }
  re_calc();
  for (int i = 1; i <= m; ++i) {
    if (mst[i]) {
      if (par[edges[i].u][0] != edges[i].v) {
        swap(edges[i].u, edges[i].v);
      }
      ans[i] = minn[edges[i].u][0];
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
