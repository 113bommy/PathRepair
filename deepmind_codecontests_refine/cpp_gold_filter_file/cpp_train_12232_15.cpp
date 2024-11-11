#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x;
  long long y;
  point() { x = y = 0; }
  point(long long x_, long long y_) {
    x = x_;
    y = y_;
  }
};
point operator+(const point &left, const point &right) {
  return point(left.x + right.x, left.y + right.y);
}
point operator-(const point &left, const point &right) {
  return point(left.x - right.x, left.y - right.y);
}
long long operator*(const point &left, const point &right) {
  return left.x * right.x + left.y * right.y;
}
long long operator%(const point &left, const point &right) {
  return left.x * right.y - right.x * left.y;
}
bool operator<(const point &left, const point &right) {
  if (left % right != 0) return left % right > 0;
  return left * left < right * right;
}
bool operator==(const point &left, const point &right) {
  return left.x == right.x && left.y == right.y;
}
point getpoint() {
  int x, y;
  scanf(" %d %d", &x, &y);
  return point(x, y);
}
bool work(vector<pair<point, int> > all) {
  sort(all.begin(), all.end());
  vector<pair<point, int> > pts;
  pts.push_back(make_pair(point(0, 0), -1));
  for (int i = 0; i < (int)all.size(); i++) {
    point cur = all[i].first;
    while (pts.size() >= 2) {
      point prv = pts.back().first;
      point prv2 = pts[(int)pts.size() - 2].first;
      if ((prv - prv2) % (cur - prv) < 0)
        pts.pop_back();
      else
        break;
    }
    pts.push_back(all[i]);
  }
  pts.push_back(pts[0]);
  int len = (int)pts.size() - 1;
  vector<int> order;
  for (int i = 1; i < len; i++) {
    point diff = pts[i + 1].first - pts[i].first;
    point df2 = pts[i - 1].first - pts[i].first;
    if (diff.x <= 0 || diff.y <= 0)
      if (df2.x <= 0 || df2.y <= 0) order.push_back(i);
  }
  for (int v : order)
    if (pts[v].second == 1) return true;
  return false;
}
void solve(int n) {
  int x, y, m;
  cin >> m >> x >> y;
  vector<point> v(n), u(m);
  for (int i = 0; i < n; i++) v[i] = getpoint();
  for (int i = 0; i < m; i++) u[i] = getpoint();
  vector<pair<point, int> > all;
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  n = ((int)(v).size());
  sort(u.begin(), u.end());
  u.resize(unique(u.begin(), u.end()) - u.begin());
  m = ((int)(u).size());
  for (int i = 0; i < n; i++) all.push_back(make_pair(v[i], 1));
  for (int i = 0; i < m; i++)
    if (!binary_search(v.begin(), v.end(), u[i]))
      all.push_back(make_pair(u[i], 0));
  bool ok = work(all);
  if (ok)
    puts("Max");
  else
    puts("Min");
}
int main() {
  int n;
  while (cin >> n) solve(n);
}
