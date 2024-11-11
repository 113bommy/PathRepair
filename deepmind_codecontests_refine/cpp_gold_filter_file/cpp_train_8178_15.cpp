#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, time, res;
  cin >> n;
  int dp[n + 1], Time[n + 1];
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> Time[i];
    res = dp[i - 1] + 20;
    time = Time[i] - 90;
    auto pos1 = upper_bound(Time + 1, Time + i + 1, time) - Time;
    pos1--;
    if (pos1 < i) res = min(res, dp[pos1] + 50);
    time = Time[i] - 1440;
    auto pos2 = upper_bound(Time + 1, Time + i + 1, time) - Time;
    pos2--;
    if (pos2 < i) res = min(res, dp[pos2] + 120);
    dp[i] = res;
    cout << res - dp[i - 1] << endl;
  }
  return 0;
}
