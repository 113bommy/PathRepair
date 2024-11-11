#include <bits/stdc++.h>
int main() {
  int r, h;
  scanf("%d %d", &r, &h);
  double x = h - 0.8660254037844386 * r;
  int ans = 3;
  if (x < 0) ans -= 2;
  while (x >= 0) {
    x -= r;
    if (x > 0) ans += 2;
  }
  if (x + r > 0.8660254037844386 * r) ans++;
  int ans2;
  x = h - 0.5 * r;
  ans2 = 2;
  if (x < 0) ans2 -= 2;
  while (x >= 0) {
    x -= r;
    if (x > 0) ans2 += 2;
  }
  if (x + r > 0.8660254037844386 * r) ans2++;
  printf("%d\n", (((ans) > (ans2)) ? (ans) : (ans2)));
}
