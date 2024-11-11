#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const long long mod = 1e9 + 7;
long long c[N];
long long f[N][N][N], val[N];
int n, m;
char s[N];
void up(long long &a, long long b) {
  a = a + b;
  a %= mod;
}
inline long long Pow(long long a, long long b, long long mod) {
  long long ret(1);
  for (; b; b >>= 1, (a *= a) %= mod)
    if (b & 1) (ret *= a) %= mod;
  return ret;
}
int main() {
  scanf("%d%d%s", &n, &m, s + 1);
  for (int i(1); i <= (n); ++i) f[s[i] - '0'][i][i] = 1;
  c[0] = c[1] = 1;
  for (int i(2); i <= (m); ++i) {
    c[i] = c[i - 1] + c[i - 2];
    c[i] %= (mod - 1);
  }
  for (int i(0); i <= (m); ++i) val[i] = Pow(2, c[i], mod) - 1;
  for (int l(2); l <= (m); ++l) {
    for (int i(n); i >= (1); --i) {
      for (int j(i); j <= (n); ++j) {
        f[l][i][j] = (f[l - 1][i][j] + f[l - 2][i][j]) % mod;
        for (int k(i); k <= (j - 1); ++k) {
          up(f[l][i][j], f[l - 1][i][k] * f[l - 2][k + 1][j] % mod);
        }
        if (i == 1) up(f[l][i][j], val[l - 1] * f[l - 2][i][j] % mod);
        if (j == n) up(f[l][i][j], val[l - 2] * f[l - 1][i][j] % mod);
      }
    }
  }
  printf("%lld\n", f[m][1][n]);
  return 0;
}
