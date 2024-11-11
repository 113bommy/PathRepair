#include <bits/stdc++.h>
inline long long absv(long long x) { return x > 0 ? x : -x; }
using namespace std;
long long dp[5][5010], a[5010], b[5010];
int main() {
  int i, j, n;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  memcpy(b, a, sizeof(b));
  sort(b, b + n);
  for (i = 0; i < n; i++) dp[0][i] = (1ll << 52);
  bool flip = false;
  for (i = 1; i <= n; i++) {
    dp[!flip][0] =
        (dp[flip][0] < absv(b[i] - a[0]) ? dp[flip][0] : absv(b[i] - a[0]));
    for (j = 1; j < n; j++) {
      dp[!flip][j] = (dp[flip][j] < dp[!flip][j - 1] + absv(b[i] - a[j])
                          ? dp[flip][j]
                          : dp[!flip][j - 1] + absv(b[i] - a[j]));
    }
    flip = !flip;
  }
  cout << dp[!flip][n - 1] << endl;
  return 0;
}
