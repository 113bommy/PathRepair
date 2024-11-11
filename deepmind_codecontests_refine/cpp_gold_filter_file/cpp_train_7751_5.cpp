#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 20, inf = 1e9;
int a[N], ans[N], nxt[N], prv[N], n, dp[N], cnt[N], mx;
void read_input() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
}
void LIS() {
  fill(dp, dp + n + 1, inf);
  dp[0] = -inf;
  for (int i = 0; i < n; i++) {
    prv[i] = lower_bound(dp, dp + n + 1, a[i]) - dp;
    dp[prv[i]] = a[i];
  }
}
void LIS2() {
  fill(dp, dp + n + 2, -inf);
  dp[n + 1] = inf;
  for (int i = n - 1; ~i; i--) {
    nxt[i] = upper_bound(dp, dp + n + 2, a[i]) - dp - 1;
    dp[nxt[i]] = a[i];
    nxt[i] = n + 1 - nxt[i];
  }
}
void solve() {
  LIS();
  LIS2();
  mx = prv[max_element(prv, prv + n) - prv];
  fill(ans, ans + n, 1);
  for (int i = 0; i < n; i++)
    if (prv[i] + nxt[i] - 1 == mx) ans[i] = 2;
  for (int i = 0; i < n; i++)
    if (ans[i] == 2) cnt[prv[i]]++;
  for (int i = 0; i < n; i++)
    if (ans[i] == 2 && cnt[prv[i]] == 1) ans[i] = 3;
}
void write_output() {
  for (int i = 0; i < n; i++) cout << ans[i];
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  read_input();
  solve();
  write_output();
  return 0;
}
