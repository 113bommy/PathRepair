#include <bits/stdc++.h>
int n, w, m, ans;
int main() {
  int i, j, k;
  scanf("%d%d%d", &n, &w, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; (j + 1) * n <= i * m; j++)
      ;
    for (k = j; (k + 1) * n < (i + 1) * m; k++)
      ;
    if (k - j >= 2) {
      ans = -1;
      break;
    }
  }
  if (ans == -1)
    printf("NO");
  else {
    printf("YES\n");
    for (i = 0; i < n; i++) {
      for (j = 0; (j + 1) * n <= i * m; j++)
        ;
      for (k = j; (k + 1) * n < (i + 1) * m; k++)
        ;
      if (k == j) {
        printf("%d %lf ", i + 1, (double)w);
        if ((j + 1) * n == (i + 1) * m) printf("\n");
      } else {
        printf("%d %lf\n%d %lf ", i + 1,
               ((double)k * n * w / m - (double)i * w), i + 1,
               ((i + 1) * w - (double)k * n * w / m));
        if ((k + 1) * n == (i + 1) * m) printf("\n");
      }
    }
  }
  return 0;
}
