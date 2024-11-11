#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int p = 1e9 + 7;
int n, a[maxn][maxn];
long long f[maxn][maxn], g[maxn][maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) a[i][n + 1] = a[1][i];
  for (int i = n; i >= 1; i--) {
    f[i][i + 1] = g[i][i + 1] = 1;
    for (int j = i + 2; j <= n + 1; j++) {
      for (int k = i + 1; k < j; k++) {
        if (a[k][j]) g[i][j] = (g[i][j] + g[i][k] * f[k][j]) % p;
        if (a[i][k]) f[i][j] = (f[i][j] + f[i][k] * f[k][j]) % p;
      }
      f[i][j] = (f[i][j] + g[i][j]) % p;
    }
  }
  printf("%lld\n", g[1][n + 1]);
  return 0;
}
