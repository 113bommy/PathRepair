#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9 + 7;
int a[2][51];
int n;
int b[51];
int dp[2][51][2][51][2];
int calc(bool r1, int i1, bool r2, int i2, bool dif) {
  if (i1 >= n || i2 >= n) return oo;
  if (r1 && r2 && i1 == i2 && i1 == n - 1) return dif ? 0 : oo;
  int &ret = dp[r1][i1][r2][i2][dif];
  if (ret != -1) return ret;
  ret = oo;
  ret = min(ret, calc(r1, i1 + 1, r2, i2 + 1, dif || (i1 != i2 || r1 != r2)) +
                     a[r1][i1] + a[r2][i2]);
  if (!r1) {
    ret = min(ret, calc(1, i1, r2, i2 + 1, dif || (i1 != i2 || r1 != r2)) +
                       b[i1] + a[r2][i2]);
    if (!r2)
      ret = min(ret, calc(1, i1, 1, i2, dif || (i1 != i2 || r1 != r2)) + b[i1] +
                         b[i2]);
  }
  if (!r2)
    ret = min(ret, calc(r1, i1 + 1, 1, i2, dif || (i1 != i2 || r1 != r2)) +
                       b[i2] + a[r1][i1]);
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j + 1 < n; ++j) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", calc(0, 0, 0, 0, 0));
  return 0;
}
