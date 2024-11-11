#include <bits/stdc++.h>
using namespace std;
long long n, k, x[1010], dp[1010][1010], sm[1010];
long long solve(long long gap) {
  dp[0][0] = 1, x[0] = -200000;
  for (long long i = 1; i <= k; ++i) {
    for (long long j = 0; j <= n; ++j)
      sm[j] = j == 0 ? dp[i - 1][j] : (dp[i - 1][j] + sm[j - 1]) % 998244353;
    long long pos = 0;
    for (long long j = 1; j <= n; ++j) {
      while (x[j] - x[pos + 1] >= gap) pos++;
      dp[i][j] = sm[pos];
    }
  }
  long long sum = 0;
  for (long long i = 1; i <= n; ++i) sum = (sum + dp[k][i]) % 998244353;
  return sum;
}
int32_t main() {
  cin.tie(0), cout.sync_with_stdio(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) cin >> x[i];
  sort(x + 1, x + 1 + n);
  long long dis = 100000 / (n - 1), pre = solve(1), ans = 0;
  for (long long i = 2; i <= dis + 5; ++i) {
    long long now = solve(i);
    ans = (ans + (pre - now + 998244353) * (i - 1)) % 998244353;
    pre = now;
  }
  cout << ans << "\n";
  return 0;
}
