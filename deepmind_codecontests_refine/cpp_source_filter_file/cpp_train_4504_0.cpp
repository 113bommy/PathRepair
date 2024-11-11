#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 10;
int n, m, k, t;
int a[maxn][maxn];
int neigh(int x, int y) {
  if (x == 0 || x == n - 1 && (y == 0 || y == m - 1)) return 2;
  if (x == 0 || x == n - 1 || y == 0 || y == m - 1) return 3;
  return 4;
}
int main() {
  int i, j;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    bool valid = true;
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        if (a[i][j] > neigh(i, j)) {
          valid = false;
        }
      }
    if (!valid) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) a[i][j] = neigh(i, j);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) printf("%d%c", a[i][j], j == m - 1 ? '\n' : ' ');
  }
  return 0;
}
