#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5e3 + 10;
const long long INF = 8e18;
const long long MOD = 998244353;
inline long long poww(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ans;
}
long long n, m, k, F[MAXN], inv[MAXN], fact[MAXN];
inline void mkey(long long& a) {
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}
inline long long C(int k, int n) {
  return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
inline long long P(int k, int n) {
  long long ans = 1;
  for (int i = n; i > n - k; i--) ans = ans * i % MOD;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  fact[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; i++)
    fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);
  for (int i = 1; i <= k; i++) {
    F[i] = poww(i, k);
    for (int j = 1; j < i; j++) mkey(F[i] -= C(j, i) * F[j]);
  }
  long long ans = 0;
  for (int i = 1; i <= k; i++) {
    long long tans = F[i];
    tans = tans * P(i, n) % MOD * inv[i] % MOD;
    long long p_m = poww(m, MOD - 2);
    p_m = poww(p_m, i);
    tans = tans * p_m % MOD;
    mkey(ans += tans);
  }
  cout << ans << '\n';
  return 0;
}
