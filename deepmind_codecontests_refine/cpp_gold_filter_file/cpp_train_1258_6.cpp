#include <bits/stdc++.h>
using namespace std;
int n, m, num, xx, yy;
long long a[300010], d[300010], d1[300010], d2[300010], h[300010],
    fa[300010][20], f1[300010], f2[300010], w[300010], dp1[300010], dp2[300010];
struct edge {
  int to, z, next;
} mp[300010 << 1];
inline char gc() {
  static char *S, *T, buf[1 << 16];
  if (T == S) {
    T = (S = buf) + fread(buf, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = gc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = gc();
  return x * f;
}
inline void ins(int x, int y, int z) {
  mp[++num].to = y;
  mp[num].z = z;
  mp[num].next = h[x];
  h[x] = num;
  mp[++num].to = x;
  mp[num].z = z;
  mp[num].next = h[y];
  h[y] = num;
}
void dfs1(int x) {
  for (int i = 1; i <= 19; i++) {
    if (!fa[x][i - 1]) break;
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  }
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].to;
    if (d[y]) continue;
    d[y] = d[x] + 1;
    d1[y] = d1[x] + a[y];
    d2[y] = d2[x] + mp[i].z;
    fa[y][0] = x;
    dfs1(y);
    w[y] = mp[i].z;
    f1[y] = max(dp1[y] + a[y] - 2 * mp[i].z, 0ll);
    dp1[x] += f1[y];
  }
}
void dfs2(int x, int f) {
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].to;
    if (d[y] != d[x] + 1) continue;
    dp2[y] = max(dp2[x] + dp1[x] + a[x] - f1[y] - 2 * mp[i].z, 0ll);
    f2[y] = max(f2[x] + dp1[x] - f1[y], 0ll);
    dfs2(y, x);
  }
}
inline int lca(int x, int y) {
  int len = d[x] - d[y];
  for (int i = 0; i <= 19; i++) {
    if (len & (1 << i)) x = fa[x][i];
  }
  if (x == y) return x;
  for (int i = 19; i >= 0; i--) {
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  xx = x, yy = y;
  return fa[x][0];
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read(), z = read();
    ins(x, y, z);
  }
  d[1] = 1;
  d1[1] = a[1];
  dfs1(1);
  dfs2(1, 0);
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    xx = yy = 0;
    if (d[x] < d[y]) swap(x, y);
    if (x == y) {
      printf("%I64d\n", dp1[x] + dp2[x] + a[x]);
      continue;
    }
    int z = lca(x, y);
    if (y == z)
      printf("%I64d\n", (d1[x] - d1[y] + a[y]) - (d2[x] - d2[y]) +
                            (f2[x] - f2[y]) + dp2[y] + dp1[x]);
    else
      printf("%I64d\n",
             (d1[x] + d1[y] - 2 * d1[z] + a[z]) - (d2[x] + d2[y] - 2 * d2[z]) +
                 (f2[x] + f2[y] - f2[xx] - f2[yy]) +
                 (dp1[z] - f1[xx] - f1[yy]) + dp2[z] + dp1[x] + dp1[y]);
  }
  return 0;
}
