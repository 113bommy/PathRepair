#include <bits/stdc++.h>
using namespace std;
int n, m;
int team[101];
char c[101];
int dp[21][(1 << 20) + 5];
int a[1001];
int solve(int pos, int mask) {
  if (pos == n) return 0;
  if (dp[pos][mask] != -1) return dp[pos][mask];
  int ans;
  if (team[pos] == 1) {
    ans = -(1 << 30);
    for (int i = 0; i < m; i++) {
      if (mask & (1 << i)) {
        if (c[pos] == 'p')
          ans = max(ans, a[i] + solve(pos + 1, mask ^ (1 << i)));
        else
          ans = max(ans, solve(pos + 1, mask ^ (1 << i)));
      }
    }
  } else {
    ans = (1 << 30);
    for (int i = 0; i < m; i++) {
      if (mask & (1 << i)) {
        if (c[pos] == 'p')
          ans = min(ans, solve(pos + 1, mask ^ (1 << i)) - a[i]);
        else
          ans = min(ans, solve(pos + 1, mask ^ (1 << i)));
      }
    }
  }
  return dp[pos][mask] = ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  cin >> m;
  n = m;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> team[i];
  }
  cout << solve(0, (1 << m) - 1) << endl;
}
