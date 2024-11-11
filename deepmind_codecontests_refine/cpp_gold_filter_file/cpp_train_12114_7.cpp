#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long m, l, r, k;
struct Matrix {
  int n, m;
  long long mat[5][5];
  Matrix() { memset(mat, 0, sizeof mat); }
};
Matrix operator*(const Matrix& a, const Matrix& b) {
  Matrix c;
  c.n = a.n;
  c.m = b.m;
  for (int i = 1; i <= c.n; ++i) {
    for (int j = 1; j <= c.m; ++j) {
      for (int k = 1; k <= a.m; ++k) {
        (c.mat[i][j] += a.mat[i][k] * b.mat[k][j] % m) %= m;
      }
    }
  }
  return c;
}
Matrix matpow(Matrix a, long long b) {
  Matrix res;
  res.n = a.n;
  res.m = a.m;
  for (int i = 1; i <= res.n; ++i) res.mat[i][i] = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long getFi(long long x) {
  if (x <= 2) return 1;
  Matrix a, b;
  a.n = 1;
  a.m = 2;
  a.mat[1][1] = a.mat[1][2] = 1;
  b.n = b.m = 2;
  b.mat[1][2] = b.mat[2][1] = b.mat[2][2] = 1;
  return (a * matpow(b, x - 2)).mat[1][2];
}
int main() {
  scanf("%lld%lld%lld%lld", &m, &l, &r, &k);
  --l;
  if (m == 1) return puts("0"), 0;
  long long now = 1, ans = 1, kl, kr, tol, tor, to;
  while (now <= r) {
    kl = l / now;
    kr = r / now;
    tol = kl ? l / kl : INF;
    tor = kr ? r / kr : INF;
    to = min(tol, tor);
    if (to <= INF && kr - kl >= k) ans = to;
    now = to + 1;
  }
  printf("%lld", getFi(ans));
  return 0;
}
