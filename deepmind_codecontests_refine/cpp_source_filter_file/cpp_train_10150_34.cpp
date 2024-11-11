#include <bits/stdc++.h>
using namespace std;
const int iinf = 0x7fffffff;
const long long linf = ~(1LL << 63);
const int maxn = 510;
const int mod = 1e9 + 7;
long long dp[2][maxn][maxn];
string inp[maxn];
int n, m;
int pos = 0;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; i++) cin >> inp[i];
  int start = ceil(max(m, n) / 2.0);
  for (int dist = start; dist >= 0; dist--) {
    int x1, y1, x2, y2;
    for (x1 = 0; x1 <= min(n - 1, dist); x1++) {
      y1 = dist - x1;
      for (x2 = n - 1; x2 >= max(n - 1 - dist, 0); x2--) {
        y2 = m - 1 + n - 1 - x2 - dist;
        if (!(0 <= x1 && x1 < n && 0 <= y1 && y1 < m && 0 <= x2 && x2 < n &&
              0 <= y2 && y2 < m))
          continue;
        if (x1 > x2 || y1 > y2) {
          dp[pos][x1][x2] = 0;
          continue;
        } else if (abs(x1 - x2) + abs(y1 - y2) <= 1) {
          dp[pos][x1][x2] = inp[x1][y1] == inp[x2][y2] ? 1 : 0;
          continue;
        } else if (inp[x1][y1] != inp[x2][y2]) {
          dp[pos][x1][x2] = 0;
          continue;
        }
        long long ans = dp[pos ^ 1][x1 + 1][x2] + dp[pos ^ 1][x1 + 1][x2 - 1] +
                        dp[pos ^ 1][x1][x2] + dp[pos ^ 1][x1][x2 - 1];
        ans %= mod;
        dp[pos][x1][x2] = ans;
      }
    }
    pos ^= 1;
  }
  cout << dp[pos ^ 1][0][n - 1] << endl;
  return 0;
}
