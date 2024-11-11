#include <bits/stdc++.h>
using namespace std;
int cnt, n, k, T, f[100][10000], g[100][10000];
const int mod = 7340033;
void init() {
  for (int i = 0; i <= 30; i++) f[i][0] = g[i][0] = 1;
  for (int i = 1; i <= 30; i++)
    for (int j = 1; j <= 1000; j++) {
      for (int k = 0; k < j; k++)
        f[i][j] =
            (1ll * g[i - 1][k] * g[i - 1][j - k - 1] % mod + f[i][j]) % mod;
      for (int k = 0; k <= j; k++)
        g[i][j] = (1ll * f[i][j] * f[i][j - k] % mod + g[i][j]) % mod;
    }
}
int main() {
  init();
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k), cnt = 0;
    for (; (n & 1) && (n > 1); n >>= 1) cnt++;
    printf("%d\n", f[cnt][k]);
  }
  return 0;
}
