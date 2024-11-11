#include <bits/stdc++.h>
using namespace std;
int n, y, m, x, cnt[10], d;
vector<vector<int> > a(301, vector<int>(301));
vector<vector<int> > mul(vector<vector<int> > a, vector<vector<int> > b) {
  vector<vector<int> > c(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) c[i][j] = -1e9;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
  return c;
}
vector<vector<int> > pow(vector<vector<int> > a, int p) {
  if (p == 1) return a;
  if (p % 2) return mul(a, pow(a, p - 1));
  vector<vector<int> > X = pow(a, p / 2);
  return mul(X, X);
}
bool check(int mo) {
  vector<vector<int> > d = pow(a, mo);
  for (int i = 1; i <= n; i++)
    if (d[i][i] > 0) return true;
  return false;
}
int bs(int l, int r) {
  int ans = m + 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = -1e9;
  for (int i = 1; i <= n; i++) a[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int w, c;
    scanf("%d%d%d%d", &x, &y, &w, &c);
    a[x][y] = w;
    a[y][x] = c;
  }
  printf("%d\n", bs(2, m));
  return 0;
}
