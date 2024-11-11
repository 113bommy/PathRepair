#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 7;
int dp[maxn], x[maxn], s[maxn];
int main() {
  int n, m;
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> s[i];
  }
  for (int j = 1; j <= m; j++) {
    dp[j] = j;
    for (int i = 1; i <= n; i++) {
      if (j >= x[i]) {
        dp[j] =
            min(dp[j], dp[max(x[i] * 2 - j - 1, 0)] + max(j - x[i] - s[i], 0));
      } else if (j >= x[i] - s[i]) {
        dp[j] = min(dp[j], dp[max(x[i] - s[i] - 1, 0)]);
      } else {
        dp[j] = min(dp[j], max(x[i] - s[i] - 1, 0));
      }
    }
  }
  cout << dp[m] << endl;
  return 0;
}
