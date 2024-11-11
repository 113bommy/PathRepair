#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[510][510], k, t;
long long f[510][510], g[510][510];
inline void read(int &x) {
  int tmp = 1;
  char ch = getchar();
  x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') tmp = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= tmp;
}
int jia(int t1, int t2) { return (t1 + t2 >= n) ? t1 + t2 - n : t1 + t2; }
int main() {
  read(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) read(a[i][j]);
  for (int i = 0; i < n; i++) f[i][i] = 1, g[i][i] = 1;
  for (int j = 1; j < n; j++)
    for (int i = 0; i < n; i++) {
      t = jia(i, j);
      k = i;
      while (k != t) {
        if (a[i][t]) g[i][t] = (g[i][t] + f[i][k] * f[jia(k, 1)][t]) % mod;
        f[i][t] = (f[i][t] + g[i][jia(k, 1)] * f[jia(k, 1)][t]) % mod;
        k = jia(k, 1);
      }
    }
  printf("%lld\n", f[0][n - 1]);
}
