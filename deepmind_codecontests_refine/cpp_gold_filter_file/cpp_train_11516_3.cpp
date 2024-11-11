#include <bits/stdc++.h>
using namespace std;
const int N = 305;
const int MX = 305;
const long long mod = 1e9 + 7;
long long dp[N][N], f[N], invf[N];
long long pow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
void init() {
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
  invf[N - 1] = pow(f[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1) % mod;
}
long long C(int n, int m) {
  if (n < 0 || m < 0 || m > n) return 0;
  if (!m || m == n) return 1;
  return f[n] * invf[n - m] % mod * invf[m] % mod;
}
bool check(long long x) {
  long long l = 1, r = 1e9;
  while (l <= r) {
    long long m = (l + r) >> 1;
    if (m * m == x) return 1;
    if (m * m < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return 0;
}
long long a[305];
int sz, cnt[N], vis[N];
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    sz++;
    for (int j = i; j <= n; j++) {
      if (check(a[i] * a[j])) vis[j] = 1, cnt[sz]++;
    }
  }
  int m = cnt[1] - 1;
  dp[1][m] = 1;
  for (int i = 2; i <= sz; m += cnt[i++]) {
    for (int j = 0; j <= m; j++) {
      if (dp[i - 1][j] == 0) continue;
      for (int k = 0; k < cnt[i]; k++) {
        for (int p = 0; p <= min(k + 1, j); p++) {
          long long tmp = dp[i - 1][j] * C(cnt[i] - 1, k) % mod * C(j, p) %
                          mod * C(m + 2 - j, k + 1 - p) % mod;
          dp[i][j + cnt[i] - 1 - k - p] += tmp;
          dp[i][j + cnt[i] - 1 - k - p] %= mod;
        }
      }
    }
  }
  long long ans = dp[sz][0];
  for (int i = 1; i <= sz; i++) ans = ans * f[cnt[i]] % mod;
  printf("%lld\n", ans);
  return 0;
}
