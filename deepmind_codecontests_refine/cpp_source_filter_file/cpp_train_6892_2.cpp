#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  if (t1 == t2) {
    cout << x1 << ' ' << x2;
    return 0;
  }
  if (t0 == t1) {
    cout << x1 << " 0";
    return 0;
  }
  if (t0 == t2) {
    cout << "0 " << x2;
    return 0;
  }
  long double mn = 1e20l;
  long long by1 = 0, by2 = 0;
  for (long long y2 = x2; y2 >= 1; y2--) {
    long long y1 = (t2 - t0) * y2 / (t0 - t1);
    if (y1 <= x1 && y1 >= 0) {
      long double now = (long double)(t1 * y1 + t2 * y2) / (y1 + y2) - t0;
      if (now < mn - 1e-13) {
        mn = now;
        by1 = y1, by2 = y2;
      }
    }
  }
  cout << by1 << ' ' << by2;
}
