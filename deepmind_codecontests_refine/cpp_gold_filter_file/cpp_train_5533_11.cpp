#include <bits/stdc++.h>
using namespace std;
const int Lim = 2e3, MAXN = Lim + 10, MOD = 1e9 + 7;
inline long long fpow(long long a, long long x) {
  long long ans = 1;
  for (; x; x >>= 1, a = a * a % MOD)
    if (x & 1) ans = ans * a % MOD;
  return ans;
}
inline long long inv(long long a) { return fpow(a, MOD - 2); }
int prime[MAXN], cntprime, sumu[MAXN];
bool nprime[MAXN];
inline void sieve() {
  for (int i = 2; i <= Lim; ++i) {
    if (!nprime[i]) prime[++cntprime] = i, sumu[i] = -1;
    for (int j = 1; j <= cntprime && i * prime[j] <= Lim; ++j) {
      nprime[i * prime[j]] = 1;
      sumu[i * prime[j]] = (i % prime[j] == 0 ? 0 : -sumu[i]);
      if (i % prime[j] == 0) break;
    }
  }
  sumu[1] = 1;
  for (int i = 2; i <= Lim; ++i) sumu[i] += sumu[i - 1];
}
unordered_map<long long, int> Smu;
inline int summu(long long n) {
  if (n <= Lim) return sumu[n];
  if (Smu.count(n)) return Smu[n];
  for (long long i = n, d; i >= 1; i = n / (d + 1)) {
    d = n / i;
    if (d <= Lim || Smu.count(d)) continue;
    long long tmp = 1;
    for (long long l = 2, r, dd; l <= d; l = r + 1) {
      r = d / (dd = d / l);
      if (dd <= Lim)
        tmp -= (r - l + 1) * sumu[dd] % MOD;
      else
        tmp -= (r - l + 1) * Smu[dd] % MOD;
    }
    tmp = (tmp - MOD) % MOD + MOD;
    Smu[d] = (tmp == MOD ? 0 : tmp);
  }
  return Smu[n];
}
int n;
int main() {
  sieve();
  cin >> n;
  long long el = 0;
  summu(n);
  for (long long l = 2, r, d; l <= n; l = r + 1) {
    r = n / (d = n / l);
    el -= (summu(r) - summu(l - 1)) * inv(n - d) % MOD;
  }
  el = (el % MOD * n % MOD + summu(n) % MOD + MOD + MOD) % MOD;
  cout << el;
  return 0;
}
