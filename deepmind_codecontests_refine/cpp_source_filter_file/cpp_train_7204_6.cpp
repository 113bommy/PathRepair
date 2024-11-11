#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 2010;
int k, n, m, ans;
int g[N][N], f[N][N], tmp[N][N];
template <typename T>
void gi(T &x) {
  x = 0;
  register char c = getchar(), pre = 0;
  for (; c < '0' || c > '9'; pre = c, c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c ^ 48);
  if (pre == '-') x = -x;
}
int main() {
  gi(k), n = 1 << k;
  for (int i = (0); i <= (n - 1); i++)
    for (int j = (0); j <= (n - 1); j++) gi(g[i][j]);
  gi(m);
  for (int i = (1); i <= (m); i++) {
    int x, y;
    gi(x), gi(y), f[x - 1][y - 1] ^= 1;
  }
  for (int h = (1); h <= (k); h++) {
    for (int i = (0); i <= (n - 1); i++)
      for (int j = (0); j <= (n - 1); j++)
        if (f[i][j]) {
          for (int ii = (0); ii <= (n - 1); ii++)
            for (int jj = (0); jj <= (n - 1); jj++)
              tmp[(ii + i) % n][(jj + j) % n] ^= g[ii][jj];
        }
    for (int i = (0); i <= (n - 1); i++)
      for (int j = (0); j <= (n - 1); j++) g[i][j] = tmp[i][j], tmp[i][j] = 0;
    for (int i = (0); i <= (n - 1); i++)
      for (int j = (0); j <= (n - 1); j++)
        tmp[(i + i) % n][(j + j) % n] ^= f[i][j];
    for (int i = (0); i <= (n - 1); i++)
      for (int j = (0); j <= (n - 1); j++) f[i][j] = tmp[i][j], tmp[i][j] = 0;
  }
  for (int i = (0); i <= (n - 1); i++)
    for (int j = (0); j <= (n - 1); j++)
      if (g[i][j]) ++ans;
  printf("%d\n", ans);
  return 0;
}
