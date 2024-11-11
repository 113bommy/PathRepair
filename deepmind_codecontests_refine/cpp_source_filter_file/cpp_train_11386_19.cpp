#include <bits/stdc++.h>
using namespace std;
namespace Main {
const double EPS = 1e-10;
double y1, y2, yw, xb, yb, r;
void solve() {
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  double low = r, high = xb;
  bool flag = false;
  for (int iter_times = 200; iter_times--;) {
    double mid = (low + high) / 2.0;
    double h = mid / (xb - mid) * (yw - r - yb);
    double alpha = atan(mid / h);
    double delta = r / sin(alpha);
    if (yw - r - h + delta + EPS > y2) {
      low = mid;
    } else {
      high = mid;
      if (yw - r - h - r - EPS > y1) {
        flag = true;
      }
    }
  }
  if (flag) {
    cout << fixed << setprecision(8) << low << endl;
  } else {
    cout << -1 << endl;
  }
}
}  // namespace Main
int main() { Main::solve(); }
