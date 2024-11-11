#include <bits/stdc++.h>
double a[175][175], b[175][175], w[175][175];
int main() {
  int n;
  scanf("%d", &n);
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%lf", &w[i][j]);
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      double aa, bb;
      aa = (w[i][j] + w[j][i]) / 2;
      bb = (w[i][j] - w[j][i]) / 2;
      a[i][j] = a[j][i] = aa;
      b[i][j] = bb;
      b[j][i] = -bb;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      printf("%.10lf", a[i][j]);
      if (j == n)
        printf("\n");
      else
        printf(" ");
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      printf("%.10lf", b[i][j]);
      if (j == n)
        printf("\n");
      else
        printf(" ");
    }
  }
  return 0;
}
