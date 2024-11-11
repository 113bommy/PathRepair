#include <bits/stdc++.h>
using namespace std;
int n, m = 1;
int f[4100][4100], b[4100], nt[2100], hd[4100], u[4100][4100];
pair<int, int> a[2100];
int find(const int x) {
  if (x == b[m]) return m;
  if (x == b[1]) return 1;
  int L = 1, R = m, mid;
  while (L + 1 < R) {
    mid = (L + R) >> 1;
    if (b[mid] == x) return mid;
    if (b[mid] < x)
      L = mid;
    else
      R = mid;
  }
  return 0;
}
void init() {
  int k = 0;
  scanf("%d", &n);
  for (int i = 1, x, y; i <= n; ++i)
    scanf("%d%d", &x, &y), b[++k] = a[i].first = x - y,
                           b[++k] = a[i].second = x + y;
  sort(b + 1, b + 1 + k);
  for (int i = 2; i <= k; ++i)
    if (b[i] != b[m]) b[++m] = b[i];
  for (int i = 1; i <= n; ++i) {
    a[i].first = find(a[i].first), a[i].second = find(a[i].second);
    u[a[i].first][a[i].second] = i;
    nt[i] = hd[a[i].first], hd[a[i].first] = i;
  }
}
void work() {
  for (int i = m; i > 0; --i)
    for (int j = i; j <= m; ++j) {
      f[i][j] = f[i + 1][j];
      for (int k = hd[i]; k != 0; k = nt[k])
        if (a[k].second < j && f[i][a[k].second] + f[a[k].second][j] > f[i][j])
          f[i][j] = f[i][a[k].second] + f[a[k].second][j];
      f[i][j] += (u[i][j] > 0);
    }
}
void Gans(const int x, const int y) {
  if (f[x][y] == 0) return;
  if (u[x][y] > 0) printf("%d ", u[x][y]), --f[x][y];
  if (f[x][y] == f[x + 1][y])
    Gans(x + 1, y);
  else
    for (int i = hd[x]; i != 0; i = nt[i])
      if (a[i].second < y && f[x][a[i].second] + f[a[i].second][y] == f[x][y]) {
        Gans(x, a[i].second), Gans(a[i].second, y);
        return;
      }
}
int main() {
  init();
  work();
  printf("%d\n", f[1][m]);
  Gans(1, m);
  return 0;
}
