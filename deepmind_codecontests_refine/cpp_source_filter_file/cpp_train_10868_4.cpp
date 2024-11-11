#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[1 << 24], dp[1 << 24], b[2];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[1 << i];
  cin >> k;
  for (int i = 0; i < k; i++) cin >> b[i];
  for (int i = 1; i < (1 << n); i++) {
    long long s = 0;
    int t = i;
    while (t) {
      s += (a[t & (-t)]);
      t -= t & (-t);
    }
    for (int j = 0; j < k; j++) {
      if (s == b[i]) {
        dp[i] = -1;
        break;
      }
    }
  }
  dp[0] = 1;
  for (int i = 1; i < (1 << n); i++) {
    if (dp[i] == -1) {
      dp[i] = 0;
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (1 & (i >> j)) {
        dp[i] += dp[i ^ (1 << j)];
      }
    }
    if (dp[i] >= 1000000007ll) dp[i] %= 1000000007ll;
  }
  cout << dp[(1 << n) - 1] << endl;
}
