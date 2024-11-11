#include <bits/stdc++.h>
using namespace std;
int main() {
  int t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  if ((t1 == t0) && (t2 == t0)) {
    cout << x1 << " " << x2;
    return 0;
  }
  if (t1 == t0) {
    cout << x1 << " " << 0;
    return 0;
  }
  if (t2 == t0) {
    cout << 0 << " " << x2;
    return 0;
  } else {
    int y2 = 0, y1 = 0, tmp;
    double delta = t2;
    if (t2 - t0 >= t0 - t1) {
      long long newx1 = 1LL * x2 * (t2 - t0) / (t0 - t1);
      if (newx1 > x1) newx1 = x1;
      for (int i = newx1; i >= 0; i--) {
        tmp = 1LL * i * (t0 - t1) / (t2 - t0);
        if ((1LL * (t0 - t1) * i) % (t2 - t0) != 0) tmp++;
        double temp = (1. * t1 * i + 1. * t2 * tmp) / (1. * i + tmp) - t0;
        if (delta == temp) {
          if (y1 + y2 < i + tmp) {
            y1 = i;
            y2 = tmp;
          }
        }
        if (delta > temp) {
          y1 = i;
          y2 = tmp;
          delta = temp;
        }
      }
    } else {
      long long newx2 = 1LL * x1 * (t0 - t1) / (t2 - t0);
      if (newx2 > x2) newx2 = x2;
      for (int i = newx2; i >= 0; i--) {
        tmp = 1LL * i * (t2 - t0) / (t0 - t1);
        double temp = (1. * t1 * tmp + 1. * t2 * i) / (1. * i + tmp) - t0;
        if (delta == temp) {
          if (y1 + y2 < i + tmp) {
            y1 = tmp;
            y2 = i;
          }
        }
        if (delta > temp) {
          y1 = tmp;
          y2 = i;
          delta = temp;
        }
      }
    }
    cout << y1 << " " << y2;
  }
}
