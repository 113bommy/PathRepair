#include <bits/stdc++.h>
using namespace std;
long long d[1000234], b[1000234], c[1000234], ans[1000234], n, m, q, a, t, s;
bool f[1000234];
long long pow_(long long x, long long y, int mod) {
  if (y == 0) return 1;
  long long tmp = pow_(x, y / 2, mod);
  tmp = tmp * tmp % mod;
  if (y % 2) tmp = tmp * x % mod;
  return tmp;
}
long long C(long long x, long long y) {
  if (y > x) return 0;
  if (y == 0 || y == x) return 1;
  return (b[x] * c[y] % t) * c[x - y] % t;
}
long long lucas(long long x, long long y) {
  if (y == 0) return 1;
  return (C(x % t, y % t) * lucas(x / t, y / t) % t);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &q);
  memset(f, true, sizeof(f));
  for (int i = 2; i < 1000234; i++)
    if (f[i])
      for (int j = 2; i * j < 1000234; j++) f[i * j] = false;
  t = 1;
  s = a % q;
  while (s % q != 1) {
    t++;
    s = s * a % q;
  }
  b[0] = 1;
  c[0] = 1;
  for (int i = 1; i < t; i++) {
    b[i] = b[i - 1] * i % t;
    c[i] = pow_(b[i], t - 1, t);
  }
  ans[0] = 1;
  for (int i = 1; i <= m; i++) {
    long long tt = lucas(m, i);
    ans[i] = (ans[i - 1] + tt) % t;
  }
  for (int i = m + 1; i < n; i++) ans[i] = ans[i - 1];
  for (int i = 1; i <= n; i++) printf("%d ", pow_(a, ans[n - i], q));
  printf("\n");
  return 0;
}
