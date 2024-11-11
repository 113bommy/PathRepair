#include <bits/stdc++.h>
using namespace std;
long long gcd(long long u, long long v) {
  while (v != 0) {
    long long r = u % v;
    u = v;
    v = r;
  }
  return u;
}
const int MOD = 1000000007;
const int MAXN = 1000000;
long long sum0[MAXN + 1];
long long sum1[MAXN + 1];
long long sum2[MAXN + 1];
int n;
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) {
    int h, w;
    scanf("%d%d", &h, &w);
    int lim = min(h, w);
    long long ret = (long long)(h + 1) * (w + 1) % MOD * sum0[lim] -
                    (h + w + 2) * sum1[lim] + sum2[lim];
    ret = ret % MOD;
    if (ret < 0) ret += MOD;
    printf("%d\n", (int)ret);
  }
}
int p[MAXN + 1];
int phi[MAXN + 1];
long long d[MAXN + 1];
long long a[MAXN + 1];
long long calcd(int L, int x, int d) {
  if (x == 1) return d * phi[L / d];
  long long ret = 0;
  int cp = p[x], cnt = 0;
  while (p[x] == cp) x /= cp, cnt++;
  for (int i = (0); i <= (cnt); ++i) {
    ret += calcd(L, x, d);
    d *= cp;
  }
  return ret;
}
void precalc() {
  for (int i = (0); i <= (MAXN); ++i) p[i] = i;
  p[0] = p[1] = -1;
  for (int i = (0); i <= (MAXN); ++i)
    if (p[i] == i)
      for (int j = i + i; j <= MAXN; j += i) p[j] = i;
  for (int i = (1); i <= (MAXN); ++i) {
    phi[i] = 1;
    int x = i;
    while (x != 1) {
      int cp = p[x], now = 1;
      while (p[x] == cp) x /= cp, now *= cp;
      phi[i] *= now - now / cp;
    }
  }
  for (int i = (1); i <= (MAXN); ++i) d[i] = calcd(i, i, 1) - i;
  for (long long i = 1; i <= MAXN; ++i)
    a[i] = (i * i + (i * i - 2 * i) * (i - 1) - i * i * (i - 1) +
            ((i - 1) * i * (2 * i - 1)) / 3 + 2 * d[i]) %
           MOD;
  sum0[0] = 0;
  for (int i = (1); i <= (MAXN); ++i) sum0[i] = (sum0[i - 1] + a[i]) % MOD;
  sum1[0] = 0;
  for (int i = (1); i <= (MAXN); ++i) sum1[i] = (sum1[i - 1] + a[i] * i) % MOD;
  sum2[0] = 0;
  for (int i = (1); i <= (MAXN); ++i)
    sum2[i] = (sum2[i - 1] + a[i] * i % MOD * i) % MOD;
}
int main() {
  precalc();
  run();
  return 0;
}
