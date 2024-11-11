#include <bits/stdc++.h>
#pragma warning(disable : 4786)
using namespace std;
int n;
struct Node {
  int v, w, id;
  Node(int v_, int w_, int idd) {
    v = v_, w = w_;
    id = idd;
  }
};
vector<Node> g[100002];
int father[100002];
int dis[100002];
int dep[100002];
int d[100002], u[100002], inn[100002], ot[100002];
int id;
void dfs(int x, int fa, int deep) {
  father[x] = fa;
  dep[x] = deep;
  for (int i = 0; i < g[x].size(); ++i) {
    int v = g[x][i].v;
    if (v == fa) continue;
    dis[v] = dis[x] + g[x][i].w;
    u[g[x][i].id] = id;
    id++;
    if (ot[x] == -1) ot[x] = g[x][i].id;
    inn[v] = g[x][i].id;
    dfs(v, x, deep + 1);
    d[g[x][i].id] = id;
    id++;
  }
}
int p[100002][30];
void Init_LCA() {
  int i, j;
  for (j = 0; (1 << j) <= n; ++j)
    for (i = 1; i <= n; ++i) p[i][j] = -1;
  for (i = 1; i <= n; ++i) p[i][0] = father[i];
  for (j = 1; (1 << j) <= n; ++j)
    for (int i = 1; i <= n; ++i)
      if (p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int i, lg;
  for (lg = 0; (1 << lg) <= dep[x]; ++lg)
    ;
  --lg;
  for (i = lg; i >= 0; --i)
    if (dep[x] - (1 << i) >= dep[y]) x = p[x][i];
  if (x == y) return x;
  for (i = lg; i >= 0; --i)
    if (p[x][i] != -1 && p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
  return father[x];
}
int num[100002 * 4], col[100002 * 4];
void pushdown(int t) {
  if (col[t]) {
    num[(t << 1)] += col[t];
    num[(t << 1 | 1)] += col[t];
    col[(t << 1)] += col[t];
    col[(t << 1 | 1)] += col[t];
    col[t] = 0;
  }
}
void update(int ll, int rr, int t, int l, int r, int z) {
  if (l != r) pushdown(t);
  if (ll <= l && r <= rr) {
    col[t] += z;
    num[t] += z;
    return;
  }
  int m = (l + r) / 2;
  if (ll <= m) update(ll, rr, (t << 1), l, m, z);
  if (rr > m) update(ll, rr, (t << 1 | 1), m + 1, r, z);
}
int query(int p, int t, int l, int r) {
  if (l != r) pushdown(t);
  if (p == l && p == r) {
    return num[t];
  }
  int m = (l + r) / 2;
  if (p <= m) return query(p, (t << 1), l, m);
  if (p > m) return query(p, (t << 1 | 1), m + 1, r);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    int i;
    for (i = 1; i <= n; i++) g[i].clear();
    for (i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      g[a].push_back(Node(b, 1, i));
      g[b].push_back(Node(a, 1, i));
    }
    memset(num, 0, sizeof(num));
    memset(col, 0, sizeof(col));
    memset(inn, -1, sizeof(inn));
    memset(ot, -1, sizeof(ot));
    id = 1;
    dis[1] = 0;
    dfs(1, -1, 0);
    Init_LCA();
    int k;
    scanf("%d", &k);
    while (k--) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (a == b) continue;
      int lca = LCA(a, b);
      if (inn[a] != -1) update(u[ot[lca]], u[inn[a]], 1, 1, id - 1, 1);
      if (inn[b] != -1) update(u[ot[lca]], u[inn[b]], 1, 1, id - 1, 1);
    }
    for (i = 1; i < n; i++) {
      int s1 = query(u[i], 1, 1, id - 1);
      int s2 = query(d[i], 1, 1, id - 1);
      if (i != 1) printf(" ");
      printf("%d", s1 - s2);
    }
    printf("\n");
  }
  return 0;
}
