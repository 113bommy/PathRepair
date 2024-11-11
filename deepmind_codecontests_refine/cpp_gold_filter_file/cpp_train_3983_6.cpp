#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long mod = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}
long long qpow(long long x, long long y, long long MOD) {
  long long a = 1;
  while (y) {
    if (y & 1) a = a * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return a;
}
int n, m, a[N], b[N], f[N], p[N];
long long gao() {
  for (int i = 1, j = 1; i <= n; ++i) {
    if (j <= m && a[i] == b[j]) {
      f[j] = i;
      ++j;
    }
  }
  if (f[m] == 0) return 0;
  for (int i = int(1); i <= int(m - 1); ++i)
    for (int j = int(f[i] + 1); j <= int(f[i + 1]); ++j) {
      if (a[j] < b[i]) {
        p[i] = j;
        break;
      }
    }
  for (int i = int(1); i <= int(f[1]); ++i)
    if (a[i] < b[1]) return 0;
  for (int i = int(2); i <= int(m); ++i) {
    for (int j = int(p[i - 1]); j <= int(f[i] - 1); ++j) {
      if (a[j] < b[i]) return 0;
    }
  }
  for (int i = int(f[m] + 1); i <= int(n); ++i)
    if (a[i] < b[m]) return 0;
  long long ans = 1;
  for (int i = int(1); i <= int(m - 1); ++i) ans = ans * (p[i] - f[i]) % mod;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = int(1); i <= int(n); ++i) cin >> a[i];
  for (int i = int(1); i <= int(m); ++i) cin >> b[i];
  reverse(a + 1, a + 1 + n);
  reverse(b + 1, b + 1 + m);
  cout << gao();
  return 0;
}
