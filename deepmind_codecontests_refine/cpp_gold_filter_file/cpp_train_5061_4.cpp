#include <bits/stdc++.h>
inline int rd() {
  int x = 0, p = 1;
  char a = getchar();
  while ((a < 48 || a > 57) && a != '-') a = getchar();
  if (a == '-') p = -p, a = getchar();
  while (a > 47 && a < 58) {
    x = (x << 1) + (x << 3) + (a & 15);
    a = getchar();
  }
  return x * p;
}
inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }
const int N = 300002;
struct Edge {
  int to, next;
} edge[N << 1];
int head[N << 1], cnt;
int n, m, k, p;
inline void add(int f, int t) {
  edge[++cnt].next = head[f];
  edge[cnt].to = t;
  head[f] = cnt;
}
int x[N], f[602][602], l, r, ans;
int vis[N], pre[N];
inline int dfs(int u) {
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (!vis[v]) {
      vis[v] = 1;
      if (!pre[v] || dfs(pre[v])) {
        pre[v] = u;
        return 1;
      }
    }
  }
  return 0;
}
inline int check(int mid) {
  cnt = 0;
  memset(head, 0, sizeof head);
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++)
      if (f[x[i]][j] <= mid) add(i, j);
  int ans = 0;
  memset(pre, 0, sizeof pre);
  for (int i = 1; i <= n; i++) ans += dfs(i), memset(vis, 0, sizeof vis);
  return ans >= p;
}
int main() {
  for (int i = 1; i <= 600; i++)
    for (int j = 1; j <= 600; j++) f[i][j] = (i ^ j) ? 1000000000 : 0;
  n = rd(), m = rd(), k = rd(), p = rd();
  for (int i = 1; i <= k; i++) x[i] = rd();
  for (int i = 1; i <= m; i++) {
    int u = rd(), v = rd(), w = rd();
    f[u][v] = f[v][u] = min(f[v][u], w);
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  l = 0, r = 1800000;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (l > 1731311)
    puts("-1");
  else
    printf("%d\n", l);
  return 0;
}
