#include <bits/stdc++.h>
using namespace std;
long long ma[30002];
long long dp[30002][502], n, d;
long long solve(long long cur, long long le) {
  if (cur > 30000) return 0;
  long long jj = 250 + le - d;
  if (dp[cur][jj] != -1) return dp[cur][jj];
  long long ans = 0;
  for (long long i = -1; i < 2; i++) {
    long long fin = cur + le + i;
    if (fin <= 30000 and fin > cur) ans = max(ans, solve(fin, le + i));
  }
  return dp[cur][jj] = ans + ma[cur];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ;
  long long i, j;
  cin >> n >> d;
  memset(dp, -1, sizeof dp);
  for (i = 0; i < n; i++) {
    long long x;
    cin >> x;
    ma[x]++;
  }
  cout << solve(d, d);
}
