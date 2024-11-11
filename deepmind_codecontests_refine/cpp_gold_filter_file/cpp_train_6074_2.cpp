#include <bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int ret = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() & 1) ret++;
  }
  ret /= 2;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() != 2) {
      continue;
    }
    int x = g[i][0], y = g[i][1];
    g[i].clear();
    if (x == y) {
      g[x].clear();
      ret++;
    } else {
      g[x][g[x][0] != i] = y;
      g[y][g[y][0] != i] = x;
    }
  }
  printf("%d %d\n", ret, m);
  return 0;
}
