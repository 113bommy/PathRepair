#include <bits/stdc++.h>
using namespace std;
long double d(long double a, long double b, long double c, long double d) {
  return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}
int main() {
  long double x1, y1, r1, x2, y2, r2;
  ios_base::sync_with_stdio(0);
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;
  long double ans;
  long double dis;
  dis = d(x1, y1, x2, y2);
  if (dis >= r1 + r1) {
    ans = 0;
    goto L1;
  } else if (dis < abs(r1 - r2)) {
    ans = 3.141592653589793 * (min(r1, r2)) * (min(r1, r2));
    goto L1;
  }
  long double a1, a2;
  a1 = acos((r1 * r1 - r2 * r2 + dis * dis) / (2 * r1 * dis)) * 2;
  a2 = acos((r2 * r2 + dis * dis - r1 * r1) / (2 * r2 * dis)) * 2;
  long double s1, s2;
  s1 = (a1 * r1 * r1 - sin(a1) * r1 * r1) / 2;
  s2 = (a2 * r2 * r2 - sin(a2) * r2 * r2) / 2;
  ans = s1 + s2;
L1:
  cout.precision(20);
  cout << fixed << ans << endl;
  return 0;
}
