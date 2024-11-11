#include <bits/stdc++.h>
using namespace std;
double X, Y, v, t, x, y, r;
int n;
vector<pair<double, int> > seg;
int main() {
  scanf("%lf %lf %lf %lf", &X, &Y, &v, &t);
  scanf("%d", &n);
  double R = v * t;
  while (n--) {
    scanf("%lf %lf %lf", &x, &y, &r);
    double d = sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
    if (d > R + r + 1e-8) continue;
    if (d < r + 1e-8) {
      cout << 1;
      return 0;
    }
    double ang = atan2(x - X, y - Y);
    if (ang < 0) ang += acos(-1) * 2;
    double ran = 0;
    if (d * d < r * r + R * R) {
      ran = asin(r / d);
    } else {
      ran = acos((d * d + R * R - r * r) / (2 * d * R));
    }
    double high = ang + ran, low = ang - ran;
    if (high >= 2 * acos(-1)) {
      seg.push_back({0, 0});
      seg.push_back({high - 2 * acos(-1), 1});
      seg.push_back({low, 0});
      seg.push_back({2 * acos(-1), 1});
    } else if (low < 0) {
      seg.push_back({0, 0});
      seg.push_back({high, 1});
      seg.push_back({low + 2 * acos(-1), 0});
      seg.push_back({2 * acos(-1), 1});
    } else {
      seg.push_back({low, 0});
      seg.push_back({high, 1});
    }
  }
  double ans = 0;
  int cnt = 0;
  double cur = 0;
  sort(seg.begin(), seg.end());
  for (auto p : seg) {
    if (cnt > 0) {
      ans += p.first - cur;
    }
    if (p.second)
      cnt--;
    else
      cnt++;
    cur = p.first;
  }
  cout << setprecision(11) << ans / (2 * acos(-1));
}
