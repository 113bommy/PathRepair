#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, v1, v2, k;
  cin >> n >> l >> v1 >> v2 >> k;
  double le = 0;
  double ri = 1000000000;
  cout << fixed << setprecision(12);
  for (int loop = 0; loop < 100; loop++) {
    double mid = (le + ri) / 2;
    double tg = 0;
    double xe = 0;
    bool tien = true;
    bool ok = true;
    int nn = n;
    while (nn > 0) {
      if (tien) {
        nn = max(0, nn - k);
        double d = l - v1 * tg;
        double tmp = l / v1 - tg;
        if (tmp <= mid - tg) break;
        tien = false;
        tmp = (tmp - mid + tg) * v1 * v2 / (v2 - v1);
        if (tmp > d) {
          ok = false;
          break;
        }
        xe = l - d + tmp;
        tg += tmp / v2;
      } else {
        tien = true;
        double d = v1 * tg;
        if (d >= xe) break;
        tg += (xe - d) / (v1 + v2);
      }
    }
    if (ok)
      ri = mid;
    else
      le = mid;
  }
  cout << ri;
  return 0;
}
