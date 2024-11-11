#include <bits/stdc++.h>
using namespace std;
long long dp[25][5][2][12];
int n, t;
long long solve(int idx, int prev, bool increasing, int humps) {
  long long &ans = dp[idx][prev][increasing][humps];
  if (ans != -1) return ans;
  if (idx == n + 1) {
    if (humps == t && !increasing) return ans = 1;
    return ans = 0;
  }
  ans = 0;
  for (int i = 1; i <= 4; i++) {
    if (idx < 3 && i < prev) continue;
    if (increasing && i > prev)
      ans += solve(idx + 1, i, increasing, humps);
    else if (increasing && i < prev)
      ans += solve(idx + 1, i, false, humps + 1);
    else if (!increasing && i < prev)
      ans += solve(idx + 1, i, increasing, humps);
    else if (!increasing && i > prev)
      ans += solve(idx + 1, i, true, humps);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n >> t;
  cout << solve(1, 0, false, 0) << endl;
  return 0;
}
