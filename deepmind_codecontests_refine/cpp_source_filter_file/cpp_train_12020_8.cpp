#include <bits/stdc++.h>
int main() {
  int n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  int i, j;
  int min = 1000000000;
  for (i = 1; i <= n / m; i++) {
    for (j = 1; j <= n; j++) {
      if (i * m + j == n && i * b + j * a < min) {
        min = i * b + j * a;
      }
    }
  }
  printf("%d", min);
  return 0;
}
