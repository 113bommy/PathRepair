#include <bits/stdc++.h>
int main() {
  int a, b, n, i, j, c, d;
  scanf("%d %d", &a, &b);
  n = a + b + 1;
  if (a == 0)
    for (i = n; i > 0; i--) printf("%d ", i);
  else if (b == 0)
    for (i = 1; i <= n; i++) printf("%d ", i);
  else {
    if (a >= b) {
      printf("1 ");
      j = b + 2;
      for (i = j; i <= n; i++) {
        printf("%d ", i);
      }
      for (i = j - 1; i >= 2; i--) {
        printf("%d ", i);
      }
    } else {
      printf("1 ");
      j = b + 2;
      for (i = j; i <= n; i++) {
        printf("%d ", i);
      }
      for (i = j - 1; i >= 2; i--) {
        printf("%d ", i);
      }
    }
  }
  return 0;
}
