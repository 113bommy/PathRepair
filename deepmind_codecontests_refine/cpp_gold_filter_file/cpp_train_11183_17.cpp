#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int dp[10000 + 1] = {0};
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    dp[arr[i]]++;
  }
  for (int i = 1; i <= 10000; i++) dp[i] = dp[i] + dp[i - 1];
  int k;
  cin >> k;
  int MAX = 0;
  for (int i = 0; i <= 10000 - (k + 1); i++)
    MAX = max(MAX, dp[i + k + 1] - dp[i]);
  cout << MAX << '\n';
  return 0;
}
