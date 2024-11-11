#include <bits/stdc++.h>
using namespace std;
const long long md = 998244353;
long long a[1000005], n, k;
long long power(long long a, long long p, long long m = md) {
  return p ? power(a * a % m, p / 2, m) * (p & 1 ? a : 1) % m : 1;
}
long long fac[200005] = {1}, inv[200005] = {1};
long long ncr(int n, int r) {
  if (r > n) return 0;
  return inv[r] * inv[n - r] % md * fac[n] % md;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    fac[i] = i * fac[i - 1] % md;
    inv[i] = power(fac[i], md - 2);
  }
  if (k >= n) return cout << 0, 0;
  k = n - k;
  long long ans = (k ? 2 : 1) * fac[k] % md * ncr(n, k) % md, s = 0;
  for (int i = 0; i <= k; ++i) {
    long long now = ncr(k, i) * power(k - i, n) % md;
    if (i % 2 == 0)
      (s += now) %= md;
    else
      (s += md - now) %= md;
  }
  cout << ans * s % md * inv[k] % md << '\n';
}
