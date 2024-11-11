#include <bits/stdc++.h>
using namespace std;
int main() {
  double y1, y2, yw, xb, yb, r, xw;
  double i, j, m, n, k;
  while (cin >> y1 >> y2 >> yw >> xb >> yb >> r) {
    m = y1 + r;
    yb = 2 * (yw - yb) + yb;
    if ((y2 - y1) > 2 * r) {
      k = (yb - m) / xb;
      n = fabs(y2 - m) / sqrt(1 + k * k);
      if (n >= r)
        printf("%.10lf\n", (yw - m - r) / k);
      else
        printf("-1\n");
    } else
      printf("-1\n");
  }
}
