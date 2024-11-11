#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long N = 100000;
long long two[N + 1], ten[N + 1], four[N + 1], seven[N + 1], prod[N + 1],
    sum[N + 1], Prod[N + 1];
void init() {
  two[0] = ten[0] = 1;
  for (long long i = 1; i <= N; i++)
    two[i] = 2 * two[i - 1] % mod, ten[i] = 10 * ten[i - 1] % mod;
  for (long long i = 1; i <= N; i++)
    four[i] = (10 * four[i - 1] + 4) % mod,
    seven[i] = (10 * seven[i - 1] + 7) % mod;
  prod[1] = Prod[1] = 28, sum[1] = 11;
  for (long long i = 2; i <= N; i++)
    prod[i] = (prod[i - 1] +
               4 * ten[i - 1] % mod *
                   (2 * sum[i - 1] - four[i - 1] - seven[i - 1]) % mod +
               4 * ten[i - 1] % mod * 4 * ten[i - 1] % mod * (two[i - 1] - 1) +
               prod[i - 1] +
               7 * ten[i - 1] % mod *
                   (2 * sum[i - 1] - four[i - 1] - seven[i - 1]) % mod +
               7 * ten[i - 1] % mod * 7 * ten[i - 1] % mod * (two[i - 1] - 1) +
               (4 * ten[i - 1] + seven[i - 1]) % mod *
                   (7 * ten[i - 1] + four[i - 1]) % mod) %
              mod,
    sum[i] = (2 * sum[i - 1] + 11 * ten[i - 1] % mod * two[i - 1] % mod) % mod,
    Prod[i] = (Prod[i - 1] + prod[i] + seven[i - 1] * four[i] % mod) % mod;
}
long long na, nb;
char a[N + 1], b[N + 1];
long long lar[N + 1];
bool dp[N + 1][2], pa[N + 1][2];
long long sol(long long n, char s[]) {
  memset(pa, -1, sizeof(pa));
  memset(dp, 0, sizeof(dp));
  if (s[n] >= '4') dp[n][0] = true;
  if (s[n] >= '7') dp[n][1] = true;
  for (long long i = n - 1; i; i--) {
    if (s[i] >= '4') {
      if (dp[i + 1][1])
        dp[i][0] = true, pa[i][0] = 1;
      else if (dp[i + 1][0])
        dp[i][0] = true, pa[i][0] = 0;
    }
    if (s[i] >= '7') {
      if (dp[i + 1][1])
        dp[i][1] = true, pa[i][1] = 1;
      else if (dp[i + 1][0])
        dp[i][1] = true, pa[i][1] = 0;
    }
  }
  long long now = dp[1][1] ? 1 : dp[1][0] ? 0 : -1;
  lar[1] = now;
  for (long long i = 1; ~now && i < n; i++) {
    now = pa[i][now];
    lar[i + 1] = now;
  }
  long long ans = Prod[n - 1];
  if (!~now) return ans;
  now = 0;
  long long las = 0;
  if (n > 1) las = seven[n - 1];
  for (long long i = 1; i <= n; i++) {
    long long head = (10 * now + 4) % mod * ten[n - i] % mod;
    if (lar[i] == 1)
      (ans += las * (head + four[n - i]) % mod + prod[n - i] +
              head * (2 * sum[n - i] - four[n - i] - seven[n - i]) % mod +
              head * head % mod * (two[n - i] - 1) % mod) %= mod,
          las = (head + seven[n - i]) % mod;
    now = (10 * now + (lar[i] == 0 ? 4 : 7)) % mod;
  }
  (ans += las * now) %= mod;
  return ans;
}
signed main() {
  init();
  cin >> a + 1 >> b + 1;
  na = strlen(a + 1), nb = strlen(b + 1);
  cout << ((sol(nb, b) - sol(na, a)) % mod + mod) % mod << "\n";
  return 0;
}
