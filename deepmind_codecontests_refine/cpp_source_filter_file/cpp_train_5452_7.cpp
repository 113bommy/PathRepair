#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[100005 + 5];
int x[100005 + 5], y[100005 + 5];
double angle(int i, int j) {
  double x1 = p[i].first;
  double y1 = p[i].second;
  double x2 = p[j].first;
  double y2 = p[j].second;
  double pi = 2 * acos(0);
  double theta1 = atan2(y1, x1) * 180 / pi;
  double theta2 = atan2(y2, x2) * 180 / pi;
  if (theta2 + 1e-9 < theta1) {
    return 360 - fabs(theta2 - theta1);
  }
  return theta2 - theta1;
}
int cmp(pair<int, int> a, pair<int, int> b) {
  int x1 = a.first, x2 = b.first, y1 = a.second, y2 = b.second;
  double pi = 2 * acos(0);
  double theta1 = atan2(y1, x1) * 180 / pi;
  double theta2 = atan2(y2, x2) * 180 / pi;
  if (theta1 + 1e-9 >= theta2) return false;
  return true;
}
int main() {
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  sort(p, p + n, cmp);
  if (n == 1)
    cout << 0 << endl;
  else if (n == 2) {
    double ans = min(angle(0, 1), 360 - angle(0, 1));
    printf("%.9lf", ans);
  } else {
    double mx = 0.0;
    for (i = 0; i < n; i++) {
      double theta = angle(i, (i + 1) % n);
      mx = max(mx, theta);
    }
    if (mx == 0) mx = 360;
    printf("%.9lf", 360 - mx);
  }
  return 0;
}
