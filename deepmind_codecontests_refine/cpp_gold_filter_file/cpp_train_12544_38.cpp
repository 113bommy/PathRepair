#include <bits/stdc++.h>
using namespace std;
const long long int MINL = (long long int)25 * 10000 * 10001;
const int MAXN = 1000 * 1001;
struct Point {
  int i, x, y;
};
bool lowerP(const Point& p1, const Point& p2) { return p1.y < p2.y; }
bool greaterP(const Point& p1, const Point& p2) { return p1.y > p2.y; }
int n;
vector<int> ans;
vector<Point> lay[1001];
inline long long int dist(const Point& p1, const Point& p2) {
  return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int a = 0; a < n; ++a) {
    int x, y;
    cin >> x >> y;
    lay[x / 1000].push_back({a, x, y});
  }
  for (int a = 0; a < 1001; ++a) {
    if (a & 1)
      sort(lay[a].begin(), lay[a].end(), lowerP);
    else
      sort(lay[a].begin(), lay[a].end(), greaterP);
    for (auto b : lay[a]) {
      ans.push_back(b.i);
    }
  }
  for (auto a : ans) {
    cout << a + 1 << " ";
  }
  return 0;
}
