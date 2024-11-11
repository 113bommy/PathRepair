#include <bits/stdc++.h>
const double eps = 1e-8;
using namespace std;
int main() {
  int n;
  double h;
  cin >> n >> h;
  double target = (1.0 * h) / (2.0 * double(n));
  double top = 0, area;
  for (int i = 0; i < n - 1; i++) {
    double lo = top + eps, hi = 1, m, found;
    while (hi - lo >= eps) {
      m = (hi + lo) / 2;
      area = ((m + top) / 2) * (m - top) * h;
      if (abs(target - area) < 1 - 7) {
        found = m;
        break;
      }
      if (area > target) {
        hi = m - eps;
      } else {
        found = m;
        lo = m + eps;
      }
    }
    top = found;
    cout << fixed << setprecision(12) << found * h << ' ';
  }
  cout << endl;
  return 0;
}
