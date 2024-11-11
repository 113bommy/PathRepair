#include <bits/stdc++.h>
using namespace std;
int sum[1 << 24], dp[1 << 24], v[1 << 24];
int main() {
  int n, k, i, j, a[2];
  cin >> n;
  for (i = 0; i < n; i++) cin >> v[1 << i];
  cin >> k;
  for (i = 0; i < k; i++) cin >> a[i];
  dp[0] = 1;
  for (i = 1; i < 1 << n; i++) {
    sum[i] = sum[i - (i & -i)] + v[i & -i];
    if (sum[i] > 1000000007) sum[i] = 1000000007;
    if (sum[i] == a[0] || sum[i] == a[1]) continue;
    for (j = i; j; j -= j & -j) {
      dp[i] += dp[i - (j & -j)];
      if (dp[i] > 1000000007) dp[i] = 1000000007;
    }
  }
  cout << dp[(1 << n) - 1] << endl;
  return 0;
}
