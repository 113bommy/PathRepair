#include <bits/stdc++.h>
const int mod = 1000000007;
int ans[105], mat[105][105], tmp1[105], tmp2[105][105];
long long n;
int m;
int powm(long long n) {
  while (n) {
    if (n & 1) {
      for (int i = 0; i < m; i++) tmp1[i] = 0;
      for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
          tmp1[i] = (tmp1[i] + 1LL * ans[j] * mat[j][i] % mod) % mod;
      for (int i = 0; i < m; i++) ans[i] = tmp1[i];
    }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) tmp2[i][j] = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++)
        for (int k = 0; k < m; k++)
          tmp2[i][j] = (tmp2[i][j] + 1LL * mat[i][k] * mat[k][j] % mod) % mod;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) mat[i][j] = tmp2[i][j];
    n >>= 1;
  }
  return ans[m - 1];
}
int main() {
  scanf("%I64d%d", &n, &m);
  ans[m - 1] = 1;
  for (int i = 0; i < m - 1; i++) mat[i + 1][i] = 1;
  mat[0][m - 1] = 1;
  mat[m - 1][m - 1] = 1;
  printf("%d\n", powm(n));
  return 0;
}
