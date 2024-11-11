#include <bits/stdc++.h>
using namespace std;
pair<double, double> x, y, w1, w2, st;
double t, v;
double Distance(pair<double, double> p1, pair<double, double> p2) {
  double dis = sqrt(((p1.first - p2.first) * (p1.first - p2.first)) +
                    ((p1.second - p2.second) * (p1.second - p2.second)));
  return dis;
}
bool solve(double mid) {
  x.first =
      st.first + (min(t, mid) * w1.first) + (max(0.0, mid - t) * w2.first);
  x.second =
      st.second + (min(t, mid) * w1.second) + (max(0.0, mid - t) * w2.second);
  double d = Distance(x, y);
  if ((d / v) - mid >= 1e-9) {
    return 1;
  }
  return 0;
}
int main() {
  cout << fixed << setprecision(15);
  cin >> st.first >> st.second >> y.first >> y.second >> v >> t >> w1.first >>
      w1.second >> w2.first >> w2.second;
  double s = 0, e = 1e9, mid, ans = -1;
  for (int i = 0; i < 200; i++) {
    mid = s + (e - s) / 2;
    if (solve(mid)) {
      s = mid;
      ans = mid;
    } else {
      e = mid;
    }
  }
  cout << e << endl;
  return 0;
}
