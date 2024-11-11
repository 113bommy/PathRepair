#include <bits/stdc++.h>
using namespace std;
const int N = 5005, MOD = 1e9 + 7;
long long dp[N][N], sum[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  clock_t begin = clock();
  int n, a, b, K;
  cin >> n >> a >> b >> K;
  for (int i = 1; i <= n; ++i)
    if (i != b) dp[i][0] = 1;
  for (int k = 1; k <= K; ++k) {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + dp[i][k - 1];
      sum[i] = sum[i] % MOD;
    }
    for (int i = 1; i <= n; ++i) {
      int diff = abs(i - b);
      dp[i][k] = (sum[min(i + diff - 1, n)] - sum[max(0, i - diff)] + MOD -
                  dp[i][k - 1] + MOD) %
                 MOD;
    }
  }
  cout << dp[a][K] << endl;
  clock_t end = clock();
  return 0;
}
