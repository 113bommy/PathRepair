#include <bits/stdc++.h>
int main() {
  int k, i, j, n, m, x, t, s;
  while (~scanf("%d", &n)) {
    x = (1 + n) / 2;
    if (n == 5) {
      printf("1 2 3\n2 3 1\n1 4 1\n4 5 1\n3 4\n3 5\n");
      continue;
    }
    for (i = 1; i < n / 2; i++) {
      printf("%d %d 1\n", i, i + x);
      printf("%d %d %d\n", i + x, i + x + 1, i * 2 - 1);
    }
    if (n & 1) printf("%d %d 1\n", n / 2, n, 1);
    printf("%d %d %d\n", (n + 1) / 2, n, i * 2 - 1);
    for (i = 1; i < n / 2; i++) printf("%d %d\n", i, i + 1);
    printf("1 3\n");
  }
  return 0;
}
