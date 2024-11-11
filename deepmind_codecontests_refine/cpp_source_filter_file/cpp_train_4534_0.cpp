#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, v[100015], t = 1, r, w[10015], a, b;
vector<int> e[100015];
void dfs(int x, int y) {
  v[x] = 1;
  w[x] = y;
  for (int j = 0; j < e[x].size(); j++) {
    if (w[e[x][j]] == y) {
      r = 10;
      return;
    }
    if (v[e[x][j]] == 0) {
      dfs(e[x][j], 3 - y);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] != 1) {
      dfs(i, 1);
    }
    if (r == 10) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (w[i] == 1) {
      a++;
    } else {
      b++;
    }
  }
  t = 0;
  printf("%d\n", a);
  for (int i = 1; i <= n; i++) {
    if (w[i] == 1 && t == 0) {
      printf("%d", i);
      t = 1;
    } else if (w[i] == 1 && t == 1) {
      printf(" %d", i);
    }
  }
  t = 0;
  printf("\n%d\n", b);
  for (int i = 1; i <= n; i++) {
    if (w[i] == 2 && t == 0) {
      printf("%d", i);
      t = 1;
    } else if (w[i] == 2 && t == 1) {
      printf(" %d", i);
    }
  }
  return 0;
}
