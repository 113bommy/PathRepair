#include <bits/stdc++.h>
using namespace std;
char ans[105][105];
int n, m;
inline char Find(int x, int y) {
  for (char c = 'A'; c <= 'Z'; ++c) {
    if ((x - 1 < 0 || ans[x - 1][y] != c) &&
        (y - 1 < 0 || ans[x][y - 1] != c) && ans[x + 1][y] != c &&
        ans[x][y + 1] != c)
      return c;
  }
  return '!';
}
inline void Fill(int x, int y, int D, char c) {
  for (int i = 0; i < D; ++i)
    for (int j = 0; j < D; ++j) ans[x + i][y + j] = c;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!ans[i][j]) {
        int D = min(n - i, m - j), k;
        char c = Find(i, j);
        for (k = j + 1; k < m; ++k)
          if (ans[i][k] || Find(i, k) != c) break;
        D = min(D, k - j);
        Fill(i, j, D, c);
      }
  for (int i = 0; i < n; ++i, puts(""))
    for (int j = 0; j < m; ++j) putchar(ans[i][j]);
  return 0;
}
