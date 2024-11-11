#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 505;
long long dp[N][N][2], cnt[N];
int n, k;
long long first(int x) { return cnt[min(x, n)]; }
long long first(int x, int y, int z) {
  if (y == n) return z;
  long long &res = dp[x][y][z];
  if (res == -1) {
    res = 0;
    for (int i = y + 1; i <= min(n, y + x); ++i)
      res = (res + first(x, i, i == y + x ? 1 : z)) % mod;
  }
  return res;
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= min(k - 1, n); ++i)
    cnt[i] = (first(i, 0, 0) + cnt[i - 1]) % mod;
  long long ans = 0;
  for (int i = 1; i <= min(k - 1, n); ++i) {
    int mx = k / i;
    ans = (ans + (cnt[i] - cnt[i - 1]) * 2 * first(mx)) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
