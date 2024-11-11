#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 1073741823;
const long long int M = 1000000007;
const int MAXN = 1030;
const long long int MOD = 1000000007;
long long int dp[MAXN][MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int a, b, answer;
  cin >> a >> b;
  for (int i = 0; i < MAXN; i++) {
    dp[i][0] = 1;
    dp[i][i] = 1;
    for (int k = 1; k < i; k++) {
      dp[i][k] = (dp[i - 1][k] + dp[i - 1][k - 1]);
      dp[i][k] %= MOD;
    }
  }
  answer = 2 * b - 1 + a;
  cout << dp[answer][a - 1] % MOD;
  return 0;
}
