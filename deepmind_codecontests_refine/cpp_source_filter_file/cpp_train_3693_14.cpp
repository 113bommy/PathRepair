#include <bits/stdc++.h>
using namespace std;
const int maxn = 405, mod = 1e4 + 7;
char s[maxn];
int n, m, n24, n25, n26, len, f[maxn][maxn][maxn];
struct matrix {
  int n, m, a[maxn][maxn];
  matrix(int _n = 0, int _m = 0) {
    n = _n;
    m = _m;
    memset(a, 0, sizeof(a));
  }
  int* operator[](int x) { return a[x]; }
  matrix operator*(matrix b) {
    matrix ans(n, b.m);
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j)
        for (int k = i; k <= j; ++k)
          ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
    return ans;
  }
} A, B;
matrix fpow(matrix A, int k) {
  matrix res = matrix(A.n, A.m);
  for (int i = 0; i <= res.n; ++i) res[i][i] = 1;
  while (k) {
    if (k & 1) res = res * A;
    k >>= 1;
    A = A * A;
  }
  return res;
}
int main() {
  scanf("%s%d", s + 1, &m);
  n = strlen(s + 1);
  for (int i = 0; i <= n; ++i)
    for (int l = n; l >= 1; --l)
      for (int r = l; r <= n; ++r)
        if (l == r)
          f[i][l][r] = i == 0;
        else if (s[l] == s[r])
          f[i][l][r] = l + 1 == r ? i == 0 : f[i][l + 1][r - 1];
        else if (i) {
          f[i][l][r] = f[i - 1][l + 1][r] + f[i - 1][l][r - 1];
          if (f[i][l][r] >= mod) f[i][l][r] -= mod;
        }
  n24 = n - 1;
  n25 = (n + 1) >> 1;
  n26 = n25;
  len = n24 + n25 + n26;
  A.n = A.m = len;
  for (int i = 1; i <= n24; ++i) A[i][i] = 24, A[i][i + 1] = 1;
  for (int i = n24 + 1; i <= n24 + n25; ++i)
    A[i][i] = 25, A[i][i + n25] = A[i - 1][i] = 1;
  for (int i = n24 + n25 + 1; i <= len; ++i) A[i][i] = 26;
  m += n;
  B = fpow(A, (m + 1) / 2 - 1);
  A = A * B;
  int ans = 0;
  for (int i = 1, j; i <= n24; ++i) {
    if ((m + 1) / 2 < i + (j = (n + 1 - i) / 2)) continue;
    ans = (ans + f[i][1][n] * A[n24 - i + 1][n24 + n25 + j]) % mod;
    if ((m & 1) && (~(n - i) & 1))
      ans = (ans + (mod - f[i][1][n]) * B[n24 - i + 1][n24 + j]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
