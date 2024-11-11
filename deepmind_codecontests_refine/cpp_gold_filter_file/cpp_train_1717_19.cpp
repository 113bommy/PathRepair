#include <bits/stdc++.h>
using namespace std;
struct Matrix {
  long long a[4][4];
};
long long n;
long long k;
int l;
long long m;
Matrix sub(Matrix aa, Matrix bb) {
  Matrix res;
  memset(res.a, 0, sizeof res.a);
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j)
      for (int k = 1; k <= 3; ++k)
        res.a[i][j] = (res.a[i][j] + (1LL * aa.a[i][k] * bb.a[k][j]) % m) % m;
  return res;
}
int main(int argc, char const *argv[]) {
  scanf("%I64d%I64d%d%I64d", &n, &k, &l, &m);
  if ((l < 63 && k >= (1LL << (long long)l))) {
    printf("0\n");
    return 0;
  }
  Matrix ans;
  Matrix base;
  memset(ans.a, 0, sizeof(ans.a));
  memset(base.a, 0, sizeof base.a);
  base.a[1][1] = base.a[1][2] = base.a[2][1] = base.a[3][2] = 1;
  base.a[3][3] = 2;
  ans.a[1][1] = 2;
  ans.a[2][1] = 1;
  ans.a[3][1] = 1;
  n -= 2;
  while (n) {
    if (n % 2) ans = sub(base, ans);
    base = sub(base, base);
    n /= 2;
  }
  long long res = 1;
  for (int i = 0; i <= l - 1; ++i) {
    if ((k & (1LL << i)) == 0) {
      res = res * (ans.a[1][1] + ans.a[2][1]) % m;
    } else
      res = (res * ans.a[3][1]) % m;
  }
  printf("%I64d\n", res % m);
  return 0;
}
