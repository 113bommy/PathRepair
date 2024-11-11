#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 2;
const int mod = 998244353;
void inc(int& x, const int& y) { (x += y) >= mod ? x -= mod : 0; }
void dec(int& x, const int& y) { x < y ? x += mod - y : x -= y; }
void cmax(int& x, const int& y) { x = x > y ? x : y; }
int n, k, m;
int l[N], r[N], x[N], pos[N], a[N], f[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> x[i];
  int ans = 1;
  for (int p = 0; p <= k - 1; p++) {
    for (int i = 1; i <= n + 1; i++) pos[i] = a[i] = 0;
    for (int i = 1; i <= m; i++)
      if (x[i] >> p & 1)
        ++a[l[i]], --a[r[i] + 1];
      else
        cmax(pos[r[i] + 1], l[i]);
    for (int i = 2; i <= n + 1; i++) a[i] += a[i - 1], cmax(pos[i], pos[i - 1]);
    f[0] = 1;
    int sum = 1, l = 0;
    for (int i = 1; i <= n + 1; i++) {
      while (l < pos[i]) dec(sum, f[l]), f[l++] = 0;
      f[i] = a[i] ? 0 : sum, inc(sum, f[i]);
    }
    ans = 1ll * ans * f[n + 1] % mod;
  }
  cout << ans << '\n';
  return 0;
}
