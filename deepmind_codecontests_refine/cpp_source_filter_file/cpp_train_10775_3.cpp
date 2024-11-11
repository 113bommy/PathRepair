#include <bits/stdc++.h>
using namespace std;
struct point {
  long double x;
  long double y;
};
long double dist(point p1, point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long double r1, r2, ans = 0, s, d, theta;
  point p1, p2;
  cin >> p1.x >> p1.y >> r1;
  cin >> p2.x >> p2.y >> r2;
  cout.precision(12);
  if (dist(p1, p2) > (r1 + r2))
    cout << "0.00";
  else if (dist(p1, p2) < abs(r1 - r2)) {
    if (r1 < r2)
      cout << acos(-1) * r1 * r1;
    else
      cout << acos(-1) * r2 * r2;
  } else {
    d = dist(p1, p2);
    theta = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
    ans += (theta)*r2 * r2 - r2 * r2 * cos(theta) * sin(theta);
    theta = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    ans += (theta)*r1 * r1 - r1 * r1 * cos(theta) * sin(theta);
    cout << ans;
  }
}
