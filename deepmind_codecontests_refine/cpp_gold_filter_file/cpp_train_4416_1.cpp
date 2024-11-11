#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int num = 0, f = 1;
  for (; !isdigit(c); c = getchar()) f = c == '-' ? -1 : f;
  for (; isdigit(c); c = getchar()) num = num * 10 + c - '0';
  return num * f;
}
const int N = 3e3 + 5;
const int mod = 1e9 + 7;
int n, m;
char s[N][N];
int f[N][N], ans[4];
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  if (s[1][2] == '#' || s[2][1] == '#') {
    puts("0");
    return 0;
  }
  f[1][2] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= m; ++j)
      if (s[i][j] == '.') f[i][j] = (f[i][j] + f[i - 1][j] + f[i][j - 1]) % mod;
  ans[0] = f[n - 1][m], ans[2] = f[n][m - 1];
  memset(f, 0, sizeof(f));
  f[2][1] = 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (s[i][j] == '.') f[i][j] = (f[i][j] + f[i - 1][j] + f[i][j - 1]) % mod;
  ans[1] = f[n][m - 1], ans[3] = f[n - 1][m];
  cout << ((1ll * ans[0] * ans[1] - 1ll * ans[2] * ans[3]) % mod + mod) % mod;
  return 0;
}
