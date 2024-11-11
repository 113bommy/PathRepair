#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int dp[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) dp[i][j] = 0;
  }
  string A, B;
  cin >> A >> B;
  int dpA[26][n];
  int dpB[26][m];
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < n; j++) dpA[i][j] = -1;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < m; j++) dpB[i][j] = -1;
  }
  for (int i = 0; i < n; i++) {
    dpA[A[i] - 'a'][i] = i;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j < n; j++) {
      dpA[i][j] = max(dpA[i][j], dpA[i][j - 1]);
    }
  }
  for (int i = 0; i < m; i++) {
    dpB[B[i] - 'a'][i] = i;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j < m; j++) {
      dpB[i][j] = max(dpB[i][j], dpB[i][j - 1]);
    }
  }
  dp[0][0] = A[0] == B[0] ? 2 : 0;
  for (int i = 1; i < m; i++) {
    if (A[0] == B[i])
      dp[0][i] = 2;
    else if (A[0] == B[i - 1])
      dp[0][i] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (A[i] == B[0])
      dp[i][0] = 2;
    else if (B[0] == A[i - 1])
      dp[i][0] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (A[i] == B[j])
        dp[i][j] = 2 + dp[i - 1][j - 1];
      else {
        int z1 = 0, z2 = 0;
        if (dpA[B[j] - 'a'][i - 1] != -1) {
          int ind = dpA[B[j] - 'a'][i - 1];
          if (ind != 0) {
            z1 = dp[ind - 1][j - 1] + 2 - (i - ind);
          } else {
            z1 = 2 - (i - ind);
          }
          z1 = max(z1, 0);
        }
        if (dpB[A[i] - 'a'][j - 1] != -1) {
          int ind = dpB[A[i] - 'a'][j - 1];
          if (ind != 0) {
            z2 = dp[i - 1][ind - 1] + 2 - (j - ind);
          } else
            z2 = 2 - (j - ind);
          z2 = max(z2, 0);
        }
        dp[i][j] = max(dp[i - 1][j - 1] - 2, max(z1, z2));
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res = max(res, dp[i][j]);
    }
  }
  cout << res << endl;
}
