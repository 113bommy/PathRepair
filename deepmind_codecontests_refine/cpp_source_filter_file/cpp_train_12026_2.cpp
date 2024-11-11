#include <bits/stdc++.h>
using namespace std;
long long n, m, dis[105], vis[105], mx[105], mn[105], flag = 1;
long long tot, head[105], nx[30005], to[30005], gc[30005], lc[30005];
void jia(long long aa, long long bb, long long cc, long long dd) {
  tot++;
  nx[tot] = head[aa];
  to[tot] = bb;
  gc[tot] = cc;
  lc[tot] = dd;
  head[aa] = tot;
  return;
}
long long gcd(long long aa, long long bb) {
  if (aa < bb) swap(aa, bb);
  while (bb) {
    long long tt = bb % aa;
    aa = bb;
    bb = tt;
  }
  return aa;
}
long long lcm(long long aa, long long bb) { return aa * bb / gcd(aa, bb); }
void dfs(long long rt, long long zhi) {
  dis[rt] = zhi;
  vis[rt] = 1;
  for (long long i = head[rt]; i; i = nx[i]) {
    long long yy = to[i];
    if ((gc[i] * lc[i]) % zhi != 0) {
      flag = 1;
      return;
    }
    long long kk = (gc[i] * lc[i]) / zhi;
    if ((dis[yy] && dis[yy] != kk) || kk < mn[yy] || kk > mx[yy] ||
        gcd(kk, zhi) != lc[i]) {
      flag = 1;
      return;
    } else if (!dis[yy]) {
      dfs(yy, kk);
      if (flag) {
        return;
      }
    }
  }
  return;
}
int main() {
  memset(mx, 0x3f3f3f, sizeof(mx));
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= m; ++i) {
    long long x, y, g, l;
    scanf("%lld%lld%lld%lld", &x, &y, &g, &l);
    if (l % g != 0) {
      puts("NO");
      return 0;
    }
    jia(x, y, g, l);
    jia(y, x, g, l);
    mx[x] = min(l, mx[x]);
    mx[y] = min(l, mx[y]);
    mn[x] = max(g, mn[x]);
    mn[y] = max(g, mn[y]);
  }
  int rr = 0;
  for (int ii = 1; ii <= n; ++ii)
    if (!dis[ii]) {
      long long zhi = 0;
      for (long long i = head[ii]; i; i = nx[i]) {
        if (!zhi)
          zhi = gc[i];
        else
          zhi = lcm(zhi, gc[i]);
      }
      long long oo = 1;
      while (zhi * oo <= mx[ii]) {
        for (int l = 1; l <= n; ++l)
          if (vis[l]) dis[l] = 0;
        memset(vis, 0, sizeof(vis));
        flag = 0;
        dfs(ii, zhi * oo);
        if (flag == 0) break;
        oo++;
      }
      memset(vis, 0, sizeof(vis));
      if (flag) {
        rr = 1;
        break;
      }
    }
  if (!rr) {
    puts("YES");
    for (long long i = 1; i <= n; ++i)
      if (dis[i])
        printf("%lld ", dis[i]);
      else
        printf("1 ");
  } else
    puts("NO");
  return 0;
}
