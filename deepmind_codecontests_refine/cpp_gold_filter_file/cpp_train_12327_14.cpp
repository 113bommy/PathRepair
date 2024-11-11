#include <bits/stdc++.h>
long long int const MOD = 1000000007;
long long int const N = 9000005;
long long int const LN = 20;
long long int const inf = 8e18;
using namespace std;
long long int n, m, a[N];
long long int dp[2][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  long long int inv = 0;
  long long int hgh = 0;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j < i; j++) {
      if (a[j] > a[i]) inv++;
      hgh++;
    }
  }
  dp[0][0] = 0;
  dp[1][0] = 0;
  for (long long int i = 1; i <= inv; i++) {
    if (i == hgh)
      dp[0][i] = dp[1][i - 1] + 1, dp[1][i] = dp[0][i - 1] + 2;
    else {
      dp[0][i] = dp[1][i - 1] + 1;
      dp[1][i] = dp[0][i - 1] + 3;
    }
  }
  cout << dp[0][inv];
  return 0;
}
