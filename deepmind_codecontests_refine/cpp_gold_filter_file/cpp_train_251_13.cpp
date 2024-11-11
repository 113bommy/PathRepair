#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, m, x;
long long ans, f[2000001], g[2000001];
inline long long read() {
  long long x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x;
}
long long qpow(long long x, long long y) {
  long long sum = 1;
  while (y) {
    if (y & 1) sum = sum * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return sum;
}
void FWT_And(int n, int jdg, long long *f) {
  for (long long i = 2, j = 1; i <= n; i <<= 1, j <<= 1)
    for (long long k = 0; k < n; k += i)
      for (long long l = 0; l < j; l++)
        f[k + l] = (f[k + l] + f[j + k + l] * jdg % mod + mod) % mod;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    x = read();
    f[x]++;
    m = max(m, x);
  }
  n = 1;
  while (n <= m) n <<= 1;
  FWT_And(n, 1, f);
  g[0] = 1;
  for (int i = 0; i < n; i++) {
    if (!g[i]) g[i] = -g[i ^ (i & (-i))];
    ans = (ans + g[i] * (qpow(2, f[i]) - 1) % mod + mod) % mod;
  }
  printf("%lld", ans);
  return 0;
}
