#include <bits/stdc++.h>
using namespace std;
double sq(double x) { return x * x; }
double dist(pair<double, double> p1, pair<double, double> p2) {
  return sqrt(sq(p1.first - p2.first) + sq(p1.second - p2.second));
}
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long X1, X2, Y1, Y2;
  cin >> X1 >> X2 >> Y1 >> Y2;
  double ans = abs(X1 - X2) + abs(Y1 - Y2);
  if (a == 0 || b == 0) {
    cout << fixed << setprecision(10) << ans;
    return 0;
  }
  vector<pair<double, double> > tochky1, tochky2;
  tochky1.push_back({X1, -(a * 1.0 * X1 + c) / b});
  tochky1.push_back({-(b * 1.0 * Y1 + c) / a, Y1});
  tochky2.push_back({X2, -(a * 1.0 * X2 + c) / b});
  tochky2.push_back({-(b * 1.0 * Y2 + c) / a, Y2});
  for (auto x : tochky1) {
    for (auto y : tochky2) {
      ans = min(ans, dist(x, y) + abs(X1 - x.first) + abs(Y1 - x.second) +
                         abs(X2 - y.first) + abs(Y2 - y.second));
    }
  }
  cout << fixed << setprecision(10) << ans;
}
