#include <bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int a[N], f[N][N], g[N][N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  a[0] = 1e9;
  for (int i = 1; i <= n + 1; ++i)
    g[i][i] = f[i][i] = f[i][i - 1] = g[i][i - 1] = 1;
  for (int len = 2; len <= n; ++len) {
    for (int l = 1; l + len - 1 <= n; ++l) {
      int r = l + len - 1, t = 0;
      for (int k = l; k <= r; ++k)
        if (a[k] < a[t]) t = k;
      f[l][r] = g[l][r] = 1ll * f[l][t - 1] * f[t + 1][r] % mod;
      for (int k = l; k < r; ++k) {
        f[l][r] = (f[l][r] + 1ll * g[l][k] * f[k + 1][r] % mod) % mod;
      }
    }
  }
  cout << f[1][n];
  return 0;
}
