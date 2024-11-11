#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct matrix {
  int i;
  long long a[5][5];
  void init() {
    memset(a, 0, sizeof(a));
    for (i = 0; i < 5; i++) {
      a[i][i] = 1;
    }
  }
};
matrix multi(matrix a, matrix b, long long md) {
  matrix ans;
  int i, j, k;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      ans.a[i][j] = 0;
      for (k = 0; k < 5; k++) {
        ans.a[i][j] += a.a[i][k] * b.a[k][j];
        ans.a[i][j] %= md;
      }
    }
  }
  return ans;
}
matrix qpow(matrix m, long long n, long long md) {
  matrix temp;
  temp.init();
  while (n) {
    if (n & 1) temp = multi(temp, m, md);
    n >>= 1;
    temp = multi(temp, temp, md);
  }
  return temp;
}
long long qpow_number(long long m, long long n, long long md) {
  long long temp;
  if (n == 0) return 1;
  temp = qpow_number(m, n >> 1, md);
  if (n % 2 == 0)
    return temp * temp % md;
  else
    return m * temp % mod * temp % md;
}
int main() {
  long long n, f1, f2, f3, c, exp_c, exp_f1, exp_f2, exp_f3, ff1, ff2, ff3, cc,
      ans;
  scanf("%lld%lld%lld%lld%lld", &n, &f1, &f2, &f3, &c);
  matrix a, final, temp, first;
  memset(a.a, 0, sizeof(a.a));
  a.a[3][0] = 2;
  a.a[4][0] = 1;
  memset(first.a, 0, sizeof(first.a));
  first.a[0][0] = 1;
  first.a[0][1] = 1;
  first.a[0][2] = 1;
  first.a[0][3] = 1;
  first.a[3][3] = 1;
  first.a[3][4] = 2;
  first.a[4][4] = 1;
  first.a[1][0] = 1;
  first.a[2][1] = 1;
  temp = qpow(first, n - 3, mod - 1);
  exp_c = multi(temp, a, mod - 1).a[0][0];
  cc = qpow_number(c, exp_c, mod);
  memset(first.a, 0, sizeof(first.a));
  first.a[0][0] = 1;
  first.a[0][1] = 1;
  first.a[0][2] = 1;
  first.a[1][0] = 1;
  first.a[2][1] = 1;
  temp = qpow(first, n - 3, mod - 1);
  memset(a.a, 0, sizeof(a.a));
  a.a[2][0] = 1;
  exp_f1 = multi(temp, a, mod - 1).a[0][0];
  memset(a.a, 0, sizeof(a.a));
  a.a[1][0] = 1;
  exp_f2 = multi(temp, a, mod - 1).a[0][0];
  memset(a.a, 0, sizeof(a.a));
  a.a[0][0] = 1;
  exp_f3 = multi(temp, a, mod - 1).a[0][0];
  ff1 = qpow_number(f1, exp_f1, mod);
  ff2 = qpow_number(f2, exp_f2, mod);
  ff3 = qpow_number(f3, exp_f3, mod);
  ans = cc * ff1 % mod * ff2 % mod * ff3 % mod;
  printf("%lld\n", ans);
  return 0;
}
