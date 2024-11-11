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
inline double &RF(double &);
inline double RF() {
  double x;
  return RF(x);
}
inline char *RS(char *s);
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
template <class T>
inline void FLC(T &A, int x) {
  memset(A, x, sizeof(A));
}
template <class T>
inline T &SRT(T &A) {
  sort(A.begin(), A.end());
  return A;
}
template <class T, class C>
inline T &SRT(T &A, C B) {
  sort(A.begin(), A.end(), B);
  return A;
}
template <class T>
inline T &UNQ(T &A) {
  A.resize(unique(SRT(A).begin(), SRT(A).end()) - A.begin());
  return A;
}
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long INFF = 1LL << 60;
const double EPS = 1e-9;
const double OO = 1e15;
const double PI = acos(-1.0);
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
inline int ceil(int x, int y) { return (x - 1) / y + 1; }
inline int sgn(double x) { return x < -EPS ? -1 : x > EPS; }
inline int sgn(double x, double y) { return sgn(x - y); }
namespace BO {
inline bool _1(int x, int i) { return bool(x & 1 << i); }
inline bool _1(long long x, int i) { return bool(x & 1LL << i); }
inline long long _1(int i) { return 1LL << i; }
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
inline int count_bits(int x) { return __builtin_popcount(x); }
inline int count_bits(long long x) { return __builtin_popcountll(x); }
}  // namespace BO
using namespace BO;
namespace NT {
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
inline int pow(int a, int b) {
  int c(1);
  while (b) {
    if (b & 1) MUL(c, a);
    MUL(a, a), b >>= 1;
  }
  return c;
}
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
inline void DIV(int &a, int b) { MUL(a, _I(b)); }
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
}  // namespace NT
using namespace NT;
namespace Math {
long long GCD(long long a, long long b) { return b ? GCD(b, a % b) : a; }
long long extendGCD(long long a, long long b, long long &x, long long &y) {
  if (!b) return x = 1, y = 0, a;
  long long res = extendGCD(b, a % b, x, y), tmp = x;
  x = y, y = tmp - (a / b) * y;
  return res;
}
long long power(long long x, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res *= x;
    x *= x, k >>= 1;
  }
  return res;
}
long long powerMod(long long x, long long k, long long m) {
  long long res = 1;
  while (x %= m, k) {
    if (k & 1) res *= x, res %= m;
    x *= x, k >>= 1;
  }
  return res;
}
long long inverse(long long a, long long p, long long t = 1) {
  long long pt = power(p, t);
  long long x, y;
  y = extendGCD(a, pt, x, y);
  return x < 0 ? x += pt : x;
}
long long linearCongruence(long long a, long long b, long long p, long long q) {
  long long x, y;
  y = extendGCD(p, q, x, y);
  while (b < a) b += q / y;
  x *= b - a, x = p * x + a, x %= p * q;
  if (x < 0) x += p * q;
  return x;
}
const int PRIMERANGE = 1000000;
int prime[PRIMERANGE + 1];
int getPrime() {
  memset(prime, 0, sizeof(int) * (PRIMERANGE + 1));
  for (int i = 2; i <= PRIMERANGE; i++) {
    if (!prime[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0] && prime[j] <= PRIMERANGE / i; j++) {
      prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  return prime[0];
}
int factor[100][3], facCnt;
int getFactors(int x) {
  facCnt = 0;
  int tmp = x;
  for (int i = 1; prime[i] <= tmp / prime[i]; i++) {
    factor[facCnt][1] = 1, factor[facCnt][2] = 0;
    if (tmp % prime[i] == 0) factor[facCnt][0] = prime[i];
    while (tmp % prime[i] == 0)
      factor[facCnt][2]++, factor[facCnt][1] *= prime[i], tmp /= prime[i];
    if (factor[facCnt][1] > 1) facCnt++;
  }
  if (tmp != 1)
    factor[facCnt][0] = tmp, factor[facCnt][1] = tmp, factor[facCnt++][2] = 1;
  return facCnt;
}
long long combinationModP(long long n, long long k, long long p) {
  if (k > n) return 0;
  if (n - k < k) k = n - k;
  long long a = 1, b = 1, x, y;
  int pcnt = 0;
  for (int i = 1; i <= k; i++) {
    x = n - i + 1, y = i;
    while (x % p == 0) x /= p, pcnt++;
    while (y % p == 0) y /= p, pcnt--;
    x %= p, y %= p, a *= x, b *= y;
    b %= p, a %= p;
  }
  if (pcnt) return 0;
  extendGCD(b, p, x, y);
  if (x < 0) x += p;
  a *= x, a %= p;
  return a;
}
};  // namespace Math
namespace Geo {
const double eps = 1e-8;
int dblcmp(double d) { return d < -eps ? -1 : d > eps; }
int sgn(double a) { return a < -eps ? -1 : a > eps; }
inline double sqr(double x) { return x * x; }
};  // namespace Geo
template <class T>
inline T &RD(T &x) {
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
inline double &RF(double &x) {
  scanf("%lf", &x);
  return x;
}
inline char *RS(char *s) {
  scanf("%s", s);
  return s;
}
int Case;
template <class T>
inline void OT(const T &x) {
  cout << x << endl;
}
const int N = 100;
int a[N], n;
int main() {
  RD(n);
  for (int i = 0; i < n; ++i) {
    RD(a[i]);
    if (a[i] == 1) {
    }
  }
  sort(a, a + n);
  int c = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == a[0]) ++c;
  }
  if (a[0] == a[n - 1] || c * 2 > n) {
    puts("Bob");
  } else {
    puts("Alice");
  }
}
