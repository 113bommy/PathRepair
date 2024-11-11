#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, u, v, w, x, y, z, a, b, c, d, e, f, t = 1, tc;
  long long flg, sz, cnt, gt, ans, mx, mn;
  long long m, k, n, i, j;
  long long low, hi, md, inp[200007], sm, ff, lev[70][3], rt, tot;
  memset(lev, 0, sizeof lev);
  scanf("%lld%lld", &n, &m);
  rt = (n + 1) / 2;
  long long nw = rt, lv = 0, lst = rt, df;
  tot = 0;
  while (nw != 1) {
    nw /= 2;
    lv++;
    df = lst - nw;
    lev[lv - 1][2] = df;
    lev[lv][1] = df;
    lst = nw;
    tot++;
  }
  int path[70];
  char st[200007];
  memset(path, 0, sizeof path);
  while (m--) {
    scanf("%lld", &x);
    getchar();
    scanf("%s", st);
    sz = strlen(st);
    nw = rt;
    lv = 0;
    while (nw != x) {
      if (nw > x)
        nw -= lev[lv][2], path[lv + 1] = 1;
      else
        nw += lev[lv][2], path[lv + 1] = -1;
      lv++;
    }
    nw = x;
    for (i = 0; i < sz; i++) {
      if (st[i] == 'U' && lv != 0) {
        nw = nw + lev[lv][1] * path[lv];
        lv--;
      } else if (st[i] == 'L' && lv < tot) {
        nw = nw - lev[lv][2];
        path[lv + 1] = 1;
        lv++;
      } else if (st[i] == 'R' && lv < tot) {
        nw = nw + lev[lv][2];
        path[lv + 1] = -1;
        lv++;
      }
    }
    for (i = 0; i <= tot; i++) path[i] = 0;
    printf("%lld\n", nw);
  }
  return 0;
}
