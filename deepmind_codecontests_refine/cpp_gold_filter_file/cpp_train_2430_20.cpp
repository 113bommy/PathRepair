#include <bits/stdc++.h>
int phi(int x) {
  int i, ret = x;
  for (i = 2; i <= x / i; ++i)
    if (x % i == 0) {
      ret = ret / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  if (x != 1) ret = ret / x * (x - 1);
  return ret;
}
int mod_pow(long long x, int n, int mod) {
  long long s = 1;
  while (n) {
    if (n & 1) s = (s * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return (int)s;
}
char a[1000005], b[1000005];
int main() {
  int c, x, m, n, i, bn, t, an;
  bool flag = 1;
  scanf("%s %s %d", a, b, &c);
  x = 0;
  for (i = 0; a[i]; ++i) x = ((long long)x * 10 + a[i] - '0') % c;
  an = strlen(a);
  --a[an - 1];
  i = an - 1;
  while (a[i] < '0') {
    a[i] += 10;
    --a[i - 1];
    --i;
  }
  for (i = 0; a[i] == '0'; ++i)
    ;
  t = 0;
  for (; a[i]; ++i) t = ((long long)t * 10 + a[i] - '0') % c;
  m = phi(c);
  bn = strlen(b);
  if (bn < 9 || (bn == 9 && b[0] == '1')) {
    if (atoi(b) <= m) flag = 0;
  }
  --b[bn - 1];
  i = bn - 1;
  while (b[i] < '0') {
    b[i] += 10;
    --b[i - 1];
    --i;
  }
  for (i = 0; b[i] == '0'; ++i)
    ;
  n = 0;
  for (; b[i]; ++i) n = ((long long)n * 10 + b[i] - '0') % m;
  int ans;
  if (flag)
    ans = mod_pow(x, n + m, c);
  else
    ans = mod_pow(x, n, c);
  ans = ((long long)ans * t) % c;
  if (ans == 0) ans = c;
  printf("%d\n", ans);
  return 0;
}
