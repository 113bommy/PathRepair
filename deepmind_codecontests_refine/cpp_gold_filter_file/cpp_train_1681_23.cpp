#include <bits/stdc++.h>
using namespace std;
int n, m, a[1001][1001];
set<int> r[1001], c[1001];
map<int, int> r_m[1001], c_m[1001];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      r[i].insert(a[i][j]);
      c[j].insert(a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    int w = 1;
    for (int x : r[i]) {
      r_m[i][x] = w;
      w++;
    }
  }
  for (int i = 1; i <= m; i++) {
    int w = 1;
    for (int x : c[i]) {
      c_m[i][x] = w;
      w++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = r_m[i][a[i][j]];
      int y = c_m[j][a[i][j]];
      if (x > y) {
        printf("%d ", max((int)r[i].size(), (int)c[j].size() + x - y));
      } else {
        printf("%d ", max((int)r[i].size() + y - x, (int)c[j].size()));
      }
    }
    printf("\n");
  }
  return 0;
}
