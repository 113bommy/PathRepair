#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5, lim = 1e6, inf = 1e8;
long long k, S;
long long q, n;
long long F[6];
long long f[maxn];
long long tot;
long long w[maxn], v[maxn];
long long g[maxn];
long long get(long long x) {
  long long ans = 0;
  for (long long i(0), endi(5); i <= endi; i++) {
    if ((x % 10) % 3 == 0) ans += (x % 10) / 3 * F[i];
    x /= 10;
  }
  return ans;
}
signed main() {
  cin >> k;
  S = 3 * (k - 1);
  for (long long i(0), endi(5); i <= endi; i++) scanf("%lld", &F[i]);
  long long now = 1;
  for (long long j(0), endj(5); j <= endj; j++) {
    long long s = S;
    for (long long i(0), endi(20); i <= endi; i++) {
      if ((1 << i) <= s && 3 * (1 << i) * now <= lim)
        w[++tot] = 3 * now * (1 << i), v[tot] = F[j] * (1 << i), s -= (1 << i);
      else
        break;
    }
    w[++tot] = 3 * now * s;
    v[tot] = F[j] * s;
    now *= 10;
  }
  for (long long i(1), endi(lim); i <= endi; i++) g[i] = get(i);
  for (long long i(1), endi(lim); i <= endi; i++) f[i] = -inf;
  f[0] = 0;
  for (long long i(1), endi(tot); i <= endi; i++)
    for (long long j(lim), endj(w[i]); j >= endj; j--)
      f[j] = max(f[j], f[j - w[i]] + v[i]);
  cin >> q;
  while (q--) {
    long long ans = 0;
    cin >> n;
    for (long long i(0), endi(n); i <= endi; i++)
      ans = max(ans, f[i] + g[n - i]);
    printf("%lld\n", ans);
  }
  return 0;
}
