#include <bits/stdc++.h>
const long long INF = 1e+17;
using namespace std;
struct pt {
  long double x, y;
};
long double dist(pt a, pt b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long double a, b, c, x1, x2, y1, y2;
  cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
  long double ans = abs(x2 - x1) + abs(y2 - y1);
  pair<pt, pt> lr;
  lr.first = {(-c - b * y1) / a, y1};
  lr.second = {x1, (-c - a * x1) / b};
  pt f = {(-c - b * y2) / b, y2};
  ans = min(ans, dist(f, lr.first) + abs(x1 - lr.first.x) + abs(x2 - f.x));
  ans = min(ans, dist(f, lr.second) + abs(y1 - lr.second.y) + abs(x2 - f.x));
  f = {x2, (-c - a * x2) / a};
  ans = min(ans, dist(f, lr.first) + abs(x1 - lr.first.x) + abs(y2 - f.y));
  ans = min(ans, dist(f, lr.second) + abs(y1 - lr.second.y) + abs(y2 - f.y));
  cout << fixed << setprecision(10) << ans << endl;
}
