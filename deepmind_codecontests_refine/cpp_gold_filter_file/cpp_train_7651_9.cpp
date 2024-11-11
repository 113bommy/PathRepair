#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, inf = 1e9 + 7;
long long n, k, i, j;
long long A[N], dp[31][31][51];
long long solve(long long n, long long m, long long k) {
  if (k > n * m || k < 0) return inf;
  long long& ans = dp[n][m][k];
  if (ans != -1) return ans;
  if (n * m == k || k == 0) return ans = 0;
  ans = inf;
  for (long long i = 1; i < n; i++)
    for (long long j = 0; j <= k; j++)
      ans = min(ans, solve(i, m, j) + solve(n - i, m, k - j) + m * m);
  for (long long i = 1; i < m; i++)
    for (long long j = 0; j <= k; j++)
      ans = min(ans, solve(n, i, j) + solve(n, m - i, k - j) + n * n);
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, a, b, ans = 0, t, m;
  cin >> t;
  memset(dp, -1, sizeof dp);
  while (t--) {
    cin >> n >> m >> k;
    cout << solve(n, m, k) << "\n";
  }
}
