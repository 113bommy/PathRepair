#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50, mod = 1e9 + 7;
int n, m, g, ans, f[N], inv[N];
int add(int x, int y) { return (x * 1ll + y) % mod; }
int mul(int x, int y) { return (x * 1ll * y) % mod; }
int c(int n, int k) { return n < k ? 0 : mul(f[n], mul(inv[k], inv[n - k])); }
int pw(int b, long long p) {
  if (!p) return 1;
  int ret = pw(b, p / 2);
  ret = mul(ret, ret);
  if (p & 1) ret = mul(ret, b);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> g;
  if (!n) return cout << (m == 1 ? g : !g), 0;
  if (!m) return cout << (n % 2 != g), 0;
  f[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = mul(f[i - 1], i);
    inv[i] = pw(f[i], mod - 2);
  }
  for (int i = 0; i <= m; i++) {
    int rst = n + m - i - 1;
    if (i % 2 == (g ^ !rst)) ans = add(ans, c(rst, m - 1));
  }
  cout << ans;
}
