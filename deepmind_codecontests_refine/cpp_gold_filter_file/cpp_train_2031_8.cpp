#include <bits/stdc++.h>
using namespace std;
long long f[15][20000];
int bo[15][20000], n, m, q, s1[1000][2], s2[1000][3], lo[20], a[20][20];
long long dp(int u, int mask) {
  if (!mask) return 1;
  if (bo[u][mask]) return f[u][mask];
  int p;
  for (int i = 1; i <= n; i++)
    if ((lo[i] | mask) == mask) {
      p = i;
      if (a[u][i]) break;
    }
  for (int newmask = mask; newmask; newmask = (newmask - 1) & mask)
    if ((newmask | lo[p]) == newmask) {
      int boo = 1;
      for (int i = 1; i <= q; i++) {
        if (s2[i][2] == u &&
            (lo[s2[i][0]] | lo[s2[i][1]] | newmask) == newmask) {
          boo = 0;
          break;
        }
        if ((lo[s2[i][2]] | newmask) == newmask &&
            (lo[s2[i][0]] | lo[s2[i][1]] | newmask) != newmask) {
          boo = 0;
          break;
        }
      }
      if (!boo) continue;
      for (int i = 1; i <= m; i++)
        if (s1[i][0] != u && s1[i][1] != u &&
            (((lo[s1[i][0]] | newmask) == newmask) +
                 ((lo[s1[i][1]] | newmask) == newmask) ==
             1)) {
          boo = 0;
          break;
        }
      if (!boo)
        continue;
      else
        boo = 0;
      for (int i = 1; i <= n; i++)
        if ((lo[i] | newmask) == newmask) boo += a[u][i];
      if (boo > 1) continue;
      if (boo == 1)
        f[u][mask] += dp(u, mask - newmask) * dp(p, newmask - lo[p]);
      else {
        for (int v = 1; v <= n; v++)
          if ((lo[v] | newmask) == newmask)
            f[u][mask] += dp(u, mask - newmask) * dp(v, newmask - lo[v]);
      }
    }
  bo[u][mask] = 1;
  return f[u][mask];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &s1[i][0], &s1[i][1]),
        a[s1[i][0]][s1[i][1]] = a[s1[i][1]][s1[i][0]] = 1;
  for (int i = 1; i <= q; i++) scanf("%d%d%d", &s2[i][0], &s2[i][1], &s2[i][2]);
  lo[1] = 1;
  int s = 0;
  for (int i = 2; i <= n; i++) lo[i] = lo[i - 1] << 1, s |= lo[i];
  printf("%lld", dp(1, s));
}
