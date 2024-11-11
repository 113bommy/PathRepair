#include <bits/stdc++.h>
using namespace std;
const int NM = 1e6 + 5;
int T;
int n, m;
int col[NM];
int to[22][NM];
char s[NM];
inline int f(int x, int y) { return (x - 1) * m + y; }
int tot, sum;
bool vis[2][NM];
int logg[NM];
int main() {
  scanf("%d", &T);
  for (int i = 2; i <= NM; ++i) logg[i] = logg[i / 2] + 1;
  while (T--) {
    for (int i = 1; i <= n * m; ++i) vis[0][i] = vis[1][i] = 0;
    tot = sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) scanf("%1d", &col[f(i, j)]);
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s + 1);
      for (int j = 1; j <= m; ++j) {
        int pos = f(i, j);
        if (s[j] == 'U') to[0][pos] = f(i - 1, j);
        if (s[j] == 'D') to[0][pos] = f(i + 1, j);
        if (s[j] == 'L') to[0][pos] = f(i, j - 1);
        if (s[j] == 'R') to[0][pos] = f(i, j + 1);
      }
    }
    int t = log(n * m) / log(2);
    for (int i = 1; i <= t; ++i)
      for (int j = 1; j <= n * m; ++j) to[i][j] = to[i - 1][to[i - 1][j]];
    for (int i = 1; i <= n * m; ++i) {
      int pos = i;
      for (int j = 0; j <= t; ++j)
        if ((n * m) & (1 << j)) pos = to[j][pos];
      vis[col[i]][pos] = 1;
    }
    for (int i = 1; i <= n * m; ++i) {
      if (vis[0][i])
        ++tot, ++sum;
      else if (vis[1][i])
        ++tot;
    }
    printf("%d %d\n", tot, sum);
  }
  return 0;
}
