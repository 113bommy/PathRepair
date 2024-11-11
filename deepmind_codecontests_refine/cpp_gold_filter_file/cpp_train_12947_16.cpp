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
inline T &SRT(T &A) {
  sort(A.begin(), A.end());
  return A;
}
template <class T, class C>
inline T &SRT(T &A, C B) {
  sort(A.begin(), A.end(), B);
  return A;
}
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};
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
inline int Ceil(int x, int y) { return (x - 1) / y + 1; }
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
inline int low_idx(int x) { return __builtin_ffs(x); }
inline int low_idx(long long x) { return __builtin_ffsll(x); }
inline int high_idx(int x) { return low_idx(reverse_bits(x)); }
inline int high_idx(long long x) { return low_idx(reverse_bits(x)); }
inline int clz(int x) { return __builtin_clz(x); }
inline int clz(long long x) { return __builtin_clzll(x); }
inline int ctz(int x) { return __builtin_ctz(x); }
inline int ctz(long long x) { return __builtin_ctzll(x); }
inline int parity(int x) { return __builtin_parity(x); }
inline int parity(long long x) { return __builtin_parityll(x); }
inline int lg2(int a) { return 31 - __builtin_clz(a); }
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
template <class T>
T GCD(T a, T b) {
  return b ? GCD(b, a % b) : a;
}
template <class T>
T extendGCD(T a, T b, T &x, T &y) {
  if (!b) return x = 1, y = 0, a;
  T res = extendGCD(b, a % b, x, y), tmp = x;
  x = y, y = tmp - (a / b) * y;
  return res;
}
template <class T>
inline T inv(T w, T M) {
  if (M <= 0) return -1;
  T x, y, d;
  d = extendGCD(w, M, x, y);
  if (d != 1) return -1;
  x = ((x % M) + M) % M;
  return x;
}
}  // namespace NT
using namespace NT;
namespace RNG {
inline unsigned int rand16() { return (bool(rand() & 1) << 15) | rand(); }
inline unsigned int rand32() { return (rand16() << 16) | rand16(); }
inline unsigned long long rand64() {
  return ((long long)rand32() << 32) | rand32();
}
inline unsigned long long random(long long l, long long r) {
  return rand64() % (r - l) + l;
}
int dice() { return rand() % 6; }
bool coin() { return bool(rand() % 2); }
}  // namespace RNG
using namespace RNG;
namespace CLOCK {
double s0, s1, rd, k, T;
inline double getTime() { return 1.0 * clock() / CLOCKS_PER_SEC; }
inline void st0(double _T = 0.98) { T = _T, s0 = getTime(); }
inline void st1(double _k = 1.618) { k = _k, s1 = getTime(); }
inline void ed1() { rd = getTime() - s1; }
inline double elapsed() { return getTime() - s0; }
inline bool safe() { return elapsed() + rd * k < T; }
}  // namespace CLOCK
template <class T>
pair<T, T> operator+(const pair<T, T> &p1, const pair<T, T> &p2) {
  return pair<T, T>(p1.first + p2.first, p1.second + p2.second);
}
template <class T>
pair<T, T> operator-(const pair<T, T> &p1, const pair<T, T> &p2) {
  return pair<T, T>(p1.first - p2.first, p1.second - p2.second);
}
template <class T>
pair<T, T> operator*(const pair<T, T> &lhs, T k) {
  return pair<T, T>(lhs.first * k, lhs.second * k);
}
template <class T>
inline T &RD(T &x) {
  char c;
  for (c = getchar(); c < '0'; c = getchar())
    ;
  x = c - '0';
  for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x;
}
int ____Case;
template <class T>
inline void OT(const T &x) {
  printf("%d\n", x);
}
const int N = 3e5;
int n, k, a[N], num[N], cnt[N];
void solve() {
  RST(num);
  RST(cnt);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int j = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[j]) a[++j] = a[i];
  }
  n = j + 1;
  for (int i = 1; i < n - 1; ++i)
    if (a[i - 1] != a[i + 1]) ++num[a[i]];
  for (int i = 0; i < n; ++i) {
    ++cnt[a[i]];
    if (i && i < n - 1) ++cnt[a[i]];
  }
  int ans = 1e9, ansi;
  for (int i = 1; i <= k; ++i) {
    if (ans > n - 1 + num[i] - cnt[i]) {
      ans = n - 1 + num[i] - cnt[i];
      ansi = i;
    }
  }
  cout << ansi << endl;
}
int main() {
  while (cin >> n >> k) solve();
}
