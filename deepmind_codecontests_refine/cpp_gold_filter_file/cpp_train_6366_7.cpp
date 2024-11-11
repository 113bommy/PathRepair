#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, k, m;
struct matrix {
  long long s[230][230];
  matrix() { memset(s, 0, sizeof(s)); }
} cs, zy;
long long count(long long x) {
  long long sum = 0;
  while (x) x -= (x & -x), sum++;
  return sum;
}
long long getid(long long x, long long y) { return x * (1 << m) + y; }
matrix operator*(matrix a, matrix b) {
  matrix c;
  for (long long i = 0; i < (k + 1) * (1 << m); i++) {
    for (long long j = 0; j < (k + 1) * (1 << m); j++) {
      for (long long l = 0; l < (k + 1) * (1 << m); l++) {
        c.s[i][j] = (c.s[i][j] + a.s[i][l] * b.s[l][j]) % mod;
      }
    }
  }
  return c;
}
matrix operator^(matrix a, long long b) {
  matrix c;
  for (long long i = 0; i < (k + 1) * (1 << m); i++) c.s[i][i] = 1;
  while (b) {
    if (b & 1) c = c * a;
    a = a * a;
    b >>= 1;
  }
  return c;
}
void solve() {
  cs.s[0][0] = 1;
  for (long long i = 0; i <= k; i++) {
    for (long long j = 0; j < (1 << m); j++) {
      zy.s[getid(i, j)][getid(i, j >> 1)] = 1;
      zy.s[getid(i, j)][getid(i + 1, (j >> 1) | (1 << (m - 1)))] = 1 + count(j);
    }
  }
  cs = cs * (zy ^ n);
}
signed main() {
  scanf("%lld%lld%lld", &n, &k, &m);
  solve();
  long long ans = 0;
  for (long long i = 0; i < (1 << m); i++)
    ans = (ans + cs.s[0][getid(k, i)]) % mod;
  printf("%lld\n", ans);
  return 0;
}
