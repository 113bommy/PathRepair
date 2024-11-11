#include <bits/stdc++.h>
int main() {
  int n, b, p, k, m, bot = 0, tow;
  scanf("%d%d%d", &n, &b, &p);
  tow = n * p;
  m = n;
  while (m > 1) {
    k = 1;
    while (k << 1 <= m) k <<= 1;
    bot += k * b + k >> 1;
    m -= k >> 1;
  }
  printf("%d %d\n", bot, tow);
  return 0;
}
