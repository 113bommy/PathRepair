#include <bits/stdc++.h>
using namespace std;
using namespace std;
double dp[1001][1001], k, prob;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q, n, i, j;
  for (i = 0; i < 1001; i++)
    for (j = 0; j < 1001; j++) dp[i][j] = 0;
  cin >> k >> q;
  dp[1][1] = 1.0;
  for (i = 2; i <= 1000; i++) dp[1][i] = dp[1][i - 1] * (1.0 / k);
  for (i = 2; i <= k; i++) {
    for (j = i; j <= 1000; j++) {
      if (i - 1 < k)
        dp[i][j] = dp[i - 1][j - 1] * (k - (double)i + 1.0) / k +
                   dp[i][j - 1] * ((double)i) / k;
      else
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] * (1.0 / k);
    }
  }
  while (q--) {
    cin >> prob;
    prob /= 2000.0;
    for (j = 1; j <= 1000; j++) {
      if (dp[(long long)k][j] >= prob) break;
    }
    cout << j << endl;
  }
}
