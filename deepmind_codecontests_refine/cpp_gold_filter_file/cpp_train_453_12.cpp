#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2010;
int n, m;
long long f[N][N], g[N][N], h[N][N], o[N][N], p[N][N], ans;
int main() {
  cin >> n >> m;
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  memset(h, 0, sizeof(h));
  memset(o, 0, sizeof(o));
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      (f[i][j] += 1 + g[i - 1][j] * j % mod + h[i - 1][j]) %= mod;
      o[i][j] = (f[i][j] - f[i - 1][j]) % mod;
    }
    for (int j = 2; j <= m; ++j) {
      g[i][j] = (g[i][j - 1] + f[i][j]) % mod;
      h[i][j] = (h[i][j - 1] + f[i][j] * (1 - j) % mod) % mod;
    }
  }
  memset(p, 0, sizeof(p));
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= m; ++j) p[i][j] = (p[i - 1][j] + o[i][j]) % mod;
  ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= m; ++j) {
      (ans += (m - j + 1) * o[i][j] % mod * p[n - i + 1][j] % mod) %= mod;
    }
  cout << (ans + mod) % mod << endl;
  return 0;
}
