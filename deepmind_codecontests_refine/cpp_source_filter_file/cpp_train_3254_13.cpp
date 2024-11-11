#include <bits/stdc++.h>
using namespace std;
bool checkSum(vector<int> &arr, int sum) {
  int n = arr.size();
  bool dp[n + 1][sum + 1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= sum; j++) dp[i][j] = false;
  for (int i = 0; i <= n; i++) dp[i][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      dp[i][j] = dp[i - 1][j];
      if (arr[i] <= j) {
        dp[i][j] = dp[i][j] | dp[i - 1][j - arr[i]];
      }
    }
  }
  return dp[n][sum];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[2 * n];
    int max[2 * n];
    int m_i = -1;
    for (int i = 0; i < 2 * n; i++) {
      cin >> arr[i];
      max[i] = m_i;
      if (m_i == -1) {
        m_i = i;
      } else if (arr[m_i] < arr[i]) {
        m_i = i;
      }
    }
    int i = 2 * n;
    vector<int> jumps;
    while (i > 0) {
      int x = i - m_i;
      jumps.push_back(x);
      i = m_i;
      m_i = max[i];
    }
    bool possible = checkSum(jumps, n);
    if (possible)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
