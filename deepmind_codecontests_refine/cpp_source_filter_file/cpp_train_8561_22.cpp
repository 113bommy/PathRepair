#include <bits/stdc++.h>
using namespace std;
const long double inf = 1e18;
const long double pi = acos(-1);
const long double eps = 1e-9;
const int mod = 998244353;
struct point {
  long double x, y;
  point(long double xx = 0, long double yy = 0) : x(xx), y(yy) {}
  point operator+(const point &a) const { return {x + a.x, y + a.y}; }
  point operator-(const point &a) const { return {x - a.x, y - a.y}; }
  point operator*(const long double &c) const { return {x * c, y * c}; }
  point operator*(const point &p) const {
    return {x * p.x - y * p.y, x * p.y + y * p.x};
  }
  point operator/(const long double &c) const { return {x / c, y / c}; }
  point operator/(const point &a) const {
    return point{x * a.x + y * a.y, y * a.x - x * a.y} /
           (a.x * a.x + a.y * a.y);
  }
  bool operator<(const point &a) const {
    if (abs(x - a.x) > eps) return x + eps < a.x;
    return y + eps < a.y;
  }
};
long double cross(const point &a, const point &b) {
  return a.x * b.y - a.y * b.x;
}
long double dot(const point &a, const point &b) {
  return a.x * b.x + a.y * b.y;
}
long double norm(const point &p) { return dot(p, p); }
long double abs(const point &p) { return sqrt(norm(p)); }
struct line {
  point p1, p2;
  line(point a = point(), point b = point()) : p1(a), p2(b) {}
  const point &operator[](const int &i) const {
    if (i == 0) return p1;
    return p2;
  }
  point &operator[](const int &i) {
    if (i == 0) return p1;
    return p2;
  }
  long double get_Y(const long double &x) {
    point v = p2 - p1;
    v = v / v.x;
    long double dx = x - p1.x;
    point p3 = p1 + v * dx;
    return p3.y;
  }
};
int ccw(point a, point b, point c) {
  b = b - a;
  c = c - a;
  if (cross(b, c) > eps) return +1;
  if (cross(b, c) < -eps) return -1;
  if (dot(b, c) < -eps) return +2;
  if (norm(b) + eps < norm(c)) return -2;
  return 0;
}
bool intersectSS(const line &s, const line &t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= eps &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= eps;
}
long double X;
vector<line> l;
struct event {
  int id, iof;
  bool operator<(const event &e) const {
    if (abs(l[id][iof].x - l[e.id][e.iof].x) > eps)
      return l[id][iof].x + eps < l[e.id][e.iof].x;
    if (abs(l[id][iof].y - l[e.id][e.iof].y) > eps)
      return l[id][iof].y + eps < l[e.id][e.iof].y;
    return iof < e.iof;
  }
};
struct status {
  int id;
  bool operator<(const status &s) const {
    return l[id].get_Y(X) + eps < l[s.id].get_Y(X);
  }
};
bool check() {
  int n = l.size() - 1;
  for (int i = 0; i < n; i++) {
    if (l[i][0].x - eps > l[i][1].x) swap(l[i][0], l[i][1]);
  }
  vector<event> e;
  for (int i = 0; i < n; i++) {
    e.push_back({i, 0});
    e.push_back({i, 1});
  }
  sort(e.begin(), e.end());
  multiset<status> ms;
  for (auto i : e) {
    X = l[i.id][i.iof].x;
    if (abs(l[i.id][0].x - l[i.id][1].x) < eps) {
      long double y1 = min(l[i.id][0].y, l[i.id][1].y);
      long double y2 = max(l[i.id][0].y, l[i.id][1].y);
      l[n] = line(point(0, y1), point(1, y1));
      auto a = ms.lower_bound({n});
      l[n] = line(point(0, y2), point(1, y2));
      auto b = ms.upper_bound({n});
      if (a != b) return true;
      continue;
    }
    if (i.iof == 0) {
      ms.insert({i.id});
      auto it = ms.find({i.id});
      if (it != ms.begin()) {
        auto it1 = it;
        it1--;
        if (intersectSS(l[it->id], l[it1->id])) return true;
      }
      auto it1 = it;
      it1++;
      if (it1 != ms.end() && intersectSS(l[it->id], l[it1->id])) return true;
    }
    if (i.iof == 1) {
      auto it = ms.find({i.id});
      if (it != ms.begin()) {
        auto it1 = it;
        it1--;
        auto it2 = it;
        it2++;
        if (it2 != ms.end() && intersectSS(l[it1->id], l[it2->id])) return true;
      }
      ms.erase(it);
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n), d(n);
  for (int i = 0; i < n; ++i) {
    int x, y, dx, dy, s;
    cin >> x >> y >> dx >> dy >> s;
    p[i] = point(x, y);
    d[i] = point(dx, dy);
    d[i] = (d[i] / abs(d[i])) * s;
  }
  long double lo = 0, hi = 1e9;
  l = vector<line>(n + 1);
  for (int i = 0; i < 200; i++) {
    long double m = (lo + hi) * 0.5;
    for (int j = 0; j < n; j++) {
      l[j][0] = p[j];
      l[j][1] = p[j] + d[j] * m;
    }
    if (check())
      hi = m;
    else
      lo = m;
  }
  if (lo < 1e9)
    cout << fixed << setprecision(15) << lo << '\n';
  else
    cout << "No show :(" << '\n';
  return 0;
}
