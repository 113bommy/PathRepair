#include <bits/stdc++.h>
int i, j, k, m, n;
int main() {
  while (scanf("%d %d", &n, &k) == 2) {
    if (k > n * n / 2) {
      printf("no solution\n");
      continue;
    }
    for (i = 1; i <= n; i++) printf("0 %d\n", i);
  }
  return 0;
}
