#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 20, K = 12;
const double eps = 0.00000000001, eps2 = 0.0001;
const int INF = (int)1e9 + 9;
const long long LINF = 1e16;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
int n, k;
long long pref[N], d[N];
long long fact[N], invf[N];
int binDeg(int x, int deg) {
  if (deg == 1) {
    return x;
  }
  if (deg == 0) {
    return 1;
  }
  long long temp = binDeg(x, deg / 2);
  long long ans = temp * temp;
  ans %= MOD;
  if (deg & 1) {
    ans *= x;
  }
  return ans % MOD;
}
int inv(int a) {
  int deg = MOD - 2;
  return binDeg(a, deg);
}
int main() {
  cin >> n >> k;
  fact[0] = invf[0] = 1;
  for (int i = 0; i < 1e6 + 2; i++) {
    fact[i + 1] = fact[i] * (i + 1);
    fact[i + 1] %= MOD;
    invf[i + 1] = inv(fact[i + 1]);
  }
  for (int i = k + 2; i <= n; i++) {
    d[i] = (i - k - 1);
    d[i] += pref[i - 1] - pref[i - k - 1];
    d[i] %= MOD;
    d[i] *= fact[i - 2];
    d[i] %= MOD;
    pref[i] = (d[i] * invf[i - 1]) % MOD;
    pref[i] = (pref[i] + pref[i - 1]) % MOD;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += d[i] * invf[i - 1];
    ans %= MOD;
  }
  cout << ans * fact[n - 1] % MOD;
  return 0;
}
