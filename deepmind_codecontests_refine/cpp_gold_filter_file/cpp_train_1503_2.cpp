#include <bits/stdc++.h>
using namespace std;
const int maxn = 410;
const int inf = 1e9;
int read() {
  int x = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return w ? -x : x;
}
int n, h[maxn], v[maxn], ans[maxn];
int f[maxn][maxn], g[maxn][maxn][2];
int main(int argc, char const *argv[]) {
  n = read();
  for (int i = 1; i <= n; ++i) v[i] = read();
  for (int i = 1; i <= n; ++i) h[i] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) f[i][j] = g[i][j][0] = g[i][j][1] = -inf;
  for (int i = n; i; --i) {
    f[i][i] = v[1], g[i][i][0] = g[i][i][1] = 0;
    for (int j = i + 1; j <= n; ++j) {
      for (int k = i; k < j - 1; ++k)
        if (h[k] + 1 == h[j])
          g[i][j][0] = max(g[i][j][0], g[i][k][0] + f[k + 1][j - 1]);
      if (h[j - 1] + 1 == h[j]) g[i][j][0] = max(g[i][j][0], g[i][j - 1][0]);
    }
    for (int j = i + 1; j <= n; ++j) {
      for (int k = i; k < j - 1; ++k)
        if (h[k] - 1 == h[j])
          g[i][j][1] = max(g[i][j][1], g[i][k][1] + f[k + 1][j - 1]);
      if (h[j - 1] - 1 == h[j]) g[i][j][1] = max(g[i][j][1], g[i][j - 1][1]);
    }
    for (int j = i; j <= n; ++j) {
      if (1 <= h[j] - h[i] + 1 && h[j] - h[i] + 1 <= n)
        f[i][j] = max(f[i][j], g[i][j][0] + v[h[j] - h[i] + 1]);
      if (1 <= h[i] - h[j] + 1 && h[i] - h[j] + 1 <= n)
        f[i][j] = max(f[i][j], g[i][j][1] + v[h[i] - h[j] + 1]);
      for (int k = i; k < j; ++k) f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
      for (int k = i + 1; k < j; ++k)
        if (1 <= 2 * h[k] - h[i] - h[j] + 1 && 2 * h[k] - h[i] - h[j] + 1 <= n)
          f[i][j] = max(
              f[i][j], g[i][k][0] + g[k][j][1] + v[2 * h[k] - h[i] - h[j] + 1]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] = ans[i - 1];
    for (int j = 0; j < i; ++j) ans[i] = max(ans[i], f[j + 1][i] + ans[j]);
  }
  cout << ans[n] << endl;
  return 0;
}
