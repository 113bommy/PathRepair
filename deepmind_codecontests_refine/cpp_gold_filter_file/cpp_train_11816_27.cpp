#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long fcts[400000];
long long invs[400000];
long long n, k, x, y, z, m;
pair<long long, long long> kalas[20000];
long long dp[30000];
long long bigMod(long long n, long long k, long long mod) {
  if (k == 0) return 1;
  if (k == 1) return (n % mod);
  long long p = 0;
  p = bigMod(n, (k / 2), mod);
  p = (p * p) % mod;
  if (k % 2) p = (p * n) % mod;
  return p;
}
long long nCr(long long n, long long r) {
  long long tmp = fcts[n];
  long long tmp1 = invs[r];
  tmp = (tmp * tmp1) % mod;
  tmp1 = invs[n - r];
  tmp = (tmp * tmp1) % mod;
  return tmp;
}
int main() {
  fcts[0] = 1;
  for (long long i = 1; i <= 300000; i++) fcts[i] = (fcts[i - 1] * i) % mod;
  for (long long i = 0; i <= 300000; i++)
    invs[i] = bigMod(fcts[i], mod - 2, mod);
  cin >> n >> m >> k;
  for (long long i = 1; i <= k; i++) {
    scanf("%lld %lld", &kalas[i].first, &kalas[i].second);
  }
  sort(kalas + 1, kalas + k + 1);
  for (long long i = 1; i <= k; i++) {
    long long tmprow = kalas[i].first;
    long long tmpcol = kalas[i].second;
    dp[i] = nCr(tmprow + tmpcol - 2, tmprow - 1);
    for (long long j = 1; j < i; j++) {
      if (kalas[j].second <= kalas[i].second) {
        long long rowdif = kalas[i].first - kalas[j].first;
        long long coldif = kalas[i].second - kalas[j].second;
        long long tmp = (nCr(rowdif + coldif, coldif) * dp[j]) % mod;
        dp[i] = (dp[i] - tmp) % mod;
        dp[i] = (dp[i] + mod) % mod;
      }
    }
  }
  long long ans = nCr(n + m - 2, n - 1);
  for (long long i = 1; i <= k; i++) {
    long long rowdif = n - kalas[i].first;
    long long coldif = m - kalas[i].second;
    long long tmp = (nCr(rowdif + coldif, coldif) * dp[i]) % mod;
    ans = (ans - tmp) % mod;
    ans = (ans + mod) % mod;
  }
  cout << ans << endl;
  return 0;
}
