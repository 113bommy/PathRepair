#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
string __file__() {
  string res = "<stdin>";
  int r = int((res).size()) - 1;
  while (res[r] != '.') --r;
  int l = r - 1;
  while (res[l] != '\\') --l;
  ++l;
  return res.substr(l, r - l);
}
void Exec(string a, string b, string c) {
  if (b.empty()) b = __file__();
  string cmd = a + ' ' + b + '.' + c;
  system(cmd.c_str());
}
void Ruby(string file = "") { Exec("ruby", file, "rb"); }
void Python(string file = "") { Exec("python", file, "py"); }
void Haskell(string file = "") { Exec("runghc", file, "hs"); }
void Pascal(string file = "") { Exec("pascal", file, "pas"); }
void Ocaml(string file = "") { Exec("ocaml", file, "ml"); }
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
inline T &RDD(T &x) {
  char c;
  for (c = getchar(); c < '-'; c = getchar())
    ;
  if (c == '-') {
    x = '0' - getchar();
    for (c = getchar(); '0' <= c && c <= '9'; c = getchar())
      x = x * 10 + '0' - c;
  } else {
    x = c - '0';
    for (c = getchar(); '0' <= c && c <= '9'; c = getchar())
      x = x * 10 + c - '0';
  }
  return x;
}
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
inline void RDD(T0 &a, T1 &b) {
  RDD(a), RDD(b);
}
template <class T0, class T1, class T2>
inline void RDD(T0 &a, T1 &b, T2 &c) {
  RDD(a), RDD(b), RDD(c);
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
inline void CLR(priority_queue<T, vector<T>, less<T> > &Q) {
  while (!Q.empty()) Q.pop();
}
template <class T>
inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q) {
  while (!Q.empty()) Q.pop();
}
template <class T>
inline void CLR(stack<T> &S) {
  while (!S.empty()) S.pop();
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
inline bool EPT(T &a) {
  return a.empty();
}
template <class T>
inline T &SRT(T &A) {
  sort(A.begin(), A.end());
  return A;
}
template <class T>
inline T &RVS(T &A) {
  reverse(A.begin(), A.end());
  return A;
}
template <class T>
inline T &UNQ(T &A) {
  A.resize(unique(SRT(A).begin(), SRT(A).end()) - A.begin());
  return A;
}
template <class T, class C>
inline T &SRT(T &A, C B) {
  sort(A.begin(), A.end(), B);
  return A;
}
const int MOD = int(1e9) + 7;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
const double OO = 1e20;
const double PI = acos(-1.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template <class T>
inline void checkMin(T &a, const T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkMax(T &a, const T b) {
  if (a < b) a = b;
}
template <class T>
inline void checkMin(T &a, T &b, const T x) {
  checkMin(a, x), checkMin(b, x);
}
template <class T>
inline void checkMax(T &a, T &b, const T x) {
  checkMax(a, x), checkMax(b, x);
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
template <class T>
inline T ceil(T x, T y) {
  return (x - 1) / y + 1;
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
struct Po;
struct Line;
struct Seg;
struct Triangle;
struct Circle;
struct Po {
  double x, y;
  Po(double x = 0, double y = 0) : x(x), y(y) {}
  inline void input() { RF(x, y); }
  inline void output() { printf("(%.2lf, %.2lf)", x, y); }
  inline friend istream &operator>>(istream &in, Po &p) {
    return in >> p.x >> p.y;
  }
  inline friend ostream &operator<<(ostream &out, Po p) {
    return out << "(" << p.x << ", " << p.y << ")";
  }
  inline bool operator==(const Po &p) const {
    return !sgn(x, p.x) && !sgn(y, p.y);
  };
  inline bool operator!=(const Po &p) const {
    return sgn(x, p.x) || sgn(y, p.y);
  }
  inline bool operator<(const Po &p) const {
    return sgn(x, p.x) < 0 || (!sgn(x, p.x) && sgn(y, p.y) < 0);
  }
  inline bool operator<=(const Po &p) const { return *this < p || *this == p; }
  inline bool operator>(const Po &p) const { return !(*this <= p); }
  inline bool operator>=(const Po &p) const { return !(*this < p); }
  inline Po operator-() const { return Po(-x, -y); }
  inline Po &operator+=(const Po &r) {
    x += r.x, y += r.y;
    return *this;
  }
  inline Po &operator-=(const Po &r) {
    x -= r.x, y -= r.y;
    return *this;
  }
  inline Po &operator*=(double k) {
    x *= k, y *= k;
    return *this;
  }
  inline Po &operator/=(double k) {
    x /= k, y /= k;
    return *this;
  }
  inline Po operator+(const Po &r) const { return Po(x + r.x, y + r.y); }
  inline Po operator-(const Po &r) const { return Po(x - r.x, y - r.y); }
  inline Po operator*(double k) const { return Po(x * k, y * k); }
  inline Po operator/(double k) const { return Po(x / k, y / k); }
  inline double operator*(const Po &) const;
  inline double operator^(const Po &) const;
  inline Po operator*(const Line &) const;
  inline double length2() const { return sqr(x) + sqr(y); }
  inline double length() const { return sqrt(length2()); }
  inline Po unit() const { return *this / length(); }
  inline bool dgt() const { return !sgn(x) && !sgn(y); }
  inline double atan() const { return atan2(y, x); }
  inline Po lt90() {
    sym(), x = -x;
    return *this;
  }
  inline Po rt90() {
    sym(), y = -y;
    return *this;
  }
  inline Po sym() {
    swap(x, y);
    return *this;
  }
  inline Po symm() {
    x = -x, y = -y;
    return *this;
  }
  inline Po rotate(double a, const Po &o = Po()) {
    x -= o.x, y -= o.y;
    return *this = Po(x * cos(a) - y * sin(a), y * cos(a) + x * sin(a)) + o;
  }
  inline Po symmetry(const Line &);
};
inline Po sym(Po p) {
  p.sym();
  return p;
}
inline Po symm(Po p) {
  p.symm();
  return p;
}
inline Po lt90(Po p) {
  p.lt90();
  return p;
}
inline Po rt90(Po p) {
  p.rt90();
  return p;
}
inline Po rotate(Po p, double alpha, const Po &o = Po()) {
  return p.rotate(alpha, o);
}
inline Po operator*(double k, Po a) { return a * k; }
inline double dot(const double &x1, const double &y1, const double &x2,
                  const double &y2) {
  return x1 * x2 + y1 * y2;
}
inline double dot(const Po &a, const Po &b) { return dot(a.x, a.y, b.x, b.y); }
inline double dot(const Po &p0, const Po &p1, const Po &p2) {
  return dot(p1 - p0, p2 - p0);
}
inline double det(const double &x1, const double &y1, const double &x2,
                  const double &y2) {
  return x1 * y2 - x2 * y1;
}
inline double det(const Po &a, const Po &b) { return det(a.x, a.y, b.x, b.y); }
inline double det(const Po &p0, const Po &p1, const Po &p2) {
  return det(p1 - p0, p2 - p0);
}
template <class T1, class T2>
inline int dett(const T1 &x, const T2 &y) {
  return sgn(det(x, y));
}
template <class T1, class T2>
inline int dott(const T1 &x, const T2 &y) {
  return sgn(dot(x, y));
}
template <class T1, class T2, class T3>
inline int dett(const T1 &x, const T2 &y, const T3 &z) {
  return sgn(det(x, y, z));
}
template <class T1, class T2, class T3>
inline int dott(const T1 &x, const T2 &y, const T3 &z) {
  return sgn(dot(x, y, z));
}
template <class T1, class T2, class T3, class T4>
inline int dett(const T1 &x, const T2 &y, const T3 &z, const T4 &w) {
  return sgn(det(x, y, z, w));
}
template <class T1, class T2, class T3, class T4>
inline int dott(const T1 &x, const T2 &y, const T3 &z, const T4 &w) {
  return sgn(dot(x, y, z, w));
}
inline double dist2(const double &x, const double &y) {
  return sqr(x) + sqr(y);
}
inline double dist2(const double &x, const double &y, const double &z) {
  return sqr(x) + sqr(y) + sqr(z);
}
inline double dist2(const Po &a, const Po &b) {
  return dist2(a.x - b.x, a.y - b.y);
}
template <class T1, class T2>
inline double dist(const T1 &x, const T2 &y) {
  return sqrt(dist2(x, y));
}
template <class T1, class T2, class T3>
inline double dist(const T1 &x, const T2 &y, const T3 &z) {
  return sqrt(dist2(x, y, z));
}
double Po::operator*(const Po &r) const { return dot(*this, r); }
double Po::operator^(const Po &r) const { return det(*this, r); }
struct Line {
  Po a, b;
  Line(const Po &a = Po(), const Po &b = Po()) : a(a), b(b) {}
  Line(double x0, double y0, double x1, double y1)
      : a(Po(x0, y0)), b(Po(x1, y1)) {}
  Line(const Line &l) : a(l.a), b(l.b) {}
  Line(const Po &a, double alpha) : a(a), b(a + Po(cos(alpha), sin(alpha))) {}
  Line(double A, double B, double C) {
    C = -C;
    if (!::sgn(A))
      a = Po(0, C / B), b = Po(1, C / B);
    else if (!::sgn(B))
      a = Po(C / A, 0), b = Po(C / A, 1);
    else
      a = Po(0, C / B), b = Po(1, (C - A) / B);
  }
  void input() { a.input(), b.input(); }
  inline friend istream &operator>>(istream &in, Line &p) {
    return in >> p.a >> p.b;
  }
  inline friend ostream &operator<<(ostream &out, Line p) {
    return out << p.a << "-" << p.b;
  }
  inline Line operator+(const Po &x) const { return Line(a + x, b + x); }
  inline Line operator-(const Po &x) const { return Line(a - x, b - x); }
  inline Line operator*(double k) const { return Line(a * k, b * k); }
  inline Po operator*(const Line &) const;
  inline Po operator*(const Po &) const;
  inline double length2() const { return (b - a).length2(); }
  inline double length() const { return (b - a).length(); }
  inline bool dgt() const { return (b - a).dgt(); }
  inline int sgn(const Po &p) const { return dett(a, b, p); }
  inline int sgn(const Line &) const;
  inline bool same_sgn(const Po &p1, const Po &p2) const {
    return sgn(p1) == sgn(p2);
  }
  inline void getEquation(double &K, double &B) const {
    K = ::sgn(a.x, b.x) ? (b.y - a.y) / (b.x - a.x) : OO;
    B = a.y - K * a.x;
  }
  inline void getEquation(double &A, double &B, double &C) const {
    A = a.y - b.y, B = b.x - a.x, C = det(a, b);
  }
  inline void getIntersect(const Line &, Po &) const;
  inline Po foot(const Po &) const;
};
inline double dot(const Line &l1, const Line &l2) {
  return dot(l1.b - l1.a, l2.b - l2.a);
}
inline double det(const Line &l1, const Line &l2) {
  return det(l1.b - l1.a, l2.b - l2.a);
}
inline int Line::sgn(const Line &l) const { return dett(*this, l); }
inline Po intersect(const Line &l1, const Line &l2) {
  return l1.a + (l1.b - l1.a) * (det(l2.a, l1.a, l2.b) / det(l2, l1));
}
inline Po Line::operator*(const Line &l) const { return intersect(*this, l); }
inline Po Line::foot(const Po &p) const {
  return *this * Line(p, p + lt90(b - a));
}
inline Po Line::operator*(const Po &p) const { return *this * p; }
inline Po Po::operator*(const Line &l) const { return l * *this; }
inline void Line::getIntersect(const Line &l, Po &p) const { p = *this * l; }
inline Po Po::symmetry(const Line &l) {
  Po o = l * *this;
  return *this = o + o - *this;
}
inline Po symmetry(Po p, const Line &l) { return p.symmetry(l); }
struct Seg : public Line {
  Seg(const Po &a = Po(), const Po &b = Po()) : Line(a, b) {}
  Seg(double x0, double y0, double x1, double y1) : Line(x0, y0, x1, y1) {}
  Seg(const Line &l) : Line(l) {}
  Seg(const Po &a, double alpha) : Line(a, alpha) {}
  Seg(double A, double B, double C) : Line(A, B, C) {}
  inline int sgn(const Po &p) const;
  inline bool qrt(const Seg &l) const;
  inline int sgn(const Seg &l) const;
};
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
inline int Seg::sgn(const Po &p) const { return -dott(p, a, b); }
inline double dist2(const Line &l, const Po &p) {
  Po v0 = l.b - l.a, v1 = p - l.a;
  return sqr(fabs(det(v0, v1))) / v0.length2();
}
inline double dist2(const Line &l1, const Line &l2) {
  return dett(l1, l2) ? 0 : dist2(l1, l2.a);
}
inline double dist2(const Seg &l, const Po &p) {
  Po v0 = l.b - l.a, v1 = p - l.a, v2 = p - l.b;
  if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0)
    return dist2(Line(l), p);
  else
    return min(v1.length2(), v2.length2());
}
inline double dist2(const Seg &l1, const Line &l2) {
  Po v0 = l2.b - l2.a, v1 = l1.a - l2.a, v2 = l1.b - l2.a;
  double c1 = det(v0, v1), c2 = det(v0, v2);
  return sgn(c1) != sgn(c2) ? 0 : sqr(min(fabs(c1), fabs(c2))) / v0.length2();
}
inline double dist2(const Seg &l1, const Seg &l2) {
  if (l1.sgn(l2))
    return 0;
  else
    return min(dist2(l2, l1.a), dist2(l2, l1.b), dist2(l1, l2.a),
               dist2(l1, l2.b));
}
const int Disjoint = -2, Exscribe = -1, Cross = 0, Inscribe = 1, Contain = 2;
Po getX3(const Po &a, const Po &b, const Po &c) {
  Po v0 = b - a, v1 = c - a;
  double s0 = v0.length2(), s1 = v1.length2(), d = det(v0, v1);
  return Po(s0 * v1.y - s1 * v0.y, s1 * v0.x - s0 * v1.x) / d + a;
}
Po getX4(const Po &a, const Po &b, const Po &c) {
  return Line(a, Line(b, c) * a) * Line(b, Line(a, c) * b);
}
struct Circle {
  Po o;
  double r;
  Circle(const Po &o = Po(), double r = 0) : o(o), r(r) {}
  Circle(const Po &a, const Po &b) { o = (a + b) / 2, r = dist(a, b) / 2; }
  Circle(const Po &a, const Po &b, const Po &c) {
    o = getX3(a, b, c), r = dist(o, a);
  }
  void input() { RF(o.x, o.y, r); }
  void output() { printf("%.2f %.2f %.2f\n", o.x, o.y, r); }
  bool operator<(const Circle &c) const { return r < c.r; }
  inline int sgn(const Po &p) const { return ::sgn(sqr(r), dist2(o, p)); }
  inline int sgn(const Line &l) const { return ::sgn(sqr(r), dist2(l, o)); }
  inline int sgn(const Circle &c) const {
    double d = dist2(o, c.o);
    if (::sgn(sqr(r + c.r), d) < 0) return Disjoint;
    if (!::sgn(sqr(r + c.r), d)) return Exscribe;
    if (!::sgn(sqr(r - c.r), d)) return Inscribe;
    if (::sgn(sqr(r - c.r), d) > 0) return Contain;
    return Cross;
  }
  inline double s() { return PI * sqr(r); }
  inline double p() { return 2 * PI * r; }
  inline Po operator^(const Circle &c) const {
    return Po(det(Po(o.x, r), Po(c.o.x, c.r)),
              det(Po(o.y, r), Po(c.o.y, c.r))) /
           (c.r - r);
  }
  inline void getIntersect(const Line &l, Po &p0, Po &p1) const {
    Po m = l.foot(o), d = (l.b - l.a).unit() * sqrt(sqr(r) - dist2(l, o));
    p0 = m + d, p1 = m - d;
  }
  inline void getTangency(const Po &p, Po &p0, Po &p1) const {
    double d = dist(o, p), a = acos(r / d);
    Po op = (p - o).unit() * r;
    p0 = o + rotate(op, a), p1 = o + rotate(op, -a);
  }
  inline void getTangency(const Circle &c, Po &p0, Po &p1, Po &p2,
                          Po &p3) const {
    if (!::sgn(r, c.r)) {
      Po d = (o - c.o).rt90().unit() * r;
      p0 = o + d, p1 = o - d, p2 = c.o + d, p3 = c.o - d;
    } else {
      Po p = (*this) ^ c;
      getTangency(p, p0, p1), c.getTangency(p, p2, p3);
    }
  }
  inline double arc(const Po &a, const Po &b) {
    double alpha = acos(cos(dist(a, o), dist(b, o), dist(a, b)));
    if (det(o, a, b) < 0) alpha = 2 * PI - alpha;
    return alpha * r;
  }
};
struct Triangle {
  Po A, B, C;
  double a, b, c;
  double alpha, beta, theta;
  double r, R;
  double S, P;
  Po I, G, O, H;
  void init() {
    a = dist(B, C), b = dist(a, c), c = dist(a, b);
    alpha = acos(cos(b, c, a)), beta = acos(cos(a, c, b)),
    theta = acos(cos(a, b, c));
    P = a + b + c;
    double s = P / 2;
    S = sqrt(s * (s - a) * (s - b) * (s - c));
    R = (a * b * c) / (4 * S), r = 2 * S / P;
    I = Po(a * A.x + b * B.x + c * C.x, a * A.y + b * B.y + c * C.y) / P;
    G = (A + B + C) / 3;
    O = getX3(A, B, C), H = getX4(A, B, C);
    assert(!sgn(dist(I, O), sqrt(R * (R - 2 * r))));
    assert(!sgn(dist(H, G), dist(O, H) * 2 / 3));
  }
  void input() {
    A.input(), B.input(), C.input();
    init();
  }
};
double getArea(vector<Po> &P) {
  double S = 0;
  for (int i = 0; i < int(int((P).size())); ++i) S += det(P[i], P[i + 1]);
  return S;
}
vector<Po> getConvexHull(vector<Po> &P) {
  int n = int((P).size());
  if (n <= 3) return P;
  SRT(P);
  vector<Po> C;
  C.resize(n + 9);
  int nn = -1;
  for (int i = 0; i < int(n); ++i) {
    while (nn > 0 && dett(C[nn - 1], C[nn], P[i]) <= 0) --nn;
    C[++nn] = P[i];
  }
  int _nn = nn;
  for (int i = int(n - 1 - 1); i >= int(0); --i) {
    while (nn > _nn && dett(C[nn - 1], C[nn], P[i]) <= 0) --nn;
    C[++nn] = P[i];
  }
  C.resize(nn + 1);
  return C;
}
Circle getMinimalCoverCircle(vector<Po> &P) {
  random_shuffle(P.begin(), P.end());
  int n = int((P).size());
  Circle C(P[0]);
  for (int i = int(1); i < int(n); ++i)
    if (!~C.sgn(P[i])) {
      C = Circle(P[i]);
      for (int j = 0; j < int(i); ++j)
        if (!~C.sgn(P[j])) {
          C = Circle(P[i], P[j]);
          for (int k = 0; k < int(j); ++k)
            if (!~C.sgn(P[k])) {
              C = Circle(P[i], P[j], P[k]);
            }
        }
    }
  return C;
}
struct Polygon {
  vector<Po> P;
  void input();
};
inline bool equal(const pair<double, double> &lhs, const Seg &rhs) {
  double k, b;
  rhs.getEquation(k, b);
  return !sgn(k, lhs.first) && !sgn(b, lhs.second);
}
double getUnion(vector<Polygon> &P, vector<Seg> &S) {
  vector<pair<double, double> > L;
  for (__typeof(S.begin()) Si = S.begin(); Si != S.end(); ++Si) {
    double k, b;
    Si->getEquation(k, b);
    L.push_back(make_pair(k, b));
  }
  UNQ(L);
  double res = 0;
  for (__typeof(L.begin()) Li = L.begin(); Li != L.end(); ++Li) {
    vector<pair<double, int> > I;
    Line l0(0, Li->second, 1, Li->first + Li->second);
    for (__typeof(P.begin()) Pi = P.begin(); Pi != P.end(); ++Pi) {
      int i;
      for (i = int(1); i < int(int((Pi->P).size())); ++i)
        if (equal(*Li, Seg(Pi->P[i - 1], Pi->P[i]))) break;
      if (i != int((Pi->P).size())) continue;
      vector<Po> cut;
      for (i = int(1); i < int(int((Pi->P).size())); ++i) {
        Seg l1(Pi->P[i - 1], Pi->P[i]);
        if (!dett(l0, l1)) continue;
        Po p = l0 * l1;
        if (~l1.sgn(p)) cut.push_back(p);
      }
      if (int((UNQ(cut)).size()) == 2) {
        I.push_back(make_pair(cut[0].x, 1));
        I.push_back(make_pair(cut[1].x, -1));
      }
    }
    for (__typeof(S.begin()) Si = S.begin(); Si != S.end(); ++Si)
      if (equal(*Li, *Si)) {
        I.push_back(make_pair(min(Si->a.x, Si->b.x), 2));
        I.push_back(make_pair(max(Si->a.x, Si->b.x), -2));
      }
    SRT(I);
    int c0 = 0, c1 = 0;
    for (int i = 0; i < int(int((I).size())); ++i) {
      if (!c0 && c1)
        res += ((Li->first * I[i - 1].first + Li->second) +
                (Li->first * I[i].first + Li->second)) *
               (I[i].first - I[i - 1].first);
      if (abs(I[i].second) == 1)
        c0 += I[i].second;
      else
        c1 += I[i].second;
    }
  }
  return res;
}
double getUnion(vector<Polygon> &P) {
  vector<Seg> up, down;
  for (__typeof(P.begin()) it = P.begin(); it != P.end(); ++it) {
    for (int i = int(1); i < int(int((it->P).size())); ++i) {
      Seg s(it->P[i - 1], it->P[i]);
      int t = sgn(s.a.x, s.b.x);
      if (t > 0)
        up.push_back(s);
      else if (t < 0)
        down.push_back(s);
    }
  }
  return getUnion(P, up) - getUnion(P, down);
}
}  // namespace CG
using namespace CG;
template <class T>
inline T &RD(T &x) {
  char c;
  for (c = getchar(); c < '0'; c = getchar())
    ;
  x = c - '0';
  for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x;
}
inline double &RF(double &x) {
  x = RDD();
  return x;
}
inline char *RS(char *s) {
  scanf("%s", s);
  return s;
}
long long last_ans;
int Case;
template <class T>
inline void OT(const T &x) {
  cout << x << endl;
}
const int N = 509;
vector<Polygon> P;
int n;
double sum_area;
void Polygon::input() {
  P.resize(4);
  for (int i = 0; i < int(4); ++i) P[i].input();
  P = getConvexHull(P);
  sum_area += getArea(P);
}
int main() {
  P.resize(RD(n));
  for (int i = 0; i < int(n); ++i) P[i].input();
  printf("%.10f\n", sum_area / getUnion(P));
}
