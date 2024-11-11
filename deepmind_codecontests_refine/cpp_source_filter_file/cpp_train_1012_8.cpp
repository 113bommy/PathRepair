#include <bits/stdc++.h>
using namespace std;
long long ans, n, k, h[11], cnt[100005], f[100005], dp[505][5005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (long long i = 0, x; i < n * k; i++) cin >> x, cnt[x]++;
  for (long long i = 0, x; i < n; i++) cin >> x, f[x]++;
  for (long long i = 1; i <= k; i++) cin >> h[i];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j <= n * k; j++)
      for (long long cur = 0; cur <= k; cur++)
        dp[i + 1][j + cur] = max(dp[i + 1][j + cur], dp[i][j] + h[cur]);
  for (long long i = 0; i < 100005; i++)
    if (f[i]) ans += dp[f[i]][cnt[i]];
  cout << ans << "\n";
}
