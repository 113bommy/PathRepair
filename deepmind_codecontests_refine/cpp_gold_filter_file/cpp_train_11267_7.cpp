#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
int a[maxn], inv[maxn], cnt[1 << 8];
bool cmp(int x, int y) { return a[x] > a[y]; }
long long dp[maxn][132];
long long val[maxn][10];
int main() {
  int n, p, k, tot = 0;
  scanf("%d%d%d", &n, &p, &k);
  tot += p + k;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) inv[i] = i;
  sort(inv + 1, inv + 1 + n, cmp);
  for (int i = 1; i < (1 << p); i++) {
    cnt[i] = cnt[i >> 1] + (i & 1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < p; j++) scanf("%lld", &val[i][j]);
  }
  memset(dp, -inf, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int now = inv[i];
    for (int j = 0; j < (1 << p); j++) {
      if (i - cnt[j] <= k) {
        dp[i][j] = max(dp[i - 1][j] + a[now], dp[i][j]);
      }
      dp[i][j] = max(dp[i - 1][j], dp[i][j]);
      for (int u = 0; u < p; u++) {
        if (j & (1 << u)) continue;
        dp[i][(1 << u) | j] =
            max(dp[i - 1][j] + val[now][u], dp[i][(1 << u) | j]);
      }
    }
  }
  long long maxe = -1;
  for (int i = 0; i < (1 << p); i++) {
    maxe = max(maxe, dp[n][i]);
  }
  cout << maxe << endl;
  return 0;
}
