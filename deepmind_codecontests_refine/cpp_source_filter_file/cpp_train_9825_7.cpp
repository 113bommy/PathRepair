#include <bits/stdc++.h>
using namespace std;
long long int n, q, t;
long long int v[100001];
long long int c[100001];
long long int a, b;
long long int dp[100001];
long long int ans;
long long int s1, s2;
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int j = 1; j <= q; j++) {
    cin >> a >> b;
    for (int i = 1; i <= n; i++) dp[i] = -1e1;
    s1 = s2 = 0;
    dp[c[1]] = b * v[1];
    ans = dp[c[1]];
    ans = max(ans, (long long int)0);
    for (int i = 2; i <= n; i++) {
      if (dp[c[i]] != -1e18)
        dp[c[i]] = max(dp[c[i]], dp[c[i]] + a * v[i]);
      else
        dp[c[i]] = max(dp[c[i]], b * v[i]);
      dp[c[i]] = max(dp[c[i]], b * v[i]);
      if (s1 != c[i]) {
        dp[c[i]] = max(dp[c[i]], b * v[i] + dp[s1]);
      } else if (s2 != c[i]) {
        dp[c[i]] = max(dp[c[i]], b * v[i] + dp[s2]);
      }
      dp[c[i]] = max(dp[c[i]], b * v[i]);
      if (c[i] != s1) {
        if (dp[c[i]] > dp[s1]) {
          s2 = s1;
          s1 = c[i];
        } else if (s1 != c[i] && dp[c[i]] > dp[s2]) {
          s2 = c[i];
        }
      }
      ans = max(ans, dp[c[i]]);
    }
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
