#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
const int oo = 1e9;
const int MOD = 1000000007;
int n, a[N];
long long first, second, p, sum = 0;
long long adl(long long a, long long b) { return (a + b) % p; }
long long subl(long long a, long long b) { return (a % p - b % p + p) % p; }
long long mul(long long a, long long b) { return ((a % p) * (b % p)) % p; }
struct matrix {
  long long mat[2][2];
  matrix() { memset(mat, 0, sizeof mat); }
  matrix operator*(const matrix &f) {
    matrix res;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
        res.mat[i][j] = 0;
        for (int k = 0; k < 2; ++k)
          res.mat[i][j] = adl(res.mat[i][j], mul(mat[i][k], f.mat[k][j]));
      }
    return res;
  }
};
long long fib(long long first) {
  matrix base;
  base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1;
  matrix res;
  res.mat[0][0] = res.mat[1][1] = 1;
  while (first) {
    if (first & 1) res = res * base;
    first = first >> 1;
    base = base * base;
  }
  return res.mat[0][1];
}
long long fast(long long a, long long b) {
  if (!b) return 1ll;
  long long rs = fast(a, b / 2);
  rs = mul(rs, rs);
  if (b & 1) return mul(rs, a);
  return rs;
}
long long geo(long long n) {
  if (n == 0) return 1;
  long long res = geo(n / 2);
  long long fw = fast(3, n / 2 + 1);
  long long ls = adl(res, mul(fw, res));
  if (n & 1) return ls;
  return subl(ls, fast(3, n + 1));
}
long long fn(long long sum, long long c, long long first) {
  if (first == 0) return sum;
  long long fn = mul(sum, fast(3, first));
  long long go = mul(c, geo(first - 1));
  fn = subl(fn, go);
  return fn;
}
long long fd(long long first, long long second, long long go) {
  if (first > second) swap(first, second);
  if (go == 0) return second;
  long long d = fib(go), m = fib(go + 1);
  return adl(mul(first, d), mul(second, m));
}
long long g[100000];
int main() {
  cin >> n >> first >> second >> p;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), sum = (sum + a[i]) % p;
  if (n == 1) {
    printf("%d\n", a[0]);
    return 0;
  }
  long long c = adl(a[0], a[n - 1]);
  sum = fn(sum, c, first);
  long long f, k, z;
  f = k = z = 0;
  for (int i = 0; i + 1 < n; ++i)
    if (a[i] + a[i + 1] > z) z = a[i] + a[i + 1], f = a[i], k = a[i + 1];
  long long lar = first == 0 ? a[n - 1] : fd(f, k, first);
  c = adl(a[0], lar);
  long long res = fn(sum, c, second);
  cout << res << endl;
  return 0;
}
