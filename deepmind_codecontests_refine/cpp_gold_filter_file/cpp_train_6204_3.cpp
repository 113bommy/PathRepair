#include <bits/stdc++.h>
using namespace std;
const double INF = 1e9 + 22;
int n;
double l = -INF, r = INF;
pair<double, double> go(double r, double v, double r1, double r2) {
  if (v == 0) {
    if (r <= r1 || r >= r2) {
      cout << -1;
      exit(0);
    }
    return {-INF, INF};
  }
  if (v < 0) return go(-r, -v, -r2, -r1);
  double e1, e2;
  if (r > r1)
    e1 = -INF;
  else
    e1 = (r1 - r) / v;
  if (r >= r2) {
    cout << -1;
    exit(0);
  }
  e2 = (r2 - r) / v;
  return {e1, e2};
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  double x1, Ehsan22, x2, y2;
  cin >> n;
  cin >> x1 >> Ehsan22 >> x2 >> y2;
  for (int i = 1; i <= n; i++) {
    double x, y, vx, vy;
    pair<double, double> p1, p2;
    cin >> x >> y >> vx >> vy;
    p1 = go(x, vx, x1, x2);
    p2 = go(y, vy, Ehsan22, y2);
    l = max(l, max((p1.first), (p2.first)));
    r = min(r, min((p1.second), (p2.second)));
  }
  if (l >= r || r < 0) return cout << -1, 0;
  if (l < 0)
    cout << 0;
  else
    cout << fixed << setprecision(6) << l;
  return 0;
}
