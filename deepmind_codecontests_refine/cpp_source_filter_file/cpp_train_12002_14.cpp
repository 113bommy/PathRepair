#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long input[70][70], dp[70][70][40][70];
long long helper(long long row, long long col, long long num, long long sum) {
  if (row == n) {
    if (sum == 0) return 0;
    return -1000000;
  }
  if (col == m) {
    if (num <= m / 2) return helper(row + 1, 0, 0, sum);
    return -1000000;
  }
  if (dp[row][col][num][sum] != -1) return dp[row][col][num][sum];
  return dp[row][col][num][sum] =
             max(input[row][col] +
                     helper(row, col + 1, num + 1, (sum + input[row][col]) % k),
                 helper(row, col + 1, num, sum));
}
int32_t main() {
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) cin >> input[i][j];
  memset(dp, -1, sizeof(dp));
  cout << helper(0, 0, 0, 0);
  return 0;
}
