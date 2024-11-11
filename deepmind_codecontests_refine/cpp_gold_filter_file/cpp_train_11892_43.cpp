#include <bits/stdc++.h>
using namespace std;
const long long N = 10 * 100 + 19;
const long long inf = 1000 * 1000 * 1000 + 19;
const long long mod = 1000000007;
long long n, m, k, Fact[N], FactRev[N];
inline void prep();
inline long long C(long long, long long);
long long pw(long long, long long);
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  prep();
  cout << (C(n - 1, 2 * k) * C(m - 1, 2 * k)) % mod;
  return 0;
}
inline void prep() {
  Fact[0] = FactRev[0] = 1;
  for (long long i = 1; i < N; i++) {
    Fact[i] = (Fact[i - 1] * i) % mod;
    FactRev[i] = pw(Fact[i], mod - 2);
  }
}
long long pw(long long x, long long y) {
  if (y == 0) return 1;
  long long t = pw(x, y / 2);
  return ((y & 1) ? ((((t * t) % mod) * x) % mod) : ((t * t) % mod));
}
inline long long C(long long x, long long y) {
  if (y < 0 || y > x) return 0;
  return (((Fact[x] * FactRev[y]) % mod) * FactRev[x - y]) % mod;
}
