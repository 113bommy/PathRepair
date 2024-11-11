#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int graph[maxn][maxn];
int row[maxn][maxn], col[maxn][maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &graph[i][j]);
      row[i][j] = graph[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) col[i][j] = graph[j][i];
  }
  for (int i = 1; i <= n; i++) {
    sort(row[i] + 1, row[i] + 1 + m);
    int tmp = unique(row[i] + 1, row[i] + 1 + m) - row[i] - 1;
    row[i][0] = tmp;
  }
  for (int i = 1; i <= m; i++) {
    sort(col[i] + 1, col[i] + 1 + n);
    int tmp = unique(col[i] + 1, col[i] + 1 + n) - col[i] - 1;
    col[i][0] = tmp;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int p1, p2, ans = 0, tmp1 = row[i][0], tmp2 = col[j][0];
      p1 = lower_bound(row[i] + 1, row[i] + 1 + tmp1, graph[i][j]) - row[i];
      p2 = lower_bound(col[j] + 1, col[j] + 1 + tmp2, graph[i][j]) - col[j];
      ans = max(tmp1 - p1, tmp2 - p2) + max(p1, p2);
      printf("%d ", ans);
    }
    printf("\n");
  }
  return 0;
}
