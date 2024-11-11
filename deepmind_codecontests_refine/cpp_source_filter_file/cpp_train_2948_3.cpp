#include <bits/stdc++.h>
using namespace std;
const int oo = 10000001;
const int N = 100005;
int n, L, R, ss, be, bi, maxd, nowd, ans, lim, rr, ansx, ansy;
int h[N], u[N], s[N], q[N], ne[N * 2], po[N * 2], w[N * 2];
pair<int, int> f[N], g[N];
void getss(int i, int fa) {
  ++ss;
  for (int j = h[i], k; k = po[j], j; j = ne[j])
    if (k != fa && !u[k]) getss(k, i);
}
void getbe(int i, int fa) {
  int t = 0;
  s[i] = 1;
  for (int j = h[i], k; k = po[j], j; j = ne[j])
    if (k != fa && !u[k]) getbe(k, i), s[i] += s[k], t = max(t, s[k]);
  t = max(t, ss - s[i]);
  if (t < be) be = t, bi = i;
}
void dfs(int i, int fa, int d, int s) {
  if (d <= R) {
    if (d > nowd) nowd = d;
    if (s > g[d].first) g[d] = make_pair(s, i);
  }
  for (int j = h[i], k; k = po[j], j; j = ne[j])
    if (k != fa && !u[k]) dfs(k, i, d + 1, s + ((w[j]) >= lim ? 1 : -1));
}
bool check() {
  maxd = 0;
  f[0] = g[0] = make_pair(0, bi);
  for (int j = h[bi], k; k = po[j], j; j = ne[j])
    if (!u[k]) {
      while (nowd) {
        if (g[nowd] > f[nowd]) f[nowd] = g[nowd];
        g[nowd--].first = -oo;
      }
      dfs(k, bi, 1, ((w[j]) >= lim ? 1 : -1));
      int st = 1, ed = 0, x = 0;
      for (int i = nowd; i; --i) {
        while (i + x <= R && x <= maxd) {
          while (st <= ed && f[x] > f[q[ed]]) --ed;
          q[++ed] = x++;
        }
        while (st <= ed && q[st] + i < L) ++st;
        if (st <= ed)
          if (f[q[st]].first + g[i].first >= 0) {
            if (lim > ans)
              ans = lim, ansx = f[q[st]].second, ansy = g[i].second;
            return 1;
          }
      }
      if (nowd > maxd) {
        for (int i = maxd + 1; i <= nowd; ++i) f[i].first = -oo;
        maxd = nowd;
      }
    }
  return 0;
}
void work(int i) {
  ss = 0;
  getss(i, 0);
  be = n + 1;
  bi = 0;
  getbe(i, 0);
  int l = 0, r = rr;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    lim = m;
    if (check())
      l = m;
    else
      r = m - 1;
  }
  lim = l;
  check();
  u[bi] = 1;
  for (int j = h[bi], k; k = po[j], j; j = ne[j])
    if (!u[k]) work(k);
}
int main() {
  scanf("%d%d%d", &n, &L, &R);
  int e = 0;
  for (int i = 1; i < n; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    ++e;
    ne[e] = h[x];
    po[e] = y;
    w[e] = z;
    h[x] = e;
    ++e;
    ne[e] = h[y];
    po[e] = x;
    w[e] = z;
    h[y] = e;
    rr = max(rr, z);
  }
  for (int i = 0; i <= n; ++i) f[i].first = g[i].first = -oo;
  ans = 0;
  work(1);
  printf("%d %d\n", ansx, ansy);
  return 0;
}
