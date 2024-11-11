#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3001, mod = 1e9 + 7;
const double eps = 1e-9;
template <typename A, typename B>
inline bool chmin(A &a, B b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename A, typename B>
inline bool chmax(A &a, B b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename A, typename B>
inline long long add(A x, B y) {
  if (x + y < 0) return x + y + mod;
  return x + y >= mod ? x + y - mod : x + y;
}
template <typename A, typename B>
inline void add2(A &x, B y) {
  if (x + y < 0)
    x = x + y + mod;
  else
    x = (x + y >= mod ? x + y - mod : x + y);
}
template <typename A, typename B>
inline long long mul(A x, B y) {
  return 1ll * x * y % mod;
}
template <typename A, typename B>
inline void mul2(A &x, B y) {
  x = (1ll * x * y % mod + mod) % mod;
}
template <typename A>
inline void debug(A a) {
  cout << a << '\n';
}
template <typename A>
inline long long sqr(A x) {
  return 1ll * x * x;
}
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int N, M, x, y;
double f[MAXN][MAXN], A[MAXN], B[MAXN], C[MAXN];
signed main() {
  N = read();
  M = read();
  x = read(), y = read();
  if (M == 1) {
    cout << 2 * (N - x);
    return 0;
  }
  for (int i = N - 1; i >= 1; i--) {
    A[1] = 1;
    B[1] = -0.5, C[1] = 1.5 + 0.5 * f[i + 1][1];
    for (int j = 2; j <= M - 1; j++) {
      double p = (-0.25 / A[j - 1]);
      A[j] = 0.75 - p * B[j - 1];
      B[j] = -0.25;
      C[j] = 1.0 + 0.25 * f[i + 1][j] - p * C[j - 1];
    }
    double tmp = -0.5 / A[M - 1];
    f[i][M] = (C[M - 1] * tmp - 1.5 - 0.5 * f[i + 1][M]) / (B[M - 1] * tmp - 1);
    f[i][M - 1] = (C[M - 1] - B[M - 1] * f[i][M]) / A[M - 1];
    for (int j = M - 2; j >= 1; j--)
      f[i][j] = (C[j] - B[j] * f[i][j + 1]) / A[j];
  }
  printf("%.5lf", f[x][y]);
  return 0;
}
