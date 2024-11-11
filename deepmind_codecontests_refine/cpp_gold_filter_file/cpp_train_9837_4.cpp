#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, ans;
char a[N][N];
int mp[N][N], ma[N][N];
int main() {
  int i, j, ii, jj;
  int del;
  scanf("%d%d\n", &n, &m);
  for (i = 1; i <= n; ++i) scanf("%s\n", a[i] + 1);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) mp[i][j] = a[i][j] == 'W' ? 1 : -1;
  memset(ma, 0, sizeof(ma));
  for (i = n; i; --i)
    for (j = m; j; --j)
      if (ma[i][j] != mp[i][j]) {
        del = mp[i][j] - ma[i][j];
        for (ii = 1; ii <= i; ++ii)
          for (jj = 1; jj <= j; ++jj) ma[ii][jj] += del;
        ++ans;
      }
  printf("%d\n", ans);
  return 0;
}
