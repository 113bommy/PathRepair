#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int main() {
  long long x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  long long xs, ys, t;
  cin >> xs >> ys >> t;
  vector<pair<long long, long long> > point;
  while (x0 < 2e16 && y0 < 2e16) {
    point.push_back({x0, y0});
    x0 = x0 * ax + bx;
    y0 = y0 * ay + by;
  }
  int n = point.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    long long cost = 0;
    int cnt = 0;
    long long curx = xs, cury = ys;
    for (int j = i; j >= 0 && cost <= t; j--) {
      cost += abs(point[j].first - curx) + abs(point[j].second - cury);
      if (cost <= t) cnt++;
      curx = point[j].first;
      cury = point[j].second;
    }
    for (int j = i + 1; j < n && cost <= t; j++) {
      cost += abs(point[j].first - curx) + abs(point[j].second - cury);
      if (cost <= t) cnt++;
      curx = point[j].first;
      cury = point[j].second;
    }
    ans = max(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}
