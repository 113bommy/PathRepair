#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const int MOD = 1e9 + 7;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
inline void Inc(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
inline int Add(int x, int y) {
  Inc(x, y);
  return x;
}
int n, K, a[N], t, m, C[N][N];
inline int ksm(int x, int k) {
  int ret = x;
  --k;
  while (k) {
    if (k & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
    k >>= 1;
  }
  return ret;
}
struct Matrix {
  int a[N][N];
  int *operator[](int x) { return a[x]; }
} A, F;
Matrix operator*(Matrix a, Matrix b) {
  Matrix ret;
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      long long tmp = 0;
      for (int k = 0; k <= m; ++k) {
        tmp = (tmp + 1LL * a[i][k] * b[k][j]) % MOD;
      }
      ret[i][j] = tmp;
    }
  }
  return ret;
}
Matrix Ksm(Matrix x, int k) {
  Matrix ret = x;
  --k;
  while (k) {
    if (k & 1) ret = ret * x;
    x = x * x;
    k >>= 1;
  }
  return ret;
}
void init() {
  read(n);
  read(K);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    t += (a[i] == 0);
  }
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
    }
  }
}
void solve() {
  int c = 0;
  for (int i = 1; i <= t; ++i) {
    c += a[i];
  }
  A[0][c] = 1;
  m = min(t, n - t);
  for (int i = 0; i <= m; ++i) {
    Inc(F[i][i], C[t][2]);
    Inc(F[i][i], C[n - t][2]);
    Inc(F[i][i], (t - i) * i);
    Inc(F[i][i], i * (n - t - i));
    if (i) Inc(F[i][i - 1], i * i);
    if (i < m) Inc(F[i][i + 1], (t - i) * (n - t - i));
  }
  A = A * Ksm(F, K);
  int ans = 1LL * A[0][0] * ksm(ksm(C[n][2], K), MOD - 2) % MOD;
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
