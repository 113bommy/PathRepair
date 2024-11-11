#include <bits/stdc++.h>
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    if (i % 2 != 0 && i < n) {
      printf("I hate that ");
    }
    if (i == n && n % 2 == 0) {
      printf("I love it ");
    }
    if (i % 2 == 0 && i < n) {
      printf("I love that ");
    }
    if (i == n && n % 2 != 0) {
      printf("I hate it ");
    }
  }
  return 0;
}
