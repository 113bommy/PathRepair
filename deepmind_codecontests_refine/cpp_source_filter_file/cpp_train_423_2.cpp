#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 5;
const long long mod = 998244353;
int n, k;
long long dp[maxn], sum[maxn], way[maxn];
long long suf[maxn];
long long add(long long x, long long y) { return ((x + y) % mod + mod) % mod; }
long long mul(long long x, long long y) { return ((x * y) % mod + mod) % mod; }
int main() {
  scanf("%d%d", &n, &k);
  for (int mx = 1; mx <= n; mx++) {
    dp[n + 1] = suf[n + 1] = 1;
    for (int x = n; x >= 1; x--) {
      dp[x] = add(suf[x + 1], suf[min(n + 2, x + mx + 1)]);
      suf[x] = add(dp[x], suf[x + 1]);
    }
    sum[mx] = dp[1];
  }
  for (int i = 1; i <= n; i++) {
    way[i] = mul(2, add(sum[i], -sum[i - 1]));
  }
  long long ans = 0;
  for (int mx = 1; mx <= n; mx++) {
    int lim = k / mx + 1;
    while (mx * lim >= k) lim--;
    dp[n + 1] = suf[n + 1] = 1;
    for (int x = n; x >= 1; x--) {
      dp[x] = add(suf[x + 1], suf[min(n + 2, x + lim + 1)]);
      suf[x] = add(dp[x], suf[x + 1]);
    }
    ans = add(ans, mul(way[mx], dp[1]));
  }
  printf("%lld", ans);
}
