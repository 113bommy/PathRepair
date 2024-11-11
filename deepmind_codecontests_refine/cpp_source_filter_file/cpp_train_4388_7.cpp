#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005], dp[100005][2];
int ans;
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    dp[i][0] = dp[i - 1][0];
    dp[i][1] = dp[i - 1][1];
    dp[i][(i & 1)] += a[i];
  }
  for (int i = 1; i <= n; ++i) {
    long long x = dp[i - 1][1];
    long long y = dp[i - 1][0];
    if (i & 1) {
      x += dp[n][0] - dp[i][0];
      y += dp[n][1] - dp[i][1];
    } else {
      x += dp[n][0] - dp[i][0];
      y += dp[n][1] - dp[i][1];
    }
    if (x == y) ++ans;
  }
  cout << ans << '\n';
}
