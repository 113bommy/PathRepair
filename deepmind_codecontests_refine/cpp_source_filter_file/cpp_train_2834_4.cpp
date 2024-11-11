#include <bits/stdc++.h>
int a[1123][1123];
int main() {
  int i, o, p, j, k, l, n, m;
  int x, y;
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    for (x = i + 1, y = 1; x >= 1; --x, ++y)
      if (x != y)
        a[x][y] = i;
      else {
        a[n][y] = i;
        a[x][n] = i;
      }
    for (x = n - 1, y = i + 2; y <= n; --x, ++y)
      if (x != y)
        a[x][y] = i;
      else {
        a[n][y] = i;
        a[x][n] = i;
      }
  }
  if (n > 2) {
    p = a[1][n - 2];
    a[n][n - 1] = p;
    a[n - 1][n] = p;
  }
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) printf("%d ", a[i][j]);
    printf("\n");
  }
  return 0;
}
