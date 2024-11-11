#include <bits/stdc++.h>
using namespace std;
long long int pos(long long int a) {
  if (a < 0) {
    long long int b = ceil((long double)a / (long double)1000000007);
    return a + 1000000007 * b;
  } else {
    return a % 1000000007;
  }
}
long long int arr[2001][2001];
long long int dp[2001][2001];
long long int maxi1[2001][2001];
long long int mini1[2001][2001];
long long int maxi2[2001][2001];
long long int mini2[2001][2001];
long long int u[2001][2001];
long long int l[2001][2001];
int main() {
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c == 'R') {
        arr[i][j] = 1;
      } else {
        arr[i][j] = 0;
      }
    }
  }
  dp[1][1] = 1;
  for (long long int i = 1; i <= n; i++) {
    long long int t = m;
    for (long long int j = m; j >= 1; j--) {
      maxi1[i][j] = j - 1;
      mini1[i][j] = 1;
    }
    for (long long int j = m; j >= 1; j--) {
      if (arr[i][j] == 1) {
        mini1[i][t] = j;
        t--;
      }
    }
  }
  for (long long int j = 1; j <= m; j++) {
    long long int t = n;
    for (long long int i = n; i >= 1; i--) {
      maxi2[i][j] = i - 1;
      mini2[i][j] = 1;
    }
    for (long long int i = n; i >= 1; i--) {
      if (arr[i][j] == 1) {
        mini2[t][j] = i;
        t--;
      }
    }
  }
  for (long long int i = 0; i <= n; i++) {
    for (long long int j = 0; j <= m; j++) {
      dp[i][j] = 0;
      l[i][j] = 0;
      u[i][j] = 0;
    }
  }
  dp[1][1] = 1;
  u[1][1] = 1;
  l[1][1] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      if (i == 1 && j == 1) continue;
      if (maxi1[i][j] >= mini1[i][j]) {
        dp[i][j] = dp[i][j] + l[i][maxi1[i][j]] - l[i][mini1[i][j] - 1];
        dp[i][j] = pos(dp[i][j]);
        u[i][j] = l[i][maxi1[i][j]] - l[i][mini1[i][j] - 1] + u[i - 1][j];
        u[i][j] = pos(u[i][j]);
      } else {
        u[i][j] = u[i - 1][j];
      }
      if (maxi2[i][j] >= mini2[i][j]) {
        dp[i][j] = (dp[i][j] + u[maxi2[i][j]][j] - u[mini2[i][j] - 1][j]);
        dp[i][j] = pos(dp[i][j]);
        l[i][j] = (u[maxi2[i][j]][j] - u[mini2[i][j] - 1][j] + l[i][j - 1]) %
                  1000000007;
        l[i][j] = pos(l[i][j]);
      } else {
        l[i][j] = l[i][j - 1];
      }
    }
  }
  cout << dp[n][m] << "\n";
}
