#include <bits/stdc++.h>
using namespace std;
long long n, k, x, tmp, f[2010], a[2010];
string s;
void solve() {
  cin >> n >> x >> k >> s;
  s = 'a' + s + 'a';
  memset(f, 0, sizeof f);
  f[n + 1] = 1;
  for (long long i = n; i >= 0; i--) {
    if (s[i] == 'a') {
      for (long long j = i + 1; j <= n + 1; j++) {
        if (s[j] == 'a') {
          if (f[j] != -1 && 1.0 * f[j] * ((j - i - 1) * x + 1) <= 1e18)
            f[i] = f[j] * ((j - i - 1) * x + 1);
          else
            f[i] = -1;
          break;
        }
      }
    }
  }
  for (long long i = 0; i <= n; i++) {
    if (s[i] == 'a') {
      if (i != 0) cout << 'a';
      for (long long j = i + 1; j <= n + 1; j++) {
        if (s[j] == 'a') {
          if (f[j] == -1) break;
          long long num = (k - 1) / f[j];
          for (long long o = 1; o <= num; o++) cout << 'b';
          k = (k - 1) % f[j] + 1;
          break;
        }
      }
    }
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
