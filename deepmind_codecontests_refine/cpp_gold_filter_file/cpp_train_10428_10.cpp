#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, k, a[600086];
int tsum[5005][5005], dp[5005][5005];
int bound[5005], ans;
int add(int x, int y) {
  int sum = x + y;
  if (sum >= mod) sum -= mod;
  return sum;
}
int solve1(int x) {
  tsum[1][0] = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = i; j <= n; j++) {
      if (i == 1) {
        dp[i][j] = 1;
        tsum[i][j] = (tsum[i][j - 1] + dp[i][j]) % mod;
        continue;
      }
      dp[i][j] = tsum[i - 1][bound[j]];
      tsum[i][j] = add(tsum[i][j - 1], dp[i][j]);
    }
  }
  return tsum[k][n];
}
int solve(int x) {
  bound[0] = 0;
  for (int i = 1; i <= n; i++) {
    bound[i] = bound[i - 1];
    while (a[i] - a[bound[i] + 1] >= x) bound[i]++;
  }
  tsum[1][0] = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = i; j <= n; j++) {
      if (i == 1) {
        dp[i][j] = 1;
        tsum[i][j] = (tsum[i][j - 1] + dp[i][j]);
        continue;
      }
      dp[i][j] = tsum[i - 1][bound[j]];
      tsum[i][j] = add(tsum[i][j - 1], dp[i][j]);
    }
  }
  return tsum[k][n];
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int ans = 0;
  int maxn = (a[n] - a[1]) / (k - 1);
  for (int c = 1; c <= maxn; c++) {
    ans = add(ans, solve(c));
  }
  cout << ans << endl;
  return 0;
}
