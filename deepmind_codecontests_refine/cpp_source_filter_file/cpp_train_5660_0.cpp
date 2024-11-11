#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &a) {
  static char c;
  static int fh;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    fh = -1, a = 0;
  else
    fh = 1, a = c - '0';
  while ((c = getchar()) <= '9' && c >= '0') a = (a << 3) + (a << 1) + c - '0';
  a = a * fh;
}
template <class T>
void write(T a) {
  if (a == 0)
    putchar('0');
  else {
    if (a < 0) putchar('-'), a = -a;
    static char c[30];
    static int c0;
    c0 = 0;
    while (a) c[++c0] = a % 10 + '0', a /= 10;
    while (c0) putchar(c[c0--]);
  }
}
long long n, m, k, c[105][105] = {{0}}, f[105][10005] = {{0}};
long long fastmi(long long a, long long kk) {
  long long ret = 1;
  while (kk) {
    if (kk & 1) (ret *= a) %= 1000000007;
    (a *= a) %= 1000000007;
    kk >>= 1;
  }
  return ret;
}
int main() {
  read(n), read(m), read(k);
  c[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 1000000007;
  }
  f[0][0] = 1;
  long long ans;
  for (int i = 1; i <= n; i++)
    for (int l = 0; l <= n; l++) {
      ans = fastmi(c[n][l], m / n + (m / n >= i)) % 1000000007;
      for (int j = l; j <= k; j++)
        (f[i][j] += f[i - 1][j - l] * ans) %= 1000000007;
    }
  write(f[n][k]);
  return 0;
}
