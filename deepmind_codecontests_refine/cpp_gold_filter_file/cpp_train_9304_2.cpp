#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  double w, h, a;
  cin >> w >> h >> a;
  if (a > 90.0) a = 180.0 - a;
  cout.setf(ios::fixed);
  cout.precision(10);
  if (a < eps) {
    cout << w * h;
    return 0;
  }
  a /= 180.0;
  a *= pi;
  double f = (1 + cos(a)) / sin(a);
  double x = (h * f - w) / (f * f - 1);
  double y = h - x * f;
  if (x >= 0 && y >= 0 && y <= h + eps && x <= w + eps) {
    double ans = w * h;
    ans -= x * x / tan(a);
    ans -= y * y / tan(a);
    cout << ans;
  } else {
    if (w < h) swap(w, h);
    cout << h * h / sin(a);
  }
  return 0;
}
