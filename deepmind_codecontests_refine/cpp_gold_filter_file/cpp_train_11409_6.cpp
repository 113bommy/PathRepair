#include <bits/stdc++.h>
#pragma G++ optimize("O3")
using namespace std;
const int X = 1000 * 100 + 16;
int a[X];
long long b[X];
long long dp[X][2];
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    b[i] = abs(a[i] - a[i + 1]);
  }
  dp[1][0] = b[1];
  long long ans = b[1];
  for (int i = 2; i < n; ++i) {
    dp[i][0] = max(b[i], b[i] + dp[i - 1][1]);
    dp[i][1] = max(-b[i], -b[i] + dp[i - 1][0]);
    ans = max(ans, max(dp[i][0], dp[i][1]));
  }
  cout << ans << endl;
  return 0;
}
