#include <bits/stdc++.h>
using namespace std;
long long int dp[100006][2], dp2[100006][2], a[100006];
int n;
void compute() {
  dp[0][0] = 0;
  dp[0][1] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] != 1)
      dp[i][0] = dp[i - 1][0] + a[i] - a[i] % 2;
    else
      dp[i][0] = 0;
    dp[i][1] = dp[i - 1][1] + a[i] - 1 + a[i] % 2;
    dp[i][1] = max(dp[i][1], dp[i][0]);
  }
  dp2[n - 1][0] = 0;
  dp2[n - 1][1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i + 1] != 1)
      dp2[i][0] = dp2[i + 1][0] + a[i + 1] - a[i + 1] % 2;
    else
      dp2[i][0] = 0;
    dp2[i][1] = dp2[i + 1][1] + a[i + 1] - 1 + a[i + 1] % 2;
    dp2[i][1] = max(dp2[i][1], dp2[i][0]);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) cin >> a[i];
  compute();
  long long int ans = 0, temp;
  for (int i = 0; i < n; i++) {
    temp = dp[i][0] + dp2[i][1];
    ans = max(ans, temp);
    temp = dp2[i][0] + dp[i][1];
    ans = max(ans, temp);
  }
  cout << ans << endl;
}
