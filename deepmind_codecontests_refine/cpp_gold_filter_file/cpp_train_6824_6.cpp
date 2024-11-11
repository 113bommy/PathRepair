#include <bits/stdc++.h>
using namespace std;
string s[100005];
string reve[100005];
int c[100005];
long long dp[100005][2];
int n;
long long solve(int i, bool rev) {
  if (i == n) {
    return 0;
  }
  long long &ret = dp[i][rev];
  if (ret != -1) {
    return ret;
  }
  ret = 1e18;
  if (!rev) {
    if (s[i - 1] <= s[i]) ret = min(ret, solve(i + 1, 0));
    if (s[i - 1] <= reve[i]) ret = min(ret, c[i] + solve(i + 1, 1));
  } else {
    if (reve[i - 1] <= s[i]) ret = min(ret, solve(i + 1, 0));
    if (reve[i - 1] <= reve[i]) ret = min(ret, c[i] + solve(i + 1, 1));
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    reve[i] = s[i];
    reverse(reve[i].begin(), reve[i].end());
  }
  memset(dp, -1, sizeof(dp));
  long long ans = min(solve(1, 0), c[0] + solve(1, 1));
  if (ans >= 1e18)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
