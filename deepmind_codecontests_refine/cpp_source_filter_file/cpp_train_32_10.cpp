#include <bits/stdc++.h>
int main() {
  int z, ans;
  float n, x, y, p1;
  scanf("%f %f %f", &n, &x, &y);
  p1 = (x / n) * 100;
  if (p1 < y) {
    ans = (y * n);
    if (ans % 100 == 0)
      z = ans / 100;
    else
      z = (ans / 100) + 1;
    if (z < 1) z = 1;
  } else
    z = 0;
  printf("%d", z);
  return 0;
}
