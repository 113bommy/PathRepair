#include <bits/stdc++.h>
const int P = 1000000007;
int main() {
  int n;
  int a, b, c, d, k, x, y;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    x = a / c;
    if (a % c != 0) {
      x += 1;
    }
    y = b / d;
    if (b % d != 0) {
      y += 1;
    }
    if (x + y <= k) {
      printf("%d %d \n", x, y);
    } else {
      printf("%d \n", -1);
    }
  }
  return 0;
}
