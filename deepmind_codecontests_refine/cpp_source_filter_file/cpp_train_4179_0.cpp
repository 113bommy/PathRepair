#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 1;
const char hard[4] = {'h', 'a', 'r', 'd'};
long long n, arr[N], dp[4][N] = {};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> n >> s;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (int i = 3; i >= 0; i--) {
    if (s[n - 1] == hard[i])
      dp[i][n - 1] = arr[n - 1];
    else
      dp[i][n - 1] = 0;
  }
  for (long long i = n - 2; i >= 0; i--) {
    if (s[i] != hard[3])
      dp[3][i] = dp[3][i + 1];
    else
      dp[3][i] = dp[3][i + 1] + arr[i];
    for (long long j = 2; j >= 0; j--) {
      if (s[i] != hard[j])
        dp[j][i] = min(dp[j][i + 1], dp[j + 1][i]);
      else
        dp[j][i] = min(dp[j][i + 1] + arr[i], dp[j + 1][i]);
    }
  }
  cout << dp[0][0] << '\n';
  return 0;
}
