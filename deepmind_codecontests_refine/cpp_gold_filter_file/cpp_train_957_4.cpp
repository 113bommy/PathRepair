#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  long long dt1 = t0 - t1;
  long long dt2 = t0 - t2;
  long long besty1 = 0, besty2 = 0;
  if (t0 == t2) {
    if (t1 == t0) {
      cout << x1 << " " << x2;
      return 0;
    }
    cout << 0 << " " << x2;
    return 0;
  }
  for (long long y1 = 0; y1 <= x1; y1++) {
    long long yy2 = min(x2, -y1 * dt1 / dt2);
    for (long long y2 = yy2 - 10; y2 <= yy2 + 10; y2++) {
      if (y2 < 0 || y2 > x2) {
        continue;
      }
      long long left = (t1 * y1 + t2 * y2) * (besty1 + besty2);
      long long right = (t1 * besty1 + t2 * besty2) * (y1 + y2);
      if (left <= right && (t1 * y1 + t2 * y2) >= t0 * (y1 + y2)) {
        besty1 = y1;
        besty2 = y2;
      }
    }
  }
  cout << besty1 << " " << besty2;
}
