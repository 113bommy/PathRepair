#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, q;
int type, x, y;
int a[N][N];
int d[N][N];
int u[N][N];
int r[N][N];
int l[N][N];
int f[N];
int maxi;
void calc() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      u[i][j] = (a[i][j] == 0 ? 0 : u[i - 1][j] + 1),
      l[i][j] = (a[i][j] == 0 ? 0 : l[i][j - 1] + 1);
  for (int i = n; i >= 1; --i)
    for (int j = m; j >= 1; --j)
      d[i][j] = (a[i][j] == 0 ? 0 : d[i + 1][j] + 1),
      r[i][j] = (a[i][j] == 0 ? 0 : r[i][j + 1] + 1);
}
void upd(int x, int y) {
  a[x][y] = 1 - a[x][y];
  if (a[x][y] == 0) u[x][y] = r[x][y] = d[x][y] = l[x][y] = 0;
  for (int j = 1; j <= n; ++j) u[j][y] = (a[j][y] == 0 ? 0 : u[j - 1][y] + 1);
  for (int j = n; j >= 1; --j) d[j][y] = (a[j][y] == 0 ? 0 : d[j + 1][y] + 1);
  for (int j = 1; j <= m; ++j) l[x][j] = (a[x][j] == 0 ? 0 : l[x][j - 1] + 1);
  for (int j = m; j >= 1; --j) r[x][j] = (a[x][j] == 0 ? 0 : r[x][j + 1] + 1);
}
stack<int> L, R;
int l1[N], r1[N];
void solve(int tp, int id) {
  int len = (tp == 1 ? n : m);
  while (!L.empty()) L.pop();
  for (int j = 1; j <= len; ++j) {
    while (!L.empty() && f[L.top()] >= f[j]) L.pop();
    l1[j] = (L.empty() ? 1 : L.top() + 1);
    L.push(j);
  }
  while (!R.empty()) R.pop();
  for (int j = len; j >= 1; --j) {
    while (!R.empty() && f[R.top()] >= f[j]) R.pop();
    r1[j] = (R.empty() ? len : R.top() - 1);
    R.push(j);
  }
  for (int j = 1; j <= len; ++j)
    if (l1[j] <= id && id <= r1[j])
      maxi = max(maxi, f[j] * (r1[j] - l1[j] + 1));
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
  calc();
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d%d", &type, &x, &y);
    if (type == 1)
      upd(x, y);
    else {
      maxi = 0;
      for (int j = 1; j <= n; ++j) f[j] = r[j][y];
      solve(1, x);
      for (int j = 1; j <= n; ++j) f[j] = l[j][y];
      solve(1, x);
      for (int j = 1; j <= m; ++j) f[j] = u[x][j];
      solve(2, y);
      for (int j = 1; j <= m; ++j) f[j] = d[x][j];
      solve(2, y);
      printf("%d\n", maxi);
    }
  }
  return 0;
}
