#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long power(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    if (ret >= MOD) ret %= MOD;
    if (a >= MOD) a %= MOD;
    b >>= 1;
  }
  return ret;
}
long long invmod(long long x) { return power(x, MOD - 2); }
bool prime[1000006];
vector<long long> pm;
vector<long long> primefac(long long n) {
  vector<long long> v;
  for (long long i = 0; pm[i] * pm[i] <= n; i++) {
    long long c = 0;
    while (n % pm[i] == 0) c++, n /= pm[i];
    if (c) v.push_back(c);
  }
  if (n >= 2) v.push_back(1);
  return v;
}
long long fac[2000006];
void facto() {
  fac[0] = 1;
  for (long long i = 1; i < 2000005; i++) fac[i] = (fac[i - 1] * i) % MOD;
}
long long C(long long n, long long r) {
  long long ans = 1;
  ans *= fac[n];
  ans *= invmod(fac[r]);
  ans %= MOD;
  ans *= invmod(fac[n - r]);
  ans %= MOD;
  return ans;
}
int main() {
  long long i, x, y, j;
  memset(prime, true, sizeof prime);
  for (i = 2; i <= 1000005; i++)
    if (prime[i])
      for (j = i + i; j <= 1000005; j += i) prime[j] = false;
  for (i = 2; i <= 1000005; i++)
    if (prime[i]) pm.push_back(i);
  facto();
  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    cin >> x >> y;
    vector<long long> v = primefac(x);
    long long ans = 1;
    for (auto it : v) {
      ans *= (C(it + y - 1, y - 1));
      ans %= MOD;
    }
    ans *= power(2, y - 1);
    ans %= MOD;
    cout << ans << endl;
  }
  return 0;
}
