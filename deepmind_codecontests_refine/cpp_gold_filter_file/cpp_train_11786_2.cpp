#include <bits/stdc++.h>
using namespace std;
namespace TYC {
const int N = 5e6 + 5;
int n, m, Pooli[N << 1], *S[N];
char Poolc[N << 1], *G[N];
inline int id(const int x, const int y) { return (x - 1) * m + y; }
int getans() {
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (G[i][j] == 'X') {
        int t = 0;
        while (j < m && G[i][j + 1] == 'X') ++t, ++j;
        ans = min(ans, t >> 1);
      }
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      if (G[i][j] == 'X') {
        int t = 0;
        while (i < n && G[i + 1][j] == 'X') ++t, ++i;
        ans = min(ans, t >> 1);
      }
  return ans;
}
inline bool Q(const int x1, const int y1, const int x2, const int y2) {
  return x1 > 0 && x2 <= n && y1 > 0 && y2 <= m &&
         S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1] ==
             (x2 - x1 + 1) * (y2 - y1 + 1);
}
void work() {
  scanf("%d%d", &n, &m);
  S[0] = Pooli + 1;
  for (int i = 1; i <= n; i++) {
    G[i] = i == 1 ? Poolc + 2 : G[i - 1] + (m + 2);
    S[i] = S[i - 1] + (m + 2);
    scanf("%s", G[i] + 1);
    for (int j = 1; j <= m; j++)
      S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + (G[i][j] == 'X');
  }
  int ans = getans();
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (Q(i - ans, j - ans, i, j) && Q(i - ans, j, i, j + ans) &&
          Q(i, j - ans, i + ans, j) && Q(i, j, i + ans, j + ans))
        putchar('X');
      else
        putchar('.');
    putchar('\n');
  }
}
}  // namespace TYC
int main() {
  TYC::work();
  return 0;
}
