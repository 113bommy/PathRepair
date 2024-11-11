#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int t1, t2, x1, x2, t0;
double best = 1e20;
int yp = (1 << 30);
int f, s;
int main() {
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  if (t0 == t2) {
    if (t1 == t0)
      cout << x1 << " " << x2 << endl;
    else
      cout << 0 << " " << x2 << endl;
    return 0;
  }
  for (int i = 0; i <= x1; i++) {
    int tv = ceil(double(i) * double(t1 - t0) / (t0 - t2));
    if (i == 0) tv = x2;
    if (tv <= x2) {
      double t = (double(i) * t1 + double(tv) * t2) / (i + tv);
      if (t + eps < t0) continue;
      if ((abs(t - best) <= eps && i + tv > yp) ||
          abs(t0 - t) < abs(t0 - best)) {
        best = t;
        yp = i + tv;
        f = i;
        s = tv;
      }
    }
  }
  cout << f << " " << s << endl;
  return 0;
}
