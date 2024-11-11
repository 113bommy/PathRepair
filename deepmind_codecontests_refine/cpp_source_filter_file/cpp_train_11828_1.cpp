#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
long long f[30][300010], ans, fac[300010], inv[300010];
int N, n, k, MO, s, p[1000010], a[55], S[1000010];
long long pw(long long x, int y) {
  long long t = 1;
  for (; y; y >>= 1) {
    if (y & 1) t = t * x % MO;
    x = x * x % MO;
  }
  return t;
}
long long P(int x, int y) { return fac[x] * inv[x - y] % MO; }
int main() {
  scanf("%d%d%d", &n, &k, &MO);
  if (n & 1) return cout << pw(k, n) << endl, 0;
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MO;
  inv[n] = pw(fac[n], MO - 2);
  for (int i = n - 1; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % MO;
  int t = n;
  for (int i = 0; i <= 20; ++i) {
    if (t & 1) a[s++] = 1 << i;
    t >>= 1;
  }
  N = 1 << s;
  for (int i = 0; i <= N - 1; ++i)
    for (int j = 0; j <= s - 1; ++j)
      if ((i >> j) & 1) S[i] += a[j];
  for (int i = 0; i <= N - 1; ++i) {
    int t = -1;
    for (int j = 0; j <= 20; ++j)
      if ((i >> j) & 1) t = j;
    p[i] = (1 << (t + 1)) + i;
  }
  f[0][0] = 1;
  for (int i = 0; i <= k - 1; ++i)
    for (int j = 0; j <= N - 1; ++j)
      if (f[i][j]) {
        for (int k = j + p[j]; k < N; k = (k + 1) | j)
          (f[i + 1][k] += f[i][j] * inv[S[k ^ j]]) %= MO;
      }
  for (int i = 0; i <= k; ++i) (ans += f[i][N - 1] * P(k, i)) %= MO;
  ans = ans * fac[n] % MO;
  ans = (pw(k, n) - ans + MO) % MO;
  cout << ans << endl;
  return 0;
}
