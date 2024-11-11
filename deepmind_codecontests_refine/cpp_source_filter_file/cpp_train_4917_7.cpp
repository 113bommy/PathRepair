#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int ans = 1000;
  int j;
  cin >> n;
  vector<int> vect(n);
  int dp[n][n];
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) cin >> vect[i];
  for (int size = 0; size < n; size++) {
    for (int i = 0, j = i + size; j < n; i++, j++) {
      if (i == j)
        dp[i][j] = vect[i];
      else {
        for (int k = i; k < j; k++) {
          if ((dp[i][k] == dp[k + 1][j]) && (dp[i][k] != -1))
            dp[i][j] = dp[i][k] + 1;
        }
      }
    }
  }
  int dp2[n];
  for (int i = 0; i < n; i++) dp2[i] = i + 1;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k <= i; k++) {
      if (dp[k][i] != -1) {
        if (k == 0)
          dp2[i] = 1;
        else
          dp2[i] = min(dp2[i], dp2[k - 1] + 1);
      }
    }
  }
  cout << dp[n - 1];
}
