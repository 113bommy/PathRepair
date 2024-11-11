#include <bits/stdc++.h>
int s, x1, x2, t1, t2, p, d, ans;
double dis;
bool f;
int main() {
  scanf("%d%d%d%d%d%d%d", &s, &x1, &x2, &t2, &t1, &p, &d);
  ans = std::abs(x1 - x2) * t1;
  if (x1 < x2) {
    if (d == -1) ans = std::min(ans, (p + x2) * t2);
    if (d == 1 && p <= x1) ans = std::min(ans, (x2 - p) * t2);
    if (d == 1 && p >= x1) ans = std::min(ans, (2 * s + p - x2) * t2);
  } else {
    if (d == 1) ans = std::min(ans, (2 * s - x2 - p) * t2);
    if (d == -1 && p <= x1) ans = std::min(ans, (2 * s + p - x2) * t2);
    if (d == -1 && p >= x1) ans = std::min(ans, (p - x2) * t2);
  }
  printf("%d", ans);
  return 0;
}
