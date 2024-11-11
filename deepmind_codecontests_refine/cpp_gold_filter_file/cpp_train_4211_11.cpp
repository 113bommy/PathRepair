#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100 * 2 + 20;
const int MAX_X = 3 * 1000 + 20;
const int MAX_N = 100 + 20;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000 + 1;
int poww(int x, int y) {
  return (!y ? 1 : (y & 1 ? x * poww(x * x, y / 2) : poww(x * x, y / 2)));
}
long long dp[MAX_X][MAX_X];
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cout.tie(0);
  long long n, k, ans = 0;
  cin >> n >> k;
  dp[0][1] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++)
      for (int t = j; t <= n; t += j) (dp[i][t] += dp[i - 1][j]) %= MOD;
  for (int i = 1; i <= n; i++) (ans += dp[k][i]) %= MOD;
  cout << ans;
  return 0;
}
