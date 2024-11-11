#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, p, i, j, k, d, e, tt = 0;
  double n, x, y, a, b, c, l, r, m, xx, dd;
  scanf("%lld", &t);
  bool vis;
  for (p = 1; p <= t; p++) {
    cin >> dd;
    d = dd;
    e = d / 2;
    vis = false;
    tt = 0;
    if (d == 0) {
      printf("Y 0.000000000 0.000000000\n");
      continue;
    }
    for (i = 0; i <= e; i++) {
      x = (double)i;
      y = (double)(dd - i);
      if ((x * y) >= ((x + y) - 0.0000005) &&
          (x * y) <= ((x + y) + 0.0000005)) {
        printf("Y %.13f %.13f\n", x, y);
        tt = 1;
        break;
      }
      l = 0.0;
      r = y;
      vis = false;
      while (l <= r) {
        m = (l + r) / 2.0;
        xx = (x + (y - m));
        if ((xx * m) > ((xx + m) + 0.0000005)) {
          l = m + 0.0000000001;
        } else if ((xx * m) < ((xx + m) - 0.0000005)) {
          r = m - 0.0000000001;
        } else {
          vis = true;
          tt = 1;
          break;
        }
      }
      if (vis == true) {
        printf("Y %.13f %.13f\n", xx, m);
        tt = 1;
        break;
      }
      l = 0.0;
      r = x;
      while (l <= r) {
        m = (l + r) / 2;
        xx = (y + (x - m));
        if ((xx * m) > ((xx + m) + 0.0000005)) {
          l = m + 0.0000000001;
        } else if ((xx * m) < ((xx + m) - 0.0000005)) {
          r = m - 0.0000000001;
        } else {
          vis = true;
          tt = 1;
          break;
        }
      }
      if (vis == true) {
        printf("Y %.13f %.13f\n", xx, m);
        tt = 1;
        break;
      }
    }
    if (tt == 0) {
      printf("N\n");
    }
  }
}
