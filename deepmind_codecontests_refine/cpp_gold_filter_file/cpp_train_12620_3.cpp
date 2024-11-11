#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> dp(n);
  long long sum = 0;
  long long ans = 0;
  vector<int> anss(n);
  int idx = -1;
  for (int i = 0; i < n; i++) {
    sum = 0;
    dp[i] = arr[i];
    sum += dp[i];
    for (int j = i - 1; j >= 0; j--) {
      dp[j] = min(dp[j + 1], arr[j]);
      sum += dp[j];
    }
    for (int j = i + 1; j < n; j++) {
      dp[j] = min(dp[j - 1], arr[j]);
      sum += dp[j];
    }
    if (sum > ans) {
      ans = sum;
      idx = i;
    }
  }
  dp[idx] = arr[idx];
  for (int j = idx - 1; j >= 0; j--) {
    dp[j] = min(dp[j + 1], arr[j]);
  }
  for (int j = idx + 1; j < n; j++) {
    dp[j] = min(dp[j - 1], arr[j]);
  }
  for (int i = 0; i < n; i++) cout << dp[i] << " ";
}
int main() { solve(); }
