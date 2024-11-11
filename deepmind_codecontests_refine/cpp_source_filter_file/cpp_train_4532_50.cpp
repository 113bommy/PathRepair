#include <bits/stdc++.h>
int main() {
  int r, c, n, k, i, x1, y1, x2, y2, x, y, total = 0, ans = 0, temp1, temp2;
  int mark[233][233] = {0};
  scanf("%d %d %d %d", &r, &c, &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &temp1, &temp2);
    mark[temp1][temp2] = 1;
  }
  for (x1 = 1; x1 <= r; x1++) {
    for (y1 = 1; y1 <= c; y1++) {
      for (x2 = x1; x2 <= r; x2++) {
        for (y2 = y1; y2 <= r; y2++) {
          total = 0;
          for (x = x1; x <= x2; x++) {
            for (y = y1; y <= y2; y++) {
              total += mark[x][y];
            }
          }
          if (total >= k) ans++;
        }
      }
    }
  }
  printf("%d\n", ans);
}
