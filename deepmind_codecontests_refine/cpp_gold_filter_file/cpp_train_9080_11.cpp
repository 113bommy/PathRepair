#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0;
  register bool f = 0;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return f ? -x : x;
}
char cr[200];
long long tt;
inline void print(register long long x, register char k = '\n') {
  if (!x) putchar('0');
  if (x < 0) putchar('-'), x = -x;
  while (x) cr[++tt] = x % 10 + '0', x /= 10;
  while (tt) putchar(cr[tt--]);
  putchar(k);
}
const long long maxn = 3010;
const long long p = 998244353;
char a[maxn], b[maxn];
long long n, m, f[maxn][maxn], ans;
void dp() {
  if (m == 1) ans = (ans + f[1][1]) % p;
  for (long long i = 2; i <= n; ++i) {
    for (long long ff = 1, gg = i - 1; gg <= n; ff++, gg++) {
      if (ff && (ff - 1 <= m ? (a[i] == b[ff - 1]) : 1)) {
        f[ff - 1][gg] = (f[ff - 1][gg] + f[ff][gg]) % p;
      }
      if (gg < n && (gg + 1 <= m ? (a[i] == b[gg + 1]) : 1)) {
        f[ff][gg + 1] = (f[ff][gg + 1] + f[ff][gg]) % p;
      }
    }
  }
}
void out() {
  for (long long i = 2; i <= n; i++)
    if (m <= i) {
      ans += f[1][i];
      ans %= p;
    }
  print((ans + ans) % p);
}
void init() {
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  for (long long i = 1; i <= n; ++i) {
    f[i][i] = (i <= m ? (a[1] == b[i]) : 1);
  }
}
signed main() {
  init();
  dp();
  out();
  return 0;
}
