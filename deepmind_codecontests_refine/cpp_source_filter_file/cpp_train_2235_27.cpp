#include <bits/stdc++.h>
int a, b, ans = 0, max = 0;
int main() {
  scanf("%d %d", &a, &b);
  int x = a;
  while (x != 0) {
    if (max < x % 10) max = x % 10;
    x /= 10;
  }
  int y = b;
  while (y != 0) {
    if (max < y % 10) max = y % 10;
    y /= 10;
  }
  int n = 0;
  while (a != 0 || b != 0) {
    n += (a % 10 + b % 10) / (max + 1);
    a /= 10;
    b /= 10;
    ans++;
  }
  if (n != 0) ans++;
  printf("%d\n", ans);
  return 0;
}
