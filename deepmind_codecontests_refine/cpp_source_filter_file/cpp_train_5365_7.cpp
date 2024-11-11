#include <bits/stdc++.h>
using namespace std;
const long double pi = acosl(-1);
const long double radian = 180 / pi;
const long double eps = 1e-12;
inline int sgn(const long double &x) {
  if (fabsl(x) < eps)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
inline int sgn(const long long &x) {
  if (x == 0)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
inline long long sqr(const long long &x) { return x * x; }
inline long double refresh(const long double &x) {
  if (x < -1 + eps)
    return -1;
  else if (x > 1 - eps)
    return 1;
  else
    return x;
}
class Point {
 public:
  long long x, y;
  Point(void) : x(0), y(0) {}
  Point(const long long &x, const long long &y) : x(x), y(y) {}
  long double length(void) const { return sqrtl(sqr(x) + sqr(y)); }
  long long length2(void) const { return sqr(x) + sqr(y); }
  long double distance(const Point &rhs) const {
    return sqrtl(sqr(rhs.x - x) + sqr(rhs.y - y));
  }
  long double distance2(const Point &rhs) const {
    return sqr(rhs.x - x) + sqr(rhs.y - y);
  }
  Point conjugate(void) const { return Point(x, -y); }
  Point normal(const bool &lft = true) const {
    return lft ? Point(-y, x) : Point(y, -x);
  }
  long long vect(const Point &lhs, const Point &rhs) const {
    return (lhs - *this) * (rhs - *this);
  }
  long long scal(const Point &lhs, const Point &rhs) const {
    return (lhs - *this) & (rhs - *this);
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
    return sgn(p.vect(q, *this)) == 0;
  }
  bool on_segment(const Point &p, const Point &q) const {
    return on_line(p, q) && sgn((p.x - x) * (q.x - x)) <= 0 &&
           sgn((p.y - y) * (q.y - y)) <= 0;
  }
  Point operator+(const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator-(const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  Point operator*(const long long &rhs) const {
    return Point(x * rhs, y * rhs);
  }
  Point operator/(const long long &rhs) const {
    return Point(x / rhs, y / rhs);
  }
  long long operator*(const Point &rhs) const { return x * rhs.y - y * rhs.x; }
  long long operator&(const Point &rhs) const { return x * rhs.x + y * rhs.y; }
  Point operator<<(const Point &rhs) const {
    return Point(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
  }
  long double operator^(const Point &rhs) const {
    int s = sgn(*this * rhs);
    long double a = acosl(
        refresh((long double)(*this & rhs) / this->length() / rhs.length()));
    return s < 0 ? -a : a;
  }
  bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
  inline int quadrant(void) const {
    if (x == 0 && y == 0)
      return 0;
    else if (x < 0 && y < 0)
      return 1;
    else if (x == 0 && y < 0)
      return 2;
    else if (x > 0 && y < 0)
      return 3;
    else if (x > 0 && y == 0)
      return 4;
    else if (x > 0 && y > 0)
      return 5;
    else if (x == 0 && y > 0)
      return 6;
    else if (x < 0 && y > 0)
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
    long long s = *this * rhs, t = *this & rhs;
    return s == 0 ? t >= 0 || inclusive : s > 0;
  }
  bool on_right(const Point &rhs, const bool &inclusive = true) const {
    long long s = *this * rhs, t = *this & rhs;
    return s == 0 ? t >= 0 || inclusive : s < 0;
  }
};
const int maxn = 2000;
int n;
Point p[maxn];
Point q[maxn * (maxn - 1) / 2];
int main(void) {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  int sz = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      q[sz++] = p[j] - p[i];
      if (q[sz - 1].quadrant() <= 4) q[sz - 1] = q[sz - 1] * -1;
    }
  }
  sort(q, q + sz);
  long long ans = 0;
  for (int i = 0; i < sz;) {
    int j = i + 1;
    for (; j < sz && q[i] * q[j] == 0; ++j)
      ;
    ans += (long long)(j - i) * (j - i - 1) / 2;
    i = j;
  }
  ans /= 2;
  cout << ans << endl;
  return 0;
}
