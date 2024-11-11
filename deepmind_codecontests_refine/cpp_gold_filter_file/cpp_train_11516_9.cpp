#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 500;
int n, x, a[N], C[N][N], now, cnt[N];
long long f[N][N], fac[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    for (int j = 2; j * j <= x; j++) {
      while (x % (j * j) == 0) x /= j * j;
    }
    a[i] = x;
  }
  sort(a + 1, a + n + 1);
  int now = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] == a[i - 1])
      cnt[now]++;
    else
      cnt[++now]++;
  f[1][cnt[1] - 1] = 1;
  fac[1] = 1;
  for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
  C[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i; j++)
      C[i][j] = j == 0 ? 1 : (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
  for (int i = 2, sum = cnt[1]; i <= now; i++, sum += cnt[i - 1])
    for (int j = 0; j < sum; j++)
      for (int k = 1; k <= cnt[i]; k++)
        for (int l = 0; l <= min(k, j); l++)
          f[i][j + cnt[i] - k - l] =
              (f[i][j + cnt[i] - k - l] + f[i - 1][j] * C[j][l] % MOD *
                                              C[cnt[i] - 1][k - 1] % MOD *
                                              C[sum - j + 1][k - l] % MOD) %
              MOD;
  long long ans = f[now][0];
  for (int i = 1; i <= now; i++) ans = (ans * fac[cnt[i]]) % MOD;
  printf("%I64d\n", ans);
}
