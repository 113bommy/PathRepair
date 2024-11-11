#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
template <typename _T>
_T Fabs(_T x) {
  return x < 0 ? -x : x;
}
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
int n, nn, m, fa[100005], head[100005], tot, ans[100005 * 10];
int f[100005][20], far[100005][20], dep[100005], num[100005];
bool used[100005 * 10];
struct ming {
  int u, v, w, id;
} a[100005 * 10];
struct edge {
  int to, nxt, paid;
} e[100005 << 1];
void addEdge(int u, int v, int w) {
  e[++tot] = (edge){v, head[u], w};
  head[u] = tot;
}
bool cmp(ming x, ming y) { return x.w < y.w; }
void makeSet(int x) {
  for (int i = 1; i <= x; i++) fa[i] = i;
}
int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
void dfs(int u, int fa) {
  f[u][0] = fa;
  for (int i = 1; i <= nn; i++)
    f[u][i] = f[f[u][i - 1]][i - 1],
    far[u][i] = max(far[u][i - 1], far[f[u][i - 1]][i - 1]);
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    far[v][0] = e[i].paid;
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
}
pair<int, int> lca(int u, int v) {
  int res = -INF;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 0, k = dep[u] - dep[v]; k; k >>= 1, i++)
    if (k & 1) res = max(far[u][i], res), u = f[u][i];
  if (u == v) return make_pair(res, u);
  for (int i = nn; i >= 0; i--)
    if (f[u][i] != f[v][i])
      res = max(res, max(far[u][i], far[v][i])), u = f[u][i], v = f[v][i];
  return make_pair(max(res, max(far[u][0], far[v][0])), f[u][0]);
}
signed main() {
  read(n);
  read(m);
  nn = log2(n);
  for (int i = 1; i <= m; i++)
    read(a[i].u), read(a[i].v), read(a[i].w), a[i].id = i;
  sort(a + 1, a + m + 1, cmp);
  makeSet(n);
  for (int i = 1; i <= m; i++) {
    int u = findSet(a[i].u), v = findSet(a[i].v), w = a[i].w;
    if (u == v) continue;
    fa[u] = v;
    used[a[i].id] = 1;
    addEdge(a[i].u, a[i].v, w);
    addEdge(a[i].v, a[i].u, w);
  }
  dfs(1, 0);
  makeSet(n);
  for (int i = 1; i <= n; i++) num[i] = 1e9;
  for (int i = 1; i <= m; i++) {
    if (used[a[i].id]) continue;
    int u = a[i].u, v = a[i].v;
    pair<int, int> u_v = lca(u, v);
    ans[a[i].id] = u_v.first;
    while (dep[findSet(u)] > dep[u_v.second]) {
      int uu = findSet(u);
      num[uu] = min(num[uu], a[i].w);
      fa[uu] = findSet(f[uu][0]);
    }
    while (dep[findSet(v)] > dep[u_v.second]) {
      int vv = findSet(v);
      num[vv] = min(num[vv], a[i].w);
      fa[vv] = findSet(f[vv][0]);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!used[a[i].id]) continue;
    int u = a[i].u, v = a[i].v;
    if (dep[u] < dep[v]) swap(u, v);
    ans[a[i].id] = num[u];
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
