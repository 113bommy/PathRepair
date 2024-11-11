#include <bits/stdc++.h>
int n, i, j, a[2000][2000], p = 0;
int main() {
  scanf("%d", &n);
  if (n * n % 2 == 0)
    printf("%d\n", n * n / 2);
  else
    printf("%d\n", n * n / 2 + 1);
  for (i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      for (j = 1; j <= n; j++)
        if (j % 2 == 0)
          printf(".");
        else {
          printf("C");
        }
      printf("\n");
    } else {
      for (j = 1; j <= n; j++)
        if (j % 2 == 1)
          printf(".");
        else {
          printf("C");
        }
      printf("\n");
    }
  }
  return 0;
}
