#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
const long long INFll = 1ll * INF * INF;
const int MOD = 1000000007;
int f[101][10101];
int g[101][101];
int z[101];
int pow(int a, long long b, int MOD) {
  if (b == 0) return 1;
  int y = 1;
  while (b > 1) {
    if (b % 2)
      y = (1ll * y * a) % MOD, b--;
    else
      a = (1ll * a * a) % MOD, b /= 2;
  }
  return 1ll * a * y % MOD;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k;
  long long m;
  cin >> n >> m >> k;
  f[0][0] = 1;
  z[0] = 1;
  for (int i = 1; i <= n; ++i)
    z[i] = 1ll * z[i - 1] * (n - i + 1) * pow(i, MOD - 2, MOD) % MOD;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= n; ++j)
      g[i][j] = pow(z[j], (m - i) / n + ((m - i) % n > 0), MOD);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= k; ++j)
      for (int z = 0; z <= n; ++z)
        f[i + 1][j + z] = (f[i + 1][j + z] + 1ll * f[i][j] * g[i][z]) % MOD;
  cout << f[n][k] << endl;
  return 0;
}
