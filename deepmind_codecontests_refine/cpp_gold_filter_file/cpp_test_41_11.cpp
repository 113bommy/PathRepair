#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
template <class T>
inline T &RD(T &);
template <class T>
inline void OT(const T &);
inline long long RD() {
  long long x;
  return RD(x);
}
inline double &RF(double &);
inline double RF() {
  double x;
  return RF(x);
}
inline char *RS(char *s);
inline char &RC(char &c);
inline char RC();
inline char &RC(char &c) {
  scanf(" %c", &c);
  return c;
}
inline char RC() {
  char c;
  return RC(c);
}
template <class T>
inline T &RDD(T &);
inline long long RDD() {
  long long x;
  return RDD(x);
}
template <class T0, class T1>
inline T0 &RD(T0 &x0, T1 &x1) {
  RD(x0), RD(x1);
  return x0;
}
template <class T0, class T1, class T2>
inline T0 &RD(T0 &x0, T1 &x1, T2 &x2) {
  RD(x0), RD(x1), RD(x2);
  return x0;
}
template <class T0, class T1, class T2, class T3>
inline T0 &RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3) {
  RD(x0), RD(x1), RD(x2), RD(x3);
  return x0;
}
template <class T0, class T1, class T2, class T3, class T4>
inline T0 &RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4);
  return x0;
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline T0 &RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);
  return x0;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline T0 &RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);
  return x0;
}
template <class T0, class T1>
inline void OT(const T0 &x0, const T1 &x1) {
  OT(x0), OT(x1);
}
template <class T0, class T1, class T2>
inline void OT(const T0 &x0, const T1 &x1, const T2 &x2) {
  OT(x0), OT(x1), OT(x2);
}
template <class T0, class T1, class T2, class T3>
inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3) {
  OT(x0), OT(x1), OT(x2), OT(x3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3,
               const T4 &x4) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3,
               const T4 &x4, const T5 &x5) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3,
               const T4 &x4, const T5 &x5, const T6 &x6) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);
}
inline char &RC(char &a, char &b) {
  RC(a), RC(b);
  return a;
}
inline char &RC(char &a, char &b, char &c) {
  RC(a), RC(b), RC(c);
  return a;
}
inline char &RC(char &a, char &b, char &c, char &d) {
  RC(a), RC(b), RC(c), RC(d);
  return a;
}
inline char &RC(char &a, char &b, char &c, char &d, char &e) {
  RC(a), RC(b), RC(c), RC(d), RC(e);
  return a;
}
inline char &RC(char &a, char &b, char &c, char &d, char &e, char &f) {
  RC(a), RC(b), RC(c), RC(d), RC(e), RC(f);
  return a;
}
inline char &RC(char &a, char &b, char &c, char &d, char &e, char &f, char &g) {
  RC(a), RC(b), RC(c), RC(d), RC(e), RC(f), RC(g);
  return a;
}
inline double &RF(double &a, double &b) {
  RF(a), RF(b);
  return a;
}
inline double &RF(double &a, double &b, double &c) {
  RF(a), RF(b), RF(c);
  return a;
}
inline double &RF(double &a, double &b, double &c, double &d) {
  RF(a), RF(b), RF(c), RF(d);
  return a;
}
inline double &RF(double &a, double &b, double &c, double &d, double &e) {
  RF(a), RF(b), RF(c), RF(d), RF(e);
  return a;
}
inline double &RF(double &a, double &b, double &c, double &d, double &e,
                  double &f) {
  RF(a), RF(b), RF(c), RF(d), RF(e), RF(f);
  return a;
}
inline double &RF(double &a, double &b, double &c, double &d, double &e,
                  double &f, double &g) {
  RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g);
  return a;
}
inline void RS(char *s1, char *s2) { RS(s1), RS(s2); }
inline void RS(char *s1, char *s2, char *s3) { RS(s1), RS(s2), RS(s3); }
template <class T0, class T1>
inline T0 &RDD(T0 &a, T1 &b) {
  RDD(a), RDD(b);
  return a;
}
template <class T0, class T1, class T2>
inline T1 &RDD(T0 &a, T1 &b, T2 &c) {
  RDD(a), RDD(b), RDD(c);
  return a;
}
template <class T>
inline void RST(T &A) {
  memset(A, 0, sizeof(A));
}
template <class T>
inline void FLC(T &A, int x) {
  memset(A, x, sizeof(A));
}
template <class T>
inline void CLR(T &A) {
  A.clear();
}
template <class T0, class T1>
inline void RST(T0 &A0, T1 &A1) {
  RST(A0), RST(A1);
}
template <class T0, class T1, class T2>
inline void RST(T0 &A0, T1 &A1, T2 &A2) {
  RST(A0), RST(A1), RST(A2);
}
template <class T0, class T1, class T2, class T3>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3) {
  RST(A0), RST(A1), RST(A2), RST(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4) {
  RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5) {
  RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6) {
  RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);
}
template <class T0, class T1>
inline void FLC(T0 &A0, T1 &A1, int x) {
  FLC(A0, x), FLC(A1, x);
}
template <class T0, class T1, class T2>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, int x) {
  FLC(A0, x), FLC(A1, x), FLC(A2, x);
}
template <class T0, class T1, class T2, class T3>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, int x) {
  FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, int x) {
  FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, int x) {
  FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6, int x) {
  FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x),
      FLC(A6, x);
}
template <class T>
inline void CLR(priority_queue<T> &Q) {
  while (!Q.empty()) Q.pop();
}
template <class T>
inline void CLR(stack<T> &S) {
  while (!S.empty()) S.pop();
}
template <class T>
inline void CLR(queue<T> &Q) {
  while (!Q.empty()) Q.pop();
}
template <class T0, class T1>
inline void CLR(T0 &A0, T1 &A1) {
  CLR(A0), CLR(A1);
}
template <class T0, class T1, class T2>
inline void CLR(T0 &A0, T1 &A1, T2 &A2) {
  CLR(A0), CLR(A1), CLR(A2);
}
template <class T0, class T1, class T2, class T3>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);
}
template <class T>
inline void CLR(T &A, int n) {
  for (int i = 0; i < n; ++i) CLR(A[i]);
}
template <class T>
inline bool EPT(T &a) {
  return a.empty();
}
template <class T>
inline T &SRT(T &A) {
  sort(A.begin(), A.end());
  return A;
}
template <class T, class C>
inline T &SRT(T &A, C cmp) {
  sort(A.begin(), A.end(), cmp);
  return A;
}
template <class T>
inline T &RVS(T &A) {
  reverse(A.begin(), A.end());
  return A;
}
template <class T>
inline T &UNQQ(T &A) {
  A.resize(unique(A.begin(), A.end()) - A.begin());
  return A;
}
template <class T>
inline T &UNQ(T &A) {
  SRT(A);
  return UNQQ(A);
}
template <class T, class C>
inline T &UNQ(T &A, C cmp) {
  SRT(A, cmp);
  return UNQQ(A);
}
const int MOD = int(1e9) + 7;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
const double OO = 1e20;
const double PI = acos(-1.0);
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
template <class T>
inline bool checkMin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool checkMax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class C>
inline bool checkUpd(T &a, const T b, C c) {
  return c(b, a) ? a = b, 1 : 0;
}
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T min(T a, T b, T c, T d) {
  return min(min(a, b), min(c, d));
}
template <class T>
inline T max(T a, T b, T c, T d) {
  return max(max(a, b), max(c, d));
}
template <class T>
inline T min(T a, T b, T c, T d, T e) {
  return min(min(min(a, b), min(c, d)), e);
}
template <class T>
inline T max(T a, T b, T c, T d, T e) {
  return max(max(max(a, b), max(c, d)), e);
}
template <class T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline T cub(T a) {
  return a * a * a;
}
template <class T>
inline T ceil(T x, T y) {
  return (x - 1) / y + 1;
}
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
inline int sgn(double x) { return x < -EPS ? -1 : x > EPS; }
inline int sgn(double x, double y) { return sgn(x - y); }
inline double cos(double a, double b, double c) {
  return (sqr(a) + sqr(b) - sqr(c)) / (2 * a * b);
}
inline double cot(double x) { return 1. / tan(x); };
inline double sec(double x) { return 1. / cos(x); };
inline double csc(double x) { return 1. / sin(x); };
namespace CG {
inline double dist2(double x, double y) { return sqr(x) + sqr(y); }
struct Po {
  double x, y;
  Po(double x = 0, double y = 0) : x(x), y(y) {}
  void in() { RF(x, y); }
  void out() { printf("(%.2f,%.2f)", x, y); }
  inline friend istream &operator>>(istream &i, Po &p) {
    return i >> p.x >> p.y;
  }
  inline friend ostream &operator<<(ostream &o, Po p) {
    return o << "(" << p.x << ", " << p.y << ")";
  }
  Po operator-() const { return Po(-x, -y); }
  Po &operator+=(const Po &p) {
    x += p.x, y += p.y;
    return *this;
  }
  Po &operator-=(const Po &p) {
    x -= p.x, y -= p.y;
    return *this;
  }
  Po &operator*=(double k) {
    x *= k, y *= k;
    return *this;
  }
  Po &operator/=(double k) {
    x /= k, y /= k;
    return *this;
  }
  Po &operator*=(const Po &p) { return *this = *this * p; }
  Po &operator/=(const Po &p) { return *this = *this / p; }
  Po operator+(const Po &p) const { return Po(x + p.x, y + p.y); }
  Po operator-(const Po &p) const { return Po(x - p.x, y - p.y); }
  Po operator*(double k) const { return Po(x * k, y * k); }
  Po operator/(double k) const { return Po(x / k, y / k); }
  Po operator*(const Po &p) const {
    return Po(x * p.x - y * p.y, y * p.x + x * p.y);
  }
  Po operator/(const Po &p) const {
    return Po(x * p.x + y * p.y, y * p.x - x * p.y) / p.len2();
  }
  bool operator==(const Po &p) const { return !sgn(x, p.x) && !sgn(y, p.y); };
  bool operator!=(const Po &p) const { return sgn(x, p.x) || sgn(y, p.y); }
  bool operator<(const Po &p) const {
    return sgn(x, p.x) < 0 || !sgn(x, p.x) && sgn(y, p.y) < 0;
  }
  bool operator<=(const Po &p) const {
    return sgn(x, p.x) < 0 || !sgn(x, p.x) && sgn(y, p.y) <= 0;
  }
  bool operator>(const Po &p) const { return !(*this <= p); }
  bool operator>=(const Po &p) const { return !(*this < p); }
  double len2() const { return dist2(x, y); }
  double len() const { return sqrt(len2()); }
  double arg() const { return atan2(y, x); }
  Po &_1() { return *this /= len(); }
  Po &conj() {
    y = -y;
    return *this;
  }
  Po &lt() {
    swap(x, y), x = -x;
    return *this;
  }
  Po &rt() {
    swap(x, y), y = -y;
    return *this;
  }
  Po &rot(double a, const Po &o = Po()) {
    *this -= o;
    *this *= Po(cos(a), sin(a));
    return *this += o;
  }
  inline int q() const { return (y > 0 || y == 0 && x >= 0) ? 0 : 1; }
};
inline double dot(double x1, double y1, double x2, double y2) {
  return x1 * x2 + y1 * y2;
}
inline double dot(const Po &a, const Po &b) { return dot(a.x, a.y, b.x, b.y); }
inline double dot(const Po &p0, const Po &p1, const Po &p2) {
  return dot(p1 - p0, p2 - p0);
}
inline double det(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
inline double det(const Po &a, const Po &b) { return det(a.x, a.y, b.x, b.y); }
inline double det(const Po &p0, const Po &p1, const Po &p2) {
  return det(p1 - p0, p2 - p0);
}
inline double ang(const Po &p0, const Po &p1) {
  return acos(dot(p0, p1) / p0.len() / p1.len());
}
inline double ang(const Po &p0, const Po &p1, const Po &p2) {
  return ang(p1 - p0, p2 - p0);
}
inline double ang(const Po &p0, const Po &p1, const Po &p2, const Po &p3) {
  return ang(p1 - p0, p3 - p2);
}
inline double dist2(const Po &a, const Po &b) {
  return dist2(a.x - b.x, a.y - b.y);
}
template <class T1, class T2>
inline int dett(const T1 &x, const T2 &y) {
  return sgn(det(x, y));
}
template <class T1, class T2, class T3>
inline int dett(const T1 &x, const T2 &y, const T3 &z) {
  return sgn(det(x, y, z));
}
template <class T1, class T2, class T3, class T4>
inline int dett(const T1 &x, const T2 &y, const T3 &z, const T4 &w) {
  return sgn(det(x, y, z, w));
}
template <class T1, class T2>
inline int dott(const T1 &x, const T2 &y) {
  return sgn(dot(x, y));
}
template <class T1, class T2, class T3>
inline int dott(const T1 &x, const T2 &y, const T3 &z) {
  return sgn(dot(x, y, z));
}
template <class T1, class T2, class T3, class T4>
inline int dott(const T1 &x, const T2 &y, const T3 &z, const T4 &w) {
  return sgn(dot(x, y, z, w));
}
template <class T1, class T2>
inline double arg(const T1 &x, const T2 &y) {
  double a = ang(x, y);
  return ~dett(x, y) ? a : 2 * PI - a;
}
template <class T1, class T2, class T3>
inline double arg(const T1 &x, const T2 &y, const T3 &z) {
  double a = ang(x, y, z);
  return ~dett(x, y, z) ? a : 2 * PI - a;
}
template <class T1, class T2, class T3, class T4>
inline double arg(const T1 &x, const T2 &y, const T3 &z, const T4 &w) {
  double a = ang(x, y, z, w);
  return ~dett(x, y, z, w) ? a : 2 * PI - a;
}
template <class T1, class T2>
inline double dist(const T1 &x, const T2 &y) {
  return sqrt(dist2(x, y));
}
template <class T1, class T2, class T3>
inline double dist(const T1 &x, const T2 &y, const T3 &z) {
  return sqrt(dist2(x, y, z));
}
inline Po _1(Po p) { return p._1(); }
inline Po conj(Po p) { return p.conj(); }
inline Po lt(Po p) { return p.lt(); }
inline Po rt(Po p) { return p.rt(); }
inline Po rot(Po p, double a, const Po &o = Po()) { return p.rot(a, o); }
inline Po operator*(double k, const Po &p) { return p * k; }
inline Po operator/(double k, const Po &p) { return conj(p) * k / p.len2(); }
struct Line {
  Po a, b;
  Line(const Po &a = Po(), const Po &b = Po()) : a(a), b(b) {}
  Line(double x0, double y0, double x1, double y1)
      : a(Po(x0, y0)), b(Po(x1, y1)) {}
  Line(const Line &l) : a(l.a), b(l.b) {}
  Line(double A, double B, double C) {
    C = -C;
    if (!::sgn(A))
      a = Po(0, C / B), b = Po(1, C / B);
    else if (!::sgn(B))
      a = Po(C / A, 0), b = Po(C / A, 1);
    else
      a = Po(0, C / B), b = Po(1, (C - A) / B);
  }
  void in() { a.in(), b.in(); }
  inline friend istream &operator>>(istream &i, Line &p) {
    return i >> p.a >> p.b;
  }
  inline friend ostream &operator<<(ostream &o, Line p) {
    return o << p.a << "-" << p.b;
  }
  Line operator+(const Po &x) const { return Line(a + x, b + x); }
  Line operator-(const Po &x) const { return Line(a - x, b - x); }
  Line operator*(double k) const { return Line(a * k, b * k); }
  Line operator/(double k) const { return Line(a / k, b / k); }
  Po operator*(const Line &) const;
  Po d() const { return b - a; }
  double len2() const { return d().len2(); }
  double len() const { return d().len(); }
  double arg() const { return d().arg(); }
  int sgn(const Po &p) const { return dett(a, b, p); }
  int sgn(const Line &) const;
  bool sameSgn(const Po &p1, const Po &p2) const { return sgn(p1) == sgn(p2); }
  void getEquation(double &K, double &B) const {
    K = ::sgn(a.x, b.x) ? (b.y - a.y) / (b.x - a.x) : OO;
    B = a.y - K * a.x;
  }
  void getEquation(double &A, double &B, double &C) const {
    A = a.y - b.y, B = b.x - a.x, C = det(a, b);
  }
  Line &push(double r) {
    Po v = d()._1().lt() * r;
    a += v, b += v;
    return *this;
  }
};
inline double dot(const Line &l1, const Line &l2) {
  return dot(l1.d(), l2.d());
}
inline double dot(const Line &l, const Po &p) { return dot(l.a, l.b, p); }
inline double dot(const Po &p, const Line &l) { return dot(p, l.a, l.b); }
inline double det(const Line &l1, const Line &l2) {
  return det(l1.d(), l2.d());
}
inline double det(const Line &l, const Po &p) { return det(l.a, l.b, p); }
inline double det(const Po &p, const Line &l) { return det(p, l.a, l.b); }
inline double ang(const Line &l0, const Line &l1) {
  return ang(l0.d(), l1.d());
}
inline double ang(const Line &l, const Po &p) { return ang(l.a, l.b, p); }
inline double ang(const Po &p, const Line &l) { return ang(p, l.a, l.b); }
inline int Line::sgn(const Line &l) const { return dett(*this, l); }
inline Po Line::operator*(const Line &l) const {
  return a + d() * det(a, l) / det(*this, l);
}
inline Po operator&(const Po &p, const Line &l) {
  return l * Line(p, p + l.d().lt());
}
inline Po operator%(const Po &p, const Line &l) { return p & l * 2 - p; }
inline Line push(Line l, double r) { return l.push(r); }
struct Seg : public Line {
  Seg(const Po &a = Po(), const Po &b = Po()) : Line(a, b) {}
  Seg(double x0, double y0, double x1, double y1) : Line(x0, y0, x1, y1) {}
  Seg(const Line &l) : Line(l) {}
  Seg(const Po &a, double alpha) : Line(a, alpha) {}
  Seg(double A, double B, double C) : Line(A, B, C) {}
  inline int sgn(const Po &p) const;
  inline int sgn(const Line &l) const;
  inline bool qrt(const Seg &l) const;
  inline int sgn(const Seg &l) const;
};
inline int Seg::sgn(const Po &p) const {
  if (dett(p, a, b)) return -1;
  if (a == p || b == p) return 0;
  return -dott(p, a, b);
}
inline int Seg::sgn(const Line &l) const { return sgn(*this * l); }
inline bool Seg::qrt(const Seg &l) const {
  return min(a.x, b.x) <= max(l.a.x, l.b.x) &&
         min(l.a.x, l.b.x) <= max(a.x, b.x) &&
         min(a.y, b.y) <= max(l.a.y, l.b.y) &&
         min(l.a.y, l.b.y) <= max(a.y, b.y);
}
inline int Seg::sgn(const Seg &l) const {
  if (!qrt(l)) return -1;
  int d1 = dett(a, b, l.a), d2 = dett(a, b, l.b), d3 = dett(l.a, l.b, a),
      d4 = dett(l.a, l.b, b);
  if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 1;
  return ((!d1 && dott(l.a - a, l.a - b) <= 0) ||
          (!d2 && dott(l.b - a, l.b - b) <= 0) ||
          (!d3 && dott(a - l.a, a - l.b) <= 0) ||
          (!d4 && dott(b - l.a, b - l.b) <= 0))
             ? 0
             : -1;
}
inline double dist2(const Line &l, const Po &p) {
  return sqr(fabs(det(l.d(), p - l.a))) / l.len2();
}
inline double dist2(const Line &l1, const Line &l2) {
  return dett(l1, l2) ? 0 : dist2(l1, l2.a);
}
inline double dist2(const Seg &l, const Po &p) {
  Po pa = p - l.a, pb = p - l.b;
  if (dott(l.d(), pa) <= 0) return pa.len2();
  if (dott(l.d(), pb) >= 0) return pb.len2();
  return dist2(Line(l), p);
}
inline double dist2(const Seg &s, const Line &l) {
  Po v1 = s.a - l.a, v2 = s.b - l.a;
  double d1 = det(l.d(), v1), d2 = det(l.d(), v2);
  return sgn(d1) != sgn(d2) ? 0 : sqr(min(fabs(d1), fabs(d2))) / l.len2();
}
inline double dist2(const Seg &l1, const Seg &l2) {
  if (~l1.sgn(l2))
    return 0;
  else
    return min(dist2(l2, l1.a), dist2(l2, l1.b), dist2(l1, l2.a),
               dist2(l1, l2.b));
}
template <class T1, class T2>
inline double dist2(const T1 &a, const T2 &b) {
  return dist2(b, a);
}
}  // namespace CG
using namespace CG;
template <class T>
inline T &RD(T &x) {
  char c;
  while (!isdigit((c = getchar())))
    ;
  x = c - '0';
  while (isdigit((c = getchar()))) x = x * 10 + c - '0';
  return x;
}
template <class T>
inline T &RDD(T &x) {
  char c;
  while ((c = getchar()), c != '-' && !isdigit(c))
    ;
  if (c == '-') {
    x = '0' - (c = getchar());
    while (isdigit((c = getchar()))) x = x * 10 + '0' - c;
  } else {
    x = c - '0';
    while (isdigit((c = getchar()))) x = x * 10 + c - '0';
  }
  return x;
}
inline double &RF(double &x) {
  char c;
  while ((c = getchar()), c != '-' && c != '.' && !isdigit(c))
    ;
  if (c == '-')
    if ((c = getchar()) == '.') {
      x = 0;
      double l = 1;
      while (isdigit((c = getchar()))) l /= 10, x = x * 10 + '0' - c;
      x *= l;
    } else {
      x = '0' - c;
      while (isdigit((c = getchar()))) x = x * 10 + '0' - c;
      if (c == '.') {
        double l = 1;
        while (isdigit((c = getchar()))) l /= 10, x = x * 10 + '0' - c;
        x *= l;
      }
    }
  else if (c == '.') {
    x = 0;
    double l = 1;
    while (isdigit((c = getchar()))) l /= 10, x = x * 10 + c - '0';
    x *= l;
  } else {
    x = c - '0';
    while (isdigit((c = getchar()))) x = x * 10 + c - '0';
    if (c == '.') {
      double l = 1;
      while (isdigit((c = getchar()))) l /= 10, x = x * 10 + c - '0';
      x *= l;
    }
  }
  return x;
}
inline char *RS(char *s) {
  scanf("%s", s);
  return s;
}
int last_ans;
int Case;
template <class T>
inline void OT(const T &x) {
  printf("%d\n", x);
}
const int N = int(1e3) + 9;
int col[N][N];
int n, k, c;
void gao(vector<int> &V, int c) {
  if (c == 1) {
    for (int i = 0; i < int((V).size()); ++i)
      for (int j = i + 1; j < int((V).size()); ++j) {
        col[V[i]][V[j]] = 1;
        col[V[j]][V[i]] = 1;
      }
    return;
  }
  vector<vector<int> > VV;
  VV.resize(k);
  int vi = 0;
  int vn = ceil(int((V).size()), k);
  for (int i = 0; i < int((V).size()); ++i) {
    VV[vi].push_back(V[i]);
    if (int((VV[vi]).size()) == vn) ++vi;
  }
  for (int i = 0; i < k; ++i)
    for (int j = i + 1; j < k; ++j) {
      for (auto vi : VV[i])
        for (auto vj : VV[j]) {
          col[vi][vj] = c;
          col[vj][vi] = c;
        }
    }
  --c;
  for (int i = 0; i < k; ++i)
    if (int((VV[i]).size())) gao(VV[i], c);
}
int main() {
  RD(n, k);
  c = 1;
  while (pow(k, c) < n) ++c;
  cout << c << endl;
  vector<int> V;
  for (int i = 0; i < n; ++i) V.push_back(i);
  gao(V, c);
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) printf("%d ", col[i][j]);
}
