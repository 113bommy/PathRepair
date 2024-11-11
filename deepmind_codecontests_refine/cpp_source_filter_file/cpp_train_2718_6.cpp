#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int d, mod, s[N][N], C[N][N], a[N], zero = 4999, one = 4997;
void add(int a, int b, int c) { printf("+ %d %d %d\n", a, b, c); }
void mul(int a, int b) { printf("^ %d %d\n", a, b); }
void clear(int a) { add(zero, zero, a); }
void qmul(int x, int bs, int res) {
  while (x) {
    if (x & 1) add(bs, res, res);
    add(bs, bs, bs), x >>= 1;
  }
}
int qpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod, y >>= 1;
  }
  return res;
}
void Gauss() {
  C[0][0] = 1;
  for (int i = 1; i <= d; ++i)
    for (int j = 0; j <= i; ++j) {
      C[i][j] = C[i - 1][j];
      if (j) C[i][j] = (C[i][j] + C[i - 1][j - 1]) % mod;
    }
  for (int i = 0; i <= d; ++i) {
    for (int j = 0, tms = 1; j <= d; ++j)
      s[j][i] = 1ll * C[d][j] * tms % mod, tms = 1ll * tms * i % mod;
  }
  s[2][d + 1] = 1;
  for (int i = 0; i <= d; ++i) {
    if (!s[i][i]) {
      int tmp = -1;
      for (int j = 0; j <= d; ++j)
        if (s[j][d]) {
          tmp = j;
          break;
        }
      if (!(~tmp)) continue;
      for (int j = i; j <= d; ++j) swap(s[i][j], s[tmp][j]);
    }
    int iv = qpow(s[i][i], mod - 2);
    for (int j = i + 1; j <= d; ++j)
      if (s[j][i]) {
        int tmp = 1ll * (mod - s[j][i]) * iv % mod;
        for (int k = i; k <= d + 1; ++k)
          s[j][k] = (s[j][k] + 1ll * tmp * s[i][k]) % mod;
      }
  }
  for (int i = d; i >= 0; --i) {
    a[i] = 1ll * qpow(s[i][i], mod - 2) * s[i][d + 1] % mod;
    for (int j = i - 1; j >= 0; --j)
      if (s[j][i])
        s[j][d + 1] = (s[j][d + 1] + 1ll * (mod - s[j][i]) * a[i] % mod) % mod;
  }
}
int main() {
  scanf("%d%d", &d, &mod);
  qmul(mod - 1, zero - 1, zero);
  Gauss();
  clear(3);
  for (int i = 2; i <= d; ++i) add(i + 2, one, i + 3);
  for (int i = 3; i <= d + 3; ++i) add(1, i, i), mul(i, i);
  clear(d + 4);
  for (int i = 0; i <= d; ++i) qmul(a[i], i + 3, d + 4);
  clear(3);
  for (int i = 1; i <= d; ++i) add(i + 2, one, i + 3);
  for (int i = 3; i <= d + 3; ++i) add(2, i, i), mul(i, i);
  clear(d + 5);
  for (int i = 0; i <= d; ++i) qmul(a[i], i + 3, d + 5);
  clear(3);
  for (int i = 1; i <= d; ++i) add(i + 2, one, i + 3);
  for (int i = 3; i <= d + 3; ++i) add(1, i, i), add(2, i, i), mul(i, i);
  clear(d + 6);
  for (int i = 0; i <= d; ++i) qmul(a[i], i + 3, d + 6);
  clear(d + 7);
  qmul(mod - 1, d + 4, d + 7);
  qmul(mod - 1, d + 5, d + 7);
  add(d + 6, d + 7, d + 7);
  clear(d + 8);
  qmul((mod + 1) >> 1, d + 7, d + 8);
  printf("f %d", d + 8);
  return 0;
}
