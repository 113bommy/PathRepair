#include <bits/stdc++.h>
using namespace std;
long double dist(long double x1, long double y1, long double x2,
                 long double y2) {
  return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(10) << fixed;
  long double a, b, c;
  cin >> a >> b >> c;
  long double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long double ans = abs(x1 - x2) + abs(y1 - y2);
  if (a == 0 || b == 0) {
    cout << ans << "\n";
    return 0;
  }
  long double y3 = -c - (a * x1);
  y3 /= b;
  long double x3 = -c - (b * y2);
  x3 /= a;
  long double x4 = -c - (b * y1);
  x4 /= a;
  long double y4 = -c - (a * x2);
  y4 /= b;
  long double ans1 = abs(x1 - x3) + min(dist(x1, y3, x3, y2) + abs(x2 - x3),
                                        dist(x1, y3, x2, y4) + abs(y2 - y4));
  long double ans2 = abs(x1 - x4) + min(dist(x4, y1, x3, y2) + abs(x2 - x3),
                                        dist(x4, y1, x2, y4) + abs(y2 - y4));
  ;
  ans = min(ans, min(ans1, ans2));
  cout << ans << "\n";
  return 0;
}
