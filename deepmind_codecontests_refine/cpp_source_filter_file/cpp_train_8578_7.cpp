#include <bits/stdc++.h>
using namespace std;
int n, arr[3001][3], dp[3001][2];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }
  dp[0][0] = arr[0][0];
  dp[0][1] = arr[1][0];
  for (int i = 1; i < n; ++i) {
    dp[i][0] = max(arr[0][i] + dp[i - 1][1], arr[1][i] + dp[i - 1][0]);
    dp[i][1] = max(arr[1][i] + dp[i - 1][1], arr[2][i] + dp[i - 1][0]);
  }
  printf("%d\n", dp[n - 1][0]);
  return 0;
}
