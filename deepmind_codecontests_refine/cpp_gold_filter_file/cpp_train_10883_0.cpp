#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
signed main() {
  if (strlen("") > 0)
    freopen(
        ""
        ".in",
        "r", stdin),
        freopen(
            ""
            ".out",
            "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  long double sx, sy, v, t;
  cin >> sx >> sy >> v >> t;
  long double R = v * t;
  vector<pair<long double, int>> sc;
  auto get_angle = [&](long double x, long double y) {
    long double alpha = atan2(y, x) + 2 * PI;
    return fmodl(alpha, 2 * PI);
  };
  auto add = [&](long double lef, long double rig) {
    assert(lef >= 0 && rig >= 0 && lef < 2 * PI && rig < 2 * PI);
    sc.push_back(make_pair(lef, 1));
    if (lef > rig) {
      sc.push_back(make_pair(2 * PI, -1));
      sc.push_back(make_pair(0, 1));
    }
    sc.push_back(make_pair(rig, -1));
  };
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long double x0, y0, r;
    cin >> x0 >> y0 >> r;
    x0 -= sx, y0 -= sy;
    long double alpha = get_angle(x0, y0);
    if (x0 * x0 + y0 * y0 <= r * r) {
      cout << "1\n";
      return 0;
    }
    if (x0 * x0 + y0 * y0 >= (R + r) * (R + r)) {
      continue;
    }
    long double d = sqrtl(x0 * x0 + y0 * y0), delta;
    if (x0 * x0 + y0 * y0 - r * r <= R * R) {
      delta = asinl(r / d);
    } else {
      delta = acosl((R * R + x0 * x0 + y0 * y0 - r * r) / (2 * d * R));
    }
    add(fmodl(alpha - delta + 2 * PI, 2 * PI),
        fmodl(alpha + delta + 2 * PI, 2 * PI));
  }
  sort(sc.begin(), sc.end());
  long double ans = 0, pr = 0;
  int bal = 0;
  for (int i = 0; i < (int)sc.size(); ++i) {
    if (bal == 0) {
      pr = sc[i].first;
    }
    bal += sc[i].second;
    if (bal == 0) {
      ans += (sc[i].first - pr);
    }
  }
  cout << fixed << setprecision(10) << ans / (2 * PI) << "\n";
  return 0;
}
