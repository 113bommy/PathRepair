#include <bits/stdc++.h>
using namespace std;
char table[2010][2010];
int l1 = 0, l0 = 0;
int n, m, visited = 0;
int dfs(int i, int j, char c) {
  if (i < 0 || j < 0 || i >= n || j >= m || c != table[i][j]) return 0;
  int d = 0;
  visited++;
  d = max(d, dfs(i - 1, j, 'v'));
  d = max(d, dfs(i + 1, j, '^'));
  d = max(d, dfs(i, j - 1, '>'));
  d = max(d, dfs(i, j + 1, '<'));
  return d + 1;
}
void upd(int d) {
  if (d >= l0) {
    l1 = l0;
    l0 = d;
  } else if (d > l1) {
    l1 = d;
  }
}
int main() {
  scanf("%I64d %I64d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", &table[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (table[i][j] == '#') {
        visited++;
        upd(dfs(i - 1, j, 'v'));
        upd(dfs(i + 1, j, '^'));
        upd(dfs(i, j - 1, '>'));
        upd(dfs(i, j + 1, '<'));
      }
  int res = visited < n * m ? -1 : l0 + max(l1, l0 - 1);
  printf("%I64d", res);
  return 0;
}
