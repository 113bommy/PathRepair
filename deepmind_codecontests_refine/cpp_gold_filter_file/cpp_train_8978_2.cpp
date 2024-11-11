#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[2 * n];
    for (int i = 0; i < 2 * n; i++) cin >> arr[i];
    vector<int> num;
    int curr = arr[0];
    int cnt = 1;
    for (int i = 1; i < 2 * n; i++) {
      if (arr[i] > curr) {
        num.push_back(cnt);
        cnt = 1;
        curr = arr[i];
      } else
        cnt++;
    }
    num.push_back(cnt);
    int len = num.size();
    bool dp[len + 1][n + 1];
    for (int i = 0; i <= len; i++) dp[i][0] = true;
    for (int i = 1; i <= n; i++) dp[0][i] = false;
    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= n; j++) {
        if (j < num[i - 1])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num[i - 1]];
      }
    }
    if (dp[len][n])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
