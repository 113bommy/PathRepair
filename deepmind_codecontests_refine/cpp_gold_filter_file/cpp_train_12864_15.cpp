#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long int n, i, j, k;
  cin >> n;
  vector<long long int> t(n + 1), dp(n + 1, 0);
  for (i = j = k = 1; i <= n; ++i) {
    cin >> t[i];
    dp[i] = dp[i - 1] + 20;
    for (; j < i && t[j] + 90 <= t[i]; j++) {
    };
    if (j < i) {
      dp[i] = min(dp[i], dp[j - 1] + 50);
    }
    for (; k < i && t[k] + 1440 <= t[i]; k++) {
    };
    if (k < i) {
      dp[i] = min(dp[i], dp[k - 1] + 120);
    }
    cout << dp[i] - dp[i - 1] << endl;
  }
}
