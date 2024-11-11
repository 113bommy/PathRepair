#include <bits/stdc++.h>
using namespace std;
const int maxn = 2505;
struct EDGE {
  int a, b, d;
  EDGE(int a = 0, int b = 0, int d = 0) : a(a), b(b), d(d) {}
  bool operator<(const EDGE &C) const { return d < C.d; }
} E[maxn * maxn];
int n;
vector<pair<int, int> > T[maxn];
int a[maxn][maxn];
int fa[maxn];
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
void mst() {
  for (int i = 0; i < n; i++) fa[i] = i;
  for (int i = 0; i < n * n; i++) {
    EDGE &e = E[i];
    if (find(e.a) == find(e.b)) continue;
    T[e.a].push_back(pair<int, int>(e.b, e.d));
    T[e.b].push_back(pair<int, int>(e.a, e.d));
    fa[find(e.a)] = find(e.b);
  }
}
int maxd[15][maxn];
int pa[15][maxn];
int dep[maxn];
void dfs(int v, int f = -1, int d = 0) {
  dep[v] = d;
  for (int i = 0; i < T[v].size(); i++) {
    int u = T[v][i].first;
    int d = T[v][i].second;
    if (u == f) continue;
    maxd[0][u] = d;
    pa[0][u] = v;
    dfs(u, v, d + 1);
  }
}
void preLca() {
  for (int k = 1; k < 15; k++) {
    for (int i = 0; i < n; i++) {
      pa[k][i] = pa[k - 1][pa[k - 1][i]];
      maxd[k][i] = max(maxd[k - 1][i], maxd[k - 1][pa[k - 1][i]]);
    }
  }
}
int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  int ans = 0;
  for (int k = 0; k < 15; k++) {
    if ((dep[a] - dep[b]) & (1 << k)) ans = max(maxd[k][a], ans), a = pa[k][a];
  }
  if (a == b) return ans;
  for (int k = 14; k >= 0; k--) {
    if (pa[k][a] != pa[k][b]) {
      ans = max(max(maxd[k][a], maxd[k][b]), ans);
      a = pa[k][a], b = pa[k][b];
    }
  }
  ans = max(max(maxd[0][a], maxd[0][b]), ans);
  return ans;
}
bool check1() {
  for (int i = 0; i < n; i++) {
    if (a[i][i] != 0) return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != a[j][i]) return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      E[i * n + j] = EDGE(i, j, a[i][j]);
    }
  }
  if (!check1()) {
    puts("NOT MAGIC");
    return 0;
  }
  sort(E, E + n * n);
  mst();
  dfs(0);
  preLca();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i][j] != lca(i, j)) {
        puts("NOT MAGIC");
        return 0;
      }
    }
  }
  puts("MAGIC");
  return 0;
}
