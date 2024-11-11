#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int>> points;
long long int sol(vector<pair<long long int, long long int>>& a,
                  vector<pair<long long int, long long int>>& b) {
  long long int ans = 0;
  for (long long int i = 0; i < (long long int)(a.size()); i++) {
    for (long long int j = 0; j < (long long int)(b.size()); j++) {
      long long int minX = 1e9, maxX = -1e9, minY = 1e9, maxY = -1e9;
      minX = min(a[i].first, minX);
      minY = min(a[i].second, minY);
      maxX = max(a[i].first, maxX);
      maxY = max(a[i].second, maxY);
      minX = min(b[j].first, minX);
      minY = min(b[j].second, minY);
      maxX = max(b[j].first, maxX);
      maxY = max(b[j].second, maxY);
      for (long long int p = 0; p < (long long int)(points.size()); p++) {
        long long int minX2 = min(points[p].first, minX);
        long long int minY2 = min(points[p].second, minY);
        long long int maxX2 = max(points[p].first, maxX);
        long long int maxY2 = max(points[p].second, maxY);
        ans = max(ans, (maxX2 - minX2) * 2 + 2 * (maxY2 - minY2));
      }
    }
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int x, y;
  long long int minX = 1e9, maxX = -1e9, minY = 1e9, maxY = -1e9;
  for (long long int i = 0; i < (long long int)(n); i++) {
    cin >> x >> y;
    minX = min(minX, x);
    minY = min(minY, y);
    maxY = max(maxY, y);
    maxX = max(maxX, x);
    points.push_back(make_pair(x, y));
  }
  long long int area = (maxX - minX) * 2 + 2 * (maxY - minY);
  vector<pair<long long int, long long int>> a, b, c, d;
  for (long long int i = 0; i < (long long int)(n); i++) {
    long long int x = points[i].first;
    long long int y = points[i].second;
    if (x == minX) a.push_back(make_pair(x, y));
    if (x == minY) b.push_back(make_pair(x, y));
    if (y == minY) c.push_back(make_pair(x, y));
    if (y == maxY) d.push_back(make_pair(x, y));
  }
  long long int ans = sol(a, b);
  ans = max(ans, sol(a, c));
  ans = max(ans, sol(a, d));
  ans = max(ans, sol(b, c));
  ans = max(ans, sol(b, d));
  ans = max(ans, sol(c, d));
  cout << ans << " ";
  for (long long int i = 0; i < (long long int)(n - 3); i++)
    cout << area << " ";
}
