#include <bits/stdc++.h>
using namespace std;
int n, k;
long long num[200100], sum[200100];
long long dp[200100][2];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    sum[i] = sum[i - 1] + num[i];
  }
  memset(dp, 0, sizeof(dp));
  for (int i = n - k + 1; i >= 0; i--) {
    long long tmp = sum[i + k - 1] - sum[i - 1];
    if (tmp >= dp[i + 1][1]) {
      dp[i][1] = tmp;
      dp[i][0] = i;
    } else {
      dp[i][1] = dp[i + 1][1];
      dp[i][0] = dp[i + 1][0];
    }
  }
  long long ans = 0, a = -1, b = -1;
  for (int i = 1; i + k + k - 1 <= n; i++) {
    long long now = sum[i + k - 1] - sum[i - 1];
    if (now + dp[i + k][1] > ans) {
      ans = now + dp[i + k][1];
      a = i, b = dp[i + k][0];
    }
  }
  cout << a << " " << b << endl;
  return 0;
}
