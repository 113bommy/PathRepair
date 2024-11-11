#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 100000 + 10;
int n, f[N][30], size[N], dep[N], m;
struct edge {
  int u, v;
  edge *next;
} e[2 * N], *point[N], *P = e;
inline void add_edge(int x, int y) {
  edge *Q = ++P;
  ++P;
  P->u = x;
  P->v = y;
  P->next = point[x];
  point[x] = P;
  Q->u = y;
  Q->v = x;
  Q->next = point[y];
  point[y] = Q;
}
void dfs(int x, int fa, int depth) {
  f[x][0] = fa;
  dep[x] = depth;
  size[x] = 1;
  for (edge *j = point[x]; j; j = j->next) {
    if (j->v == fa) continue;
    dfs(j->v, x, depth + 1);
    size[x] += size[j->v];
  }
}
void LCA_init() {
  for (int d = 1; d <= 29; d++) {
    for (int i = 1; i <= n; i++) f[i][d] = f[f[i][d - 1]][d - 1];
  }
}
int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int dd = dep[u] - dep[v];
  for (int i = 0; i < 30; i++)
    if ((1 << i) & dd) u = f[u][i];
  if (u == v) return u;
  for (int i = 29; i >= 0; i--)
    if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
  u = f[u][0];
  return u;
}
int fa(int x, int dep) {
  int i = 0;
  while (dep) {
    if (dep & 1) x = f[x][i];
    i++;
    dep >>= 1;
  }
  return x;
}
int main() {
  f[0][0] = 0;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add_edge(a, b);
  }
  dfs(1, 0, 1);
  LCA_init();
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x, y, f, fx, fy, ans;
    scanf("%d%d", &x, &y);
    f = LCA(x, y);
    if (dep[x] == dep[y]) {
      if (x == y)
        ans = n - 1;
      else {
        fx = fa(x, dep[x] - dep[f] - 1);
        fy = fa(y, dep[y] - dep[f] - 1);
        ans = n - size[f];
        ans += size[f] - size[fx] - size[fy];
      }
    } else {
      if (dep[x] > dep[y]) swap(x, y);
      int len = dep[x] - dep[f] + dep[y] - dep[f] - 1;
      if (len % 2 == 0)
        ans = 0;
      else {
        fy = fa(y, len / 2);
        f = fa(fy, 1);
        ans = size[f] - size[fy];
      }
    }
    printf("%d\n", ans);
  }
}
