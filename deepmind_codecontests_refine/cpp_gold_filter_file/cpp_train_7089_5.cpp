#include <bits/stdc++.h>
namespace io {
int F() {
  int F = 1, n = 0;
  char ch;
  while ((ch = getchar()) != '-' && (ch < '0' || ch > '9'))
    ;
  ch == '-' ? F = 0 : n = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') n = n * 10 + ch - '0';
  return F ? n : -n;
}
long long G() {
  long long F = 1, n = 0;
  char ch;
  while ((ch = getchar()) != '-' && (ch < '0' || ch > '9'))
    ;
  ch == '-' ? F = 0 : n = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') n = n * 10 + ch - '0';
  return F ? n : -n;
}
}  // namespace io
long long siz[1111111];
int fa[1111111];
int cnt[1111111];
int f[1111111];
long long gcd(long long x, long long y) {
  long long r;
  while (r = x % y) x = y, y = r;
  return y;
}
int main() {
  int n = io::F();
  for (register int i = 1; i <= n; ++i) siz[i] = io::F();
  for (register int i = 2; i <= n; ++i) fa[i] = io::F();
  for (register int i = n; i > 1; --i) siz[fa[i]] += siz[i];
  for (register int i = 1; i <= n; ++i) {
    long long g = gcd(siz[i], siz[1]);
    if (siz[1] / g <= n) cnt[siz[1] / g]++;
  }
  for (register int i = n; i; --i)
    for (register int j = i + i; j <= n; j += i) cnt[j] += cnt[i];
  f[1] = 1;
  for (register int i = 1; i <= n; ++i)
    for (register int j = i + i; j <= n; j += i)
      if (cnt[j] == j) f[j] = (f[j] + f[i]) % 1000000007;
  int ans = 0;
  for (register int i = 1; i <= n; ++i) ans = (ans + f[i]) % 1000000007;
  printf("%d\n", ans);
  return 0;
}
