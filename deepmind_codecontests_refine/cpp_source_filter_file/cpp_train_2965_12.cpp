#include <bits/stdc++.h>
using namespace std;
double f[32][32][209];
bool vis[32][32][209];
int n, a[32], k;
double dfs(int i, int j, int k) {
  if (vis[i][j][k]) return f[i][j][k];
  vis[i][j][k] = 1;
  if (i > j) return f[i][j][k] = 1.0 - dfs(j, i, k);
  if (k == 0) return f[i][j][k] = (i < j);
  f[i][j][k] = 0;
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      int ni, nj;
      if (l <= i && i <= r)
        ni = l + r - i;
      else
        ni = i;
      if (l <= j && j <= r)
        nj = l + r - j;
      else
        nj = j;
      f[i][j][k] += dfs(ni, nj, k - 1);
    }
  }
  f[i][j][k] /= (n + 1) * n / 2;
  return f[i][j][k];
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  double ans;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j])
        ans += dfs(i, j, k);
      else
        ans += dfs(j, i, k);
    }
  }
  printf("%.15f\n", ans);
  return 0;
}
