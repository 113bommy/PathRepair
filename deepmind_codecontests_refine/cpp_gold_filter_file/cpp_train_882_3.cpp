#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long mat[19][19];
long long val[19], ans = -1;
long long dp[(1 << 19)][19];
long long func(long long pos, long long mask, long long cnt, long long prev) {
  if (cnt > m) return -1;
  if (cnt == m) {
    return max(0ll, dp[mask][prev]);
  }
  if (dp[mask][prev] != -1) return dp[mask][prev];
  long long res = 0;
  for (long long int i = 0; i < n; i++) {
    if (((1 << i) & (mask)) == 0) {
      long long z = func(pos + 1, (mask | (1 << i)), cnt + 1, i + 1);
      if (z != -1) res = max(res, val[i + 1] + mat[prev][i + 1] + z);
    }
  }
  dp[mask][prev] = max(dp[mask][prev], res);
  return dp[mask][prev];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  memset(dp, -1, sizeof(dp));
  for (long long int i = 1; i < n + 1; i++) {
    cin >> val[i];
  }
  for (long long int i = 0; i < k; i++) {
    long long x, y, s;
    cin >> x >> y >> s;
    mat[x][y] = s;
  }
  cout << func(0, 0, 0, 0);
}
