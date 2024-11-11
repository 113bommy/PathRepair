#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const int maxn = 5e6 + 10, maxm = 1e7 + 10, mod = 998244353;
int n, m, a[maxn], b[maxn], inv[maxm], f[maxm];
inline void work() {
  n = read();
  for (int i = 1; i <= n; i++) m += a[i] = read();
  inv[1] = 1;
  for (int i = 2; i <= m; i++)
    inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
  for (int g = 0, i = 1; i < m; i++)
    g = 1ll * i * (n - 1) % mod * inv[m - i] % mod * (g - 1 + mod) % mod,
    f[i + 1] = f[i] + g;
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + f[a[i]]) % mod;
  printf("%d\n", (ans - f[m] + mod) % mod);
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
