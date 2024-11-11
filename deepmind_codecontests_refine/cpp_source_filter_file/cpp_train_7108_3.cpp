#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 5;
const long long mod = 998244353;
int n;
int a[maxn], cnt[maxn];
int fac[maxn], ifac[maxn];
int dp[maxn];
long long add(long long x, long long y) { return (x + y) % mod; }
long long mul(long long x, long long y) { return (x * y) % mod; }
long long inv(long long x, long long y) {
  return 1 < x ? y - inv(y % x, x) * y / x : 1LL;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(&a[1], &a[n + 1]);
  if (a[n] < a[n - 1] * 2) return !printf("0");
  cnt[0] = -1;
  for (int x = 1; x <= n; x++) {
    cnt[x] = cnt[x - 1];
    while (2 * a[cnt[x] + 1] <= a[x]) cnt[x]++;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
  for (int i = 0; i <= n; i++) ifac[i] = inv(fac[i], mod);
  dp[n] = 1;
  for (int x = n - 1; x >= 0; x--) {
    for (int y = x + 1; y <= n; y++) {
      if (a[x] * 2 > a[y]) continue;
      int star = cnt[y] - cnt[x] - 1;
      int bar = n - cnt[y] - 1;
      dp[x] = add(dp[x], mul(mul(fac[star + bar], ifac[bar]), dp[y]));
    }
  }
  printf("%d", dp[0]);
}
