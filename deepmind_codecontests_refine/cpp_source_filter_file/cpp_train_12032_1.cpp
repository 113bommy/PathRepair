#include <bits/stdc++.h>
using namespace std;
long long C[201][201];
long long f[17][201], cnt[17];
inline long long calc(long long len) {
  memset(f, 0, sizeof(f));
  f[0][len] = 1;
  for (long long i = 1; i <= 16; i++)
    for (long long j = 0; j <= len; j++)
      if (f[i - 1][j])
        for (long long k = 0; k <= cnt[i] && k <= j; k++)
          f[i][j - k] += f[i - 1][j] * C[j][k];
  return f[16][0];
}
long long k, t;
signed main() {
  for (long long i = 0; i < 200; i++) C[i][0] = 1;
  for (long long i = 1; i <= 200; i++)
    for (long long j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  scanf("%lld%lld", &k, &t);
  for (long long i = 1; i <= 16; i++) cnt[i] = t;
  long long len = 1;
  for (;;) {
    long long t = calc(len) / 16 * 15;
    if (k <= t) break;
    k -= t;
    len++;
  }
  for (long long i = 1; i <= len; i++)
    for (long long j = 1; j <= 16; j++) {
      if (i == 1 && j == 1) continue;
      cnt[j]--;
      long long t = calc(len - i);
      if (t >= k) {
        if (j <= 11)
          putchar(j - 1 + '0');
        else
          putchar(j - 11 + 'a');
        break;
      }
      k -= t;
      cnt[j]++;
    }
  return 0;
}
