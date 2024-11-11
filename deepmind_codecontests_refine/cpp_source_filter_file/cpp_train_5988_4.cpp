#include <bits/stdc++.h>
using namespace std;
long long dp[1000][1000];
long long arr[1000];
long long solve(long long i, long long j) {
  if (i > j) {
    return 0;
  } else if (i == j) {
    return 1;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  long long ans = 1 + solve(i + 1, j);
  if (arr[i] == arr[i + 1]) {
    ans = min(ans, solve(i + 2, j) + 1);
  }
  for (long long k = i + 1; k <= j; k++) {
    if (arr[i] == arr[k]) {
      ans = min(ans, solve(i + 1, k - 1) + solve(k + 1, j));
    }
  }
  return dp[i][j] = ans;
}
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, n);
}
