#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int _min(int x, int y) { return x < y ? x : y; }
int _max(int x, int y) { return x > y ? x : y; }
int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
int a[510][510];
long long f[510][510], g[510][510];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = read();
  for (int i = 1; i <= n; i++) f[i][i] = 1;
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l <= n - len + 1; l++) {
      int r = l + len - 1;
      if (a[l][r]) {
        for (int k = l; k < r; k++)
          (f[l][r] +=
           (f[l][k] + g[l][k]) * (g[k + 1][r] + f[k + 1][r]) % mod) %= mod;
      }
      for (int k = l + 1; k < r; k++)
        if (a[l][k]) {
          (g[l][r] += f[l][k] * (f[k][r] + g[k][r])) %= mod;
        }
    }
  }
  long long ans = f[1][n];
  (ans += g[1][n]) %= mod;
  printf("%lld\n", ans);
  return 0;
}
