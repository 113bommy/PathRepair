#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, k, a[maxn], f[5005], w[15];
int cnt[maxn], num[maxn], dp[5005][521];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(cnt, 0, sizeof cnt);
  memset(num, 0, sizeof num);
  cin >> n >> k;
  for (int i = 1; i <= n * k; i++) cin >> a[i], cnt[a[i]]++;
  for (int i = 1; i <= n; i++) cin >> f[i], num[f[i]]++;
  for (int i = 1; i <= k; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) {
    dp[i][1] = w[min(i, k)];
    for (int j = 2; j <= n; j++) {
      for (int u = 1; u <= min(i, k); u++)
        dp[i][j] = max(dp[i][j], dp[i - u][j - 1] + w[u]);
    }
  }
  long long ans = 0;
  for (int i = 1; i < maxn; i++)
    if (num[i]) ans += dp[cnt[i]][num[i]];
  cout << ans << endl;
  return 0;
}
