#include <bits/stdc++.h>
using namespace std;
const int maxn = 600010;
const int mod = 1000000007;
char buf[25];
char a[maxn], b[maxn];
int c[maxn], p[maxn], inv[maxn], u[maxn], prime[maxn];
bool bol[maxn];
int n, m, len, sum, ans, tot;
int wa, wb, ta, tb;
int read() {
  int x = 0, f = 0;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = 1;
  } while (ch < '0' || ch > '9');
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int cnt = 0;
  while (x) {
    buf[++cnt] = '0' + x % 10;
    x /= 10;
  }
  for (int i = cnt; i >= 1; --i) putchar(buf[i]);
}
int ksm(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = 1ll * ans * x % mod;
    x = 1ll * x * x % mod;
  }
  return ans;
}
int gcd(int x, int y) {
  int z = x % y;
  while (z) {
    x = y;
    y = z;
    z = x % y;
  }
  return y;
}
int C(int x, int y) {
  if (x < 0 || y < 0 || x > y) return 0;
  return 1ll * c[y] * inv[x] % mod * inv[y - x] % mod;
}
int solve(int x, int y) {
  if (x == 0 && y == 0) {
    return tot;
  } else if (1ll * x * y >= 0)
    return 0;
  else {
    x = abs(x);
    y = abs(y);
    if (x == y)
      return p[len + 1] - 2;
    else
      return p[len / (max(x, y) / gcd(x, y)) + 1] - 2;
  }
}
void perpare() {
  int R = max(n + m, len) + 1;
  c[0] = 1;
  for (int i = 1; i <= R; ++i) c[i] = 1ll * c[i - 1] * i % mod;
  for (int i = 0; i <= R; ++i) inv[i] = ksm(c[i], mod - 2);
  p[0] = 1;
  for (int i = 1; i <= R; ++i) p[i] = 1ll * p[i - 1] * 2 % mod;
  for (int i = 1; i <= R; ++i) bol[i] = true;
  u[1] = 1;
  bol[1] = false;
  int cnt = 0;
  for (int i = 2; i <= R; ++i) {
    if (bol[i]) {
      u[i] = mod - 1;
      prime[++cnt] = i;
    }
    for (int j = 1; j <= cnt; ++j) {
      if (R / prime[j] < i) break;
      int x = prime[j] * i;
      bol[x] = false;
      if (i % prime[j] == 0) {
        u[x] = 0;
        break;
      }
      u[x] = 1ll * u[prime[j]] * u[i] % mod;
    }
  }
}
void dp() {
  sum = 1;
  for (int i = 1; i <= n; ++i)
    if (a[i] == '?' && b[i] == '?')
      sum = 1ll * sum * 2 % mod;
    else if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
      sum = 0;
      break;
    }
}
int main() {
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  len = read();
  n = strlen(a + 1);
  m = strlen(b + 1);
  for (int i = 1; i <= n; ++i)
    if (a[i] == '?')
      ++wa;
    else if (a[i] == 'A')
      ++ta;
    else if (a[i] == 'B')
      ++tb;
  for (int i = 1; i <= m; ++i)
    if (b[i] == '?')
      ++wb;
    else if (b[i] == 'A')
      --ta;
    else if (b[i] == 'B')
      --tb;
  perpare();
  if (n == m) dp();
  for (int i = 1; i <= len; ++i) {
    int tmp = 0;
    for (int j = 1; j <= len / i; ++j)
      tmp = (tmp + 1ll * u[j] * (len / (i * j)) % mod * (len / (i * j))) % mod;
    tot = (tot + 1ll * p[i] * tmp) % mod;
  }
  ans = 1ll * sum * (p[len + 1] - 2) % mod * (p[len + 1] - 2) % mod;
  for (int i = -wb; i <= wa; ++i) {
    if (ta + i == 0 && tb + wa - wb - i == 0)
      ans = (ans + 1ll * solve(ta + i, tb + wa - wb - i) *
                       (C(wb + i, wa + wb) - sum + mod)) %
            mod;
    else
      ans = (ans + 1ll * solve(ta + i, tb + wa - wb - i) * C(wb + i, wa + wb)) %
            mod;
  }
  write(ans);
  return 0;
}
