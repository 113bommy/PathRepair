#include <bits/stdc++.h>
int n, T, m, a[300055], x[300055], y[300055], t, l, p, k;
int vis[300055], tim;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (register int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
    bool flag = 0;
    for (register int j = (30); j >= (0); --j) {
      int c0 = 0, c1 = 0;
      for (register int i = (1); i <= (n); ++i)
        if (1 << j & a[i])
          ++c1;
        else
          ++c0;
      if ((c1 & 1) && (c0 & 1) || ((c1 & 3) == 1)) {
        printf("WIN\n");
        flag = 1;
      } else if ((c1 & 1) && !(c0 & 1)) {
        printf("LOSE\n");
        flag = 1;
      }
      if (flag) break;
    }
    if (!flag) printf("DRAW\n");
  }
  return 0;
}
