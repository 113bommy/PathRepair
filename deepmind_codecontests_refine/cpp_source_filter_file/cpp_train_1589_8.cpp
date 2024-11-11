#include <bits/stdc++.h>
int main() {
  int x, y, n;
  int k, i, t;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d %d", &x, &y, &n);
    if (n - n % x + y <= n) {
      k = n - n % x + y;
    } else {
      k = n - n % x - (x - y);
    }
    printf("%d", k);
  }
  return 0;
}
