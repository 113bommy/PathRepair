#include <bits/stdc++.h>
using namespace std;
int k1, k2;
int dp[53][53][3];
int win1;
int win2;
int rec(int n1, int n2, int flag) {
  if (dp[n1][n2][flag] != -1) return dp[n1][n2][flag];
  if (flag == 0) {
    if (n1 <= 0) {
      return 1;
    }
  } else {
    if (n2 <= 0) {
      return 1;
    }
  }
  dp[n1][n2][flag] = 1;
  if (flag == 0) {
    int x = 0;
    for (int i = 1; i <= k1; i++) {
      if (n1 >= i) {
        x = max(rec(n1 - i, n2, 1), x);
      }
    }
    dp[n1][n2][flag] = x;
    return !dp[n1][n2][flag];
  } else {
    int x = 0;
    for (int i = 1; i <= k2; i++) {
      if (n2 >= i) {
        x = max(rec(n1, n2 - i, 0), x);
      }
    }
    dp[n1][n2][flag] = x;
    return !(dp[n1][n2][flag]);
  }
  return 0;
}
int main() {
  int n1, n2;
  cin >> n1 >> n2 >> k1 >> k2;
  for (int i = 0; i <= 51; i++)
    for (int j = 0; j <= 51; j++)
      for (int k = 0; k <= 2; k++) dp[i][j][k] = -1;
  int x = rec(n1, n2, 0);
  if (x == 0)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
