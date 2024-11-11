#include <bits/stdc++.h>
const long long mod = 1e8 + 0;
const long long modd = 998244353;
const long long maxn = 2e3 + 10;
const double eps = 1e-8;
using namespace std;
char s[maxn];
int g[maxn][maxn], f[maxn][maxn];
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 0; i <= n + 1; i++) {
    if (s[i] == '(') break;
    f[i][0] = 1;
  }
  for (int i = n + 1; i >= 1; i--) {
    if (s[i] == ')') break;
    g[i][0] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      if (s[i] == '(')
        f[i][j] = f[i - 1][j - 1];
      else if (s[i] == ')')
        f[i][j] = f[i - 1][j];
      else
        f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % modd;
    }
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= n - i + 1; j++) {
      if (s[i] == ')')
        g[i][j] = g[i + 1][j - 1];
      else if (s[i] == '(')
        g[i][j] = g[i + 1][j];
      else
        g[i][j] = (g[i + 1][j] + g[i + 1][j - 1]) % modd;
    }
  int ans = 0;
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= min(i, n - i); j++) {
      ans += f[i][j] * g[i + 1][j] % modd * j % modd;
      ans %= modd;
    }
  printf("%d\n", ans);
  return 0;
}
