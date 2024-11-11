#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long mod = 1e9 + 7;
long long qpow(long long a, long long n) {
  long long ans = 1;
  long long base = a;
  while (n) {
    if (n & 1) ans = ans * base % mod;
    base = base * base % mod;
    n >>= 1;
  }
  return ans;
}
long long ol(long long x) {
  long long i, res = x;
  for (i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      res = res - res / i;
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) res = res - res / x;
  return res;
}
int N = 5;
struct Matrix {
  long long matrix[5][5];
};
Matrix a, b;
void init(Matrix &res) {
  memset(res.matrix, 0, sizeof(res.matrix));
  for (int i = 0; i < N; i++) res.matrix[i][i] = 1;
}
Matrix multiplicative(Matrix a, Matrix b) {
  Matrix res;
  memset(res.matrix, 0, sizeof(res.matrix));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        res.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
        res.matrix[i][j] += mod;
        res.matrix[i][j] %= mod;
      }
    }
  }
  return res;
}
Matrix Pow(Matrix mx, long long m) {
  Matrix res, base = mx;
  init(res);
  while (m) {
    if (m & 1) res = multiplicative(res, base);
    base = multiplicative(base, base);
    m >>= 1;
  }
  return res;
}
long long n, f1, f2, f3, c;
Matrix ATP, ADP, TCP, UDP;
int main() {
  scanf("%lld%lld%lld%lld%lld", &n, &f1, &f2, &f3, &c);
  memset(a.matrix, 0, sizeof(a.matrix));
  memset(b.matrix, 0, sizeof(b.matrix));
  mod -= 1;
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 1;
  a.matrix[0][2] = 1;
  a.matrix[0][3] = 1;
  a.matrix[0][4] = 1;
  a.matrix[1][0] = 1;
  a.matrix[2][1] = 1;
  a.matrix[3][3] = 1;
  a.matrix[3][4] = (-qpow(3, (ol(mod) - 1 + mod) % mod) + mod) % mod;
  a.matrix[4][4] = 1;
  b.matrix[0][0] = 1;
  b.matrix[0][1] = 1;
  b.matrix[0][2] = 1;
  b.matrix[1][0] = 1;
  b.matrix[2][1] = 1;
  ATP.matrix[3][0] = 8;
  ATP.matrix[4][0] = (-6 + mod) % mod;
  Matrix op = Pow(a, n - 3);
  Matrix ty = multiplicative(op, ATP);
  long long you = ty.matrix[0][0];
  N = 3;
  long long ans = 1;
  mod++;
  ans = ans * qpow(c, you) % mod;
  mod--;
  ADP.matrix[2][0] = 1;
  TCP.matrix[1][0] = 1;
  UDP.matrix[0][0] = 1;
  Matrix tp = Pow(b, n - 3);
  Matrix p1 = multiplicative(tp, ADP);
  Matrix p2 = multiplicative(tp, TCP);
  Matrix p3 = multiplicative(tp, UDP);
  mod++;
  ans = ans * qpow(f1, p1.matrix[0][0]) % mod;
  ans = ans * qpow(f2, p2.matrix[0][0]) % mod;
  ans = ans * qpow(f3, p3.matrix[0][0]) % mod;
  printf("%lld\n", ans);
}
