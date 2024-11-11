#include <bits/stdc++.h>
int a, b;
int main() {
  scanf("%d%d", &a, &b);
  int max = 0;
  int n = a;
  while (n > 0) {
    if (n % 10 > max) max = n % 10;
    n /= 10;
  }
  n = b;
  while (n > 0) {
    if (n % 10 > max) max = n % 10;
    n /= 10;
  }
  int base = max + 1;
  int ans = 0;
  int x, y, k = 0;
  while (a > 0 || b > 0) {
    x = a % 10;
    y = b % 10;
    ans++;
    k = (x + y + k) / base;
    a /= 10;
    b /= 10;
  }
  if (k > 0) ans++;
  printf("%d", ans);
  return 0;
}
