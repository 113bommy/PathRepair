#include <bits/stdc++.h>
using namespace std;
int direction(pair<long long, long long> &a, pair<long long, long long> &b,
              pair<long long, long long> &c) {
  long long val = a.first * c.second - c.first * a.second +
                  b.first * (a.second - c.second) +
                  b.second * (c.first - a.first);
  return val < 0 ? -1 : val > 0 ? 1 : 0;
}
int main() {
  int n, m;
  set<pair<long long, long long> > inner;
  vector<pair<long long, long long> > pts;
  cin >> n;
  for (int i = 0; i < n; i++) {
    pts.push_back({0, 0});
    cin >> pts.back().first >> pts.back().second;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    pts.push_back({0, 0});
    cin >> pts.back().first >> pts.back().second;
    inner.insert(pts.back());
  }
  sort(pts.begin(), pts.end());
  pair<long long, long long> &st = pts[0], &en = pts.back();
  vector<int> up, down;
  up.push_back(0);
  down.push_back(0);
  for (int i = 1; i < pts.size(); i++) {
    if (direction(st, pts[i], en) >= 0) {
      while (up.size() > 1 &&
             direction(pts[up[up.size() - 2]], pts[up.back()], pts[i]) == -1) {
        up.pop_back();
      }
      up.push_back(i);
    }
    if (direction(st, pts[i], en) <= 0) {
      while (down.size() > 1 && direction(pts[down[down.size() - 2]],
                                          pts[down.back()], pts[i]) == 1) {
        down.pop_back();
      }
      down.push_back(i);
    }
  }
  for (int u : up) {
    if (inner.count(pts[u])) {
      cout << "NO";
      return 0;
    }
  }
  for (int u : down) {
    if (inner.count(pts[u])) {
      cout << "NO0";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
