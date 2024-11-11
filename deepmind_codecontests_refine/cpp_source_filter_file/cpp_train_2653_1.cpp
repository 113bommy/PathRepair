#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long pow(long long a, long long b) {
  long long ans = 1;
  a %= mod;
  while (b) {
    if (b % 2) {
      ans *= a;
      ans %= mod;
    }
    b /= 2;
    a *= a;
    a %= mod;
  }
  return ans;
}
long long inv(long long a) { return pow(a, mod - 2); }
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
struct cmp {
  bool operator()(pair<long long, long long> a,
                  pair<long long, long long> b) const {
    long long x = a.first;
    long long y = b.first;
    return x >= y;
  }
};
long long p[605];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(15);
  ;
  long long m, t, r;
  cin >> m >> t >> r;
  long long w[m];
  for (long long i = 0; i < m; i++) cin >> w[i];
  long long ans = 0;
  if (r > t)
    cout << -1;
  else {
    long long j = 0;
    for (long long i = w[0]; i <= w[m - 1]; i++) {
      p[i] += p[i - 1];
      if (i == w[j]) {
        long long diff = r - p[i];
        ans += diff;
        long long x = i - 1 + t;
        for (long long k = x; k > x - diff; k--) {
          p[k] = -1;
        }
        j++;
        p[i] = r;
      }
    }
    cout << ans;
  }
  return 0;
}
