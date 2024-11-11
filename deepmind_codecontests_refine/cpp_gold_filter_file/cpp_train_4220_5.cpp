#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long f[N][(1 << 5)];
int n, m, y[N], a[N][6], b[N][6];
void dfs(int i, int dep, int s1, int s2, long long cost) {
  if (dep == n) {
    if (y[0] != y[n - 1]) cost += b[i + 1][n - 1];
    if (f[i][s1] + cost < f[i + 1][s2]) f[i + 1][s2] = f[i][s1] + cost;
    return;
  }
  for (int p = 0; p < 2; ++p)
    for (int q = 0; q < 2; ++q) {
      long long tmp = cost;
      y[dep] = q;
      if (p != q) tmp += a[i][dep];
      if (dep > 0 && y[dep] != y[dep - 1]) tmp += b[i + 1][dep - 1];
      dfs(i, dep + 1, s1 + p * (1 << dep), s2 + q * (1 << dep), tmp);
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < m; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
  for (int i = 1; i <= m; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &b[i][j]);
  for (int i = 1; i <= m; ++i)
    for (int j = 0; j < (1 << n); ++j) f[i][j] = 1LL << 60;
  f[1][0] = 0;
  for (int i = 1; i < m; ++i) dfs(i, 0, 0, 0, 0);
  cout << f[m][(1 << n) - 1] << endl;
  return 0;
}
