#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int32_t main() {
  if (fopen("input.txt", "r"))
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long a[n], dp[n + 110][101], c[n + 110][101];
  for (long long i = 0; i < n; i++) cin >> a[i];
  memset(dp, 0, sizeof dp);
  memset(c, 0, sizeof c);
  c[0][0] = 1;
  for (long long i = 1; i < n + 110; i++) {
    c[i][0] = 1;
    for (long long j = 1; j < min(101LL, i); j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  while (m--) {
    long long l, r, k;
    cin >> l >> r >> k;
    l--, r--;
    dp[l][k] = (dp[l][k] + 1) % mod;
    for (long long i = 0; i <= k; i++)
      dp[r + 1][i] = (dp[r + 1][i] + mod - c[r - l + 1 + k - i][k - i]) % mod;
  }
  for (long long i = 100; i; --i) {
    long long p = 0;
    for (long long j = 0; j < n; j++) {
      p = (p + dp[j][i]) % mod;
      dp[j][i - 1] = (dp[j][i - 1] + p) % mod;
    }
  }
  long long p = 0;
  for (long long i = 0; i < n; i++) {
    p = (p + dp[i][0]) % mod;
    cout << (p + a[i]) % mod << " ";
  }
}
