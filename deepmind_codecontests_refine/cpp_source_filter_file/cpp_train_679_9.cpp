#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long llinf = (1LL << 62);
const int inf = (1 << 30);
const int nmax = 5e5 + 50;
const int ad = 2e5;
const int mod = 1e9 + 7;
using namespace std;
int a, b, k, t, i, j;
long long f[nmax], s[2][nmax], ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  cin >> a >> b >> k >> t;
  t *= 2;
  f[a - b + ad] = 1;
  for (j = -ad; j <= ad; j++) {
    s[0][j + ad] = f[j + ad];
    if (j + ad > 0) s[0][j + ad] = (s[0][j + ad] + s[0][j + ad - 1]) % mod;
  }
  for (i = 1; i <= t; i++) {
    for (j = -ad; j <= ad; j++) {
      f[j + ad] = s[0][min(j + k + ad, 2 * ad)];
      if (j - k - 1 + ad >= 0)
        f[j + ad] = (f[j + ad] - s[0][j - k - 1 + ad] + mod) % mod;
      s[1][j + ad] = f[j + ad];
      if (j + ad > 0) s[1][j + ad] = (s[1][j + ad] + s[1][j + ad - 1]) % mod;
    }
    for (j = -ad; j <= ad; j++) s[0][j + ad] = s[1][j + ad];
  }
  ans = (s[0][2 * ad] - s[0][ad] + mod) % mod;
  cout << ans << endl;
  return 0;
}
