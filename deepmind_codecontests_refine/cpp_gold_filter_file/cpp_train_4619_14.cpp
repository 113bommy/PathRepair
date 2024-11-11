#include <bits/stdc++.h>
int main() {
  int n, x, i, a, b, c;
  scanf("%d", &n);
  x = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    if (a == 1 && b == 1) {
      x = x + 1;
    } else if (b == 1 && c == 1) {
      x = x + 1;
    } else if (c == 1 && a == 1) {
      x = x + 1;
    } else if (a == 1 && b == 1 && c == 1) {
      x = x + 1;
    } else {
      x = x;
    }
  }
  printf("%d", x);
  return 0;
}
