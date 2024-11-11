#include <bits/stdc++.h>
using namespace std;
int task(vector<int> &nums, int k) {
  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] =
          max(dp[i - 1][j], dp[i - 1][j - 1] + ((nums[i - 1] == j) ? 1 : 0));
    }
  }
  int ans = INT_MAX;
  for (int i = k; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[i][j] >= k) {
        ans = min(ans, i - j);
      }
    }
  }
  if (ans == INT_MAX) {
    return -1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int j = 0; j < n; j++) {
      cin >> nums[j];
    }
    int ans = task(nums, k);
    cout << ans << '\n';
  }
}
