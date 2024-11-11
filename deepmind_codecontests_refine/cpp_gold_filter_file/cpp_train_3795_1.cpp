#include <bits/stdc++.h>
int main() {
  int n, i, j, k, l, m, x, y;
  scanf("%d", &n);
  x = n / 2, y = 1, m = 1;
  for (i = 1; i < n / 2 + 1; i++) {
    for (j = x; j > 0; j--) {
      printf("*");
    }
    {
      for (k = 1; k <= m; k++) {
        printf("D");
      }
    }
    for (l = x; l > 0; l--) {
      printf("*");
    }
    printf("\n");
    x--;
    y += 2, m += 2;
  }
  for (i = 1; i <= n; i++) {
    printf("D");
  }
  printf("\n");
  m = n - 2;
  for (i = 0; i < n / 2; i++) {
    for (j = 0; j <= i; j++) {
      printf("*");
    }
    for (k = m; k >= 1; k--) {
      printf("D");
    }
    for (l = 0; l <= i; l++) {
      printf("*");
    }
    printf("\n");
    m -= 2;
  }
  return 0;
}
