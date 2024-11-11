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
namespace BO {
inline bool _1(int x, int i) { return bool(x & 1 << i); }
inline bool _1(long long x, int i) { return bool(x & 1LL << i); }
inline long long _1(int i) { return 1LL << i; }
inline long long _U(int i) { return _1(i) - 1; };
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
template <class T>
inline bool odd(T x) {
  return x & 1;
}
template <class T>
inline bool even(T x) {
  return !odd(x);
}
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
template <class T>
inline int cover_idx(T x) {
  int p = 0;
  while (_1(p) < x) ++p;
  return p;
}
inline int clz(int x) { return __builtin_clz(x); }
inline int clz(long long x) { return __builtin_clzll(x); }
inline int ctz(int x) { return __builtin_ctz(x); }
inline int ctz(long long x) { return __builtin_ctzll(x); }
inline int lg2(int x) { return !x ? -1 : 31 - clz(x); }
inline int lg2(long long x) { return !x ? -1 : 63 - clz(x); }
inline int low_idx(int x) { return !x ? -1 : ctz(x); }
inline int low_idx(long long x) { return !x ? -1 : ctz(x); }
inline int high_idx(int x) { return lg2(x); }
inline int high_idx(long long x) { return lg2(x); }
inline int parity(int x) { return __builtin_parity(x); }
inline int parity(long long x) { return __builtin_parityll(x); }
inline int count_bits(int x) { return __builtin_popcount(x); }
inline int count_bits(long long x) { return __builtin_popcountll(x); }
}  // namespace BO
using namespace BO;
namespace NT {
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
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
inline int pdt(int x, int y) {
  int ret;
  __asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n"
                       : "=d"(ret)
                       : "a"(x), "b"(y), "c"(MOD));
  return ret;
}
inline int gcd(int m, int n, int &x, int &y) {
  x = 1, y = 0;
  int xx = 0, yy = 1, q;
  while (1) {
    q = m / n, m %= n;
    if (!m) {
      x = xx, y = yy;
      return n;
    }
    DEC(x, pdt(q, xx)), DEC(y, pdt(q, yy));
    q = n / m, n %= m;
    if (!n) return m;
    DEC(xx, pdt(q, x)), DEC(yy, pdt(q, y));
  }
}
inline int sum(int a, int b, int c) { return sum(a, sum(b, c)); }
inline int sum(int a, int b, int c, int d) { return sum(sum(a, b), sum(c, d)); }
inline int pdt(int a, int b, int c) { return pdt(a, pdt(b, c)); }
inline int pdt(int a, int b, int c, int d) { return pdt(pdt(a, b), pdt(c, d)); }
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
template <class T>
inline T pow(T a, int b) {
  return pow(a, (long long)b);
}
inline int _I(int b) {
  int a = MOD, x1 = 0, x2 = 1, q;
  while (1) {
    q = a / b, a %= b;
    if (!a) return x2;
    DEC(x1, pdt(q, x2));
    q = b / a, b %= a;
    if (!b) return x1;
    DEC(x2, pdt(q, x1));
  }
}
inline void DIV(int &a, int b) { MUL(a, _I(b)); }
inline int qtt(int a, int b) { return pdt(a, _I(b)); }
struct Int {
  int val;
  operator int() const { return val; }
  Int(int _val = 0) : val(_val) {
    val %= MOD;
    if (val < 0) val += MOD;
  }
  Int(long long _val) : val(_val) {
    _val %= MOD;
    if (_val < 0) _val += MOD;
    val = _val;
  }
  Int &operator+=(const int &rhs) {
    INC(val, rhs);
    return *this;
  }
  Int operator+(const int &rhs) const { return sum(val, rhs); }
  Int &operator-=(const int &rhs) {
    DEC(val, rhs);
    return *this;
  }
  Int operator-(const int &rhs) const { return dff(val, rhs); }
  Int &operator*=(const int &rhs) {
    MUL(val, rhs);
    return *this;
  }
  Int operator*(const int &rhs) const { return pdt(val, rhs); }
  Int &operator/=(const int &rhs) {
    DIV(val, rhs);
    return *this;
  }
  Int operator/(const int &rhs) const { return qtt(val, rhs); }
  Int operator-() const { return MOD - *this; }
};
}  // namespace NT
using namespace NT;
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
long long last_ans;
int Case;
template <class T>
inline void OT(const T &x) {
  cout << x << endl;
}
const int N = int(1e3) + 9;
vector<int> adj[N];
int n, m;
int a[N], b[N];
int fa[N];
long long p[N], p0;
int Q[N], cz, op;
void add_path(int u) {
  while (~fa[u]) {
    Q[op++] = u;
    p0 += b[u];
    int v = fa[u];
    fa[u] = -1;
    u = v;
  }
}
bool find_circle() {
  for (int i = 0; i < n; ++i) fa[i] = -1, p[i] = 0;
  for (int i = 0; i < op; ++i) p[Q[i]] = p0;
  cz = 0;
  int op = ::op;
  while (cz < op) {
    int u = Q[cz++];
    for (auto v : adj[u])
      if (v != fa[u] && p[u] > a[v]) {
        if (~fa[v] || p[v] == p0 && p[u] != p0) {
          add_path(u);
          add_path(v);
          return 1;
        }
        if (p[v] == p0) continue;
        p[v] = p[u] + b[v];
        fa[v] = u;
        Q[op++] = v;
      }
  }
  return 0;
}
bool ok(int _p0) {
  op = 0;
  Q[op++] = 0;
  p0 = _p0;
  while (find_circle())
    ;
  return op == n;
}
int main() {
  for (int ____T = RD(); ____T--;) {
    RD(n, m);
    for (int i = 1; i < n; ++i) RD(a[i]);
    for (int i = 1; i < n; ++i) RD(b[i]);
    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int ____n = m; ____n-- > 0;) {
      int x, y;
      RD(x, y);
      --x;
      --y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    int l = 2, r = int(1e9) + 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (ok(m))
        r = m;
      else
        l = m + 1;
    }
    cout << l << endl;
  }
}
