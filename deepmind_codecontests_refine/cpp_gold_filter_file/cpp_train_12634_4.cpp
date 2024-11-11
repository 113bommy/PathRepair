#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:36777216")
template <class T>
inline T &RD(T &);
template <class T>
inline void OT(const T &);
inline long long RD() {
  long long x;
  return RD(x);
}
inline char &RC(char &c) {
  scanf(" %c", &c);
  return c;
}
inline char RC() {
  char c;
  return RC(c);
}
inline double &RF(double &x) {
  scanf("%lf", &x);
  return x;
}
inline double RF() {
  double x;
  return RF(x);
}
inline char *RS(char *s) {
  scanf("%s", s);
  return s;
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
inline void OT(T0 &x0, T1 &x1) {
  OT(x0), OT(x1);
}
template <class T0, class T1, class T2>
inline void OT(T0 &x0, T1 &x1, T2 &x2) {
  OT(x0), OT(x1), OT(x2);
}
template <class T0, class T1, class T2, class T3>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3) {
  OT(x0), OT(x1), OT(x2), OT(x3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6) {
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
template <class T>
inline void RST(T &A) {
  memset(A, 0, sizeof(A));
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
template <class T>
inline void FLC(T &A, int x) {
  memset(A, x, sizeof(A));
}
template <class T0, class T1>
inline void FLC(T0 &A0, T1 &A1, int x) {
  FLC(A0, x), FLC(A1, x);
}
template <class T0, class T1, class T2>
inline void FLC(T0 &A0, T1 &A1, T2 &A2) {
  FLC(A0), FLC(A1), FLC(A2);
}
template <class T0, class T1, class T2, class T3>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5), FLC(A6);
}
template <class T>
inline void CLR(priority_queue<T, vector<T>, less<T> > &Q) {
  while (!Q.empty()) Q.pop();
}
template <class T>
inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q) {
  while (!Q.empty()) Q.pop();
}
template <class T>
inline void CLR(T &A) {
  A.clear();
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
  for (int i = 0; i < int(n); ++i) CLR(A[i]);
}
template <class T>
inline void SRT(T &A) {
  sort(A.begin(), A.end());
}
template <class T, class C>
inline void SRT(T &A, C B) {
  sort(A.begin(), A.end(), B);
}
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const double OO = 1e15;
const double PI = acos(-1.0);
template <class T>
inline void checkMin(T &a, const T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkMax(T &a, const T b) {
  if (b > a) a = b;
}
template <class T, class C>
inline void checkMin(T &a, const T b, C c) {
  if (c(b, a)) a = b;
}
template <class T, class C>
inline void checkMax(T &a, const T b, C c) {
  if (c(a, b)) a = b;
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
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline T cub(T a) {
  return a * a * a;
}
inline int Ceil(int x, int y) { return (x - 1) / y + 1; }
inline bool _1(int x, int i) { return x & 1 << i; }
inline bool _1(long long x, int i) { return x & 1LL << i; }
inline long long _1(int i) { return 1LL << i; }
inline long long _U(int i) { return _1(i) - 1; };
template <class T>
inline T low_bit(T x) {
  return x & -x;
}
template <class T>
inline T high_bit(T x) {
  T p = low_bit(x);
  while (p != x) x -= p, p = low_bit(x);
  return p;
}
template <class T>
inline T cover_bit(T x) {
  T p = 1;
  while (p < x) p <<= 1;
  return p;
}
inline int count_bits(int x) {
  x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
  x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
  x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
  x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
  x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
  return x;
}
inline int count_bits(long long x) {
  x = (x & 0x5555555555555555LL) + ((x & 0xaaaaaaaaaaaaaaaaLL) >> 1);
  x = (x & 0x3333333333333333LL) + ((x & 0xccccccccccccccccLL) >> 2);
  x = (x & 0x0f0f0f0f0f0f0f0fLL) + ((x & 0xf0f0f0f0f0f0f0f0LL) >> 4);
  x = (x & 0x00ff00ff00ff00ffLL) + ((x & 0xff00ff00ff00ff00LL) >> 8);
  x = (x & 0x0000ffff0000ffffLL) + ((x & 0xffff0000ffff0000LL) >> 16);
  x = (x & 0x00000000ffffffffLL) + ((x & 0xffffffff00000000LL) >> 32);
  return x;
}
inline int reverse_bits(int x) {
  x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
  x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
  x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
  x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
  x = ((x >> 16) & 0x0000ffff) | ((x << 16) & 0xffff0000);
  return x;
}
inline long long reverse_bits(long long x) {
  x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
  x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
  x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
  x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
  x = ((x >> 16) & 0x0000ffff0000ffffLL) | ((x << 16) & 0xffff0000ffff0000LL);
  x = ((x >> 32) & 0x00000000ffffffffLL) | ((x << 32) & 0xffffffff00000000LL);
  return x;
}
inline void INC(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline int sum(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
inline void DEC(int &a, int b) {
  a -= b;
  if (a < 0) a += MOD;
}
inline int dff(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
inline void MUL(int &a, int b) { a = (long long)a * b % MOD; }
inline int pdt(int a, int b) { return (long long)a * b % MOD; }
inline int sum(int a, int b, int c) { return sum(sum(a, b), c); }
inline int sum(int a, int b, int c, int d) { return sum(sum(a, b), sum(c, d)); }
inline int pdt(int a, int b, int c) { return pdt(pdt(a, b), c); }
inline int pdt(int a, int b, int c, int d) { return pdt(pdt(pdt(a, b), c), d); }
inline int pow(int a, long long b) {
  int c(1);
  while (b) {
    if (b & 1) MUL(c, a);
    MUL(a, a), b >>= 1;
  }
  return c;
}
template <class T>
inline T pow(T a, long long b) {
  T c(1);
  while (b) {
    if (b & 1) c *= a;
    a *= a, b >>= 1;
  }
  return c;
}
inline int _I(int b) {
  int a = MOD, x1 = 0, x2 = 1, q;
  while (true) {
    q = a / b, a %= b;
    if (!a) return (x2 + MOD) % MOD;
    DEC(x1, pdt(q, x2));
    q = b / a, b %= a;
    if (!b) return (x1 + MOD) % MOD;
    DEC(x2, pdt(q, x1));
  }
}
inline void DIA(int &a, int b) { MUL(a, _I(b)); }
inline int qtt(int a, int b) { return pdt(a, _I(b)); }
inline int phi(int n) {
  int res = n;
  for (int i = 2; sqr(i) <= n; ++i)
    if (!(n % i)) {
      DEC(res, qtt(res, i));
      do {
        n /= i;
      } while (!(n % i));
    }
  if (n != 1) DEC(res, qtt(res, n));
  return res;
}
struct Po;
struct Line;
struct Seg;
inline int sgn(double x) { return x < -EPS ? -1 : x > EPS; }
inline int sgn(double x, double y) { return sgn(x - y); }
struct Po {
  double x, y;
  Po(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  friend istream &operator>>(istream &in, Po &p) { return in >> p.x >> p.y; }
  friend ostream &operator<<(ostream &out, Po p) {
    return out << "(" << p.x << ", " << p.y << ")";
  }
  friend bool operator==(Po, Po);
  friend bool operator!=(Po, Po);
  friend Po operator+(Po, Po);
  friend Po operator-(Po, Po);
  friend Po operator*(Po, double);
  friend Po operator/(Po, double);
  bool operator<(const Po &rhs) const {
    return sgn(x, rhs.x) < 0 || sgn(x, rhs.x) == 0 && sgn(y, rhs.y) < 0;
  }
  Po operator-() const { return Po(-x, -y); }
  Po &operator+=(Po rhs) {
    x += rhs.x, y += rhs.y;
    return *this;
  }
  Po &operator-=(Po rhs) {
    x -= rhs.x, y -= rhs.y;
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
  double length_sqr() { return sqr(x) + sqr(y); }
  double length() { return sqrt(length_sqr()); }
  Po unit() { return (*this) / length(); }
  double atan() { return atan2(y, x); }
  void input() { scanf("%lf %lf", &x, &y); }
};
bool operator==(Po a, Po b) {
  return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
}
bool operator!=(Po a, Po b) {
  return sgn(a.x - b.x) != 0 || sgn(a.y - b.y) != 0;
}
Po operator+(Po a, Po b) { return Po(a.x + b.x, a.y + b.y); }
Po operator-(Po a, Po b) { return Po(a.x - b.x, a.y - b.y); }
Po operator*(Po a, double k) { return Po(a.x * k, a.y * k); }
Po operator*(double k, Po a) { return a * k; }
Po operator/(Po a, double k) { return Po(a.x / k, a.y / k); }
struct Line {
  Po a, b;
  Line(Po _a = Po(), Po _b = Po()) : a(_a), b(_b) {}
  Line(double x0, double y0, double x1, double y1)
      : a(Po(x0, y0)), b(Po(x1, y1)) {}
  Line(Seg);
  Line operator+(Po x) const { return Line(a + x, b + x); }
  friend ostream &operator<<(ostream &out, Line p) {
    return out << p.a << "-" << p.b;
  }
};
struct Seg {
  Po a, b;
  Seg(Po _a = Po(), Po _b = Po()) : a(_a), b(_b) {}
  Seg(double x0, double y0, double x1, double y1)
      : a(Po(x0, y0)), b(Po(x1, y1)) {}
  Seg(Line l);
  Seg operator+(Po x) const { return Seg(a + x, b + x); }
  friend ostream &operator<<(ostream &out, Seg p) {
    return out << p.a << "-" << p.b;
  }
  double length() { return (b - a).length(); }
};
Line::Line(Seg l) : a(l.a), b(l.b) {}
Seg::Seg(Line l) : a(l.a), b(l.b) {}
inline double dot(double x1, double y1, double x2, double y2) {
  return x1 * x2 + y1 * y2;
}
inline double dot(Po a, Po b) { return dot(a.x, a.y, b.x, b.y); }
inline double dot(Po p0, Po p1, Po p2) { return dot(p1 - p0, p2 - p0); }
inline double dot(Line l1, Line l2) { return dot(l1.b - l1.a, l2.b - l2.a); }
inline double det(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
inline double det(Po a, Po b) { return det(a.x, a.y, b.x, b.y); }
inline double det(Po p0, Po p1, Po p2) { return det(p1 - p0, p2 - p0); }
inline double det(Line l1, Line l2) { return det(l1.b - l1.a, l2.b - l2.a); }
template <class T1, class T2>
inline double dist(T1 x, T2 y) {
  return sqrt(dist_sqr(x, y));
}
inline double dist_sqr(Po a, Po b) { return sqr(a.x - b.x) + sqr(a.y - b.y); }
inline double dist_sqr(Po p, Line l) {
  Po v0 = l.b - l.a, v1 = p - l.a;
  return sqr(fabs(det(v0, v1))) / v0.length_sqr();
}
inline double dist_sqr(Po p, Seg l) {
  Po v0 = l.b - l.a, v1 = p - l.a, v2 = p - l.b;
  if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0)
    return dist_sqr(p, Line(l));
  else
    return min(v1.length_sqr(), v2.length_sqr());
}
inline double dist_sqr(Line l, Po p) { return dist_sqr(p, l); }
inline double dist_sqr(Seg l, Po p) { return dist_sqr(p, l); }
inline double dist_sqr(Line l1, Line l2) {
  if (sgn(det(l1, l2)) != 0) return 0;
  return dist_sqr(l1.a, l2);
}
inline double dist_sqr(Line l1, Seg l2) {
  Po v0 = l1.b - l1.a, v1 = l2.a - l1.a, v2 = l2.b - l1.a;
  double c1 = det(v0, v1), c2 = det(v0, v2);
  return sgn(c1) != sgn(c2) ? 0
                            : sqr(min(fabs(c1), fabs(c2))) / v0.length_sqr();
}
bool isIntersect(Seg l1, Seg l2) {
  return min(l1.a.x, l1.b.x) <= max(l2.a.x, l2.b.x) &&
         min(l2.a.x, l2.b.x) <= max(l1.a.x, l1.b.x) &&
         min(l1.a.y, l1.b.y) <= max(l2.a.y, l2.b.y) &&
         min(l2.a.y, l2.b.y) <= max(l1.a.y, l1.b.y) &&
         sgn(det(l1.a, l2.a, l2.b)) * sgn(det(l1.b, l2.a, l2.b)) <= 0 &&
         sgn(det(l2.a, l1.a, l1.b)) * sgn(det(l2.b, l1.a, l1.b)) <= 0;
}
inline double dist_sqr(Seg l1, Seg l2) {
  if (isIntersect(l1, l2))
    return 0;
  else
    return min(dist_sqr(l1.a, l2), dist_sqr(l1.b, l2), dist_sqr(l2.a, l1),
               dist_sqr(l2.b, l1));
}
inline bool isOnExtremePoint(const Po &p, const Seg &l) {
  return p == l.a || p == l.b;
}
inline bool isOnseg(const Po &p, const Seg &l) {
  return sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <= 0 &&
         sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0;
}
inline Po intersect(const Line &l1, const Line &l2) {
  return l1.a + (l1.b - l1.a) * (det(l2.a, l1.a, l2.b) / det(l2, l1));
}
inline Po intersect(const Po &p, const Line &l) {
  return intersect(Line(p, p + Po(l.a.y - l.b.y, l.b.x - l.a.x)), l);
}
inline Po rotate(Po p, double alpha, Po o = Po()) {
  p.x -= o.x, p.y -= o.y;
  return Po(p.x * cos(alpha) - p.y * sin(alpha),
            p.y * cos(alpha) + p.x * sin(alpha)) +
         o;
}
inline int rand32() {
  return (bool(rand() & 1) << 30) | (rand() << 15) + rand();
}
inline int random32(int l, int r) { return rand32() % (r - l + 1) + l; }
inline int random(int l, int r) { return rand() % (r - l + 1) + l; }
int dice() { return rand() % 6; }
bool coin() { return rand() % 2; }
template <class T>
inline T &RD(T &x) {
  scanf("%d", &x);
  return x;
}
int ____Case;
template <class T>
inline void OT(const T &x) {
  printf("%d\n", x);
}
const int N = 100020;
pair<int, int> a[N];
int c[N];
int n, x, y;
int main() {
  for (int n____ = int(--RD(n)), i = 1; i <= n____; ++i) {
    RD(x, y);
    a[i] = make_pair(x, y);
    if (!c[x]) c[x] = i;
    if (!c[y]) c[y] = i;
  }
  OT(n);
  for (int i = 1; i <= int(n); ++i)
    printf("2 %d %d\n", a[i].first, a[i].second);
  for (int i = 1; i <= int(n); ++i) {
    if (i != c[a[i].first]) printf("%d %d\n", i, c[a[i].first]);
    if (i != c[a[i].second]) printf("%d %d\n", i, c[a[i].second]);
  }
}
