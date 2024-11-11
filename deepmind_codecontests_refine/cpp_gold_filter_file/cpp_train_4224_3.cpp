#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
long long dp[10001][2];
long long p[10001], s[10001];
int n;
long long c;
long long ans;
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[0][1] = dp[0][0] + p[i];
    for (int j = 1; j < i; j++) {
      dp[j][1] = min(dp[j - 1][0] + s[i], dp[j][0] + p[i] + c * j);
    }
    dp[i][1] = dp[i - 1][0] + s[i];
    for (int j = 0; j <= n; j++) dp[j][0] = dp[j][1];
  }
  ans = INF;
  for (int j = 0; j <= n; j++) ans = min(ans, dp[j][0]);
  cout << ans << endl;
  return 0;
}
