#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
const int mod = 998244353;
int n, k, m, l[N], r[N], x[N], dp[N], c[N], lmx[N];
int solve(int b) {
  for (int i = 1; i <= n; ++i) lmx[i] = 0, c[i] = 0, dp[i] = 0;
  for (int i = 1; i <= m; ++i) {
    if (x[i] >> b & 1)
      ++c[l[i]], --c[r[i] + 1];
    else
      lmx[r[i] + 1] = max(lmx[r[i] + 1], l[i]);
  }
  for (int i = 1; i <= n + 1; ++i)
    lmx[i] = max(lmx[i], lmx[i - 1]), c[i] += c[i - 1];
  int sdp = 1, j = 0;
  dp[0] = 1;
  for (int i = 1; i <= n + 1; ++i) {
    if (c[i] > 0) {
      dp[i] = 0;
      continue;
    }
    while (j < lmx[i]) sdp = (sdp - dp[j++] + mod) % mod;
    dp[i] = sdp;
    sdp = (sdp + dp[i]) % mod;
  }
  return dp[n + 1];
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &l[i], &r[i], &x[i]);
  int ans = 1;
  for (int i = 0; i < k; ++i) ans = 1ll * ans * solve(i) % mod;
  cout << ans << '\n';
  return 0;
}
