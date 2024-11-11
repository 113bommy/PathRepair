#include <bits/stdc++.h>
const long long N = 2e6 + 9, mod = 998244353;
typedef long long aN[N];
char s[N];
long long nxt[N], f[222][111][222];
long long readll() {
  long long x = 0, w = 1;
  int c = getchar();
  for (; c < '0' || c > '9'; c - '-' || (w = -w), c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar())
    ;
  return x * w;
}
int readchar(int l = '0', int r = 'z') {
  int c = getchar();
  for (; c < l || c > r; c = getchar())
    ;
  return c;
}
int add(long long& u, long long v) {
  u = (u + v) % mod;
  return 1;
}
int main() {
  long long m = readll() * 2, now;
  scanf("%s", s + 1);
  long long n = strlen(s + 1);
  nxt[1] = 0;
  for (register long long i = 2, j = 0; i < n; i++) {
    while (j && s[j + 1] != s[i]) j = nxt[j];
    nxt[i] = s[j + 1] != s[i] ? j : ++j;
  }
  f[0][0][0] = 1;
  for (register long long i = 0; i <= m - 1; i++)
    for (register long long j = 0; j <= m / 2; j++)
      for (register long long k = 0; k <= n; k++)
        if (f[i][j][k]) {
          now = k;
          while (now && ')' != s[now + 1]) now = nxt[now];
          j&& add(f[i + 1][j - 1][k == n ? n : now + (')' == s[now + 1])],
                  f[i][j][k]);
          now = k;
          while (now && '(' != s[now + 1]) now = nxt[now];
          add(f[i + 1][j + 1][k == n ? n : now + ('(' == s[now + 1])],
              f[i][j][k]);
        }
  printf("%lld\n", f[m][0][n]);
  return 0;
}
