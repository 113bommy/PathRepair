#include <bits/stdc++.h>
using namespace std;
long long modpow(long long b, long long e, long long mod) {
  long long ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
const int N = 200005;
const int MAGIC = 4160000;
const int CSQ = 225;
bool isp[MAGIC];
vector<int> primes;
long long n;
int sj[MAGIC], dp[N][CSQ];
long long icbrt(long long x) {
  long long u = cbrt(x);
  if (u * u * u < x) return u + 1;
  return u;
}
long long solve(long long i, int j) {
  if (j == 0) return i;
  if (i < (primes[j] * 1ll) * (primes[j] * 1ll) && i < MAGIC) {
    return sj[i] - (j - 1);
  }
  if (i < N && j < CSQ) return dp[i][j];
  return solve(i, j - 1) - solve(i / primes[j - 1], j - 1);
}
long long pi(long long x) {
  if (x < MAGIC) return sj[x];
  long long opt = icbrt(x);
  long long ans = solve(x, opt) + (opt - 1);
  while ((1ll * primes[opt]) * (1ll * primes[opt]) <= x) {
    ans -= pi(x / primes[opt]) - (opt);
    opt++;
  }
  return ans;
}
int32_t main() {
  scanf("%lld", &n);
  long long ans = 0;
  for (int i = 2; i < (MAGIC); ++i) {
    if (!isp[i]) {
      sj[i]++;
      primes.push_back(i);
      for (int j = 2 * i; j < MAGIC; j += i) isp[j] = 1;
    }
    sj[i] += sj[i - 1];
  }
  long long less = 0;
  for (int i = 1; i < (N); ++i) {
    dp[i][0] = i;
    for (int j = 1; j < (CSQ); ++j) {
      dp[i][j] = dp[i][j - 1] - dp[i / primes[j - 1]][j - 1];
    }
  }
  for (auto w : primes) {
    less++;
    if ((w * 1ll) * (w * 1ll) > n) break;
    if ((w * 1ll) * (w * 1ll) * (w * 1ll) <= n) ans++;
    ans += pi(n / (w * 1ll)) - less;
  }
  printf("%lld\n", ans);
}
