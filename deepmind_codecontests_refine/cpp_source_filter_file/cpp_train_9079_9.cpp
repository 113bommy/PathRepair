#include <bits/stdc++.h>
using namespace std;
long long lowbit(long long x) { return x & -x; }
const long long N = 500000, M = 1000000;
long long n, m;
char a[N + 5], b[N + 5], c[M + 5];
long long lcP1[N + 1], lcP2[N + 1];
long long s;
char d[N + M + 5];
void con(char x[], char y[]) {
  s = 0;
  for (long long i = 1; i <= m; i++) d[++s] = x[i];
  d[++s] = '!';
  for (long long i = 1; i <= n; i++) d[++s] = y[i];
}
long long z[N + M + 1];
void z_init() {
  z[1] = s;
  long long zl = 0, zr = 0;
  for (long long i = 2; i <= s; i++)
    if (zr < i) {
      z[i] = 0;
      while (i + z[i] <= s && d[i + z[i]] == d[1 + z[i]]) z[i]++;
      if (z[i]) zl = i, zr = i + z[i] - 1;
    } else if (i + z[i - zl + 1] <= zr)
      z[i] = z[i - zl + 1];
    else {
      z[i] = zr - i + 1;
      while (i + z[i] <= s && d[i + z[i]] == d[1 + z[i]]) z[i]++;
      zl = i;
      zr = i + z[i] - 1;
    }
}
struct bitree {
  long long sum[M + 1], cnt[M + 1];
  void add(long long v) {
    long long x = v;
    while (x <= n) sum[x] += v, cnt[x]++, x += lowbit(x);
  }
  void del(long long v) {
    long long x = v;
    while (x <= n) sum[x] -= v, cnt[x]--, x += lowbit(x);
  }
  long long Sum(long long x) {
    long long res = 0;
    while (x) res += sum[x], x -= lowbit(x);
    return res;
  }
  long long Cnt(long long x) {
    long long res = 0;
    while (x) res += cnt[x], x -= lowbit(x);
    return res;
  }
} bit;
signed main() {
  scanf("%lld%lld%s%s%s", &n, &m, a + 1, b + 1, c + 1);
  con(c, a);
  z_init();
  for (long long i = 1; i <= n; i++) lcP1[i] = z[m + 1 + i];
  reverse(b + 1, b + n + 1);
  reverse(c + 1, c + m + 1);
  con(c, b);
  z_init();
  for (long long i = 1; i <= n; i++) lcP2[i] = z[m + 1 + (n - i + 1)];
  long long ans = 0;
  for (long long i = 1; i <= min(n, m - 1); i++) bit.add(max(1ll, m - lcP2[i]));
  for (long long i = 1; i <= n; i++) {
    if (i > 1)
      bit.del(max(1ll, m - lcP2[i - 1])),
          i + m - 2 <= n && (bit.add(max(1ll, m - lcP2[i + m - 2])), 0);
    ans += (min(lcP1[i], m - 1) + 1) * bit.Cnt(min(lcP1[i], m - 1) + 1) -
           bit.Sum(min(lcP1[i], m - 1) + 1);
  }
  cout << ans;
  return 0;
}
