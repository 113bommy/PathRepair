#include <bits/stdc++.h>
using namespace std;
char c, a[1000004];
int n, i, j, s, hh, l, y[1000004];
long long p = 1000000007, sh[1000004], h[1000004], g[50];
int sri() {
  c = getchar();
  int x = 0;
  while (c < '0') c = getchar();
  while (c >= '0') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x;
}
inline int kk(int t, int l) {
  if (h[t + l] >= h[t - 1])
    return h[t + l] - h[t - 1];
  else
    return h[t + l] + p - h[t - 1];
}
void sc(long long x) {
  int l = 0;
  if (x == 0) g[l = 1] = 0;
  if (x < 0) putchar('-'), x = -x;
  while (x) g[++l] = x % 10, x /= 10;
  for (; l; l--) putchar(g[l] + '0');
}
int main() {
  n = sri();
  sh[0] = 1;
  c = getchar();
  while (c < 'a') c = getchar();
  for (i = 0; i < n; i++) a[i] = c, c = getchar(), sh[i + 1] = sh[i] * 131 % p;
  h[1] = a[0] - 'a' + 1;
  for (i = 2; i <= n; i++)
    h[i] = ((a[i - 1] - 'a' + 1) * sh[i - 1] + h[i - 1]) % p;
  hh = (n + 1) >> 1;
  l = 2 - (n & 1);
  s = -1;
  if (l > 1)
    if (a[hh] == a[hh + 1]) s = 1;
  y[hh] = s;
  for (i = hh - 1; i >= 1; i--) {
    l += 2;
    s += 2;
    if (s >= l) s = l - 1;
    if (!(s & 1)) s--;
    while (s > 0 &&
           kk(i, s - 1) * sh[n - i - s + 2 - i] % p != kk(n - i - s + 2, s - 1))
      s -= 2;
    y[i] = s;
  }
  for (i = 1; i <= hh; i++) sc(y[i]), putchar(' ');
  return 0;
}
