#include <bits/stdc++.h>
char _1[65536], _2[65536], *_3 = _1 + 65536, *_4 = _2;
inline char __getchar() {
  if (_3 == _1 + 65536) fread(_1, 1, 65536, stdin), _3 = _1;
  return *_3++;
}
inline void _putchar(char c) {
  if (_4 == _2 + 65536) fwrite(_2, 1, 65536, stdout), _4 = _2;
  *_4++ = c;
}
int _5[65];
inline void putint(int x) {
  if (x == 0) {
    _putchar('0');
    return;
  }
  register int _6;
  for (_6 = 0; x; x /= 10) _5[++_6] = x % 10;
  while (_6) _putchar(_5[_6--] ^ 48);
}
inline void flush() { fwrite(_2, 1, _4 - _2, stdout); }
inline void add(int &x, int y) {
  x += y;
  if (x >= 1e9 + 7) x -= 1e9 + 7;
}
char a[2][2005], s[2005];
int n = 0, m = 0, f[2][2005][2005];
long long seed[2005];
inline int gline(char *b) {
  char c = __getchar();
  int len = 0;
  for (; !(c >= 'a' && c <= 'z'); c = __getchar())
    ;
  for (; c >= 'a' && c <= 'z'; b[++len] = c, c = __getchar())
    ;
  b[++len] = 0;
  return len - 1;
}
inline void init() {
  seed[0] = 1;
  for (int i = 1; i <= 2005; i++) seed[i] = seed[i - 1] * 31 % 987654321;
}
inline void reverse(char *str, int len) {
  if (!str) return;
  for (register int i = 0; i < (len >> 1); i++) {
    char temp = *(str + i);
    *(str + i) = *(str + len - 1 - i);
    *(str + len - 1 - i) = temp;
  }
}
struct hash {
  long long h[2005];
  inline void make(int n, char *b) {
    h[0] = 0;
    for (int i = 1; i <= n; i++)
      h[i] = (h[i - 1] * 31 + b[i] - 'a') % 987654321;
  }
  inline void make_r(int n, char *b) {
    h[0] = 0;
    for (int i = 1; i <= n; i++)
      h[i] = (h[i - 1] * 31 + b[n + 1 - i] - 'a') % 987654321;
  }
  inline long long cut(int l, int r) {
    return (h[r] + 987654321 - h[l - 1] * seed[r - l + 1] % 987654321) %
           987654321;
  }
} pre[2], suf[2], ss;
inline void __input() {
  n = gline(a[0]);
  pre[0].make(n, a[0]);
  suf[0].make_r(n, a[0]);
  n = gline(a[1]);
  pre[1].make(n, a[1]);
  suf[1].make_r(n, a[1]);
  m = gline(s);
  ss.make(m, s);
}
inline int solve(int flag) {
  int ret = 0;
  memset(f, 0, sizeof(f));
  for (int j = 1; j <= n; j++) {
    f[0][j][0] = f[1][j][0] = 1;
    for (int i = 0; i < 2; i++)
      for (int k = 2; k <= (((n - j + 1) < (m / 2)) ? (n - j + 1) : (m / 2));
           k++)
        if (ss.cut(m - 2 * k + 1, m - k) == pre[i].cut(j, j + k - 1) &&
            ss.cut(m - k + 1, m) ==
                suf[i ^ 1].cut(n - (j + k - 1) + 1, n - j + 1))
          if (2 * k != m || flag) add(ret, f[i][j][m - 2 * k]);
    for (int i = 0; i < 2; i++)
      for (int k = 2; k <= (((j) < (m / 2)) ? (j) : (m / 2)); k++)
        if (ss.cut(k + 1, 2 * k) == pre[i].cut(j - k + 1, j) &&
            ss.cut(1, k) == suf[i ^ 1].cut(n - j + 1, n - (j - k + 1) + 1))
          if (2 * k != m || flag) add(f[i][j + 1][2 * k], 1);
    for (int i = 0; i < 2; i++)
      for (int k = 0; k < m; k++)
        if (a[i][j] == s[k + 1]) {
          add(f[i][j + 1][k + 1], f[i][j][k]);
          if (k + 2 <= m && a[i ^ 1][j] == s[k + 2])
            add(f[i ^ 1][j + 1][k + 2], f[i][j][k]);
        }
    for (int i = 0; i < 2; i++) add(ret, f[i][j + 1][m]);
  }
  return ret;
}
int main() {
  init();
  __input();
  int ans = 0;
  add(ans, solve(1));
  if (m > 1) {
    reverse(s + 1, m);
    ss.make(m, s);
    add(ans, solve(0));
    if (m == 2)
      for (int j = 1; j <= n; j++)
        for (int i = 0; i < 2; i++)
          if (a[i][j] == s[1] && a[i ^ 1][j] == s[2]) add(ans, 1e9 + 7 - 1);
  }
  putint(ans);
  flush();
  return 0;
}
