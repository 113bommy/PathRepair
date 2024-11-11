#include <bits/stdc++.h>
using namespace std;
const long long mod = 10000007;
const long long maxn = 85;
struct Matrix {
  long long n, m;
  long long v[maxn][maxn];
  Matrix(long long n, long long m) : n(n), m(m) { init(); }
  void init() {
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++) v[i][j] = 0;
  }
  Matrix operator*(Matrix &b) const {
    Matrix c(n, b.m);
    c.init();
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= b.m; j++)
        for (long long k = 1; k <= m; k++) {
          c.v[i][j] += v[i][k] * b.v[k][j];
          c.v[i][j] %= mod;
        }
    return c;
  }
  void prll() {
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) cout << v[i][j] << " ";
      cout << endl;
    }
  }
};
Matrix unit(maxn - 1, maxn - 1);
void init() {
  memset(unit.v, 0, sizeof(unit.v));
  for (long long i = 1; i <= maxn - 1; i++) unit.v[i][i] = 1;
}
Matrix fp(Matrix &a, long long n) {
  Matrix res = unit;
  res.n = res.m = a.n;
  while (n) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}
long long C[45][45];
int main() {
  init();
  for (long long i = 0; i <= 42; i++) C[i][0] = C[i][i] = 1;
  for (long long i = 2; i <= 42; i++)
    for (long long j = 1; j < i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  long long n, k;
  cin >> n >> k;
  Matrix t(2 * k + 3, 2 * k + 3), a1(2 * k + 3, 1);
  for (long long i = 1; i <= k + 1; i++) {
    for (long long j = 1; j <= i; j++)
      t.v[i][j] = t.v[i + k + 1][j] = t.v[i][j + k + 1] = C[i - 1][j - 1];
  }
  t.v[2 * k + 3][k + 1] = t.v[2 * k + 3][2 * k + 3] = 1;
  for (long long i = 1; i <= 2 * k + 2; i++) a1.v[i][1] = 1;
  if (n == 1)
    printf("1\n");
  else {
    t = fp(t, n);
    cout << (t * a1).v[2 * k + 3][1] << endl;
  }
}
