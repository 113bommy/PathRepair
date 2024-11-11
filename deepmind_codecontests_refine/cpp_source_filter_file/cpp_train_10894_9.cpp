#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
const long long mod = 1e9 + 7;
long long f[N][N];
long long n, k, inv, mul, ans;
inline long long Pow(long long a, long long b, long long mod) {
  long long ret(1);
  for (; b; b >>= 1, (a *= a) %= mod)
    if (b & 1) (ret *= a) %= mod;
  return ret;
}
int main() {
  scanf("%lld%lld", &n, &k);
  f[0][0] = 1;
  for (int i(0); i <= (k - 1); ++i) {
    for (int j(0); j <= (i); ++j) {
      f[i + 1][j] += f[i][i] * j;
      f[i + 1][j] %= mod;
      f[i + 1][j + 1] += f[i][j] * (n - j);
      f[i + 1][j + 1] %= mod;
    }
  }
  ans = 0;
  inv = Pow(2, mod - 2, mod);
  mul = Pow(2, n, mod);
  for (int j(0); j <= (k); ++j) {
    ans += f[k][j] * mul;
    ans %= mod;
    mul *= inv;
    mul %= mod;
  }
  printf("%lld\n", ans);
  return 0;
}
