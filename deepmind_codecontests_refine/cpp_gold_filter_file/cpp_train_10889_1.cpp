#include <bits/stdc++.h>
using namespace std;
const int inf = 510;
const int N = 110;
int n, m, a[N][N], row[N], col[N], ans = 0;
void solverow() {
  for (int i = 0; i < n; i++) {
    int mi = inf;
    for (int j = 0; j < m; j++) mi = min(mi, a[i][j]);
    row[i] = mi;
    ans += mi;
    for (int j = 0; j < m; j++) a[i][j] -= mi;
  }
}
void solvecol() {
  for (int j = 0; j < m; j++) {
    int mi = inf;
    for (int i = 0; i < n; i++) mi = min(mi, a[i][j]);
    col[j] = mi;
    ans += mi;
    for (int i = 0; i < n; i++) a[i][j] -= mi;
  }
}
bool check() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] > 0) return false;
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  if (n <= m) {
    solverow();
    solvecol();
  } else {
    solvecol();
    solverow();
  }
  if (!check())
    printf("-1\n");
  else {
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < row[i]; j++) printf("row %d\n", i + 1);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < col[i]; j++) printf("col %d\n", i + 1);
  }
  return 0;
}
