#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-17;
struct Point {
  long double x;
  long double y;
  Point(long double x_, long double y_) {
    x = x_;
    y = y_;
  }
  friend Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
  }
  friend Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
  }
  Point operator/(long double to) const { return Point(x / to, y / to); }
  Point operator*(long double to) const { return Point(x * to, y * to); }
  friend long double operator*(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
  }
  friend long double operator%(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
  }
  friend bool operator<(const Point &a, const Point &b) {
    if (fabs(a.x - b.x) > eps) {
      return a.x < b.x;
    } else if (fabs(a.y - b.y) > eps) {
      return a.y < b.y;
    } else {
      return false;
    }
  }
  long double dist(const Point &other) const {
    long double dx = x - other.x;
    long double dy = y - other.y;
    return hypot(dx, dy);
  }
};
bool is_on_line(const Point &a, const Point &b, const Point &to) {
  long double s = (b - a) * (to - a);
  return fabs(s) < eps;
}
bool is_on_ray(const Point &a, const Point &b, const Point &to) {
  long double tmp = (b - a) % (to - a);
  return is_on_line(a, b, to) && (tmp > 0);
}
bool is_in_segment(const Point &a, const Point &b, const Point &to) {
  return is_on_ray(a, b, to) && is_on_ray(b, a, to);
}
long double ans_x = -1;
void relax(const Point &a, const Point &b, const Point &c, const Point &d) {
  long double s1 = (c - a) * (d - a);
  long double s2 = (d - b) * (c - b);
  long double s = s1 + s2;
  if (fabs(s) < eps) {
    return;
  }
  Point np = b - a;
  np = np / s;
  np = np * s1;
  Point rs = a + np;
  if (is_in_segment(a, b, rs) && is_on_ray(c, d, rs)) {
    ans_x = max(ans_x, rs.x);
  }
}
vector<Point> poly;
vector<Point> res;
void solve() {
  int n = (int)poly.size();
  int ind = 0;
  for (int i = 0; i < n; i++) {
    if (poly[i] < poly[ind]) {
      ind = i;
    }
  }
  Point to = poly[ind];
  poly.erase(poly.begin() + ind);
  auto cmp = [&](const Point &a, const Point &b) {
    long double s = (a - to) * (b - to);
    if (fabs(s) > eps) {
      return s > 0;
    } else {
      return a.dist(to) < b.dist(to);
    }
  };
  sort(poly.begin(), poly.end(), cmp);
  auto ok = [&](const Point &a, const Point &b, const Point &c) {
    long double tmp = (b - a) * (c - b);
    return tmp > eps;
  };
  vector<Point> st = {to};
  for (auto p : poly) {
    while (true) {
      int pnt = (int)st.size() - 1;
      if ((int)st.size() > 1 && !ok(st[pnt - 1], st[pnt], p)) {
        st.pop_back();
      } else {
        break;
      }
    }
    st.push_back(p);
  }
  res = st;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, p, q;
  cin >> n >> p >> q;
  Point c(0, 0);
  Point d(p, q);
  set<pair<int, int>> hv;
  int max_x = -1;
  int max_y = -1;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    hv.insert({x, y});
    max_x = max(max_x, x);
    max_y = max(max_y, y);
  }
  hv.insert({0, max_y});
  hv.insert({max_x, 0});
  for (auto [x, y] : hv) {
    poly.push_back(Point(x, y));
  }
  solve();
  for (int i = 0; i < (int)res.size(); i++) {
    Point a = res[i];
    Point b = res[(i + 1) % (int)res.size()];
    relax(a, b, c, d);
  }
  cout << fixed << setprecision(8);
  cout << (long double)p / ans_x << endl;
}
