#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int mod = 1e9 + 7;
int n, a[N];
int f[N][2 * N], s[N], tot[N * 2];
int pw(int x, int i) {
  long long b = 1;
  for (; i; i >>= 1, x = 1ll * x * x % mod)
    if (i & 1) b = 1ll * b * 1ll * x % mod;
  return b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  s[0] = 1;
  for (int i = 1; i < n; ++i) s[i] = 1ll * s[i - 1] * a[i] % mod;
  for (int i = n; i >= 1; --i) {
    f[i][0] = 1;
    for (int j = 1; j <= n - i; ++j) {
      f[i][j] = 1ll * f[i + 1][j - 1] * 1ll * a[i] % mod;
      tot[j] = (1ll * tot[j] + 1ll * f[i][j] * 1ll * s[i - 1] % mod) % mod;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 2 * n - 2; j >= 1; --j) {
      f[i][j] = f[i - 1][j - 1];
      if (i > 1 && j > 1 && j - 2 <= n - i)
        f[i][j] =
            (1ll * f[i][j] + 1ll * f[i][j - 2] * 1ll * (a[i - 1] - 1) % mod) %
            mod;
      tot[j] = (1ll * tot[j] + 1ll * f[i][j] * 1ll * s[i - 1] % mod) % mod;
    }
  }
  for (int i = 1; i <= 2 * n - 2; ++i)
    cout << (1ll * tot[i] * (mod + 1) / 2) % mod << ' ';
}
