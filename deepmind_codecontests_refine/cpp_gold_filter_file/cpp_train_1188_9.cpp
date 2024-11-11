#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
int n, a[101000], p[101000];
long long f[101000], g[101000];
int F(int x, int y) {
  if (x < 0 || y < 0) return 0;
  return f[x + y] * g[x] % mod * g[y] % mod;
}
long long pow(long long x, int y) {
  long long t = 1;
  while (y) {
    if (y & 1) t = t * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return t;
}
inline bool cmp(int x, int y) { return x > y; }
int main() {
  f[0] = g[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    f[i] = f[i - 1] * i % mod;
    g[i] = g[i - 1] * pow((long long)i, mod - 2) % mod;
  }
  scanf("%d", &n);
  int m = n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i]) p[a[i]] = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (; a[n] == 0 && n; n--)
    ;
  if (!n) {
    long long ans = 0;
    for (int i = 1; i <= m; i++) ans = (ans + F(i - 1, m - i)) % mod;
    cout << ans << endl;
  } else {
    long long tr = 0, tl = 0;
    if (a[n] == 1)
      tr = 1;
    else {
      for (int i = p[a[n]] + 1; i <= min(m, p[a[n]] + a[n] - 1); i++)
        tr = (tr + F(i - p[a[n]] - 1, p[a[n]] + a[n] - i - 1)) % mod;
      for (int i = p[a[n]] - 1; i >= max(1, p[a[n]] - a[n] + 1); i--)
        tl = (tl + F(p[a[n]] - i - 1, i - p[a[n]] + a[n] - 1)) % mod;
    }
    for (int i = n - 1; i >= 1; i--) {
      long long ntl = 0, ntr = 0;
      if (p[a[i]] < p[a[i + 1]])
        if (p[a[i + 1]] - p[a[i]] <= a[i] - a[i + 1])
          ntr = (ntr + tr *
                           F(p[a[i + 1]] - p[a[i]] - 1,
                             a[i] - a[i + 1] - (p[a[i + 1]] - p[a[i]])) %
                           mod) %
                mod;
      if (p[a[i]] < p[a[i + 1]] - a[i + 1] + 1)
        if (p[a[i + 1]] - a[i + 1] + 1 - p[a[i]] <= a[i] - a[i + 1])
          ntr = (ntr + tl *
                           F((p[a[i + 1]] - a[i + 1] + 1) - p[a[i]] - 1,
                             a[i] - a[i + 1] -
                                 ((p[a[i + 1]] - a[i + 1] + 1) - p[a[i]])) %
                           mod) %
                mod;
      if (p[a[i]] > p[a[i + 1]])
        if (p[a[i]] - p[a[i + 1]] <= a[i] - a[i + 1])
          ntl = (ntl + tl *
                           F(p[a[i]] - p[a[i + 1]] - 1,
                             a[i] - a[i + 1] - (p[a[i]] - p[a[i + 1]])) %
                           mod) %
                mod;
      if (p[a[i]] > p[a[i + 1]] + a[i + 1] - 1)
        if (p[a[i]] - (p[a[i + 1]] + a[i + 1] - 1) <= a[i] - a[i + 1])
          ntl = (ntl + tr *
                           F(p[a[i]] - (p[a[i + 1]] + a[i + 1] - 1) - 1,
                             a[i] - a[i + 1] -
                                 (p[a[i]] - (p[a[i + 1]] + a[i + 1] - 1))) %
                           mod) %
                mod;
      tr = ntr;
      tl = ntl;
    }
    cout << (tl * F(p[a[1]] - a[1], m - p[a[1]]) % mod +
             tr * F(p[a[1]] - 1, m - (p[a[1]] + a[1] - 1)) % mod) %
                mod
         << endl;
  }
  return 0;
}
