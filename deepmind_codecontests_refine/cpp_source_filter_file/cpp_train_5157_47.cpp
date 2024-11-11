#include <bits/stdc++.h>
using namespace std;
vector<pair<double, double> > points;
bool PointInPolygon(pair<double, double> point) {
  int i, j, nvert = points.size();
  bool c = false;
  for (i = 0, j = nvert - 1; i < nvert; j = i++) {
    if (((points[i].second >= point.second) !=
         (points[j].second >= point.second)) &&
        (point.first <= (points[j].first - points[i].first) *
                                (point.second - points[i].second) /
                                (points[j].second - points[i].second) +
                            points[i].first))
      c = !c;
  }
  return c;
}
int main() {
  int i, n, first, second, ans = 0;
  cin >> n;
  for (i = 1; i <= n + 1; i++) {
    cin >> first >> second;
    points.push_back({first, second});
  }
  for (i = 2; i <= n + 1; i++) {
    if (points[i].first == points[i - 1].first) {
      if (points[i].second > points[i - 1].second) {
        ans += PointInPolygon({points[i].first, points[i].second + 0.2});
      } else {
        ans += PointInPolygon({points[i].first, points[i].second - 0.2});
      }
    } else {
      if (points[i].first > points[i - 1].first) {
        ans += PointInPolygon({points[i].first + 0.2, points[i].second});
      } else {
        ans += PointInPolygon({points[i].first - 0.2, points[i].second});
      }
    }
  }
  cout << ans;
  return 0;
}
