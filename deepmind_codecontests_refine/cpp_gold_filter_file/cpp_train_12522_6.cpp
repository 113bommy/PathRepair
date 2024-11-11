#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
void inp(int n, int arr[]) {
  for (int i = 0; i < n; i++) cin >> arr[i];
}
int dp[5001][5001];
int ans = 0;
int n, m;
string a, b;
int fun(int i, int j) {
  if (i < 0 || j < 0)
    return 0;
  else if (dp[i][j] != -1)
    return dp[i][j];
  else
    dp[i][j] = max(fun(i - 1, j), fun(i, j - 1)) - 1;
  if (a[i] == b[j]) dp[i][j] = max(dp[i][j], fun(i - 1, j - 1) + 2);
  dp[i][j] = max(dp[i][j], (int)0);
  ans = max(ans, dp[i][j]);
  return dp[i][j];
}
void solve() {
  cin >> n >> m;
  cin >> a >> b;
  memset(dp, -1, sizeof(dp));
  fun(n - 1, m - 1);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
