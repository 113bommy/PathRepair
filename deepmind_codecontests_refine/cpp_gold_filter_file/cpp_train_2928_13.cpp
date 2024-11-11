#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x;
}
long long dp[202][202];
int y[222];
int main() {
  int n, kr, x;
  n = read(), kr = read(), x = read();
  kr = kr;
  for (register int i = 1; i <= n; i++) y[i] = read();
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (register int i = 1; i <= n + 1; i++) {
    for (register int j = 1; j <= x + 1; j++) {
      long long maxx = -1;
      for (register int k = max(0, i - kr); k <= i - 1; k++) {
        if (dp[k][j - 1] > maxx) {
          maxx = dp[k][j - 1];
        }
      }
      if (maxx != -1) {
        dp[i][j] = maxx + y[i];
      }
    }
  }
  cout << dp[n + 1][x + 1];
  return 0;
}
