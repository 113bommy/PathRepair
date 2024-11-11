#include <bits/stdc++.h>
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    if (k > n * (n - 1) / 2) {
      printf("no solution\n");
    } else {
      for (int i = 0; i < n; i++) {
        printf("0 %d\n", i);
      }
    }
  }
  return 0;
}
