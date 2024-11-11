#include <bits/stdc++.h>
#pragma GCC optimize(2)
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const double eps = 1e-8;
using namespace std;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int t, n, m, k, x, y, a[N], b[N], L, R, pos;
long long ans;
bool check() {
  int mx = max(a[L - 1], a[R]), mxcnt = 0, len = R - L;
  for (int i = L; i < R; ++i)
    if (a[i] > mx) ++mxcnt;
  if (len < k) {
    if (mxcnt) return 1;
    ans += 1ll * y * len;
  } else {
    if (mxcnt) len -= k, ans += x;
    ans += min(1ll * y * len, 1ll * (len / k) * x + 1ll * (len % k) * y);
  }
  return 0;
}
long long solve() {
  cin >> n >> m >> x >> k >> y;
  a[n] = -1;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  for (R = 0; R < n; ++R) {
    if (a[R] == b[pos]) {
      if (L != R - 1 || L + R == 0)
        if (check()) return -1;
      ++pos, L = R + 1;
    }
  }
  if (pos != m) return -1;
  if (L < n)
    if (check()) return -1;
  return ans;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cout << solve();
  return 0;
}
