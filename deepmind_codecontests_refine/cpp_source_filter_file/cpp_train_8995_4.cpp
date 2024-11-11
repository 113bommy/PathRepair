#include <bits/stdc++.h>
using namespace std;
struct Matrix {
  long long m[7][7];
  Matrix() { memset(m, 0, sizeof(m)); }
  inline void init() {
    m[1][1] = 2, m[1][2] = 1, m[1][3] = 1, m[1][4] = 0, m[1][5] = 1,
    m[1][6] = 2;
    m[2][1] = 1, m[2][2] = 2, m[2][3] = 0, m[2][4] = 1, m[2][5] = 1,
    m[2][6] = 2;
    m[3][1] = 1, m[3][2] = 1, m[3][3] = 1, m[3][4] = 0, m[3][5] = 1,
    m[3][6] = 2;
    m[4][1] = 1, m[4][2] = 1, m[4][3] = 0, m[4][4] = 1, m[4][5] = 1,
    m[4][6] = 2;
    m[5][1] = 0, m[5][2] = 0, m[5][3] = 0, m[5][4] = 0, m[5][5] = 1,
    m[5][6] = 1;
    m[6][1] = 0, m[6][2] = 0, m[6][3] = 0, m[6][4] = 0, m[6][5] = 0,
    m[6][6] = 1;
  }
  inline void reset() {
    m[1][1] = m[2][2] = m[3][3] = 1;
    m[4][4] = m[5][5] = m[6][6] = 1;
  }
  inline long long *operator[](long long x) { return m[x]; }
  inline const long long *operator[](long long x) const { return m[x]; }
};
long long n, x, y, dx, dy, t;
inline long long read() {
  long long x = 0;
  long long f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch == '-' && (f = -1);
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix x;
  for (long long i = 1; i <= 6; i++)
    for (long long j = 1; j <= 6; j++)
      for (long long k = 1; k <= 6; k++)
        x[i][j] += (a[i][k] * b[k][j]) % n, x[i][j] += n, x[i][j] %= n;
  return x;
}
inline Matrix qpow(const Matrix &x, long long y) {
  Matrix r, k = x;
  r.reset();
  while (y) {
    if (y & 1) r = r * k;
    k = k * k, y >>= 1;
  }
  return r;
}
signed main() {
  n = read(), x = read(), y = read(), dx = read(), dy = read(), t = read();
  Matrix A, B;
  A.init();
  A = qpow(A, t);
  B[1][1] = x - 1, B[2][1] = y - 1, B[3][1] = dx, B[4][1] = dy, B[5][1] = 0,
  B[6][1] = 1;
  B = A * B;
  printf("%lld %lld\n", B[1][1] + 1, B[1][2] + 1);
  return 0;
}
