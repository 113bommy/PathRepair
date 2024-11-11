#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;
const int mod = 998244353;
const int maxn = 55;
int le[maxn], ri[maxn], lsh[maxn << 1], ls[maxn << 1], lsc, n;
int dp[maxn][maxn], ni[maxn];
int mi(int x, int y) {
  int ret = 1;
  while (y > 0) {
    if (y & 1) ret = 1ll * ret * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return ret;
}
void LSH(int lim) {
  sort(lsh + 1, lsh + lim + 1);
  ls[lsc = 1] = lsh[1];
  for (int i = 2; i <= lim; ++i)
    if (lsh[i] != lsh[i - 1]) ls[++lsc] = lsh[i];
}
int cal(int x, int y) {
  if (x + y - 1 >= mod) return 0;
  int fz = 1, fm = 1;
  for (int i = 1; i <= y; ++i) {
    fz = 1ll * fz * (x + y - i) % mod;
    fm = 1ll * fm * ni[i] % mod;
  }
  return 1ll * fz * fm % mod;
}
int main() {
  for (int i = 1; i < maxn; ++i) ni[i] = mi(i, mod - 2);
  scanf("%d", &n);
  for (int i = n; i >= 1; --i) {
    scanf("%d%d", &le[i], &ri[i]);
    ri[i]++;
    lsh[2 * i - 1] = le[i];
    lsh[2 * i] = ri[i];
  }
  LSH(n << 1);
  for (int i = 1; i <= n; ++i) {
    le[i] = lower_bound(ls + 1, ls + lsc + 1, le[i]) - ls;
    ri[i] = lower_bound(ls + 1, ls + lsc + 1, ri[i]) - ls;
  }
  int base = 1;
  for (int i = 1; i <= n; ++i)
    base = 1ll * base * (ls[ri[i]] - ls[le[i]]) % mod;
  for (int i = 0; i <= lsc; ++i) dp[0][i] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = le[i]; j < ri[i]; ++j)
      for (int k = i; k >= 1; --k) {
        if (j >= ri[k] || j < le[k]) break;
        int val = cal(ls[j + 1] - ls[j], i - k + 1);
        (dp[i][j] += 1ll * dp[k - 1][j - 1] * val % mod) %= mod;
      }
    for (int j = 1; j <= lsc; ++j) (dp[i][j] += dp[i][j - 1]) %= mod;
  }
  printf("%lld\n", 1ll * dp[n][ri[n] - 1] * mi(base, mod - 2) % mod);
  return 0;
}
