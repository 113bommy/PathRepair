#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[200][200];
int d[200][200];
void dfs(int a, int b, int cx) {
  if (a < 0 || a >= n || b < 0 || b >= m) return;
  if (d[a][b] > 0 || c[a][b] != 'B') return;
  d[a][b] = cx;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0) dfs(a + i, b + j, cx);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  memset(d, 0, sizeof(d));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (d[i][j] == 0 && c[i][j] == 'B') dfs(i, j, ++ans);
    }
  }
  printf("d\n", ans);
  return 0;
}
