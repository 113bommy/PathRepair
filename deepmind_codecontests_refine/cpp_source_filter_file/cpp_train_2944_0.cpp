#include <bits/stdc++.h>
using namespace std;
void solve() {
  int b;
  cin >> b;
  int arr[b + 1];
  for (int i = 0; i < b; i++) {
    cin >> arr[i];
  }
  arr[b] = 0;
  int dp[b + 1];
  for (int i = b; i >= 0; i--) {
    if (i == b || i == b - 1 || i == b - 2 || i == b - 3) {
      dp[i] = arr[i];
      continue;
    }
    dp[i] = min(dp[i + 2], min(dp[i + 3], dp[i + 4] + arr[i + 1])) + arr[i];
  }
  cout << dp[0];
  return;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
