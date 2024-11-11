#include <bits/stdc++.h>
using namespace std;
long long dp[2000005];
void solve() {
  int n;
  cin >> n;
  cout << (4 * dp[n]) % 1000000007 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  dp[1] = dp[2] = 0;
  for (int i = 3; i <= 2000000; ++i) {
    dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 1000000007;
    if (i % 3 == 0) {
      dp[i] = (dp[i] + 1) % 1000000007;
    }
  }
  while (t--) {
    solve();
  }
  return 0;
}
