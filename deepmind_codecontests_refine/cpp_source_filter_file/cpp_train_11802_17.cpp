#include <bits/stdc++.h>
using namespace std;
long long int MOD;
struct matrix {
  int n, m;
  long long int a[2][2];
  matrix() {}
  matrix(int n_, int m_) {
    n = n_, m = m_;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = 0;
  }
  matrix operator*(const matrix &t) {
    int p = t.m;
    matrix res(n, p);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p; j++) {
        for (int k = 0; k < m; k++) {
          long long int v = 1ll * a[i][k] * t.a[k][j] % MOD;
          res.a[i][j] = (res.a[i][j] + v) % MOD;
        }
      }
    }
    return res;
  }
  void print() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) printf("%lld ", a[i][j]);
      printf("\n");
    }
    printf("\n");
  }
};
matrix fpow(matrix a, long long int n) {
  matrix ans(a.n, a.m);
  for (int i = 0; i < a.n; i++) ans.a[i][i] = 1;
  while (n > 0) {
    if (n & 1) ans = ans * a;
    a = a * a;
    n >>= 1;
  }
  return ans;
}
int main() {
  long long int l, r, k, actual = 1;
  scanf("%lld%lld%lld%lld", &MOD, &l, &r, &k);
  for (long long int i = 2; i * i <= r; i++) {
    long long int tmp = r / i - (l - 1) / i;
    long long int tmp1 = r / i;
    long long int tmp2 = r / tmp1 - (l - 1) / tmp1;
    if (tmp >= k) actual = max(actual, i);
    if (tmp2 >= k) actual = max(actual, r / i);
  }
  matrix f(2, 2), v(2, 1);
  f.a[0][0] = f.a[1][0] = f.a[0][1] = 1;
  v.a[0][0] = v.a[1][0] = 1;
  matrix sol = fpow(f, actual - 1);
  printf("%d", sol.a[0][0]);
  return 0;
}
