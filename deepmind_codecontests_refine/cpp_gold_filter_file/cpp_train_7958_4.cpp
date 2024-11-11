#include <bits/stdc++.h>
int main() {
  int n, i;
  while (~scanf("%d", &n)) {
    if (n < 4)
      printf("NO\n");
    else if (n == 4) {
      printf("YES\n");
      printf("1 * 2 = 2\n3 * 4 = 12\n2 * 12 = 24\n");
    } else if (n & 1) {
      printf("YES\n");
      printf("5 - 1 = 4\n4 - 2 = 2\n3 * 4 = 12\n2 * 12 = 24\n");
      for (i = 6; i <= n; i += 2) {
        printf("%d - %d = 1\n", i + 1, i);
        printf("24 * 1 = 24\n");
      }
    } else {
      printf("YES\n");
      printf("1 * 2 = 2\n3 * 4 = 12\n2 * 12 = 24\n");
      for (i = 5; i <= n; i += 2) {
        printf("%d - %d = 1\n", i + 1, i);
        printf("24 * 1 = 24\n");
      }
    }
  }
}
