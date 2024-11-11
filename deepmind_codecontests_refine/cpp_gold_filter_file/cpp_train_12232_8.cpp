#include <bits/stdc++.h>
using namespace std;
struct point {
  int idx;
  long long int x, y;
  point operator-(const point &o) const { return {-1, x - o.x, y - o.y}; }
  long long int operator^(const point &o) const { return x * o.y - y * o.x; }
};
point origin{-1, 0, 0};
long long int sign(point a, point b, point c) { return (b - a) ^ (c - a); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<point> p(n + m);
  long long int max_x = 0, max_y = 0;
  for (int i = 0; i < (int)(n + m); i++) {
    cin >> p[i].x >> p[i].y;
    p[i].idx = i;
    if (i >= n) {
      max_x = max(max_x, p[i].x);
      max_y = max(max_y, p[i].y);
    }
  }
  p.push_back(point{((int)(p).size()), max_x, 0});
  p.push_back(point{((int)(p).size()), 0, max_y});
  sort((p).begin(), (p).end(),
       [](point a, point b) { return sign(origin, a, b) > 0; });
  vector<point> keep;
  for (int i = 0; i < ((int)(p).size());) {
    int j = i;
    while (j < ((int)(p).size()) && sign(origin, p[i], p[j]) == 0) ++j;
    point pick = p[i];
    for (int k = (int)(i); k < ((int)j); k++)
      if (p[k].x > pick.x || (p[k].x == pick.x && p[k].idx < n)) pick = p[k];
    keep.emplace_back(pick);
    i = j;
  }
  vector<point> chull(1, origin);
  for (auto p : keep) {
    while (((int)(chull).size()) >= 2 &&
           sign(chull[((int)(chull).size()) - 2],
                chull[((int)(chull).size()) - 1], p) < 0)
      chull.pop_back();
    chull.emplace_back(p);
  }
  bool first = false;
  for (int i = (int)(1); i < ((int)((int)(chull).size())); i++) {
    const auto &p = chull[i];
    first |= p.idx < n;
  }
  cout << (first ? "Max" : "Min");
  return 0;
}
