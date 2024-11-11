#include <bits/stdc++.h>
using namespace std;
double w, h, a;
int main() {
  cin >> w >> h >> a;
  if (a > 90.0) a = 180.0 - a;
  if (h > w) swap(h, w);
  a *= 3.14159265358979323846264338327950288 / 180.0;
  double b = 2.0 * atan2(h, w);
  if (a < b) {
    double x = 1.0 + cos(a), y = sin(a);
    double t1 = (w - (y * ((h - w) / (x - y)))) / (x + y);
    double t2 = t1 + ((h - w) / (x - y));
    double ans = w * h - (((t1 * t1) + (t2 * t2)) * (x - 1.0) * y);
    cout << fixed << setprecision(10) << ans << endl;
  } else {
    cout << fixed << setprecision(10) << h * h * sin(a) << endl;
  }
  return 0;
}
