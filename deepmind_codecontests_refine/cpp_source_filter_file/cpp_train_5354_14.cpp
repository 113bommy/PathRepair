#include <bits/stdc++.h>
using namespace std;
const int oo = 2000000009;
const double eps = 1e-9;
const int mx = 2003;
int row[mx], col[mx];
int vis[mx][mx], n, m;
long double dp[mx][mx];
long double solve(int r, int c) {
  if (r < 0 || c < 0) return 0;
  if (r + c == 0) return 0;
  long double &ret = dp[r][c];
  if (vis[r][c]) return ret;
  vis[r][c] = 1;
  ret = 0;
  long double s = 0, p = 0;
  s += 1.0 * r * c / (n * n) * (1 + solve(r - 1, c - 1));
  s += 1.0 * r * (n - c) / (n * n) * (1 + solve(r - 1, c));
  s += 1.0 * (n - r) * c / (n * n) * (1 + solve(r, c - 1));
  p = 1.0 * (n - r) * (n - c) / (n * n);
  ret = (s + p) / (1 - p);
  return ret;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < (m); ++i) {
    int x, y;
    cin >> x >> y;
    row[x - 1] = col[y - 1] = 1;
  }
  int nr = 0, nc = 0;
  for (int i = 0; i < (n); ++i) {
    if (!row[i]) ++nr;
    if (!col[i]) ++nc;
  }
  memset(vis, 0, sizeof(vis));
  printf("%.09Lf\n", solve(nr, nc));
  return 0;
}
