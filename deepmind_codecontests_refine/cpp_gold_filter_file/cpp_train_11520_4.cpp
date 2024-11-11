#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N], dp[N], pre[N], suf[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, l, r;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> l >> r, a[l]++, a[r + 1]--;
  for (int i = 2; i <= m; i++) a[i] += a[i - 1];
  memset(dp, INF, sizeof(dp));
  for (int i = 1; i <= m; i++) {
    *upper_bound(dp + 1, dp + m + 1, a[i]) = a[i];
    pre[i] = lower_bound(dp + 1, dp + m + 1, INF) - dp - 1;
  }
  memset(dp, INF, sizeof(dp));
  for (int i = m; i >= 1; i--) {
    *upper_bound(dp + 1, dp + m + 1, a[i]) = a[i];
    suf[i] = lower_bound(dp + 1, dp + m + 1, INF) - dp - 1;
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) ans = max(ans, pre[i] + suf[i + 1]);
  cout << ans << endl;
  return 0;
}
