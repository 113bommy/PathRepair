#include <bits/stdc++.h>
using namespace std;
long long int rain[2010];
long long int dp[2010][2010];
long long int umb[2010];
long long int a;
long long int dfs(long long int x, long long int y) {
  if (x == a) return 0;
  long long int &ans = dp[x][y];
  if (ans != -1) return ans;
  ans = 1e14;
  if (umb[x]) ans = dfs(x, x);
  if (rain[x] and y == a + 1) return ans;
  if (rain[x])
    ans = min(ans, umb[y] + min(dfs(x + 1, y), dfs(x + 1, a + 1)));
  else {
    ans = min(ans, umb[y] + min(dfs(x + 1, y), dfs(x + 1, a + 1)));
    ans = min(ans, dfs(x + 1, a + 1));
  }
  return dp[x][y] = ans;
}
int main() {
  long long int n, m, i, l, r, j;
  cin >> a >> n >> m;
  memset(dp, -1, sizeof(dp));
  for (i = 0; i < n; i++) {
    cin >> l >> r;
    for (j = l; j < r; j++) {
      rain[j] = 1;
    }
  }
  for (i = 0; i < m; i++) {
    cin >> l >> r;
    if (umb[l] == 0) {
      umb[l] = r;
    } else {
      umb[l] = min(umb[l], r);
    }
  }
  long long int ans = dfs(0, a + 1);
  if (ans == 1e14)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
