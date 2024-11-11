#include <bits/stdc++.h>
using namespace std;
namespace zzc {
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const int maxn = 32;
const int maxm = 1000;
const long long mod = 7340033;
long long qt, n, m;
long long f[maxn + 5][maxm + 5], g[maxn + 5][maxm + 5];
void init() {
  for (register int i = 0; i <= maxn; i++) f[i][0] = g[i][0] = 1;
  for (register int i = 1; i <= maxn; i++) {
    for (register int j = maxm; j; j--)
      for (register int k = 0; k < j; k++)
        f[i][j] = (f[i][j] + g[i - 1][k] * g[i - 1][j - k - 1] % mod) % mod;
    for (register int j = maxm; j; j--)
      for (register int k = 0; k <= j; k++)
        g[i][j] = (g[i][j] + f[i][k] * f[i][j - k] % mod) % mod;
  }
}
void work() {
  init();
  qt = read();
  for (register int i = 1; i <= qt; i++) {
    n = read();
    m = read();
    int dep = 0;
    while ((n > 1) && (n & 1)) n >>= 1, dep++;
    printf("%lld\n", f[dep][m]);
  }
}
}  // namespace zzc
int main() {
  zzc::work();
  return 0;
}
