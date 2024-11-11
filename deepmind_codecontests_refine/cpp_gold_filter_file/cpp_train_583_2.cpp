#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int d = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; d = d * 10 + c - 48, c = getchar())
    ;
  return d * f;
}
const int N = 500001;
int n, dp[N][2], DP[N][2];
int cnt, fa[N], head[N], sz[N], SZ[N];
struct xint {
  int to, next;
} e[N * 2];
void addedge(int x, int y) {
  e[++cnt] = (xint){y, head[x]};
  head[x] = cnt;
}
void Addedge(int x, int y) {
  addedge(x, y);
  addedge(y, x);
}
void dfs1(int x) {
  sz[x] = 1;
  for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
    if (y != fa[x]) fa[y] = x, dfs1(y), sz[x] += sz[y];
  if (sz[x] == 1) {
    dp[x][0] = 1;
    return;
  }
  int s = 0, o = 0;
  for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
    if (y != fa[x])
      if (sz[y] & 1) s++, o = y;
  if (!(sz[x] & 1)) {
    if (s != 1) return;
    bool fg = 1;
    for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
      if (y != fa[x])
        if (y != o) fg = fg && dp[y][0];
    if (fg) dp[x][0] = dp[o][0], dp[x][1] = dp[o][0] + dp[o][1];
  } else {
    if (s != 0 && s != 2) return;
    bool fg = 1;
    if (s == 0) {
      int tg = 0, tt = 0;
      for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
        if (y != fa[x])
          if (!dp[y][0]) tg++, tt = y;
      if (!tg) dp[x][0] = 1;
      if (!tg)
        for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
          if (y != fa[x]) dp[x][1] += dp[y][1];
      if (tg == 1) dp[x][1] = dp[tt][1];
    }
    if (s == 2) {
      int oo = 0;
      for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
        if (y != fa[x])
          if (sz[y] & 1) {
            oo = y;
            break;
          }
      for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
        if (y != fa[x])
          if (y != o && y != oo) fg = fg && dp[y][0];
      if (!fg) return;
      bool b1 = dp[o][0], b2 = dp[oo][0];
      if (b1) dp[x][1] = dp[oo][1] + b2;
      if (b2) dp[x][1] += dp[o][1] + b1;
    }
  }
}
struct yint {
  int a, b, c, d, e, f;
} qz[N], hz[N];
int p[N], p0[N], p1[N];
void dfs2(int x) {
  int m = 0;
  for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
    if (y != fa[x]) p[++m] = y, p0[y] = dp[y][0], p1[y] = dp[y][1];
  if (x == 1 && m == 1) {
    DP[p[1]][0] = 1;
    dfs2(p[1]);
    return;
  }
  qz[0] = hz[m + 1] = (yint){0, 1, 0, 0, 0, 0};
  if (x != 1) {
    p[0] = x;
    p0[x] = DP[x][0];
    p1[x] = DP[x][1];
    qz[0].a = (SZ[x] & 1);
    if (!(SZ[x] & 1))
      qz[0].b &= p0[x];
    else
      qz[0].c = x;
    if (!p0[x]) qz[0].e++, qz[0].f = x;
  }
  for (int i = 1; i <= m; ++i) {
    int y = p[i];
    qz[i] = qz[i - 1];
    qz[i].a += (sz[y] & 1);
    if (!(sz[y] & 1))
      qz[i].b &= p0[y];
    else if (qz[i].c)
      qz[i].d = y;
    else
      qz[i].c = y;
    if (!p0[y]) qz[i].e++, qz[i].f = y;
  }
  for (int i = m; i >= 1; --i) {
    int y = p[i];
    hz[i] = hz[i + 1];
    hz[i].a += (sz[y] & 1);
    if (!(sz[y] & 1))
      hz[i].b &= p0[y];
    else if (hz[i].c)
      hz[i].d = y;
    else
      hz[i].c = y;
    if (!p0[y]) hz[i].e++, hz[i].f = y;
  }
  int tot = 0;
  if (x != 1) tot = p1[x];
  for (int i = 1; i <= m; ++i) tot += p1[p[i]];
  for (int i = 1; i <= m; ++i) {
    int y = p[i];
    int s = qz[i - 1].a + hz[i + 1].a;
    if (!(SZ[y] & 1)) {
      if (s != 1) continue;
      if (!qz[i - 1].b || !hz[i + 1].b) continue;
      int o = qz[i - 1].c;
      if (!o) o = hz[i + 1].c;
      DP[y][0] = p0[o];
      DP[y][1] = p0[o] + p1[o];
    } else {
      if (s != 0 && s != 2) continue;
      if (s == 0) {
        int ss = qz[i - 1].e + hz[i + 1].e;
        if (!ss) DP[y][0] = 1;
        if (!ss) DP[y][1] = tot - p1[y];
        if (ss == 1) {
          int o = qz[i - 1].f;
          if (!o) o = hz[i + 1].f;
          DP[y][1] = p1[o];
        }
      }
      if (s == 2) {
        if (!qz[i - 1].b || !hz[i + 1].b) continue;
        int o1 = qz[i - 1].c;
        if (!o1) o1 = hz[i + 1].d;
        int o2 = qz[i - 1].d;
        if (!o2) o2 = hz[i + 1].c;
        bool b1 = p0[o1], b2 = p0[o2];
        if (b1) DP[y][1] = p1[o2] + b2;
        if (b2) DP[y][1] += p1[o1] + b1;
      }
    }
  }
  for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
    if (y != fa[x]) dfs2(y);
}
long long ans;
int main() {
  n = read();
  if (n & 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 2; i <= n; ++i) Addedge(read(), read());
  dfs1(1);
  for (int i = 1; i <= n; ++i) SZ[i] = n - sz[i];
  dfs2(1);
  for (int i = 2; i <= n; ++i) {
    if (sz[i] & 1)
      ans += (long long)(dp[i][1] + dp[i][0]) * (DP[i][1] + DP[i][0]);
    else if (dp[i][0] && DP[i][0])
      ans += (long long)sz[i] * SZ[i];
  }
  printf("%lld\n", ans);
}
