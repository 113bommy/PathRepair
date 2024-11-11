#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool mod(long double a, long double b) { return a / b - floor(a / b); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, first;
  cin >> t;
  while (t--) {
    long long arr[3], vrr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    memset(vrr, -1, sizeof(vrr));
    long long dp[3][20001], val[3][20001];
    memset(dp, -1, sizeof(dp));
    memset(val, -1, sizeof(val));
    for (i = 1; i < 20001; i++) {
      dp[2][i] = abs(arr[2] - i);
    }
    for (i = 1; i < 20001; i++) {
      for (j = i; j < 20001; j += i) {
        if (dp[1][i] == -1 || dp[1][i] > dp[2][j]) {
          dp[1][i] = dp[2][j];
          val[1][i] = j;
        }
      }
      dp[1][i] += abs(arr[1] - i);
    }
    long long mm = 1;
    for (i = 1; i < 20001; i++) {
      for (j = i; j < 20001; j += i) {
        if (dp[0][i] == -1 || dp[0][i] > dp[1][j]) {
          dp[0][i] = dp[1][j];
          val[0][i] = j;
        }
      }
      dp[0][i] += abs(arr[0] - i);
      if (dp[0][i] < dp[0][mm]) mm = i;
    }
    cout << dp[0][mm] << '\n';
    cout << mm << " " << val[0][mm] << " " << val[1][val[0][mm]] << '\n';
  }
  return 0;
}
