#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int n, m, garden[maxn][maxn];
int counttree(int x, int y, int a, int b) {
  int ret = 0;
  for (int i = x; i < x + a; i++)
    for (int j = y; j < y + b; j++)
      if (garden[i][j]) ret++;
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &garden[i][j]);
  int a, b;
  scanf("%d %d", &a, &b);
  int mini = a * b;
  for (int i = 0; i <= n - a; i++)
    for (int j = 0; j <= m - b; j++) {
      int cur = counttree(i, j, a, b);
      if (cur < mini) mini = cur;
    }
  for (int i = 0; i <= n - b; i++)
    for (int j = 0; j <= n - a; j++) {
      int cur = counttree(i, j, b, a);
      if (cur < mini) mini = cur;
    }
  printf("%d\n", mini);
  return 0;
}
