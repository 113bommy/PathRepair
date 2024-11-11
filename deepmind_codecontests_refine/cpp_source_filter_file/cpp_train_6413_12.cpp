#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, K = 20, oo = 1e9 + 8;
struct node {
  int x, y, z, id;
};
int n, m;
node e[N];
vector<pair<int, int> > adj[N];
int cha[N];
bool mark[N];
int F[N][20], D[N][20], dep[N];
int ew[N];
int ans[N];
bool cmp(node i, node j) { return i.z < j.z; }
int timgoc(int u) {
  if (u != cha[u]) cha[u] = timgoc(cha[u]);
  return cha[u];
}
void hop_cay(int u, int v, int d) {
  int gocu = timgoc(u), gocv = timgoc(v);
  if (gocu == gocv) return;
  cha[gocu] = gocv;
  adj[u].push_back(make_pair(v, d));
  adj[u].push_back(make_pair(u, d));
  mark[d] = true;
}
void dfs(int u) {
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i].first;
    int d = adj[u][i].second;
    if (F[v][0] == -1) {
      F[v][0] = u;
      D[v][0] = e[d].z;
      ew[v] = e[d].id;
      dep[v] = dep[u] + 1;
      dfs(v);
    }
  }
}
int lca(int u, int v, int d) {
  int tmp = 0;
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = 19; i >= 0; --i)
    if (dep[F[v][i]] <= dep[u]) {
      tmp = max(tmp, D[v][i]);
      v = F[v][i];
    }
  for (int i = 19; i >= 0; --i)
    if (F[v][i] != F[u][i]) {
      tmp = max(tmp, D[u][i]);
      tmp = max(tmp, D[v][i]);
      u = F[u][i];
      v = F[v][i];
    }
  if (v != u) {
    tmp = max(tmp, max(D[u][0], D[v][0]));
    u = F[u][0];
    v = F[v][0];
  }
  ans[d] = tmp - 1;
  return u;
}
void upd(int u, int v, int z) {
  u = timgoc(u);
  while (dep[u] > dep[v]) {
    ans[ew[u]] = min(ans[ew[u]], z);
    int y = timgoc(F[u][0]);
    cha[u] = y;
    u = y;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> e[i].x >> e[i].y >> e[i].z, e[i].id = i;
  sort(e + 1, e + m + 1, cmp);
  memset(mark, false, sizeof(mark));
  for (int i = 1; i <= n; ++i) cha[i] = i;
  for (int i = 1; i <= m; ++i) hop_cay(e[i].x, e[i].y, i);
  for (int i = 1; i <= n; ++i) F[i][0] = -1;
  F[1][0] = 0;
  dep[1] = 1;
  dfs(1);
  for (int i = 1; i < K; ++i)
    for (int j = 1; j <= n; ++j) {
      D[j][i] = max(D[j][i - 1], D[F[j][i - 1]][i - 1]);
      F[j][i] = F[F[j][i - 1]][i - 1];
    }
  memset(ans, 127, sizeof(ans));
  for (int i = 1; i <= n; ++i) cha[i] = i;
  for (int i = 1; i <= m; ++i)
    if (!mark[i]) {
      int a = lca(e[i].x, e[i].y, e[i].id);
      upd(e[i].x, a, e[i].z - 1);
      upd(e[i].y, a, e[i].z - 1);
    }
  for (int i = 1; i <= m; ++i)
    if (ans[i] > oo)
      cout << -1 << ' ';
    else
      cout << ans[i] << ' ';
}
