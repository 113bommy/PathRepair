#include <bits/stdc++.h>
using namespace std;
int x1, yy, x2, y2, n;
int x, y, z;
const double eps = 1e-8;
int check(double k) {
  if (abs(k) < eps) return 1;
  return 0;
}
int main() {
  cin >> x1 >> yy;
  cin >> x2 >> y2;
  cin >> n;
  long long a = yy - y2;
  long long b = x2 - x1;
  long long c = (long long)x2 * (y2 - yy) - (long long)y2 * (x2 - x1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> z;
    if (check(a * y - b * x)) continue;
    double x0 = (b * z - c * y) * 1.0 / (b * x - a * y);
    double y0 = (a * z - c * x) * 1.0 / (a * y - b * x);
    if (x0 > min(x1, x2) && x0 < max(x2, x1))
      if (y0 < max(yy, y2) && y0 > min(yy, y2)) {
        ans++;
      }
  }
  cout << ans;
  return 0;
}
