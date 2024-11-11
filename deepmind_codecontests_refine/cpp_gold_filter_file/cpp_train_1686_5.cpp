#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int u = 1; u <= n; u++) {
      if (u <= n / 2) {
        printf("%d ", n * (u - 1) + i);
      } else {
        printf("%d ", n * (u - 1) + n - i + 1);
      }
    }
    printf("\n");
  }
  return 0;
}
