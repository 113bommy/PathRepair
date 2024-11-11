#include <bits/stdc++.h>
using namespace std;
int n, h;
long long dp[40][40][40];
long long calc(int l, int r, int d) {
  if (dp[l][r][d] != -1) return dp[l][r][d];
  if (l > r && d == 0)
    return dp[l][r][d] = 1;
  else if (l > r)
    return dp[l][r][d] = 0;
  if (l == r && d == 1)
    return dp[l][r][d] = 1;
  else if (l == r)
    return dp[l][r][d] = 0;
  long long res = 0;
  for (int i = l; i <= r; i++) {
    for (int j = 0; j < d - 1; j++)
      res += calc(l, i - 1, j) * calc(i + 1, r, d - 1) +
             calc(i + 1, r, j) * calc(l, i - 1, d - 1);
    res += calc(l, i - 1, d - 1) * calc(i + 1, r, d - 1);
  }
  return dp[l][r][d] = res;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> h;
  long long ans = 0;
  for (int i = n; i >= h; i--) {
    ans += calc(1, n, i);
  }
  cout << ans << endl;
  return 0;
}
