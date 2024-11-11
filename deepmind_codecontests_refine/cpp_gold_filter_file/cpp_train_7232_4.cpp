#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10, Mod = 1e9 + 7;
long long n, k, t, A[maxn], fact[maxn], inv[maxn], ps[maxn], dah[maxn], ans;
string s;
long long poow(long long x, long long y) {
  if (!y) return 1;
  long long tmp = poow(x, y / 2);
  tmp = (tmp * tmp) % Mod;
  if (y % 2) tmp = (tmp * x) % Mod;
  return tmp;
}
long long choose(long long x, long long y) {
  return (((fact[x] * inv[y]) % Mod * inv[x - y]) % Mod);
}
int32_t main() {
  cin >> n >> k;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    A[i] = int32_t(s[i]) - 48;
  }
  t = n - 1;
  fact[0] = 1;
  dah[0] = 1;
  inv[0] = 1;
  for (long long i = 1; i < maxn; i++) {
    fact[i] = (fact[i - 1] * i) % Mod;
    dah[i] = (dah[i - 1] * 10) % Mod;
  }
  inv[maxn - 1] = poow(fact[maxn - 1], Mod - 2);
  for (long long i = maxn - 2; i; i--) {
    inv[i] = (inv[i + 1] * (i + 1)) % Mod;
  }
  for (long long i = 1; i < maxn; i++) {
    if (t - i >= k - 1)
      ps[i] = (ps[i - 1] + (dah[i - 1] * choose(t - i, k - 1) % Mod)) % Mod;
  }
  for (long long i = 0; i < n - 1; i++) {
    long long tmp = 0;
    if (n - i <= n - k) {
      tmp = (A[i] * ps[n - i - 1]) % Mod;
      tmp += (A[i] * dah[n - i - 1] * choose(i, k)) % Mod;
    } else {
      tmp = (A[i] * ps[n - k]) % Mod;
    }
    ans = (ans + tmp) % Mod;
  }
  ans = (ans + choose(t, k) * A[n - 1]) % Mod;
  cout << ans;
  return 0;
}
