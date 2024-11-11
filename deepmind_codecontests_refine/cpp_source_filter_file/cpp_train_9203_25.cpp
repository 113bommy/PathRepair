#include <bits/stdc++.h>
int main() {
  int i, j, m, n, t, p, q;
  int num[5][5];
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= 4; i++) {
      for (j = 1; j <= 4; j++) {
        scanf("%d", &num[i][j]);
      }
    }
    int mi, ma;
    p = 111111, q = 11111;
    for (i = 1; i <= 4; i++) {
      int x = 1111111, y = 1111111;
      x = num[i][1] < x ? num[i][1] : x;
      mi = num[i][2] < x ? num[i][2] : x;
      y = num[i][3] < y ? num[i][3] : y;
      ma = num[i][4] < y ? num[i][4] : y;
      if (ma + mi <= n) {
        p = ma;
        q = mi;
        t = i;
      }
    }
    if (p + q <= n) {
      printf("%d", t);
      printf(" %d %d\n", p, n - p);
    } else
      printf("-1\n");
  }
  return 0;
}
