#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const long long MOD = 1e9 + 7;
long long pr[MAXN], f[MAXN], g[MAXN], s[MAXN], ss[MAXN], sss[MAXN];
long long bruh(long long n) {
  long long res = 1;
  while (n > 1) {
    long long p = pr[n], a = 0, pa = 1;
    while (n % p == 0) {
      n /= p;
      a++;
      pa *= p;
    }
    long long tm = ((a + 1) * pa - a * (pa / p));
    res *= tm;
  }
  return res;
}
void add(long long &x, long long y) {
  y %= MOD;
  x += y;
  x %= MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int p = 2; p < MAXN; p++) {
    if (pr[p]) continue;
    for (int q = p; q < MAXN; q += p) pr[q] = p;
  }
  for (int i = 1; i < MAXN; i++) f[i] = bruh(i);
  for (long long i = 1; i < MAXN; i++) {
    g[i] = (i * (i + 1) * (2 * i + 1) / 3 - i * i * 3 + 2LL * f[i]) % MOD;
    s[i] = (s[i - 1] + g[i]) % MOD;
    ss[i] = (ss[i - 1] + i * g[i]) % MOD;
    sss[i] = (sss[i - 1] + ((i * g[i]) % MOD * i)) % MOD;
  }
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    long long k = min(n, m);
    add(ans, sss[k]);
    add(ans, -(n + m + 2) * ss[k]);
    add(ans, (((n + 1) * (m + 1) % MOD) * s[k]) % MOD);
    cout << (ans + MOD) % MOD << '\n';
  }
}
