#include <bits/stdc++.h>
constexpr long long inf = 1e9 + 7, N = 1e5 + 70;
using namespace std;
long long k, n, a[N], vis[N], psum[N], x, dp[5005][5005];
long long calc(long long i, long long j, long long pos) {
  if (i < 0 || j < 0) return inf;
  if (dp[i][j] != -1) return dp[i][j];
  if (i == 0 && j == 0) return 0;
  return dp[i][j] =
             min(calc(i - 1, j, pos - x) + psum[pos] - psum[pos - x + 1],
                 calc(i, j - 1, pos - x - 1) + psum[pos] - psum[pos - x]);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long kk = n % k;
  x = n / k;
  memset(dp, -1, sizeof dp);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (long long i = 2; i <= n; i++)
    psum[i] = psum[i - 1] + abs(a[i] - a[i - 1]);
  cout << calc(k - kk, kk, n);
}
