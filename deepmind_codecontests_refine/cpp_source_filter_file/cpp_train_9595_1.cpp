#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 1005;
long long dp[N][N], tot[N][N], ans = 0, ret[N];
int n, a[N], k;
void solve(int x) {
  dp[0][0] = 1;
  tot[0][0] = 1;
  int now = 0;
  for (int i = 1; i <= n; ++i) {
    while ((a[i] - a[now]) >= x) ++now;
    for (int j = 0; j <= k; ++j) {
      if (j > 0) dp[i][j] = tot[now - 1][j - 1];
      tot[i][j] = (tot[i - 1][j] + dp[i][j]) % mod;
    }
    ret[x] = (ret[x] + dp[i][k]) % mod;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  a[0] = -1000000000;
  for (int i = 1; i * (k - 1) <= a[n]; ++i) {
    solve(i);
    ans = (ans + ret[i]) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
