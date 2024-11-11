#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, y = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') y = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * y;
}
const int N = 2005, mod = 998244353;
int n, f[N][N], num[N];
char s[N];
inline int qpow(long long x, int y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) f[i][i] = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == '?') num[i]++;
  for (int i = 1; i <= n; i++) num[i] += num[i - 1];
  for (int t = 1; t <= n; t++) {
    for (int i = 1; i <= n - t; i++) {
      int j = i + t;
      if (s[i] != '(') f[i][j] = (1ll * f[i][j] + f[i + 1][j]) % mod;
      if (s[j] != ')') f[i][j] = (1ll * f[i][j] + f[i][j - 1]) % mod;
      if (s[i] != '(' && s[j] != ')')
        f[i][j] = (1ll * f[i][j] + mod - f[i + 1][j - 1]) % mod;
      if (s[i] != ')' && s[j] != '(')
        f[i][j] =
            (1ll * f[i][j] + f[i + 1][j - 1] + qpow(2, num[j - 1] - num[i])) %
            mod;
    }
  }
  printf("%d\n", f[1][n]);
  return 0;
}
