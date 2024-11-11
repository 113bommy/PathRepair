#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 105, inf = 1e9;
pair<int, int> e[N];
int n;
int f[N][N][2];
int main() {
  n = read();
  int ans = 0;
  for (int i = 1; i <= n; i++) e[i].first = read(), e[i].second = read();
  sort(e + 1, e + 1 + n);
  e[0].first = -inf;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      for (int p = 0; p < 2; p++) {
        int o = e[i].first + p * e[i].second, z = -inf, x, y;
        ans = max(ans, f[i][j][p]);
        for (int k = i + 1; k <= n; k++)
          for (int q = 0; q < 2; q++) {
            int t = e[k].first + q * e[k].second;
            if (t > z) z = t, x = k, y = q;
            f[k][x][y] =
                max(f[k][x][y], f[i][j][p] + min(e[k].second, t - o) + z - t);
          }
      }
  printf("%d\n", ans);
  return 0;
}
