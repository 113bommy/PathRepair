#include <bits/stdc++.h>
using namespace std;
unsigned int dp[23333][133], n, p, q, as, f[133][133];
struct mat {
  unsigned int s[133][133];
  mat() {
    for (unsigned int i = 0; i <= p; i++)
      for (unsigned int j = 0; j <= p; j++) s[i][j] = 0;
  }
} v[133], a;
mat mul(mat a, mat b) {
  mat c;
  for (unsigned int i = 0; i <= p; i++)
    for (unsigned int k = 0; k <= p; k++)
      if (a.s[i][k])
        for (unsigned int j = 0; j <= p; j++)
          c.s[i][j] = (c.s[i][j] + 1ull * a.s[i][k] * b.s[k][j]) & 4294967295ll;
  return c;
}
mat pw(mat a, unsigned int b) {
  mat as;
  for (unsigned int i = 0; i <= p; i++) as.s[i][i] = 1;
  while (b) {
    if (b & 1) as = mul(as, a);
    a = mul(a, a);
    b >>= 1;
  }
  return as;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  unsigned int g = exgcd(b, a % b, y, x);
  y = y - a / b * x;
  return g;
}
unsigned int getinv(unsigned int s) {
  long long x, y;
  exgcd(s, 1ull << 32, x, y);
  return (x + (1ull << 32)) & 4294967295ll;
}
unsigned int C(unsigned int i, unsigned int j) {
  unsigned int st1 = 1, st2 = 0;
  for (unsigned int k = 1; k <= j; k++) {
    unsigned int l = i - k + 1, r = k;
    while (~l & 1) l >>= 1, st2++;
    while (~r & 1) r >>= 1, st2--;
    st1 = (1ull * st1 * l) & 4294967295ll;
    st1 = (1ull * st1 * getinv(r)) & 4294967295ll;
  }
  st1 <<= st2;
  return st1 & 4294967295ll;
}
signed main() {
  scanf("%u%u%u", &n, &p, &q);
  for (unsigned int i = 0; i <= p; i++) dp[0][i] = 1;
  if (p >= n) p = n - 1;
  for (unsigned int j = 0; j <= p; j++)
    for (unsigned int k = 0; k <= j; k++) f[j][k] = C(n - (p - j), j - k);
  for (unsigned int i = 1; i <= q && i <= 16000; i++)
    for (unsigned int j = 0; j <= p; j++)
      for (unsigned int k = 0; k <= j; k++) dp[i][j] += dp[i - 1][k] * f[j][k];
  for (unsigned int j = 0; j <= p; j++)
    for (unsigned int k = 0; k <= j; k++) a.s[j][k] = f[j][k];
  a = pw(a, 16000);
  for (unsigned int j = 0; j <= p; j++) v[0].s[j][j] = 1;
  for (unsigned int i = 1; i <= 130; i++) v[i] = mul(v[i - 1], a);
  for (unsigned int i = 1; i <= q; i++) {
    unsigned int as1 = 0;
    unsigned int st1 = i % 16000, st2 = i / 16000;
    for (unsigned int j = 0; j <= p; j++)
      as1 += 1ull * v[st2].s[p][j] * dp[st1][j];
    as ^= 1ull * i * as1;
  }
  printf("%u\n", as);
}
