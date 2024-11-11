#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int re() {
  int x = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * w;
}
int n, m, cnt, len, s, ed, di, ans;
int h[N], p[N], t[N], l[N], lg[N], dep[N], f[N], g[2][20][N];
bool vis[N];
struct edge {
  int to, next;
} e[N << 1];
void link(int u, int v) {
  e[++cnt] = (edge){v, h[u]};
  h[u] = cnt;
  e[++cnt] = (edge){u, h[v]};
  h[v] = cnt;
}
void dfs(int u, int fa, int d, int o) {
  if (d > len) len = d, s = u;
  if (o) p[u] = fa;
  for (int i = h[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v != fa) dfs(v, u, d + 1, o);
  }
}
void init(int u, int fa, int tp) {
  t[u] = tp;
  f[tp] = max(f[tp], dep[u]);
  for (int i = h[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (!vis[v] && v != fa) dep[v] = dep[u] + 1, init(v, u, tp);
  }
}
int q(int l, int r, int o) {
  if (r < l) return -1e9;
  int k = lg[r - l + 1];
  return max(g[o][k][l], g[o][k][r - (1 << k) + 1]);
}
int main() {
  n = re();
  for (int i = 1, u, v; i < n; i++) {
    u = re(), v = re();
    link(u, v);
  }
  m = re();
  dfs(1, 0, 0, 0);
  ed = s;
  len = 0;
  dfs(ed, 0, 0, 1);
  for (int i = s; i; i = p[i]) vis[i] = 1, l[++di] = i;
  for (int i = 1; i <= di; i++) init(l[i], 0, i);
  for (int i = 1; i <= di; i++) g[0][0][i] = f[i] + i, g[1][0][i] = f[i] - i;
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int k = 0; k < 2; k++)
    for (int i = 1; i <= 17; i++)
      for (int j = 1; j + (1 << i) - 1 <= di; j++)
        g[k][i][j] = max(g[k][i - 1][j], g[k][i - 1][j + (1 << (i - 1))]);
  while (m--) {
    int x = re(), y = re();
    if (t[x] == t[y])
      ans = max(t[x] - 1, di - t[x]) + min(dep[x], dep[y]);
    else {
      if (t[x] > t[y]) swap(x, y);
      int mid = (t[x] + t[y] - dep[x] + dep[y]);
      if (mid <= t[x] * 2)
        ans = max(t[y] - 1, di - t[y]) + dep[y];
      else if (mid >= t[y] * 2)
        ans = max(t[x] - 1, di - t[x]) + dep[x];
      else {
        mid >>= 1;
        ans = max(max(t[x] - 1, q(t[x] + 1, mid, 0) - t[x]) + dep[x],
                  max(di - t[y], q(mid + 1, t[y] - 1, 1) + t[y]) + dep[y]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
