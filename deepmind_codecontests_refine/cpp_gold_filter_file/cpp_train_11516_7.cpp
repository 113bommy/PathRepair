#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int maxn = 309;
int f[maxn][maxn], cnt[maxn], C[maxn][maxn], fac[maxn], vis[maxn], a[maxn];
int n, m, num;
bool check(long long x) {
  long long l = 1, r = 1e9, mid;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    if (mid * mid <= x)
      l = mid;
    else
      r = mid - 1;
  }
  return l * l == x;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    cnt[++num] = 1;
    for (int j = i + 1; j <= n; j++)
      if (check(1LL * a[i] * a[j])) {
        cnt[num]++;
        vis[j] = 1;
      }
  }
  C[0][0] = 1;
  for (int i = 1; i < maxn; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
  f[1][cnt[1] - 1] = 1;
  m = cnt[1];
  for (int i = 2; i <= num; i++) {
    for (int j = 0; j <= m - 1; j++)
      for (int k = 1; k <= cnt[i]; k++)
        for (int p = 0; p <= k && p <= j; p++)
          f[i][j + cnt[i] - k - p] =
              (f[i][j + cnt[i] - k - p] +
               1LL * f[i - 1][j] * C[cnt[i] - 1][k - 1] % MOD * C[j][p] % MOD *
                   C[m - 1 - j + 2][k - p]) %
              MOD;
    m += cnt[i];
  }
  int ans = f[num][0];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % MOD;
  for (int i = 1; i <= num; i++) ans = 1LL * ans * fac[cnt[i]] % MOD;
  printf("%d\n", ans);
  return 0;
}
