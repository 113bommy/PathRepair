#include <bits/stdc++.h>
using namespace std;
long long tavan(long long a, long long b) {
  long long res = 1;
  while (b) {
    res *= b % 2 ? a : 1;
    res %= ((long long)1e9 + 7);
    a *= a;
    a %= ((long long)1e9 + 7);
    b /= 2;
  }
  return res;
}
long long n, m, k, s, dp[((long long)2020)][((long long)26)],
    fac[((long long)101 * 1000)], dis[((long long)2020)][((long long)2020)];
pair<long long, long long> a[((long long)2020)];
long long C(long long x, long long y) {
  return (fac[x] * tavan((fac[x - y] * fac[y]) % ((long long)1e9 + 7),
                         ((long long)1e9 + 7) - 2)) %
         ((long long)1e9 + 7);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> s;
  fac[0] = 1;
  for (long long i = 1; i < ((long long)101 * 1000); i++)
    fac[i] = (fac[i - 1] * i) % ((long long)1e9 + 7);
  a[0] = {n, m};
  for (int i = 1; i <= k; i++) cin >> a[i].first >> a[i].second;
  sort(a, a + k + 1);
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < i; j++)
      dis[i][j] = C(a[i].second - a[j].second + a[i].first - a[j].first,
                    a[i].first - a[j].first);
  for (int i = 0; i <= k; i++) {
    for (int p = 1; p < ((long long)26); p++)
      for (int j = 0; j < i; j++)
        if (a[j].second <= a[i].second)
          dp[i][p] += dp[j][p] * dis[i][j], dp[i][p] %= ((long long)1e9 + 7);
    dp[i][0] = C(a[i].first - 1 + a[i].second - 1, a[i].first - 1) - dp[i][1];
    dp[i][0] %= ((long long)1e9 + 7);
    dp[i][0] += ((long long)1e9 + 7);
    dp[i][0] %= ((long long)1e9 + 7);
    for (int p = 1; p < ((long long)26) - 1; p++)
      dp[i][p] -= dp[i][p + 1], dp[i][p] %= ((long long)1e9 + 7),
          dp[i][p] += ((long long)1e9 + 7), dp[i][p] %= ((long long)1e9 + 7);
    if (i != k) {
      for (long long p = 1, last = dp[i][0]; p < ((long long)26); p++) {
        long long ex = dp[i][p];
        dp[i][p] = last;
        last = ex;
      }
      dp[i][0] = 0;
    }
  }
  long long ans = 0, num = 0;
  for (long long i = 0, x = s; i < ((long long)26) - 1; i++, x = (x + 1) / 2)
    ans += dp[k][i] * x, num += dp[k][i], num %= ((long long)1e9 + 7),
        ans %= ((long long)1e9 + 7);
  ans += C(n - 1 + m - 1, n - 1) - num;
  ans %= ((long long)1e9 + 7);
  ans += ((long long)1e9 + 7);
  ans %= ((long long)1e9 + 7);
  ans *= tavan(C(n - 1 + m - 1, n - 1), ((long long)1e9 + 7) - 2);
  ans %= ((long long)1e9 + 7);
  cout << ans;
  return 0;
}
