#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int n, m, i, j, f[3005][3005], g[3005][3005], mod = 998244353, a[100005],
                                              w[100005], s1, s2, s3;
int pw(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) z = 1ll * z * x % mod;
  return z;
}
int main() {
  read(n);
  read(m);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) read(a[i]);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) read(w[i]);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    if (a[i])
      s1 += w[i];
    else
      s2 += w[i];
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) s3 += w[i];
  for ((i) = (m); (i) >= (0); (i)--) {
    f[i][m - i] = g[i][m - i] = 1;
    for ((j) = (min(s2, m - i - 1)); (j) >= (0); (j)--) {
      f[i][j] =
          (1ll * f[i + 1][j] * (s1 + i + 1) + 1ll * f[i][j + 1] * (s2 - j)) %
          mod * pw(s3 + i - j, mod - 2) % mod;
      g[i][j] =
          (1ll * g[i + 1][j] * (s1 + i) + 1ll * g[i][j + 1] * (s2 - j - 1)) %
          mod * pw(s3 + i - j, mod - 2) % mod;
    }
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    if (a[i]) {
      printf("%d\n", 1ll * f[0][0] * w[i] % mod);
    } else {
      printf("%d\n", 1ll * g[0][0] * w[i] % mod);
    }
  }
  return 0;
}
