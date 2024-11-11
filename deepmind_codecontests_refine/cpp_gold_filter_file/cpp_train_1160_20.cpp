#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long dp[100013] = {};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<long long> in_;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    in_.push_back(h);
  }
  dp[1] = in_[0] * (n + 1 - in_[0]);
  for (int i = 2; i <= n; ++i) {
    if (in_[i - 1] > in_[i - 2]) {
      dp[i] = dp[i - 1] + (in_[i - 1] - in_[i - 2]) * (n + 1 - in_[i - 1]);
    } else {
      dp[i] = dp[i - 1] + (in_[i - 1]) * (in_[i - 2] - in_[i - 1]);
    }
  }
  cout << dp[n];
}
