#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long sgcd[1000010], h[1000010], sq_2[1000010], f[1000010], fi[1000010],
    fii[1000010];
int p[1000010], pr[100010], ptop, phi[1000010], low[1000010];
void eratos(int x) {
  int i;
  p[0] = p[1] = 1;
  low[1] = 998244353;
  phi[1] = 1;
  int j;
  for (i = 2; i <= x; i++) {
    if (!p[i]) phi[i] = i - 1, low[i] = pr[ptop++] = i;
    for (j = 0; j < ptop; j++) {
      if (pr[j] * i > x) break;
      p[pr[j] * i] = 1;
      low[pr[j] * i] = i;
      if (i % pr[j] == 0) {
        phi[i * pr[j]] = pr[j] * phi[i];
        break;
      } else
        phi[i * pr[j]] = (pr[j] - 1) * phi[i];
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  eratos(1000000);
  int i, j, cnt, base;
  for (i = 1; i <= 1000000; i++) {
    base = phi[i];
    cnt = 0;
    for (j = i; j <= 1000000; j += i) {
      cnt += base;
      sgcd[j] += cnt;
    }
    sgcd[i] -= i;
    sgcd[i] %= mod;
  }
  for (i = 2; i <= 1000000; i++) {
    h[i] =
        (h[i - 1] + (((i - 2ll) * (i - 3) >> 1) - 1 - sgcd[i - 1] + sgcd[i]) %
                        mod * (mod + 1 >> 1)) %
        mod;
  }
  sq_2[1] = 1;
  for (i = 2; i <= 1000000; i++) {
    sq_2[i] = (sq_2[i - 2] + (long long)i * i) % mod;
  }
  f[1] = 1;
  for (i = 2; i <= 1000000; i++) {
    f[i] = ((long long)i * i + 2 * sq_2[i - 2] + 4 * h[i]) % mod;
  }
  for (i = 1; i <= 1000000; i++) {
    fii[i] = (f[i] * i % mod * i + fii[i - 1]) % mod;
    fi[i] = (f[i] * i + fi[i - 1]) % mod;
    f[i] = (f[i] + f[i - 1]) % mod;
  }
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n > m) n ^= m ^= n ^= m;
    long long ans = 0;
    ans = f[n] * (n + 1) % mod * (m + 1) % mod;
    ans = (ans + (mod - n - m - 2) * fi[n]) % mod;
    ans = (ans + fii[n]) % mod;
    cout << ans << '\n';
  }
  return 0;
}
