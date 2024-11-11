#include <bits/stdc++.h>
int main() {
  int i, j, k, t, n;
  scanf("%d", &n);
  if (n > 4) {
    printf("%d\n", n);
    if (n % 2 == 0) {
      for (i = 1; i <= n - 1;) {
        printf("%d ", i);
        i = i + 2;
      }
      for (i = 2; i <= n - 2;) {
        printf("%d ", i);
        i = i + 2;
      }
    } else {
      for (i = 1; i <= n;) {
        printf("%d ", i);
        i = i + 2;
      }
      for (i = 2; i <= n - 1;) {
        printf("%d ", i);
        i = i + 2;
      }
    }
  }
  if (n == 4) {
    printf("%d\n", 4);
    printf("3 1 4 2");
  }
  if (n == 3) {
    printf("%d\n", 2);
    printf("1 3");
  }
  if (n == 2) {
    printf("%d\n", 1);
    printf("1");
  }
  if (n == 1) {
    printf("%d\n", 1);
    printf("1");
  }
  return 0;
}
