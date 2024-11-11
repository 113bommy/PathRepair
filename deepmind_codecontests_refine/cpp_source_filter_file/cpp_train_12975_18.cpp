#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  double n, rad;
  cin >> n >> rad;
  vector<pair<double, double>> circles;
  while (n--) {
    double x;
    cin >> x;
    double maxY = rad;
    for (pair<double, double> circle : circles) {
      if (abs(circle.first - x) > rad * 2) continue;
      double l = circle.second;
      double r = 1e9;
      while (r - l > 1e-6) {
        double mid = (r - l) / 2 + l;
        if (sqrt((x - circle.first) * (x - circle.first) +
                 (circle.second - mid) * (circle.second - mid)) > rad * 2)
          r = mid;
        else
          l = mid;
      }
      double ans = (r - l) / 2 + l;
      if (maxY < ans) maxY = ans;
    }
    circles.push_back(make_pair(x, maxY));
    cout << fixed << setprecision(6) << maxY;
  }
  cout << '\n';
}
