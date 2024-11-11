#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 1e1;
const int mod = 1e9 + 7;
vector<int> in[maxn];
int f[maxn][maxn], fac[maxn], inv[maxn], n, siz, sum;
inline int mul(const int &x, const int &y) {
  return (long long int)x * y % mod;
}
inline void adde(int &dst, const int &x) {
  if ((dst += x) >= mod) dst -= mod;
}
inline void mule(int &dst, const int &x) { dst = (long long int)dst * x % mod; }
inline int c(int n, int m) {
  if (n < m || m < 0) return 0;
  return mul(fac[n], mul(inv[m], inv[n - m]));
}
inline int fastpow(int base, int tim) {
  int ret = 1;
  while (tim) {
    if (tim & 1) mule(ret, base);
    if (tim >>= 1) mule(base, base);
  }
  return ret;
}
inline long long int lli_sqrt(const long long int &x) {
  int l = 0, r = 0x3f3f3f3f, mid;
  while (r > l + 1) {
    mid = (l + r) >> 1;
    if ((long long int)mid * mid <= x)
      l = mid;
    else
      r = mid;
  }
  return l;
}
inline bool issquare(const long long int &x) {
  const long long int sq = lli_sqrt(x);
  return sq * sq == x;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    for (int j = 1; j <= siz; j++)
      if (issquare((long long int)x * *in[j].begin())) {
        in[j].push_back(x), x = -1;
        break;
      }
    if (~x) in[++siz].push_back(x);
  }
  *fac = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  inv[n] = fastpow(fac[n], mod - 2);
  for (int i = n; i; i--) inv[i - 1] = mul(inv[i], i);
  f[0][0] = 1;
  for (int i = 1; i <= siz; i++) {
    const int siz = in[i].size();
    for (int k = 1; k <= siz; k++)
      for (int j = 0; j <= sum; j++)
        for (int p = 0; p <= j; p++)
          adde(f[i][j + siz - k - p],
               mul(f[i - 1][j], mul(mul(fac[siz], c(siz - 1, k - 1)),
                                    mul(c(j, p), c(sum + 1 - j, k - p)))));
    sum += in[i].size();
  }
  printf("%d\n", f[siz][0]);
  return 0;
}
