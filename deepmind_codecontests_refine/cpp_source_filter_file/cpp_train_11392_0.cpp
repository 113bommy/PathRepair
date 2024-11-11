#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3003;
const long long INF = (1LL << 60LL);
int n;
pair<int, int> a[MAXN];
long long dp[MAXN][MAXN];
int main() {
  cin.sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  sort(a + 1, a + n + 1);
  dp[1][1] = a[1].second;
  for (int i = 1; i < n; i++) {
    dp[i][i] = INF;
    for (int j = 1; j < i; j++) {
      dp[i][j] = dp[i - 1][j] + a[i].first - a[j].first;
      dp[i][i] = min(dp[i][i], dp[i - 1][j] + a[i].second);
    }
  }
  long long ans = INF;
  for (int i = 1; i <= n; i++) ans = min(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
