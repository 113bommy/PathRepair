#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:36777216")
template <class T>
inline void RD(T &x) {
  char c;
  for (c = getchar(); c < '0'; c = getchar())
    ;
  x = c - '0';
  for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
}
template <class T>
inline void OT(const T &x) {
  cout << x << endl;
}
template <class T>
inline T &_RD(T &x) {
  RD(x);
  return x;
}
inline int RD() {
  int x;
  RD(x);
  return x;
}
inline long long RD_LL() {
  int x;
  RD(x);
  return x;
}
inline double RD_DB() {
  double x;
  RD(x);
  return x;
}
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
inline void checkMin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkMax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
const int MOD = 1000000007;
const int INF = 0x7fffffff;
const double EPS = 1e-6;
const double OO = 1e15;
const int N = 20000 + 5;
bool A[3], B[3], _B[3], B_[3];
int x[3], m[3], l[3], u[3];
int res;
void dfs() {
  int _i, i_;
  for (int i = 0; i < int(3); ++i)
    if (!_B[i]) {
      if (i == 0)
        _i = 1, i_ = 2;
      else if (i == 1)
        _i = 0, i_ = 2;
      else
        _i = 0, i_ = 1;
      if (B[i] && !B_[i]) {
        if (u[i] == i_) swap(_i, i_);
        B_[i] = true, _B[_i] = false;
        if (B[_i] && !B_[_i]) {
          checkMax(res, x[i] + l[i] + l[_i] + (A[i_] ? 0 : m[i_]));
        } else {
          int x_i = x[_i];
          for (int j = int(-l[i]); j <= int(l[i]); ++j)
            if (j != 0) {
              int xx = x[i] + j;
              if (x[i_] != xx &&
                  (abs(x[i_] - xx) == 1 || j == 1 || j == l[i])) {
                checkMax(res, xx);
                x[_i] = xx, dfs();
                x[_i] = x_i;
              }
            }
        }
        _B[_i] = true, B_[i] = false;
      } else {
        if (!B[i]) {
          if (!_B[_i] && x[_i] == x[i] + -1) {
            x[_i] = x[i], B[i] = _B[_i] = true, u[i] = _i, dfs(),
            x[_i] = x[i] + -1;
            B[i] = _B[_i] = false;
          };
          if (!_B[_i] && x[_i] == x[i] + 1) {
            x[_i] = x[i], B[i] = _B[_i] = true, u[i] = _i, dfs(),
            x[_i] = x[i] + 1;
            B[i] = _B[_i] = false;
          };
          if (!_B[i_] && x[i_] == x[i] + -1) {
            x[i_] = x[i], B[i] = _B[i_] = true, u[i] = i_, dfs(),
            x[i_] = x[i] + -1;
            B[i] = _B[i_] = false;
          };
          if (!_B[i_] && x[i_] == x[i] + 1) {
            x[i_] = x[i], B[i] = _B[i_] = true, u[i] = i_, dfs(),
            x[i_] = x[i] + 1;
            B[i] = _B[i_] = false;
          };
        }
        if (!A[i]) {
          A[i] = true;
          int xi = x[i];
          for (int j = int(-m[i]); j <= int(m[i]); ++j)
            if (j != 0) {
              int xx = xi + j;
              if (x[_i] != xx && x[i_] != xx &&
                  (abs(x[_i] - xx) == 1 || abs(x[i_] - xx) == 1 || j == m[i] ||
                   j == -m[i])) {
                checkMax(res, xx);
                x[i] = xx, dfs(), x[i] = xi;
              }
            }
          A[i] = false;
        }
      }
    }
}
int main() {
  for (int i = 0; i < int(3); ++i) RD(x[i], m[i], l[i]);
  res = max(x[0], x[1], x[2]);
  dfs();
  OT(res);
}
