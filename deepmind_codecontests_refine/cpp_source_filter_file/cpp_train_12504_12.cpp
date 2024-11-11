#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int a, dp[200010][2], n, k, ans, minvalue = LONG_MAX;
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a;
    dp[a][0]++;
    dp[a][1]++;
    minvalue = min(a, minvalue);
  }
  for (int i = 200000; i > minvalue; i--) {
    dp[i][1] += dp[i + 1][1];
    dp[i][0] += dp[i + 1][0] + dp[i + 1][1];
    if (dp[i][0] >= k) {
      dp[i][0] -= dp[i + 1][0];
      ans++;
    }
  }
  if (dp[minvalue + 1][0]) ans++;
  cout << ans;
}
int main() { solve(); }
