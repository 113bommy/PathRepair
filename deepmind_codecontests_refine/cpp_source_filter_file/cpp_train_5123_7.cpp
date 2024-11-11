#include <bits/stdc++.h>
const long long mod = 998244353;
using namespace std;
long long n, a[200001], s[200001], z[200001];
long long fpow(long long x, long long st) {
  if (st == 0) return 1;
  long long t = fpow(x, st / 2);
  if (st % 2 == 0)
    return (t * t) % mod;
  else
    return ((t * t) % mod * x) % mod;
}
long long del(long long x) { return fpow(x, mod - 2); }
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  long long p = 1;
  for (long long i = n - 1; i >= 0; i--) {
    p = (p * 100 * del(a[i])) % mod;
    ans = (ans + p) % mod;
  }
  cout << ans;
  return 0;
}
