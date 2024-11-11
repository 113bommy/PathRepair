#include <bits/stdc++.h>
int main() {
  int n, i, x;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x % 2 == 0) {
      printf("%d\n", x / 2);
    } else {
      printf("%d\n", x / 2 + 1);
    }
  }
  return 0;
}
