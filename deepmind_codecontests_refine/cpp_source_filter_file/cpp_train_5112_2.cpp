#include <bits/stdc++.h>
using namespace std;
void optimize() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n;
int a[100000];
int dp[100000][5];
int main() {
  optimize();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= 5; i++) dp[1][i] = 6;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= 5; j++) dp[i][j] = 0;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= 5; j++) {
      if (a[i] > a[i - 1]) {
        for (int k = 1; k <= j - 1; k++) {
          if (dp[i - 1][k]) dp[i][j] = k;
        }
      }
      if (a[i] < a[i - 1]) {
        for (int k = j + 1; k <= 5; k++) {
          if (dp[i - 1][k]) dp[i][j] = k;
        }
      }
      if (a[i] == a[i - 1]) {
        for (int k = 1; k <= j - 1; k++) {
          if (dp[i - 1][k]) dp[i][j] = k;
        }
        for (int k = j + 1; k <= 5; k++) {
          if (dp[i - 1][k]) dp[i][j] = k;
        }
      }
    }
  int x = 0;
  for (int j = 1; j <= 5; j++) {
    if (dp[n][j]) x = j;
  }
  if (x) {
    for (int i = n; i >= 1; i--) {
      a[i] = x;
      x = dp[i][x];
    }
  } else {
    cout << "-1";
    return 0;
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
