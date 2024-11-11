#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char s[2][N][N];
int n, m;
pair<int, int> ans[2][100005];
void gao(int x, int y, int p) {
  if (s[p][x + 1][y] == 'U') {
    if (s[p][x + 1][y + 1] == 'L') gao(x + 1, y + 1, p);
    s[p][x + 1][y] = s[p][x + 2][y] = 'L';
    s[p][x + 1][y + 1] = s[p][x + 2][y + 1] = 'R';
    ans[p][++ans[p][0].first] = make_pair(x + 1, y);
  }
  s[p][x][y] = s[p][x][y + 1] = 'U';
  s[p][x + 1][y] = s[p][x + 1][y + 1] = 'D';
  ans[p][++ans[p][0].first] = make_pair(x, y);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int k = 0; k < 2; ++k)
    for (int i = 0; i < n; ++i) scanf("%s", s[k][i]);
  for (int k = 0; k < 2; ++k)
    for (int i = 0; i < n - 1; ++i)
      for (int j = 0; j < m; ++j)
        if (s[k][i][j] == 'L') gao(i, j, k);
  printf("%d\n", ans[0][0].first + ans[1][0].first);
  for (int i = 1; i <= ans[0][0].first; ++i)
    printf("%d %d\n", ans[0][i].first + 1, ans[0][i].second + 1);
  for (int i = ans[1][0].first; i >= 1; --i)
    printf("%d %d\n", ans[1][i].first + 1, ans[1][i].second + 1);
  return 0;
}
