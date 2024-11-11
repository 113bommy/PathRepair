#include <bits/stdc++.h>
using namespace std;
int dp[505];
int main(void) {
  int k;
  cin >> k;
  dp[1] = 0;
  for (int i = 2; i <= 500; ++i) {
    dp[i] = 1e9;
    for (int j = 1; j < i; ++j)
      dp[i] = min(dp[i], dp[i - j] + dp[j] + (i - j) * j);
  }
  string ans = "a";
  for (int i = 'b'; k && i <= 'z'; ++i) {
    int cnt = 0;
    while (dp[cnt + 1] <= k) ++cnt;
    k -= dp[cnt];
    for (int j = 0; j < cnt; ++j) ans += char(i);
  }
  cout << ans << '\n';
  return 0;
}
