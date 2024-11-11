#include <bits/stdc++.h>
int l, r, x, y;
int gcd(int p, int q) {
  int r;
  while (q != 0) {
    r = p % q;
    p = q;
    q = r;
  }
  return p;
}
void run() {
  int i, j, k, c;
  while (scanf("%d%d%d%d", &l, &r, &x, &y) != EOF) {
    if (y % x != 0) {
      printf("0\n");
      continue;
    }
    j = y / x;
    c = 0;
    for (i = 1; i < 100007 && i <= j; i++) {
      if (j % i == 0) {
        k = j / i;
        if (k < i) {
          break;
        }
        if (i * x >= l && i * x <= r && k * x >= l && k * x <= r) {
          if (gcd(i, k) == x) {
            c += i == k ? 1 : 2;
          }
        }
      }
    }
    printf("%d\n", c);
  }
}
int main() {
  run();
  return 0;
}
