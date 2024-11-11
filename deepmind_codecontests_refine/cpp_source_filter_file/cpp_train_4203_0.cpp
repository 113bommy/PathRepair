#include <bits/stdc++.h>
using namespace std;
int g[510][510], sum[510][510];
bool f[510][510][10];
int getsum(int x, int y, int len) {
  return sum[x + len][y + len] + sum[x][y] - sum[x + len][y] - sum[x][y + len];
}
int main() {
  int n, m;
  cin >> n >> m;
  int i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      char c;
      cin >> c;
      g[i][j] = (c == '*' ? 1 : 0);
      sum[i + 1][j + 1] = g[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
    }
  long long ans = 0;
  for (int p = 0; p < 16; p++) {
    int a[4], b = p;
    for (i = 0; i < 4; i++, b /= 2) a[i] = b % 2;
    memset(f, 0, sizeof(f));
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        if (g[i][j] == 0) f[i][j][0] = 1;
    int t = 1;
    for (int len = 2; len < min(n, m); t++, len *= 2) {
      int l = len / 2;
      for (i = 0; i + len <= n; i++)
        for (j = 0; j + len <= m; j++) {
          int x[4], y[4];
          x[0] = i;
          y[0] = j;
          x[1] = i;
          y[1] = j + l;
          x[2] = i + l;
          y[2] = j;
          x[3] = i + l;
          y[3] = j + l;
          for (k = 0; k < 4; k++) {
            if (a[k] && getsum(x[k], y[k], l) != l * l) break;
            if (!a[k] && !f[x[k]][y[k]][t - 1]) break;
          }
          if (k == 4) {
            f[i][j][t] = 1;
            if (l > 1) ans++;
          }
        }
    }
  }
  cout << ans << endl;
  return 0;
}
