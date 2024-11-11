#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
const int mod = 1e9 + 7;
int n, k;
int f[35][N], g[35][N];
void init() {
  for (int i = 0; i <= 31; i++) f[i][0] = g[i][0] = 1;
  for (int i = 1; i <= 31; i++) {
    for (int j = 1; j < N; j++) {
      for (int k = 0; k < j; k++) {
        f[i][j] += 1LL * g[i - 1][k] * g[i - 1][j - k - 1] % mod;
        f[i][j] %= mod;
      }
      for (int k = 0; k <= j; k++) {
        g[i][j] += 1LL * f[i][k] * f[i][j - k] % mod;
        g[i][j] %= mod;
      }
    }
  }
}
int main() {
  init();
  int T;
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &k);
    int cnt = 0;
    while ((n & 1) && n >= 3) {
      cnt++;
      n >>= 1;
    }
    printf("%d\n", f[cnt][k]);
  }
  return 0;
}
