#include <bits/stdc++.h>
const int B = 255;
using std::max;
const int MAXN = 2e5 + 7;
int n, m;
int a[MAXN];
int home[MAXN], nxt[MAXN], to[MAXN], ccnt;
inline void ct(int x, int y) {
  ccnt++;
  nxt[ccnt] = home[x];
  to[ccnt] = y;
  home[x] = ccnt;
}
int dep[MAXN], fa[MAXN];
inline void dfs(int u, int F) {
  fa[u] = F;
  for (int i = home[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == F) continue;
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
  return;
}
int ch[MAXN][2], T, f[MAXN][B + 10], gp[MAXN];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1, x, y; i < n; ++i) {
    scanf("%d%d", &x, &y);
    ct(x, y);
    ct(y, x);
  }
  dfs(1, 0);
  for (int i = 1, x; i <= n; ++i) {
    if (dep[i] >= B) {
      x = i;
      ch[0][0] = 0;
      ch[0][1] = 0;
      T = 0;
      for (int j = 0; j <= B; ++j, x = fa[x]) {
        int t = a[x] ^ j;
        int nw = 0;
        for (int k = 16; k >= 0; --k) {
          int c = (t >> k) & 1;
          if (!ch[nw][c]) {
            ch[nw][c] = ++T;
            ch[T][0] = ch[T][1] = 0;
          }
          nw = ch[nw][c];
        }
      }
      for (int j = 0; j <= B; ++j) {
        int t = j << 8;
        int nw = 0, S = 0;
        for (int k = 16; k >= 0; --k) {
          int c = (t >> k) & 1;
          if (ch[nw][c ^ 1]) {
            nw = ch[nw][c ^ 1];
            S += (1 << k);
          } else
            nw = ch[nw][c];
        }
        f[i][j] = S;
      }
      gp[i] = x;
    }
  }
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    int ans = 0;
    int qwq = 0;
    int st = dep[y];
    while (dep[y] - dep[x] >= B) {
      ans = max(f[y][qwq], ans);
      ++qwq;
      y = gp[y];
    }
    while (y != fa[x]) {
      ans = max(ans, a[y] ^ (st - dep[y]));
      y = fa[y];
    }
    printf("%d\n", ans);
  }
  return 0;
}
