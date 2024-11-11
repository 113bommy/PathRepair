#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long dp[60][10][10];
long long n;
long long w[4][4];
long long go(long long x, long long a, long long b, long long c) {
  if (x == 0) return 0;
  if (dp[x][a][b] >= 0) return dp[x][a][b];
  dp[x][a][b] = ((long long)(1ll << 61));
  dp[x][a][b] =
      min(dp[x][a][b], go(x - 1, a, c, b) + go(x - 1, c, b, a) + w[a][b]);
  dp[x][a][b] = min(dp[x][a][b], 2 * go(x - 1, a, b, c) + go(x - 1, b, a, c) +
                                     w[a][c] + w[c][b]);
  return dp[x][a][b];
}
int main() {
  ios::sync_with_stdio(0);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> w[i][j];
  memset(dp, -1, sizeof(dp));
  cin >> n;
  cout << go(n, 0, 2, 1);
}
