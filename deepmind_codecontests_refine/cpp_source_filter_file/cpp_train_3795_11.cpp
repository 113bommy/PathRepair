#include <bits/stdc++.h>
int main() {
  int i, j, n;
  scanf("%d", &n);
  for (i = (n % 2); i >= 0; i--) {
    for (j = 1; j <= n; j++) {
      if (j > i && j < n - i + 1) {
        printf("D");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
  for (i = 1; i <= (n % 2); i++) {
    for (j = 1; j <= n; j++) {
      if (j > i && j < n - i + 1) {
        printf("D");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
  return 0;
}
