#include <bits/stdc++.h>
using namespace std;
int fact[1005], c[1005][1005] = {0}, f[1005][1005][4] = {0}, an[1005] = {0}, n,
                K;
inline void upd(int &x, int y) { x = (x + y) % 1000000007; }
int main() {
  scanf("%d%d", &n, &K);
  fact[0] = c[0][0] = 1;
  for (int i = 1; i <= n; i++)
    c[i][0] = 1, fact[i] = 1ll * fact[i - 1] * i % 1000000007;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
  f[0][0][2] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < i; j++)
      for (int k = 0; k < 4; k++) {
        if (k & 1) upd(f[i][j + 1][(k >> 1) | 2], f[i - 1][j][k]);
        if (i < n) upd(f[i][j + 1][k >> 1], f[i - 1][j][k]);
        upd(f[i][j][(k >> 1) | 2], f[i - 1][j][k]);
      }
  for (int i = 0; i <= n; i++) {
    for (int k = 0; k < 4; k++) upd(an[i], f[n][i][k]);
    an[i] = 1ll * an[i] * fact[n - i] % 1000000007;
  }
  for (int i = n - 1; ~i; i--)
    for (int j = i + 1; j <= n; j++)
      upd(an[i], -1ll * c[j][i] * an[j] % 1000000007);
  printf("%d\n", (an[K] % 1000000007 + 1000000007) % 1000000007);
  return 0;
}
