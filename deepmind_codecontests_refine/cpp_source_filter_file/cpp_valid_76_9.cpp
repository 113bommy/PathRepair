#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, m;
long long f[maxn], s[maxn];
inline void solve() {
  cin >> n >> m;
  s[1] = 1;
  for (int i = 2; i <= n; ++i) {
    f[i] = s[i - 1];
    for (int j = 2, x, r; j <= i; ++j) {
      x = i / j;
      r = min(i / x, n);
      f[i] = (f[i] + f[x] * (r - j + 1)) % m;
      j = r;
    }
    s[i] = (s[i - 1] + f[i]) % m;
  }
  cout << f[n] << '\n';
}
signed main() {
  cin.sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  while (_--) solve();
  return 0;
}
