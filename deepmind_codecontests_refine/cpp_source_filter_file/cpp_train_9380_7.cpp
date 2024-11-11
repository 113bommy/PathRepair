#include <bits/stdc++.h>
using namespace std;
const long double pi = acosl(-1);
const long double radian = 180 / pi;
const long double eps = 1e-12;
const int inf = 0x7f7f7f7f;
const long long infll = 0x7f7f7f7f7f7f7f7fll;
const long double infl = 1e20;
inline int sgn(const long double &x) { return (x > eps) - (x < -eps); }
inline int sgn(const long long &x) { return (x > 0) - (x < 0); }
inline long double sqr(const long double &x) { return x * x; }
inline long long sqr(const long long &x) { return x * x; }
inline long double refresh(const long double &x) {
  if (x < -1 + eps)
    return -1;
  else if (x > 1 - eps)
    return 1;
  else
    return x;
}
struct Point {
  long double x, y;
  Point() : x(0), y(0) {}
  Point(const long double &x, const long double &y) : x(x), y(y) {}
  long double angle() const { return atan2l(y, x); }
  long double angle(const Point &lhs, const Point &rhs) const {
    return (lhs - *this) ^ (rhs - *this);
  }
  long double length() const { return sqrtl(sqr(x) + sqr(y)); }
  long double length2() const { return sqr(x) + sqr(y); }
  long double distance(const Point &rhs) const {
    return (rhs - *this).length();
  }
  long double distance2(const Point &rhs) const {
    return (rhs - *this).length2();
  }
  Point rotate(const long double &a) const {
    long double c = cosl(a), s = sinl(a);
    return Point(x * c - y * s, x * s + y * c);
  }
  Point polar(const long double &r, const long double &t) const {
    return Point(x + r * cosl(t), y + r * sinl(t));
  }
  Point conjugate() const { return Point(x, -y); }
  Point unit(const long double &n = 1) const {
    long double l = length();
    return sgn(l) == 0 ? Point(n, 0) : Point(x / l * n, y / l * n);
  }
  Point normal(const bool &lft = true) const {
    return lft ? Point(-y, x) : Point(y, -x);
  }
  Point moderate() const { return *this * (this->quadrant() <= 4 ? -1 : 1); }
  long double vect(const Point &lhs, const Point &rhs) const {
    return (lhs - *this) * (rhs - *this);
  }
  long double scal(const Point &lhs, const Point &rhs) const {
    return (lhs - *this) & (rhs - *this);
  }
  Point project(const Point &p, const Point &q) const {
    return p + (q - p) * p.scal(q, *this) / p.distance2(q);
  }
  Point mirror(const Point &p, const Point &q) const {
    return this->project(p, q) * 2 - *this;
  }
  long double distance_to_line(const Point &p, const Point &q) const {
    return fabsl(p.vect(q, *this) / p.distance(q));
  }
  long double distance_to_segment(const Point &p, const Point &q) const {
    if (p.scal(q, *this) < 0)
      return p.distance(*this);
    else if (q.scal(p, *this) < 0)
      return q.distance(*this);
    else
      return this->distance_to_line(p, q);
  }
  bool on_line(const Point &p, const Point &q) const {
    return sgn(this->vect(p, q)) == 0;
  }
  bool on_halfline(const Point &p, const Point &q,
                   const bool &inclusive = true) const {
    if (*this == p)
      return inclusive;
    else
      return this->on_line(p, q) && sgn(p.scal(q, *this)) >= 0;
  }
  bool on_segment(const Point &p, const Point &q,
                  const bool &inclusive = true) const {
    if (*this == p || *this == q)
      return inclusive;
    else
      return this->on_line(p, q) && sgn(this->scal(p, q)) <= 0;
  }
  bool in_triangle(const Point &u, const Point &v, const Point &w,
                   const bool &inclusive = true) const {
    Point p[3] = {u, v, w};
    if (sgn(u.vect(v, w)) < 0) reverse(p, p + 3);
    for (int i = 0; i < 3; i++) {
      if (this->on_segment(p[i], p[(i + 1) % 3]))
        return inclusive;
      else if (sgn(this->vect(p[i], p[(i + 1) % 3])) < 0)
        return false;
    }
    return true;
  }
  bool in_angle(const Point &o, const Point &p, const Point &q,
                const bool &inclusive = true) const {
    if (this->on_halfline(o, p) || this->on_halfline(o, q)) return inclusive;
    int vp = sgn(o.vect(p, *this)), vq = sgn(o.vect(*this, q));
    if (sgn(o.vect(p, q)) >= 0)
      return vp > 0 && vq > 0;
    else
      return vp > 0 || vq > 0;
  }
  Point operator+(const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator-(const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  Point operator*(const long double &rhs) const {
    return Point(x * rhs, y * rhs);
  }
  Point operator/(const long double &rhs) const {
    return Point(x / rhs, y / rhs);
  }
  long double operator*(const Point &rhs) const {
    return x * rhs.y - y * rhs.x;
  }
  long double operator&(const Point &rhs) const {
    return x * rhs.x + y * rhs.y;
  }
  Point operator<<(const Point &rhs) const {
    return Point(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
  }
  Point operator>>(const Point &rhs) const {
    return Point(x * rhs.x + y * rhs.y, -x * rhs.y + y * rhs.x) / rhs.length2();
  }
  long double operator^(const Point &rhs) const {
    int s = sgn(*this * rhs);
    long double a = acosl(
        refresh((long double)(*this & rhs) / this->length() / rhs.length()));
    return s < 0 ? -a : a;
  }
  bool operator==(const Point &rhs) const {
    return sgn(x - rhs.x) == 0 && sgn(y - rhs.y) == 0;
  }
  int quadrant() const {
    int xs = sgn(x), ys = sgn(y);
    if (xs == 0 && ys == 0)
      return 0;
    else if (xs < 0 && ys < 0)
      return 1;
    else if (xs == 0 && ys < 0)
      return 2;
    else if (xs > 0 && ys < 0)
      return 3;
    else if (xs > 0 && ys == 0)
      return 4;
    else if (xs > 0 && ys > 0)
      return 5;
    else if (xs == 0 && ys > 0)
      return 6;
    else if (xs < 0 && ys > 0)
      return 7;
    else
      return 8;
  }
  bool operator<(const Point &rhs) const {
    int lq = quadrant(), rq = rhs.quadrant();
    if (lq != rq)
      return lq < rq;
    else {
      int s = sgn(*this * rhs);
      return s != 0 ? s > 0 : sgn(length2() - rhs.length2()) < 0;
    }
  }
  bool on_left(const Point &rhs, const bool &inclusive = true) const {
    int s = sgn(*this * rhs), t = sgn(*this & rhs);
    return s == 0 ? t >= 0 || inclusive : s > 0;
  }
  bool on_right(const Point &rhs, const bool &inclusive = true) const {
    int s = sgn(*this * rhs), t = sgn(*this & rhs);
    return s == 0 ? t >= 0 || inclusive : s < 0;
  }
};
inline bool xycmp(const Point &lhs, const Point &rhs) {
  if (sgn(lhs.x - rhs.x) != 0)
    return lhs.x < rhs.x;
  else
    return lhs.y < rhs.y;
}
inline bool yxcmp(const Point &lhs, const Point &rhs) {
  if (sgn(lhs.y - rhs.y) != 0)
    return lhs.y < rhs.y;
  else
    return lhs.x < rhs.x;
}
const int maxN = 100000;
int N;
int d1, d2;
Point A[maxN], B[maxN];
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  cin >> d1 >> d2;
  for (int i = 0; i < N; i++) cin >> A[i].x >> A[i].y >> B[i].x >> B[i].y;
  int ans = 0;
  bool flg = true;
  for (int i = 0; i < N - 1; i++) {
    Point C = B[i + 1] - A[i + 1] + A[i];
    if (sgn(A[i].distance(B[i]) - d2) > 0) flg = true;
    if (B[i] == C) {
      if (flg && sgn(A[i].distance(B[i]) - d1) == 0) {
        flg = false;
        ans++;
      }
    } else {
      if (flg && sgn(A[i].distance_to_segment(B[i], C) - d1) <= 0) {
        flg = false;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
