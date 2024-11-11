#include <bits/stdc++.h>
using namespace std;
const long long ts = 100005;
const long long mod = 998244353;
long long n, m, l, r;
long long binpow(long long a, long long p) {
  if (p == 1) return a;
  if (p == 0) return 1ll;
  long long res = binpow(a, p / 2);
  if (p & 1)
    return ((res * res % mod) * a) % mod;
  else
    return (1ll * res * res) % mod;
}
long long init() {
  cin >> n >> m >> l >> r;
  if ((1ll * n * m) % 2 == 1) {
    return binpow((long long)r - l + 1, (long long)n * m);
  } else if (r - l == 0)
    return 1ll;
  else {
    long long ans = binpow((long long)r - l + 1, (long long)n * m);
    if ((r - l + 1) % 2 == 1) ans++;
    if (ans % 2 == 1)
      return (ans + mod) / 2;
    else
      return ans / 2;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout << init();
}
