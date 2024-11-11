#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long int mod = 1e9 + 7;
const int N = 100005;
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  double x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double a, b, c, x, y, z;
  a = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
  b = sqrt(((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2)));
  c = sqrt(((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3)));
  x = acos((b * b + c * c - a * a) / (2 * c * b));
  y = acos((a * a + c * c - b * b) / (2 * a * c));
  z = acos((b * b + a * a - c * c) / (2 * a * b));
  double ans = LLONG_MAX;
  for (long long int i = 3; i <= 100; i++) {
    float a1, b1, c1;
    double n;
    n = 3.14159265358979323846 / i;
    a1 = x / n;
    b1 = y / n;
    c1 = z / n;
    if (abs(round(a1) - a1) <= 0.00001 && abs(round(b1) - b1) <= 0.00001 &&
        abs(round(c1) - c1) <= 0.00001) {
      double R, L, S;
      R = a / (2 * sin(x));
      L = 2 * R * sin(3.14159265358979323846 / i);
      S = L * L * i / (4 * tan(3.14159265358979323846 / i));
      ans = min(ans, S);
    }
  }
  cout << fixed << setprecision(6);
  return cout << ans, 0;
}
