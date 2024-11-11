#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int r, h;
int main() {
  scanf("%d%d", &r, &h);
  double tt = r + sqrt(3) / 2.0 * r;
  double hh = h + r - tt;
  int ans = 1;
  if (hh > 0 - eps) ans = max(ans, (int)floor(hh + eps) / r * 2 + 3);
  if (h > r / 2.0 - eps) {
    ans = max(ans, (int)floor(h - r / 2.0 + eps) / r * 2 + 2);
  }
  printf("%d\n", ans);
  return 0;
}
