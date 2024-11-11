#include <bits/stdc++.h>
using namespace std;
int solve(int n, int a, int b, int c, int *dp) {
  if (n == 0) return 0;
  if (n < 0)
    return -1;
  else if (dp[n] != -1)
    return dp[n];
  else {
    int ans = max(solve(n - a, a, b, c, dp),
                  max(solve(n - b, a, b, c, dp), solve(n - c, a, b, c, dp)));
    if (ans >= 0) dp[n] = ans + 1;
  }
  return dp[n];
}
int main() {
  int n, a, b, c, ans;
  int dp[4001];
  cin >> n >> a >> b >> c;
  for (int i = 0; i * a <= n; i++)
    for (int j = 0; j * b + i * a <= n; j++) {
      int res = (n - j * b - i * a);
      if (res % c == 0) ans = max(ans, i + j + res / c);
    }
  cout << ans;
}
