#include <bits/stdc++.h>
using namespace std;
int a[505];
long long f[505][505] = {};
long long g[505][505];
int main() {
  int n, m;
  int i, j, k;
  int lim, mod;
  cin >> n >> m >> lim >> mod;
  for (i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  f[m][0] = 1;
  int dx;
  int t;
  for (k = 1; k <= n; ++k) {
    memset(g, 0, sizeof(g));
    dx = a[k] - a[k - 1];
    for (i = m; i >= 0; --i)
      for (j = 0; j <= lim; ++j) {
        if (j - a[k - 1] >= 0)
          g[i][j] = f[i][j] + g[i + 1][j - a[k - 1]] % mod;
        else
          g[i][j] = f[i][j];
      }
    memcpy(f, g, sizeof(g));
  }
  long long res = 0;
  for (i = 0; i <= lim; ++i) res = (res + f[0][i]) % mod;
  cout << res << endl;
  return 0;
}
