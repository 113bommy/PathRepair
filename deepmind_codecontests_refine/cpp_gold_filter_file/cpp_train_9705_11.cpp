#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
string Co = "RGYB";
int n, m, q;
int num[5][maxn][maxn];
int ans[300005];
char mp[maxn][maxn];
struct {
  int lx, ly, rx, ry;
} Q[300005];
int query(int k, int lx, int ly, int rx, int ry) {
  return num[k][rx][ry] - num[k][rx][ly - 1] - num[k][lx - 1][ry] +
         num[k][lx - 1][ly - 1];
}
int main() {
  scanf(" %d%d%d", &n, &m, &q);
  for (int i = (1); i <= (n); ++i) scanf(" %s", mp[i] + 1);
  for (int c = (0); c <= (3); ++c)
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (m); ++j) {
        num[c][i][j] +=
            num[c][i - 1][j] + num[c][i][j - 1] - num[c][i - 1][j - 1];
        num[c][i][j] += mp[i][j] == Co[c];
      }
  for (int i = (1); i <= (q); ++i)
    scanf(" %d%d%d%d", &Q[i].lx, &Q[i].ly, &Q[i].rx, &Q[i].ry);
  for (int l = (1); l <= (250); ++l) {
    if (l * 2 > n || l * 2 > m) break;
    for (int i = (1); i <= (n - 2 * l + 1); ++i)
      for (int j = (1); j <= (m - 2 * l + 1); ++j)
        if (query(0, i, j, i + l - 1, j + l - 1) == l * l &&
            query(1, i, j + l, i + l - 1, j + 2 * l - 1) == l * l &&
            query(2, i + l, j, i + 2 * l - 1, j + l - 1) == l * l &&
            query(3, i + l, j + l, i + 2 * l - 1, j + 2 * l - 1) == l * l)
          num[4][i][j] = 1;
        else
          num[4][i][j] = 0;
    for (int i = (1); i <= (n - 2 * l + 1); ++i)
      for (int j = (1); j <= (m - 2 * l + 1); ++j) {
        num[4][i][j] +=
            num[4][i - 1][j] + num[4][i][j - 1] - num[4][i - 1][j - 1];
      }
    for (int i = (1); i <= (q); ++i)
      if (Q[i].rx - Q[i].lx + 1 >= 2 * l && Q[i].ry - Q[i].ly + 1 >= 2 * l &&
          query(4, Q[i].lx, Q[i].ly, Q[i].rx - 2 * l + 1, Q[i].ry - 2 * l + 1))
        ans[i] = l;
  }
  for (int i = (1); i <= (q); ++i) printf("%d\n", 4 * ans[i] * ans[i]);
  return 0;
}
