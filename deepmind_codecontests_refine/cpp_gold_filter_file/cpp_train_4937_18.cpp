#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int SUM = 0, ff = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    SUM = (SUM << 3) + (SUM << 1) + (ch ^ 48);
    ch = getchar();
  }
  return SUM * ff;
}
const int N = 1000010;
struct edge {
  int nxt, to;
} e[N << 1];
int h[N], cnte = 1;
inline void addedge(int u, int v) { e[++cnte] = (edge){h[u], v}, h[u] = cnte; }
int Q, cnt = 1;
int dep[N], fa[N][21];
int d1, d2, ans;
inline void dfs(int u, int fu) {
  dep[u] = dep[fu] + 1;
  fa[u][0] = fu;
  for (int i = 1; (1 << i) <= dep[u]; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fu) continue;
    dfs(v, u);
  }
}
inline int getlca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int l = dep[u] - dep[v];
  for (int i = 20; i >= 0; i--)
    if (l & (1 << i)) u = fa[u][i];
  if (u == v) return u;
  for (int i = 20; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i];
      v = fa[v][i];
    }
  return fa[u][0];
}
int main() {
  for (int i = 1; i <= 3; i++) addedge(1, ++cnt);
  dfs(1, 0);
  d1 = 2, d2 = 3, ans = 2;
  Q = read();
  while (Q--) {
    int v = read();
    addedge(v, ++cnt);
    addedge(v, ++cnt);
    dfs(v, fa[v][0]);
    int lca1 = getlca(v, d1), lca2 = getlca(v, d2);
    int len1 = dep[v] + dep[d1] - 2 * dep[lca1] + 1;
    int len2 = dep[v] + dep[d2] - 2 * dep[lca2] + 1;
    if (len1 <= ans && len2 <= ans) {
      printf("%d\n", ans);
    } else if (len1 > len2) {
      ans = len1;
      d2 = cnt;
      printf("%d\n", ans);
    } else {
      ans = len2;
      d1 = cnt;
      printf("%d\n", ans);
    }
  }
  return 0;
}
