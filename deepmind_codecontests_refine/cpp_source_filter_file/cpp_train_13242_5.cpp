#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void read(int &a) {
  a = 0;
  int d = 1;
  char ch;
  while (ch = getchar(), ch > '9' || ch < '0')
    if (ch == '-') d = -1;
  a = ch ^ 48;
  while (ch = getchar(), ch >= '0' && ch <= '9')
    a = (a << 3) + (a << 1) + (ch ^ 48);
  a *= d;
}
long long f[2005][2005];
int p[2005];
char a[2005];
int quickmod(int x, int y) {
  int res = 1, base = x;
  while (y) {
    if (y & 1) res = 1ll * res * base % mod;
    base = base * base % mod;
    y >>= 1;
  }
  return res;
}
int main() {
  scanf("%s", a);
  int len = strlen(a);
  for (register int i = 0; i < len; i++)
    p[i + 1] = p[i], p[i + 1] += a[i] == '?';
  for (register int t = 2; t <= len; t++) {
    for (register int i = 0; i < len - t + 1; i++) {
      int j = i + t - 1;
      if (a[i] != '(') (f[i][j] += f[i + 1][j]) %= mod;
      if (a[j] != ')') (f[i][j] += f[i][j - 1]) %= mod;
      if (a[i] != '(' && a[j] != ')')
        f[i][j] = (f[i][j] - f[i + 1][j - 1] + mod) % mod;
      if (a[i] != ')' && a[j] != '(')
        f[i][j] =
            (f[i][j] + f[i + 1][j - 1] + quickmod(2, p[j] - p[i + 1])) % mod;
    }
  }
  printf("%lld", f[0][len - 1]);
  return 0;
}
