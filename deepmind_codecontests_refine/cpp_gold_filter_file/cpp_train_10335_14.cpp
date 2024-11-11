#include <bits/stdc++.h>
using namespace std;
int n, m, mod, l[1111222];
long long a[5555], p[5555], e[5555][5555], f[2][5555], s[2];
int main() {
  if (0) {
    freopen("aaa.inp", "r", stdin);
    freopen("aaa.out", "w", stdout);
  };
  scanf("%d%d%d", &n, &m, &mod);
  for (int i = 1; i <= n; i++) scanf("%d", l + i);
  a[0] = 1;
  for (int i = 1; i < 5001 && i <= m; i++) a[i] = a[i - 1] * (m - i + 1) % mod;
  p[0] = 1;
  for (int i = 1; i < 5001 && i <= m; i++) p[i] = p[i - 1] * i % mod;
  e[1][1] = 1;
  for (int i = 2; i <= 5001; i++)
    for (int j = 2; j <= i; j++)
      e[i][j] = (e[i - 1][j - 1] + e[i - 1][j] * (j - 1)) % mod;
  for (int j = 1; j <= l[1]; j++) s[1] += f[1][j] = e[l[1]][j] * a[j] % mod;
  s[1] %= mod;
  for (int i = 2; i <= n; i++) {
    int i1 = i & 1, i2 = i1 ^ 1;
    s[i1] = 0;
    for (int j = 1; j <= l[i]; j++) {
      f[i1][j] = e[l[i]][j] * a[j] % mod * s[i2] % mod;
      if (j <= l[i - 1]) {
        long long c = p[j] * e[l[i]][j] % mod * f[i2][j] % mod;
        f[i1][j] = (f[i1][j] + mod - c) % mod;
      }
      s[i1] += f[i1][j];
    }
    s[i1] %= mod;
  }
  cout << s[n & 1];
  return 0;
};
