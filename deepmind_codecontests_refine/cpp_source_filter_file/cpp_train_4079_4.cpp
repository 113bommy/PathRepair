#include <bits/stdc++.h>
using namespace std;
long q, n, t = 0, x, y, f1, f2, f3, f4;
int main() {
  cin >> q;
  while (q--) {
    cin >> n;
    long xmin = -1e5, ymin = -1e5, ymax = 1e5, xmax = 1e5;
    for (long i = 1; i <= n; i++) {
      cin >> x >> y >> f1 >> f2 >> f3 >> f4;
      if (f1 == 0) {
        xmin = max(xmin, x);
      }
      if (f2 == 0) {
        ymax = min(ymax, y);
      }
      if (f3 == 0) {
        xmax = min(xmax, x);
      }
      if (f4 == 0) {
        ymin = max(ymin, y);
      }
    }
    if ((xmin != xmax || ymin != ymax) && n != 1)
      cout << 0 << endl;
    else
      cout << 1 << " " << xmin << " " << ymin << endl;
  }
}
