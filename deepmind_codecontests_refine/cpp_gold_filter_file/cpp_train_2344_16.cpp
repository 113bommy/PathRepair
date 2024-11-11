#include <bits/stdc++.h>
using namespace std;
int mod;
struct Matrix {
  int a[3][3];
  void clean() {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) a[i][j] = 0;
  }
  void id() {
    clean();
    for (int i = 0; i < 3; i++) a[i][i] = 1;
  }
  Matrix() { clean(); }
  void Print() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) printf("%i ", a[i][j]);
      printf("\n");
    }
  }
} fib, base;
Matrix operator*(Matrix a, Matrix b) {
  Matrix ans;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ans.a[i][j] = 0;
      for (int k = 0; k < 3; k++)
        ans.a[i][j] += (long long)a.a[i][k] * b.a[k][j] % mod,
            ans.a[i][j] %= mod;
    }
  }
  return ans;
}
Matrix pow(Matrix x, long long k) {
  Matrix ret;
  ret.id();
  for (; k; k >>= 1, x = x * x)
    if (k & 1) ret = ret * x;
  return ret;
}
const int N = 1000050;
int a[N];
int main() {
  int n, sum = 0, i;
  long long x, y;
  scanf("%i %lld %lld %i", &n, &x, &y, &mod);
  for (i = 1; i <= n; i++) scanf("%i", &a[i]), sum += a[i], sum %= mod;
  if (n == 1) return 0 * printf("%i\n", a[1] % mod);
  fib.a[0][0] = 1;
  fib.a[1][0] = 1;
  fib.a[0][1] = 1;
  fib.a[1][1] = 0;
  base.a[0][0] = 3;
  base.a[0][1] = 0;
  base.a[0][2] = 0;
  base.a[1][0] = mod - 1;
  base.a[1][1] = 1;
  base.a[1][2] = 0;
  base.a[2][0] = mod - 1;
  base.a[2][1] = 0;
  base.a[2][2] = 1;
  Matrix tmp = pow(base, x);
  sum =
      (long long)sum * tmp.a[0][0] % mod + (long long)a[1] * tmp.a[1][0] % mod;
  sum %= mod;
  sum += (long long)a[n] * tmp.a[2][0] % mod;
  sum %= mod;
  int mn = a[1], mx;
  tmp = pow(fib, x);
  mx = (long long)a[n] * tmp.a[0][0] % mod +
       (long long)a[n - 1] * tmp.a[1][0] % mod;
  mx %= mod;
  tmp = pow(base, y);
  sum = (long long)sum * tmp.a[0][0] % mod + (long long)mn * tmp.a[1][0] % mod;
  sum %= mod;
  sum += (long long)mx * tmp.a[2][0] % mod;
  sum %= mod;
  printf("%i\n", sum);
  return 0;
}
