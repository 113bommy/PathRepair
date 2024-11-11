#include <bits/stdc++.h>
using namespace std;
int T = 10;
int main() {
  double a, b, c, d;
  while (T--) {
    cin >> a >> b >> c >> d;
    double l = 0, r = 1e10, m = (l + r) * .5;
    for (int i = 0; i < 1000; ++i) {
      double a1 = a + m, a2 = a - m;
      double b1 = b + m, b2 = b - m;
      double c1 = c + m, c2 = c - m;
      double d1 = d + m, d2 = d - m;
      double p1 = min(min(a1 * d1, a1 * d2), min(a2 * d1, a2 * d2));
      double p2 = max(max(a1 * d1, a1 * d2), max(a2 * d1, a2 * d2));
      double q1 = min(min(b1 * c1, b1 * c2), min(b2 * c1, b2 * c2));
      double q2 = max(max(b1 * c1, b1 * c2), max(b2 * c1, b2 * c2));
      (p1 - q2 <= 0 && p2 - q1 >= 0) ? r = m : l = m;
      m = (l + r) * .5;
    }
    cout << fixed << setprecision(10) << m << endl;
  }
  return 0;
}
