#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 9;
int n, m, z, x, y, mai, maj;
long long f[4005][4005], c[4005][4005], jc[4005], ans;
int main() {
  scanf("%d%d%d", &n, &x, &y);
  c[0][0] = 1;
  for (int i = 1; i <= 4000; ++i)
    for (int j = 0; j <= i; ++j) {
      if (j != 0)
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
      else
        c[i][j] = c[i - 1][j];
    }
  jc[0] = 1;
  for (int i = 1; i <= 4000; ++i) jc[i] = (jc[i - 1] * i) % mod;
  mai = min(x - 1, n - 2);
  ans = 0;
  for (int i = 1; i <= mai; ++i) {
    maj = min(x - 1, n - i - 1);
    for (int j = 1; j <= maj; ++j)
      ans = (ans + c[y - 1][n - i - j - 1] * c[x - 1][i + j - 1]) % mod;
  }
  ans = ans * jc[x] % mod * jc[y] % mod;
  printf("%I64d", ans);
}
