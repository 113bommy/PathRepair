#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > towers, ans;
int n, r, answer = INT_MIN;
vector<pair<int, int> > points;
double dist(pair<int, int> a, pair<int, int> b) {
  return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}
long long int get_orientation(pair<int, int> x, pair<int, int> y,
                              pair<int, int> z) {
  return x.first * (y.second - z.second) + y.first * (z.second - x.second) +
         z.first * (x.second - y.second);
}
bool new_cmp(pair<int, int> x, pair<int, int> y) {
  return (x.first * x.first + x.second * x.second) >
         (y.first * y.first + y.second * y.second);
}
vector<pair<int, int> > getConvexHull(vector<pair<int, int> > pts) {
  sort(pts.begin(), pts.end());
  pair<int, int> mx = pts[pts.size() - 1];
  pair<int, int> least = pts[0];
  vector<pair<int, int> > set1, set2;
  set1.emplace_back(least);
  set2.emplace_back(least);
  for (int i = 1; i < pts.size(); i++) {
    long long int temp = get_orientation(mx, least, pts[i]);
    if (temp <= 0) {
      while (set1.size() > 1 &&
             get_orientation(set1[set1.size() - 2], set1.back(), pts[i]) >= 0)
        set1.pop_back();
      set1.push_back(pts[i]);
    }
    if (temp >= 0) {
      while (set2.size() > 1 &&
             get_orientation(set2[set2.size() - 2], set2.back(), pts[i]) <= 0)
        set2.pop_back();
      set2.emplace_back(pts[i]);
    }
  }
  vector<pair<int, int> > h = set1;
  for (int i = set2.size() - 2; i > 0; i--) h.emplace_back(set2[i]);
  return h;
}
void check(int x, int count, int score) {
  if (x >= points.size()) {
    if (count < n) return;
    if (score > answer) {
      answer = score;
      ans = towers;
    }
    return;
  }
  check(x + 1, count, score);
  for (int i = count + 1; i <= n; i++) {
    towers[i - 1] = points[x];
    for (int j = 0; j < i - 1; ++j) score += dist(towers[j], towers[i - 1]);
    check(x + 1, i, score);
  }
  return;
}
int main() {
  cin >> n >> r;
  if (n <= 2) {
    cout << pow(r, 2) * 4 << "\n";
    cout << "0 " << r << "\n"
         << "0" << -1 * r << "\n";
    return 0;
  }
  for (int i = -r; i <= r; i++) {
    for (int j = -r; j <= r; j++) {
      if (i * i + j * j <= r * r) points.emplace_back(make_pair(i, j));
    }
  }
  points = getConvexHull(points);
  sort(points.begin(), points.end(), new_cmp);
  for (int i = 0; i < n; i++) towers.emplace_back(make_pair(0, 0));
  points.resize(24, {0, 0});
  check(0, 0, 0);
  cout << answer << "\n";
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
  return 0;
}
