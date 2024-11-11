#include <bits/stdc++.h>
using namespace std;
template <class T, class S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  return os << "(" << v.first << ", " << v.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = int(0); i <= int((static_cast<int>((v).size())) - 1); ++i) {
    if (i) os << ", ";
    os << v[i];
  }
  return os << "]";
}
template <class T>
bool setmax(T& _a, T _b) {
  if (_b > _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T& _a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
const long double PI = acosl(-1);
int sgn(long double x, long double e = 1e-12) { return x < -e ? -1 : x > e; }
struct Point {
  long double x, y;
  int label = 0;
  Point() : x(0), y(0) {}
  Point(long double _x, long double _y) : x(_x), y(_y) {}
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  Point operator*(long double b) const { return Point(x * b, y * b); }
  Point operator/(long double b) const { return Point(x / b, y / b); }
  bool operator==(Point p) const {
    return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;
  }
  long double sqr_abs() const { return x * x + y * y; }
  long double abs() const { return sqrt(sqr_abs()); }
  long double ang() const { return atan2l(y, x); }
  friend long double mult(Point p1, Point p2) {
    return p1.x * p2.y - p1.y * p2.x;
  }
  friend long double mult(Point p0, Point p1, Point p2) {
    return mult(p1 - p0, p2 - p0);
  }
  friend long double dot(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
  }
  friend long double dot(Point p0, Point p1, Point p2) {
    return dot(p1 - p0, p2 - p0);
  }
  void print() const { printf("%.2lf %.2lf", (double)x, (double)y); }
};
Point read_point() {
  double u, v;
  scanf("%lf%lf", &u, &v);
  return Point(u, v);
}
vector<Point> ps;
long double normalize(long double ang) {
  if (ang < -PI) ang += PI * 2;
  if (ang > +PI) ang -= PI * 2;
  return ang;
}
bool check(Point center, long double r) {
  struct Event {
    long double t;
    int label;
    int stub;
    bool operator<(const Event& e) const {
      int s = sgn(t - e.t);
      if (s != 0) return s < 0;
      if (stub != e.stub) return stub < 0;
      if (stub > 0) {
        return label > e.label;
      } else {
        return label < e.label;
      }
    }
  };
  vector<Event> es;
  for (const auto& p : ps) {
    if (p == center) continue;
    if (center.label && p.label) continue;
    long double d = (p - center).abs();
    if (sgn(d - r * 2) > 0) continue;
    long double dir = (p - center).ang();
    long double phi = acosl(d / 2 / r);
    long double st = normalize(dir - phi), en = normalize(dir + phi);
    if (sgn(st - en) <= 0) {
      es.push_back({st, p.label, 1});
      es.push_back({en, p.label, -1});
    } else {
      es.push_back({st, p.label, 1});
      es.push_back({PI + 1, p.label, -1});
      es.push_back({-PI - 1, p.label, 1});
      es.push_back({en, p.label, -1});
    }
  }
  if (center.label) {
    es.push_back({-PI - 1, 1, 1});
    es.push_back({0, 1, -1});
    es.push_back({0, 1, 1});
    es.push_back({PI + 1, 1, -1});
  }
  sort((es).begin(), (es).end());
  int cnt[2] = {0, 0};
  for (const auto& e : es) {
    cnt[e.label] += e.stub;
    if (sgn(e.t + PI) >= 0 && sgn(e.t - PI) <= 0) {
      if (cnt[1] > 0 && cnt[0] == 0) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = int(0); i <= int((n)-1); ++i) {
    ps.push_back(read_point());
    ps.back().label = 1;
  }
  for (int i = int(0); i <= int((m)-1); ++i) {
    ps.push_back(read_point());
  }
  for (const auto& p : ps) {
    if (p.label && check(p, 1e15)) {
      printf("-1\n");
      return 0;
    }
  }
  long double ans = 0.1;
  for (int label = int(1); label >= int(0); --label) {
    for (const auto& p : ps) {
      if (p.label == label) {
        if (!check(p, ans)) continue;
        long double l = ans, r = ans * 2;
        while (check(p, r)) r *= 2;
        for (int i = int(0); i <= int((70) - 1); ++i) {
          long double mid = (l + r) / 2;
          if (check(p, mid))
            l = mid;
          else
            r = mid;
        }
        ans = l;
      }
    }
  }
  printf("%.9lf\n", (double)ans);
  return 0;
}
