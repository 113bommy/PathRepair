#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 3e5 + 1;
long long C[maxn], e[maxn], s[maxn];
int t[maxn], cnt[maxn][20];
long long qpow(long long a, int b) {
  long long ret = 1LL;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
long long inv(long long x) { return qpow(x, mod - 2); }
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", t + i);
  C[0] = 1LL;
  for (int i = 1; i < n; i++) C[i] = C[i - 1] * (n - i) % mod * inv(i) % mod;
  for (int i = 0; i < n - 1; i++) e[1] = (e[1] - C[i] + mod) % mod;
  for (int i = 2; i <= n; i++)
    e[i] = (e[i - 1] + C[n - i] + C[n - i + 1]) % mod;
  for (int i = 1; i <= n; i++) s[i] = (s[i - 1] + e[i]) % mod;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j * j <= t[i]; j++) {
      int tmp = 0;
      while (t[i] % j == 0) t[i] /= j, tmp++;
      if (tmp) cnt[j][tmp]++;
    }
    if (t[i] > 1) cnt[t[i]][1]++;
  }
  long long ans = 0LL;
  for (int i = 1; i < maxn; i++) {
    cnt[i][0] = n;
    for (int j = 1; j < 20; j++) cnt[i][0] -= cnt[i][j];
    int cur = 0;
    for (int j = 0; j < 20; j++)
      ans = (ans + (s[cur + cnt[i][j]] - s[cur] + mod) * j % mod) % mod,
      cur += cnt[i][j];
  }
  printf("%I64d\n", ans);
  return 0;
}
