#include <bits/stdc++.h>
using namespace std;
long long gi() {
  char cc = getchar();
  long long cn = 0, flus = 1;
  while (cc < '0' || cc > '9') {
    if (cc == '-') flus = -flus;
    cc = getchar();
  }
  while (cc >= '0' && cc <= '9') cn = cn * 10 + cc - '0', cc = getchar();
  return cn * flus;
}
const long long N = 14;
const long long inf = (1ll << 61);
long long n, ans, c[N], a[N], d[N], f[1 << 14];
char s[N];
void write(long long x, long long l) {
  if (!l) return;
  write(x / 16, l - 1);
  long long z = x % 16;
  if (z <= 9)
    cout << z;
  else
    cout << (char)(z - 10 + 'a');
}
signed main() {
  cin >> s, n = strlen(s);
  long long sum = 0;
  for (long long i = (0); i < (n); ++i)
    c[i] = (s[i] >= 'a') ? (s[i] - 'a' + 10) : (s[i] - '0'), sum += c[i],
    a[n - i - 1] = c[i];
  if (sum % 15) {
    puts("NO");
    exit(0);
  }
  sum /= 15, ans = inf;
  long long limit = (1 << (n - 1)) - 1, m = 0;
  for (long long T = 0; T <= limit; ++T) {
    m = 0;
    for (long long i = (0); i < (n); ++i) m += ((T >> i) & 1);
    if (m != sum) continue;
    long long o = 0;
    for (long long i = (0); i < (n); ++i) d[i] = a[i];
    for (long long i = (0); i < (n); ++i)
      if ((T >> i) & 1) d[i] -= 16, ++d[i + 1];
    for (long long i = (0); i < (n); ++i) o += d[i];
    if (o != 0) continue;
    long long lim = (1 << n);
    for (long long S = (0); S < (lim); ++S) f[S] = inf;
    for (long long i = (0); i < (n); ++i) f[1 << i] = 0;
    for (long long S = (1); S < (lim); ++S) {
      long long su = 0;
      for (long long j = (0); j < (n); ++j)
        if ((S >> j) & 1) su += d[j];
      if (su > 15 || su < 0) continue;
      for (long long j = (0); j < (n); ++j)
        if ((S >> j) & 1) {
          su -= d[j];
          if (su >= 0 && su <= 15)
            f[S] = min(f[S ^ (1ll << j)] + su * (1ll << (4 * j)), f[S]);
          su += d[j];
        }
    }
    ans = min(ans, f[lim - 1]);
  }
  if (ans >= inf)
    puts("NO");
  else
    write(ans, n);
  return 0;
}
