#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int main() {
  double h, w, a;
  cin >> w >> h >> a;
  if (a == 180 || a == 0) {
    cout << fixed << setprecision(10) << h * w << endl;
    return 0;
  }
  if (a == 90) {
    h = min(h, w);
    w = h;
    cout << fixed << setprecision(10) << h * w << endl;
    return 0;
  }
  if (h > w) swap(h, w);
  if (a > 90) a = 180 - a;
  a *= PI;
  a /= 180.0;
  double a1 = 2 * atan2(h, w);
  if (a >= a1) {
    double h1 = h / sin(a);
    double x = h1 * cos(a);
    double res = h * x + (h1 - x) * h;
    cout << fixed << setprecision(10) << res;
    return 0;
  }
  double x1 = (w - h * (1 + cos(a)) / sin(a)) *
              (sin(a) / (-(1 + cos(a)) * (1 + cos(a)) + sin(a) * sin(a)));
  double l1 = (h - (x1 * (1 + cos(a)))) / sin(a);
  double l2 = l1 * sin(a);
  double l3 = l1 * cos(a);
  double x2 = x1 * sin(a);
  double x3 = x1 * cos(a);
  double res = h * w;
  res -= x3 * x2;
  res -= l3 * l2;
  cout << fixed << setprecision(10) << res;
  return 0;
}
