#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
int num1[maxn], num2[maxn];
long long dp[maxn][2][2][2][2][2];
long long dfs(int pos, bool pre1, bool pre2, bool eq, bool lim1, bool lim2) {
  if (pos == 0) return 1;
  if (dp[pos][pre1][pre2][eq][lim1][lim2] != -1)
    return dp[pos][pre1][pre2][eq][lim1][lim2];
  int lo = lim1 ? num1[pos] : 0;
  int up2 = lim2 ? num2[pos] : 1;
  long long ans = 0;
  if (lo == 0) {
    ans += dfs(pos - 1, 0, 0, eq, lim1, lim2 & (up2 == 0));
    if (!eq) ans += dfs(pos - 1, 1, 0, 0, 0, lim2 & (up2 == 0));
    if (up2) ans += dfs(pos - 1, 0, 1, 0, lim1, lim2);
  } else if (!eq) {
    ans += dfs(pos - 1, 1, 0, 0, 1, lim2 & (up2 == 0));
  }
  dp[pos][pre1][pre2][eq][lim1][lim2] = ans;
  return ans;
}
long long solve(int n, int m) {
  if (n == m) return n == 0;
  int cnt = 0;
  memset(dp, -1, sizeof(dp));
  while (m) {
    num1[++cnt] = n & 1;
    num2[cnt] = m & 1;
    n >>= 1;
    m >>= 1;
  }
  if (num1[cnt] == 0)
    return dfs(cnt, 0, 0, 1, 1, 1);
  else
    return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  int n, m;
  while (t--) {
    cin >> n >> m;
    cout << 2LL * solve(n, m) - (n == 0) << endl;
  }
  return 0;
}
