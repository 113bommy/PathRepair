#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
long double distance(long double x, long double y, long double x1,
                     long double y1, long double x2, long double y2) {
  long double A = x - x1;
  long double B = y - y1;
  long double C = x2 - x1;
  long double D = y2 - y1;
  long double dot = A * C + B * D;
  long double len_sq = C * C + D * D;
  long double param = -1;
  long double xx, yy;
  if (len_sq != 0.0) param = dot / len_sq;
  if (param < 0.0) {
    xx = x1;
    yy = y1;
  } else if (param > 1.0) {
    xx = x2;
    yy = y2;
  } else {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }
  long double dx = x - xx;
  long double dy = y - yy;
  return dx * dx + dy * dy;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long double r, yw;
  pair<long double, long double> y1, y2, ball;
  cin >> y1.second >> y2.second >> yw >> ball.first >> ball.second >> r;
  y1.first = y2.first = 0.0;
  yw -= r, y1.second += r + eps;
  pair<long double, long double> b, ans;
  b.first = 0.0;
  b.second = yw + (yw - y1.second);
  long double m = (b.second - ball.second) / (b.first - ball.first);
  ans.second = yw, ans.first = (yw - b.second) / m;
  long double dis =
      distance(y2.first, y2.second, y1.first, y1.second, ans.first, ans.second);
  if (dis <= r * r)
    cout << -1 << endl;
  else
    cout << setprecision(10) << ans.first << endl;
  return 0;
}
