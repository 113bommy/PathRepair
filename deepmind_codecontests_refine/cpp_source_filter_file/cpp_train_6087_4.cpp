#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 7 | 1, M = 998244353;
int dp[N], x, f[N], n;
struct zz {
  int a[N][N];
} A;
zz cf(zz x, zz y) {
  zz z;
  memset(z.a, 0, sizeof z.a);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        z.a[i][j] = (z.a[i][j] + (long long)x.a[i][k] * y.a[k][j]) % M;
  return z;
}
zz ksm(zz x, int y) {
  zz ans;
  memset(ans.a, 0, sizeof ans.a);
  for (int i = 0; i < n; i++) ans.a[i][i] = 1;
  for (; y; y >>= 1, x = cf(x, x))
    if (y & 1) ans = cf(ans, x);
  return ans;
}
int main() {
  dp[0] = 1;
  for (int T = 1; T <= 7; T++) {
    n = 1 << T;
    for (int j = 0; j < n / 2; j++) dp[j + n / 2] = dp[j], dp[j] = 0;
    memset(A.a, 0, sizeof A.a);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n / 2; k++) {
          int flag = 1;
          for (int l = 0; l < T; l++)
            if ((l == 0 || (1 << (l - 1) & k)) &&
                (l == T - 1 || ((1 << l) & k)) && ((1 << l) & i) &&
                ((1 << l) & j))
              flag = 0;
          A.a[i][j] += flag;
        }
    scanf("%d", &x);
    A = ksm(A, x);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        f[j] = (f[j] + (long long)dp[i] * A.a[i][j]) % M;
    for (int i = 0; i < n; i++) dp[i] = f[i], f[i] = 0;
  }
  printf("%d\n", dp[(1 << 7) - 1]);
}
