#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 0, fl = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fl = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch - '0');
  return x * fl;
}
const int N = 25;
const double eps = 1e-15;
int n, m, a, b, de[N];
double p[N], g[N][N], f[N][N], ans[N];
vector<int> e[N];
int main() {
  n = read();
  m = read();
  a = read();
  b = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    e[x].push_back(y);
    e[y].push_back(x);
    de[x]++;
    de[y]++;
  }
  for (int i = 1; i <= n; i++) cin >> p[i];
  g[a][b] = 1;
  for (int tim = 1; tim <= 150000; tim++) {
    memcpy(f, g, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (f[i][j] < eps) continue;
        if (i == j) {
          ans[i] += f[i][j];
          continue;
        }
        double tmp = (1 - p[i]) * p[j] / (1.0 * de[i]);
        for (auto x : e[i]) g[x][j] += tmp * f[i][j];
        tmp = p[i] * (1 - p[j]) / (1.0 * de[j]);
        for (auto x : e[j]) g[i][x] += tmp * f[i][j];
        tmp = (1 - p[i]) * (1 - p[j]) / (1.0 * de[i]) / (1.0 * de[j]);
        for (auto x : e[i]) {
          for (auto y : e[j]) g[x][y] += tmp * f[i][j];
        }
        g[i][j] += p[i] * p[j] * f[i][j];
      }
  }
  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(15) << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
