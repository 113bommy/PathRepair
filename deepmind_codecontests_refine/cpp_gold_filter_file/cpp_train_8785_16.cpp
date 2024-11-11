#include <bits/stdc++.h>
int main() {
  int n, a, b, i, r;
  scanf("%d", &n);
  for (i = 0; i <= ((n * n) / 2) - 1; i++) {
    printf("%d %d\n", (n * n - i), i + 1);
  }
  return 0;
}
