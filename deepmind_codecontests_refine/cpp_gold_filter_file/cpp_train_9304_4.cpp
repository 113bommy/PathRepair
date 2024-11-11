#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool Up(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool Down(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
inline double dcmp(double a) {
  if (a > (1e-12)) return 1;
  if (a < -(1e-12)) return -1;
  return 0;
}
inline double dcmp(double a, double b) {
  double x = a - b;
  if (x > (1e-12)) return 1;
  if (x < -(1e-12)) return -1;
  return 0;
}
struct Vec {
  double x, y;
  Vec() : x(0.0), y(0.0) {}
  Vec(double x, double y) : x(x), y(y) {}
  Vec unit() const {
    double l = abs();
    return Vec(x / l, y / l);
  }
  Vec rot90() const { return Vec(-y, x); }
  Vec rot(double alpha) const {
    return Vec(x * cos(alpha) - y * sin(alpha),
               x * sin(alpha) + y * cos(alpha));
  }
  double abs() const { return sqrt(x * x + y * y); }
  double abs2() const { return x * x + y * y; }
  double alpha() const { return atan2(y, x); }
  double cross(const Vec &, const Vec &) const;
  double dot(const Vec &, const Vec &) const;
  bool between(const Vec &, const Vec &) const;
  bool goRight(const Vec &, const Vec &) const;
  bool goLeft(const Vec &, const Vec &) const;
  bool operator<(const Vec &rhs) const {
    int c = dcmp(x, rhs.x);
    if (c) return c < 0;
    return dcmp(y, rhs.y) < 0;
  }
};
inline Vec operator+(const Vec &lhs, const Vec &rhs) {
  return Vec(lhs.x + rhs.x, lhs.y + rhs.y);
}
inline Vec operator-(const Vec &lhs, const Vec &rhs) {
  return Vec(lhs.x - rhs.x, lhs.y - rhs.y);
}
inline Vec operator-(const Vec &lhs) { return Vec(-lhs.x, -lhs.y); }
inline Vec operator*(const Vec &v, const double &k) {
  return Vec(k * v.x, k * v.y);
}
inline Vec operator*(const double &k, const Vec &v) {
  return Vec(k * v.x, k * v.y);
}
inline Vec operator/(const Vec &v, const double &k) {
  return Vec(v.x / k, v.y / k);
}
inline double cross(const Vec &lhs, const Vec &rhs) {
  return lhs.x * rhs.y - lhs.y * rhs.x;
}
inline double dot(const Vec &lhs, const Vec &rhs) {
  return lhs.x * rhs.x - lhs.y * rhs.y;
}
inline ostream &operator<<(ostream &os, const Vec &v) {
  os << "(" << v.x << ", " << v.y << ")";
  return os;
}
inline istream &operator>>(istream &is, Vec &v) {
  is >> v.x >> v.y;
  return is;
}
inline double Vec::cross(const Vec &l, const Vec &r) const {
  return ::cross(l - *this, r - *this);
}
inline double Vec::dot(const Vec &l, const Vec &r) const {
  return ::dot(l - *this, r - *this);
}
inline bool Vec::between(const Vec &a, const Vec &b) const {
  return dcmp(::dot(a - *this, b - *this)) <= 0;
}
inline bool Vec::goRight(const Vec &a, const Vec &b) const {
  return dcmp(::cross(a - *this, b - *this)) > 0;
}
inline bool Vec::goLeft(const Vec &a, const Vec &b) const {
  return dcmp(::cross(a - *this, b - *this)) < 0;
}
inline bool cmpByXY(const Vec &lhs, const Vec &rhs) {
  int c = dcmp(lhs.x, rhs.x);
  if (c) return c < 0;
  return dcmp(lhs.y, rhs.y) < 0;
}
int iCnt;
inline int segCross(const Vec &a, const Vec &b, const Vec &c, const Vec &d,
                    Vec &o) {
  double s1, s2, s3, s4;
  int d1 = dcmp(s1 = a.cross(b, c)), d2 = dcmp(s2 = a.cross(b, d));
  int d3 = dcmp(s3 = c.cross(d, a)), d4 = dcmp(s4 = c.cross(d, b));
  if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) {
    o = (c * s2 - d * s1) / (s2 - s1);
    return 1;
  }
  iCnt = 0;
  if (d1 == 0 && c.between(a, b)) ++iCnt;
  if (d2 == 0 && d.between(a, b)) ++iCnt;
  if (d3 == 0 && a.between(c, d)) ++iCnt;
  if (d4 == 0 && b.between(c, d)) ++iCnt;
  return iCnt ? 2 : 0;
}
inline Vec getIntersection(const Vec &a, const Vec &b, const Vec &c,
                           const Vec &d) {
  double s1 = c.cross(d, a), s2 = c.cross(b, d);
  return (a * s2 + b * s1) / (s1 + s2);
}
vector<Vec> convexCut(const vector<Vec> &ps, Vec q1, Vec q2) {
  vector<Vec> qs;
  int n = ps.size();
  for (int i = (0); i < (n); ++i) {
    const Vec &p1 = ps[i], &p2 = ps[i + 1 == n ? 0 : i + 1];
    int d1 = dcmp(q1.cross(q2, p1)), d2 = dcmp(q1.cross(q2, p2));
    if (d1 >= 0) qs.push_back(p1);
    if ((d1 ^ d2) == -2) qs.push_back(getIntersection(p1, p2, q1, q2));
  }
  return qs;
}
double polyArea(const vector<Vec> &p) {
  int n = p.size();
  double a = 0;
  for (int i = (0); i < (n); ++i) a += cross(p[i], p[i + 1 == n ? 0 : i + 1]);
  return fabs(a * 0.5);
}
vector<Vec> convexHull(vector<Vec> P) {
  int n = P.size(), top = -1, len;
  if (n <= 1) return P;
  vector<Vec> Stack(n + 1);
  sort(P.begin(), P.end());
  for (int i = (0); i < (n); ++i) {
    while (top > 0 && !Stack[top - 1].goRight(Stack[top], P[i])) --top;
    Stack[++top] = P[i];
  }
  len = top;
  Stack[++top] = P[n - 2];
  for (int i = (n - 3); i >= (0); --i) {
    while (top > len && !Stack[top - 1].goRight(Stack[top], P[i])) --top;
    Stack[++top] = P[i];
  }
  Stack.resize(top);
  return Stack;
}
double convexDiameter(const vector<Vec> &ps) {
  int n = ps.size();
  int is = 0, js = 0;
  for (int i = (1); i < (n); ++i) {
    if (ps[i].x > ps[is].x) is = i;
    if (ps[i].x < ps[js].x) js = i;
  }
  double maxd = (ps[is] - ps[js]).abs();
  int i = is, j = js;
  do {
    int ni = i + 1 == n ? 0 : i + 1;
    int nj = j + 1 == n ? 0 : j + 1;
    if (dcmp(cross(ps[ni] - ps[i], ps[nj] - ps[j])) >= 0)
      j = nj;
    else
      i = ni;
    maxd = max(maxd, (ps[i] - ps[j]).abs());
  } while (i != is || j != js);
  return maxd;
}
namespace HPI {
int n = 0, qh, qt;
const int MAX_BORDER = 123;
struct Border {
  Vec p1, p2;
  long double alpha;
  void set(const Vec &_p1, const Vec &_p2) {
    p1 = _p1;
    p2 = _p2;
    alpha = atan2(p2.y - p1.y, p2.x - p1.x);
  }
} border[MAX_BORDER], que[MAX_BORDER];
bool operator<(const Border &a, const Border &b) {
  int c = dcmp(a.alpha - b.alpha);
  if (c) return c > 0;
  return b.p1.goRight(b.p2, a.p1);
}
bool operator==(const Border &a, const Border &b) {
  return dcmp(a.alpha - b.alpha) == 0;
}
void add(long double x, long double y, long double nx, long double ny) {
  border[n++].set(Vec(x, y), Vec(nx, ny));
}
void add(Vec p1, Vec p2) { border[n++].set(p1, p2); }
Vec isBorder(const Border &a, const Border &b) {
  return getIntersection(a.p1, a.p2, b.p1, b.p2);
}
bool check(const Border &a, const Border &b, const Border &me) {
  return me.p1.goRight(me.p2, getIntersection(a.p1, a.p2, b.p1, b.p2));
}
void convexIntersection() {
  qh = qt = 0;
  sort(border, border + n);
  n = unique(border, border + n) - border;
  for (int i = (0); i < (n); ++i) {
    Border cur = border[i];
    while (qh + 1 < qt && !check(que[qt - 2], que[qt - 1], cur)) --qt;
    while (qh + 1 < qt && !check(que[qh], que[qh + 1], cur)) ++qh;
    que[qt++] = cur;
  }
  while (qh + 1 < qt && !check(que[qt - 2], que[qt - 1], que[qh])) --qt;
  while (qh + 1 < qt && !check(que[qh], que[qh + 1], que[qt - 1])) ++qh;
}
vector<Vec> getConvexHull() {
  vector<Vec> res;
  if (qt - qh <= 2) return res;
  for (int i = qh; i < qt; ++i) {
    int next = i + 1 == qt ? qh : i + 1;
    res.push_back(isBorder(que[i], que[next]));
  }
  return res;
}
}  // namespace HPI
double h, w, a;
Vec A, B, C, D;
Vec AA, BB, CC, DD;
int main() {
  scanf("%lf %lf %lf", &w, &h, &a);
  a = a / 180 * M_PI;
  A = Vec(-0.5 * w, 0.5 * h);
  B = Vec(0.5 * w, 0.5 * h);
  C = Vec(0.5 * w, -0.5 * h);
  D = Vec(-0.5 * w, -0.5 * h);
  AA = A.rot(a);
  BB = B.rot(a);
  CC = C.rot(a);
  DD = D.rot(a);
  HPI::add(D, C);
  HPI::add(C, B);
  HPI::add(B, A);
  HPI::add(A, D);
  HPI::add(DD, CC);
  HPI::add(CC, BB);
  HPI::add(BB, AA);
  HPI::add(AA, DD);
  HPI::convexIntersection();
  printf("%.9f\n", polyArea(HPI::getConvexHull()));
  return 0;
}
