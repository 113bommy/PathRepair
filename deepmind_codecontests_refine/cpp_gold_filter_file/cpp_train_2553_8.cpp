#include <bits/stdc++.h>
using namespace std;
const long long maxN = 2e5 + 5, mod = 1e9 + 7, maxV = 2e6 + 5;
long long N, K, Q;
long long coef[maxV];
long long cnt[maxV];
long long fac[maxN];
long long inv[maxN];
long long ans;
long long bp(long long a, long long b) {
  long long re = 1;
  while (b) {
    if (b & 1) re = (re * a) % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return re;
}
void init() {
  for (long long i = (long long)0; i <= (long long)maxN - 1; i++) {
    if (!i)
      fac[i] = 1;
    else
      fac[i] = fac[i - 1] * i % mod;
    inv[i] = bp(fac[i], mod - 2);
  }
  for (long long i = (long long)1; i <= (long long)maxV - 1; i++) {
    coef[i] = i;
  }
  for (long long i = (long long)1; i <= (long long)maxV - 1; i++) {
    for (long long j = 2 * i; j < maxV - 1; j += i) coef[j] -= coef[i];
  }
}
long long C(long long k, long long n) {
  if (k > n) return 0;
  return fac[n] * inv[n - k] % mod * inv[k] % mod;
}
void add(long long v) {
  ans -= C(K, cnt[v]) * coef[v] % mod;
  assert(C(K, cnt[v]) >= 0);
  cnt[v]++;
  ans += C(K, cnt[v]) * coef[v] % mod;
  ans = (ans % mod + mod) % mod;
}
void insert(long long x) {
  for (long long i = 1; i * i <= x; ++i) {
    if (x % i) continue;
    add(i);
    if (i * i != x) add(x / i);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K >> Q;
  init();
  for (long long i = (long long)1; i <= (long long)N; i++) {
    long long t;
    cin >> t;
    insert(t);
  }
  for (long long id = (long long)1; id <= (long long)Q; id++) {
    long long t;
    cin >> t;
    insert(t);
    cout << ans << '\n';
  }
}
