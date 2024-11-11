#include <bits/stdc++.h>
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class Iterable,
          class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v)) {
  os << "[";
  for (auto vv : v) os << vv << ", ";
  return os << "]";
}
const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;
template <class T>
int sign(T x) {
  return (x > 0) - (x < 0);
}
template <class T>
T abs(const T &x) {
  return (x < T(0)) ? -x : x;
}
const long double EPS = 1e-2;
template <class T>
struct point {
  T x, y;
  explicit point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(point<T> p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(point<T> p) const { return tie(x, y) == tie(p.x, p.y); }
  point<T> operator+(point<T> p) const { return point<T>(x + p.x, y + p.y); }
  point<T> operator-(point<T> p) const { return point<T>(x - p.x, y - p.y); }
  point<T> operator*(T d) const { return point<T>(x * d, y * d); }
  point<T> operator/(T d) const { return point<T>(x / d, y / d); }
  T dot(point<T> p) const { return x * p.x + y * p.y; }
  T cross(point<T> p) const { return x * p.y - y * p.x; }
  T cross(point<T> a, point<T> b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  long double dist() const { return sqrt((long double)dist2()); }
  long double angle() const { return atan2(y, x); }
  point<long double> unit() const { return *this / dist(); }
  point<T> perp() const { return point<T>(-y, x); }
  point<long double> normal() const { return perp().unit(); }
  point<long double> rotate(long double a) const {
    return point<T>(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  long double angle(point<T> p) const { return p.rotate(-angle()).angle(); }
};
template <class T>
pair<int, point<T>> linear_solve2(T a, T b, T c, T d, T e, T f) {
  point<T> retv;
  T det = a * d - b * c;
  if (det == 0) {
    if (b * f == d * e && a * f == c * e) return {-1, point<T>()};
    return {0, point<T>()};
  }
  return {1, point<T>((e * d - f * b) / det, (a * f - c * e) / det)};
}
template <class T>
struct segment {
  point<T> pi, pf;
  explicit segment(point<T> a = point<T>(), point<T> b = point<T>())
      : pi(a), pf(b) {}
  long double dist(point<T> p) {
    if (pi == pf) return (p - pi).dist();
    auto d = (pf - pi).dist2();
    auto t = min(d, max(.0, (p - pi).dot(pf - pi)));
    return ((p - pi) * d - (pf - pi) * t).dist() / d;
  }
  bool on_segment(point<T> p) {
    return p.cross(pi, pf) == 0 && (pi - p).dot(pf - p) <= 0;
  }
  vector<point<T>> intersect(segment rhs) {
    auto oa = rhs.pi.cross(rhs.pf, pi), ob = rhs.pi.cross(rhs.pf, pf),
         oc = pi.cross(pf, rhs.pi), od = pi.cross(pf, rhs.pf);
    if (sign(oa) * sign(ob) < 0 && sign(oc) * sign(od) < 0)
      return {(pi * ob - pf * oa) / (ob - oa)};
    set<point<T>> s;
    if (rhs.on_segment(pi)) s.insert(pi);
    if (rhs.on_segment(pf)) s.insert(pf);
    if (on_segment(rhs.pi)) s.insert(rhs.pi);
    if (on_segment(rhs.pf)) s.insert(rhs.pf);
    return vector<point<T>>(s.begin(), s.end());
  }
};
template <class T>
struct line {
  T a, b, c;
  explicit line(point<T> p1, point<T> p2) {
    assert(!(p1 == p2));
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = a * p1.x + b * p1.y;
  }
  explicit line(T _a, T _b, T _c) : a(_a), b(_b), c(_c) {}
  long double dist(point<T> p) {
    return abs(a * p.x + b * p.y - c) / sqrt((long double)(a * a + b * b));
  }
  pair<int, point<T>> intersect(line rhs) {
    return linear_solve2(a, b, rhs.a, rhs.b, c, rhs.c);
  }
  line normalize() {
    long double d = (c < 0 ? -1 : 1);
    return line(a / d, b / d, c / d);
  }
};
template <class T>
struct circle {
  point<T> center;
  T r;
  T r2;
  int intersect(line<T> l, pair<point<T>, point<T>> &retv) {
    l.c -= l.a * center.x + l.b * center.y;
    l = l.normalize();
    point<T> v(l.a, l.b);
    point<T> p0(l.a * l.c / point<T>(l.a, l.b).dist2(),
                l.b * l.c / point<T>(l.a, l.b).dist2());
    if (p0.dist2() > r2 * (1 + EPS))
      return 0;
    else if (p0.dist2() > r2) {
      retv = {p0, p0};
      return 1;
    }
    long double d = sqrt(r2 - p0.dist2());
    retv = {center + p0 + v.normal() * d, center + p0 - v.normal() * d};
    return 2;
  }
  int intersect(circle rhs, pair<point<T>, point<T>> &retv) {
    rhs.center = rhs.center - center;
    int num =
        rhs.intersect(line<T>(2 * rhs.center.x, 2 * rhs.center.y,
                              rhs.center.x * rhs.center.x +
                                  rhs.center.y * rhs.center.y + r2 - rhs.r2),
                      retv);
    retv.first = retv.first + center;
    retv.second = retv.second + center;
    return num;
  }
  pair<point<T>, point<T>> tangents(point<T> p) {
    p = p - center;
    long double k1 = r * r / p.dist2();
    long double k2 = sqrt(k1 - k1 * k1);
    return {center + p * k1 + p.perp() * k2, center + p * k1 - p.perp() * k2};
  }
};
circle<long double> circumcircle(const point<long double> &A,
                                 const point<long double> &B,
                                 const point<long double> &C) {
  circle<long double> retv;
  point<long double> a = C - B, b = C - A, c = B - A;
  retv.r = a.dist() * b.dist() * c.dist() / abs(c.cross(b)) / 2;
  retv.center = A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
  return retv;
}
int n;
point<long long> p[112345];
long long d[112345];
point<long double> center;
set<point<long long>> ans;
long long tmp_d[112345];
void check(point<long long> b) {
  for (int i = 0; i < n; i++)
    tmp_d[i] =
        ((b.x - p[i].x) * (b.x - p[i].x) + (b.y - p[i].y) * (b.y - p[i].y));
  sort(tmp_d, tmp_d + n);
  for (int i = 0; i < n; i++)
    if (d[i] != tmp_d[i]) return;
  ans.insert(b);
}
template <class T>
ostream &operator<<(ostream &os, point<T> p) {
  return os << "(" << p.x << ", " << p.y << ")";
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
  for (int i = 0; i < n; i++) center.x += p[i].x;
  for (int i = 0; i < n; i++) center.y += p[i].y;
  cerr << fixed << setprecision(10);
  int q;
  cin >> q;
  while (q--) {
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d, d + n);
    circle<long double> c;
    c.center = point<long double>(0, 0);
    c.r2 = 0;
    for (int i = 0; i < n; i++)
      c.r2 += (n * 1.0L * n * d[i] -
               (n * p[i].x - center.x) * (n * p[i].x - center.x) -
               (n * p[i].y - center.y) * (n * p[i].y - center.y));
    c.r2 /= n;
    c.r = sqrt(c.r2);
    ans.clear();
    for (int i = 0; i < n; i++) {
      circle<long double> c2;
      c2.center = point<long double>(n * p[0].x, n * p[0].y) - center;
      c2.r2 = n * 1.0L * n * d[i];
      c2.r = sqrt(c2.r2);
      pair<point<long double>, point<long double>> pts;
      if (c2.intersect(c, pts) > 0) {
        point<long double> tmp = (pts.first + center) / n;
        int lim = 16;
        for (int j = -lim; j <= lim; j++)
          for (int k = -lim; k <= lim; k++) {
            point<long long> u(tmp.x + j, tmp.y + k);
            if ((u - p[0]).dist2() == d[i]) check(u);
          }
        tmp = (pts.second + center) / n;
        for (int j = -lim; j <= lim; j++)
          for (int k = -lim; k <= lim; k++) {
            point<long long> u(tmp.x + j, tmp.y + k);
            if ((u - p[0]).dist2() == d[i]) check(u);
          }
      }
    }
    cout << ans.size();
    for (point<long long> tmp : ans) cout << " " << tmp.x << " " << tmp.y;
    cout << endl;
  }
}
