#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 1;
int h[N], dp[N][5], ans, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> h[i];
  h[n] = inf;
  dp[0][0] = h[0] - 1;
  if (h[1] < h[0]) dp[0][1] = h[1] - 1;
  for (int i = 1; i < n; i++) {
    if (h[i] >= h[i - 1]) {
      dp[i][0] = (h[i] - 1 + 1ll * (h[i - 1] - 1) * dp[i - 1][0] % mod) % mod;
      if (h[i] > h[i + 1])
        dp[i][1] =
            (h[i + 1] - 1 +
             1ll * min(h[i + 1] - 1, h[i - 1] - 1) * dp[i - 1][0] % mod) %
            mod;
    } else {
      dp[i][0] = (h[i] - 1 + 1ll * (h[i] - 1) * dp[i - 1][1] % mod) % mod;
      if (h[i] > h[i + 1])
        dp[i][1] =
            (h[i + 1] - 1 + 1ll * (h[i + 1] - 1) * dp[i - 1][1] % mod) % mod;
    }
  }
  for (int i = 0; i < n; i++) ans = (ans + dp[i][0]) % mod;
  cout << ans;
  return 0;
}
