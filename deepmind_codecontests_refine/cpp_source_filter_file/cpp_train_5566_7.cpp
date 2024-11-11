#include <bits/stdc++.h>
using namespace std;
ifstream fin("A.in");
int dp[5010][5010], ans, n, k, a, b;
void adjust(int &x) {
  if (x >= 1000000009) x -= 1000000009;
  if (x < 0) x += 1000000009;
}
int main() {
  cin >> n >> a >> b >> k;
  dp[0][a] = 1;
  dp[0][a + 1] = -1;
  for (int i = 0; i < k; ++i) {
    int s = 0;
    for (int j = 1; j <= n; ++j) {
      s += dp[i][j];
      adjust(s);
      int val = abs(j - b);
      if (val > 1) {
        dp[i + 1][max(j - val + 1, 1)] += s;
        adjust(dp[i + 1][max(j - val + 1, 1)]);
        dp[i + 1][j] -= s;
        adjust(dp[i + 1][j]);
        dp[i + 1][j + 1] += s;
        adjust(dp[i + 1][j + 1]);
        dp[i + 1][min(j + val, n + 1)] -= s;
        adjust(dp[i + 1][min(j + val, n + 1)]);
      }
    }
  }
  int s = 0;
  for (int i = 1; i <= n; ++i) {
    s += dp[k][i];
    adjust(s);
    ans += s;
    adjust(ans);
  }
  cout << ans;
}
