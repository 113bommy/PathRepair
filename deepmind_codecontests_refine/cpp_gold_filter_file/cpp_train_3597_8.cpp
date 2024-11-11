#include <bits/stdc++.h>
#pragma GCC optimize(2, "Ofast", "inline", "-fgcse", "-fgcse-lm", "-fipa-sra", \
                     "-ftree-pre", "-ftree-vrp", "-fpeephole2", "-ffast-math", \
                     "-fsched-spec", "unroll-loops", "-falign-jumps",          \
                     "-falign-loops", "-falign-labels", "-fdevirtualize",      \
                     "-fcaller-saves", "-fcrossjumping", "-fthread-jumps",     \
                     "-funroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
char BB[1 << 20], *SS = BB, *TT = BB;
inline long long read() {
  long long s = 0;
  char ch =
      (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 20, stdin), SS == TT)
           ? EOF
           : *SS++);
  while (!((ch >= '0') && (ch <= '9')))
    ch = (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 20, stdin), SS == TT)
              ? EOF
              : *SS++);
  while (((ch >= '0') && (ch <= '9')))
    s = (s << 3) + (s << 1) + (ch ^ 48),
    ch = (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 20, stdin), SS == TT)
              ? EOF
              : *SS++);
  return s;
}
const int mod = 1000000007;
inline long long che(long long a) { return a >= mod ? a - mod : a; }
inline long long ksm(long long a, long long b) {
  if (b < 0) return 0;
  long long res = 1;
  for (; b; b >>= 1ll, a = a * a % mod)
    if (b & 1ll) res = res * a % mod;
  return res;
}
const int maxn = 2000005;
const int mn = 1505;
inline long long inv(long long a) { return ksm(a, mod - 2); }
long long fac[maxn], inc[maxn], dd[maxn];
long long C(long long x, long long y) {
  return x <= y ? fac[y] * inc[x] % mod * inc[y - x] % mod : 0;
}
long long ss[2][mn][mn], sum1[mn], sum2[mn], sum3[mn];
int main() {
  long long n = read(), m = read(), a = read(), b = read(), k = read();
  long long ans = 1, anss = 0, an = 0;
  ans = a * inv(b) % mod;
  an = inv(1 - ans + mod);
  fac[0] = 1;
  for (long long i = 1; i <= 2 * k; ++i) fac[i] = fac[i - 1] * i % mod;
  inc[2 * k] = inv(fac[2 * k]);
  for (long long i = 2 * k - 1; i >= 0; --i)
    inc[i] = inc[i + 1] * (i + 1) % mod;
  for (long long i = 0; i <= k; ++i)
    dd[i] = ksm(1 - ans + mod, k - i) * C(i, k) % mod * ksm(ans, i) % mod;
  for (int j = 1; j <= m; ++j) ss[0][j][m] = 1;
  sum1[0] = dd[0];
  for (int i = 1; i <= m; ++i) sum1[i] = che(sum1[i - 1] + dd[i]);
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= 1; --j)
      sum2[j] = che(sum2[j + 1] + ss[(i ^ 1) & 1][j][m] * dd[m - j] % mod);
    for (int j = 1; j <= m; ++j)
      sum3[j] = che(sum3[j - 1] +
                    (mod - ss[(i ^ 1) & 1][j - 1][j - 1]) * dd[j - 1] % mod);
    for (int j = 1; j <= m; ++j) {
      ss[i & 1][j][m] = 0;
      ss[i & 1][j][m] =
          che(ss[i & 1][j][m] + che(mod + mod - ss[(i ^ 1) & 1][j - 1][j - 1]) *
                                    sum1[m - j] % mod);
      ss[i & 1][j][m] = che(ss[i & 1][j][m] + sum2[j]);
      ss[i & 1][j][m] = ss[i & 1][j][m] * dd[j - 1] % mod;
      ss[i & 1][j][m] = che(ss[i & 1][j][m] + ss[i & 1][j - 1][m]);
    }
    for (int l = 1; l < m; ++l) {
      ss[i & 1][l][l] = 0;
      ss[i & 1][l][l] = che(ss[i & 1][l][l] + sum3[l]);
      ss[i & 1][l][l] =
          che(ss[i & 1][l][l] + (ss[(i ^ 1) & 1][l][m]) * sum1[l - 1] % mod);
      ss[i & 1][l][l] = ss[i & 1][l][l] * dd[m - l] % mod;
      ss[i & 1][l][l] = che(ss[i & 1][l][l] + ss[i & 1][l - 1][l - 1]);
    }
  }
  printf("%lld\n", ss[n & 1][m][m]);
  return 0;
}
