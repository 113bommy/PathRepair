#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % mod;
    }
    x = (x * x) % mod;
    y = (y >> 1);
  }
  return res;
}
signed main() {
  long long int fact[200005];
  fact[0] = 1;
  for (long long int i = 1; i < 200005; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int ans;
    ans = (fact[m] * power(fact[m - (n - 1)], mod - 2)) % mod;
    ans = (ans * power(fact[n - 1], mod - 2)) % mod;
    ans = (ans * (n - 2)) % mod;
    ans = (ans * power(2, n - 3)) % mod;
    cout << ans << endl;
  }
}
