#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int out[100001], w[100001], dp[100001][40];
long long sum[100001][40];
long long mn[100001][40];
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &out[i]);
    dp[i][0] = out[i];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &w[i]);
    sum[i][0] = w[i];
    mn[i][0] = w[i];
  }
  for (int k = 1; k < 40; ++k) {
    for (int u = 0; u < n; ++u) {
      dp[u][k] = dp[dp[u][k - 1]][k - 1];
      sum[u][k] = sum[u][k - 1] + sum[dp[u][k - 1]][k - 1];
      mn[u][k] = min(mn[u][k - 1], mn[dp[u][k - 1]][k - 1]);
    }
  }
  for (int i = 0; i < n; ++i) {
    long long si = 0;
    int cur = i;
    long long rem = k;
    long long m = 1e18;
    for (long long p = 39; p >= 0; --p) {
      if ((1ll << p) <= rem) {
        rem -= (1 << p);
        m = min(m, mn[cur][p]);
        si += sum[cur][p];
        cur = dp[cur][p];
      }
    }
    printf("%lld %lld\n", si, m);
  }
  return 0;
}
