#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = 5e4 + 5;
inline long long read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x;
}
long long n, m, mod, maxx, l[2000005], A[M], fac[M], f[5005][5005], g[2][5010];
int main() {
  scanf("%lld%lld%lld", &n, &m, &mod);
  fac[0] = A[0] = f[0][0] = 1;
  for (int i = 1; i <= n; ++i) l[i] = read(), maxx = max(maxx, l[i]);
  for (int i = 1; i <= maxx; ++i) A[i] = A[i - 1] * (m - i + 1) % mod;
  for (int i = 1; i <= maxx; ++i) fac[i] = fac[i - 1] * i % mod;
  for (int i = 1; i <= maxx; ++i)
    for (int j = 1; j <= i && j <= m; ++j)
      f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * (j - 1)) % mod;
  long long ans = 1, sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= l[i]; ++j) {
      long long tmp = (A[j] * ans - g[i & 1 ^ 1][j] * fac[j]) % mod;
      g[i & 1][j] = f[l[i]][j] * tmp % mod;
      sum += g[i & 1][j];
    }
    ans = (sum + mod) % mod;
    sum = 0;
    memset(g[i & 1 ^ 1], 0, sizeof(g[0]));
  }
  printf("%lld", ans);
}
