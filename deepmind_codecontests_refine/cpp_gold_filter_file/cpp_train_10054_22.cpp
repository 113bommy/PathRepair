#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
long long a[4][M];
long long dp[M][4];
long long sum(int pos, int l, int r) {
  if (l > r) {
    swap(l, r);
  }
  long long sum = 0;
  for (int i = l; i <= r; i++) {
    sum += a[i][pos];
  }
  return sum;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 3; j++) {
      dp[i][j] = -1000000000000000;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + sum(i, j, k));
      }
    }
    dp[i][0] = max(dp[i][0], dp[i - 1][3] + sum(i, 0, 2));
    dp[i][2] = max(dp[i][2], dp[i - 1][3] + sum(i, 0, 2));
    dp[i][3] = max(dp[i][3], max(dp[i - 1][0], dp[i - 1][2]) + sum(i, 0, 2));
  }
  cout << dp[n][2] << endl;
  return 0;
}
