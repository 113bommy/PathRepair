#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize("O2")
template <class T>
inline void RD(T &);
template <class T>
inline void OT(const T &);
inline int RD() {
  int x;
  RD(x);
  return x;
}
template <class T>
inline T &_RD(T &x) {
  RD(x);
  return x;
}
inline void RC(char &c) { scanf(" %c", &c); }
inline void RS(char *s) { scanf("%s", s); }
template <class T0, class T1>
inline void RD(T0 &x0, T1 &x1) {
  RD(x0), RD(x1);
}
template <class T0, class T1, class T2>
inline void RD(T0 &x0, T1 &x1, T2 &x2) {
  RD(x0), RD(x1), RD(x2);
}
template <class T0, class T1, class T2, class T3>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3) {
  RD(x0), RD(x1), RD(x2), RD(x3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);
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
inline void SRT(T &A) {
  sort(A.begin(), A.end());
}
template <class T, class C>
inline void SRT(T &A, C B) {
  sort(A.begin(), A.end(), B);
}
const int MOD = 1000000007;
const double EPS = 1e-6;
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
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline T cub(T a) {
  return a * a * a;
}
int Ceil(int x, int y) { return (x - 1) / y + 1; }
inline bool _1(int x, int i) { return x & 1 << i; }
inline int _1(int i) { return 1 << i; }
inline int _U(int i) { return _1(i) - 1; };
inline int count_bits(int x) {
  x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
  x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
  x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
  x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
  x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
  return x;
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
inline void RD(T &x) {
  cin >> x;
}
int ____Case;
template <class T>
inline void OT(const T &x) {
  printf("%d\n", x);
}
const long long INF = 1LL << 60;
inline void INC(long long &a, long long b) {
  a += b;
  if (a >= INF) a = INF;
}
const int N = 209;
long long F[N][N];
int o[N];
char s[N];
int n, m;
long long k;
long long f() {
  RST(F), F[0][0] = 1;
  for (int i = 0; i < int(n + m); ++i)
    for (int j = 0; j < int(n + m); ++j)
      if (F[i][j]) {
        if (!s[i] || s[i] == '(') INC(F[i + 1][j + 1], F[i][j]);
        if ((!s[i] || s[i] == ')') && j) INC(F[i + 1][j - 1], F[i][j]);
      }
  return F[n + m - 1][0];
}
int main() {
  RD(n, m, k);
  --k;
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(m); ++j) o[RD() - 1] = i + j;
  for (int n____ = int(n * m), i = 0; i < n____; ++i)
    if (!s[o[i]]) {
      s[o[i]] = '(';
      long long t = f();
      if (t <= k) k -= t, s[o[i]] = ')';
    }
  for (int i = 0; i < int(n); ++i) {
    for (int j = 0; j < int(m); ++j) putchar(s[i + j]);
    puts("");
  }
}
