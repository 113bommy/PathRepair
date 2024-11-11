#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long LLinf = 0x3f3f3f3f3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10ll + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 100 + 10;
const int mod = 1000000007;
char s[maxn];
long long n, x;
long long f[maxn][maxn][maxn];
long long powlen[maxn];
void build() {
  n = read();
  x = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0')
      f[0][i][i] = 1;
    else
      f[1][i][i] = 1;
  }
  powlen[0] = powlen[1] = 2;
  for (int i = 2; i <= x; i++) powlen[i] = powlen[i - 1] * powlen[i - 2] % mod;
  for (int i = 2; i <= x; i++) {
    for (int j = 1; j <= n; j++)
      for (int k = j; k <= n; k++) {
        if (k == n)
          f[i][j][k] += f[i - 1][j][k] * powlen[i - 2] % mod;
        else
          f[i][j][k] += f[i - 1][j][k] % mod;
        if (j == 1)
          f[i][j][k] += f[i - 2][j][k] * powlen[i - 1] % mod;
        else
          f[i][j][k] += f[i - 2][j][k] % mod;
      }
    for (int j = 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++) {
        for (int c = j; c < k; c++)
          f[i][j][k] =
              (f[i][j][k] + (f[i - 1][j][c] * f[i - 2][c + 1][k]) % mod) % mod;
      }
  }
  cout << f[x][1][n] % mod << '\n';
}
void solve() {}
int main() {
  build();
  solve();
  return 0;
}
