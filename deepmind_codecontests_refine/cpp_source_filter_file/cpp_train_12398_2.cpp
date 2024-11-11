#include <bits/stdc++.h>
using namespace std;
long long n, a[5050], dp[5001][2505];
bool flag[5001][2505];
long long build_cost(int pos, bool f) {
  long long ans = 0;
  ans += max((long long)0, a[pos + 1] - a[pos] + 1);
  if (pos >= 2) {
    if (f)
      ans += max(min(a[pos - 2] - 1, a[pos - 1]) - (a[pos]) + 1, (long long)0);
    else
      ans += max(a[pos - 1] - (a[pos]) + 1, (long long)0);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  a[0] = a[n + 1] = -1145141919;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j <= 2500; j++) {
      dp[i][j] = 1145141919;
    }
  }
  for (int j = 0; j <= 2500; j++) dp[0][j] = 1145141919;
  dp[0][0] = dp[1][0] = 0, dp[1][1] = build_cost(1, false), flag[1][1] = true;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = dp[i - 1][0];
    for (int j = 1; j <= i / 2 + (i % 2); j++) {
      dp[i][j] = dp[i - 1][j];
      long long temp = dp[i - 2][j - 1] + build_cost(i, flag[i - 2][j - 1]);
      if (dp[i][j] > temp) {
        flag[i][j] = true;
        dp[i][j] = temp;
      }
    }
  }
  for (int j = 1; j <= (n / 2) + (n % 2); j++) {
    cout << dp[n][j] << " ";
  }
  return 0;
}
