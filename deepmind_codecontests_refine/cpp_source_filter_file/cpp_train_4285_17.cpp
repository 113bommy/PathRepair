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
const int maxn = 105, mod = 1e9 + 7;
int n, m, k, a[maxn];
inline int fpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
struct mat {
  int a[maxn][maxn];
  mat() { memset(a, 0, sizeof a); }
  inline void set() {
    for (int i = 0; i < n; i++) a[i][i] = 1;
  }
  inline const int *operator[](const int &x) const { return a[x]; }
  inline int *operator[](const int &x) { return a[x]; }
  inline mat operator*(const mat &b) {
    mat ans;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
        for (int k = 0; k <= n; k++)
          ans[i][j] = (ans[i][j] + 1ll * a[i][k] * b[k][j] % mod) % mod;
    return ans;
  }
} now, pow;
inline mat fpow(mat a, int b) {
  mat ans;
  ans.set();
  for (; b; b >>= 1, a = a * a)
    if (b & 1) ans = ans * a;
  return ans;
}
inline void work() {
  m = read();
  k = read();
  for (int i = 1; i <= m; i++) n += (a[i] = read()) == 0;
  int t = 0;
  for (int i = 1; i <= n; i++) t += a[i] == 0;
  now[0][t] = 1;
  for (int i = 0; i <= n; i++) {
    if (i) pow[i - 1][i] = 1ll * (n - i + 1) * (n - i + 1) % mod;
    pow[i][i] =
        (1ll * i * (n - i) % mod + 1ll * (n - i) * (m - n - n + i) % mod) % mod;
    pow[i][i] = (pow[i][i] + 1ll * n * (n - 1) / 2 % mod) % mod;
    pow[i][i] = (pow[i][i] + 1ll * (m - n) * (m - n - 1) / 2 % mod) % mod;
    if (i != n) pow[i + 1][i] = 1ll * (i + 1) * (m - n - n + i + 1) % mod;
  }
  now = now * fpow(pow, k);
  int up = now[0][n], down = 0;
  for (int i = 0; i <= n; i++) down = (down + now[0][i]) % mod;
  printf("%lld\n", 1ll * up * fpow(down, mod - 2) % mod);
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
