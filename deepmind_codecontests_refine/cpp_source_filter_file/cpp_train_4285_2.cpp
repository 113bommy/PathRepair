#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f = ch ^ 45, ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? x : -x;
}
int n, m, c, inv;
const int mod = 1e9 + 7;
struct mat {
  int a[105][105];
  inline mat operator*(const mat &t) {
    mat res;
    for (int i = 0; i <= c; ++i)
      for (int j = 0; j <= c; ++j) {
        res.a[i][j] = 0;
        for (int k = 0; k <= c; ++k)
          res.a[i][j] = (res.a[i][j] + 1ll * a[i][k] * t.a[k][j]) % mod;
      }
    return res;
  }
} A, B, C, I;
int a[105];
inline int ksm(int b, int x) {
  int res = 1;
  while (x) {
    if (x & 1) res = 1ll * res * b % mod;
    b = 1ll * b * b % mod;
    x >>= 1;
  }
  return res;
}
inline mat qpow(mat b, int x) {
  mat res = I;
  while (x) {
    if (x & 1) res = res * b;
    b = b * b;
    x >>= 1;
  }
  return res;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i) c += (!a[i]);
  int cnt = 0;
  for (int i = 1; i <= c; ++i) cnt += (!a[i]);
  A.a[1][cnt] = 1;
  int inv = ksm(n * (n - 1) >> 1, mod - 2);
  for (int i = 0; i <= c; ++i) {
    I.a[i][i] = 1;
    if (n - 2 * c + i < 0) continue;
    B.a[i][i + 1] = 1ll * (c - i) * (c - i) * inv % mod;
    B.a[i][i - 1] = 1ll * i * (n - 2 * c + i) * inv % mod;
    B.a[i][i] = (mod + mod + 1 - B.a[i][i + 1] - B.a[i][i - 1]) % mod;
  }
  A = A * qpow(B, m);
  cout << A.a[1][c];
}
