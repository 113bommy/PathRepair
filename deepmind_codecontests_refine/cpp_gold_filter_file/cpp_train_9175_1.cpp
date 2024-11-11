#include <bits/stdc++.h>
using namespace std;
const int maxn = 22 + 1, maxround = 17;
int n, m, a, b, x, y, cur, k, num[maxn][maxn], size;
double M[2][maxn * maxn][maxn * maxn], pro, p[maxn][maxn];
vector<int> G[maxn];
void solve() {
  cur = 0, size = n * n;
  for (int T = 1; T <= maxround; T++) {
    cur ^= 1;
    memset(M[cur], 0, sizeof(M[cur]));
    for (int i = 1; i <= size; i++)
      for (int k = 1; k <= size; k++) {
        if (M[cur ^ 1][i][k] < (1e-10)) continue;
        for (int j = 1; j <= size; j++)
          M[cur][i][j] += M[cur ^ 1][i][k] * M[cur ^ 1][k][j];
      }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) num[i][j] = (i - 1) * n + j;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &pro);
    p[i][i] = pro, k = (int)(G[i].size());
    for (int j = 0; j <= (int)(G[i].size()) - 1; j++)
      p[i][G[i][j]] = (1 - pro) / k;
    G[i].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j)
        for (int l = 0; l <= (int)(G[i].size()) - 1; l++)
          for (int r = 0; r <= (int)(G[j].size()) - 1; r++) {
            x = G[i][l], y = G[j][r];
            M[0][num[x][y]][num[i][j]] = p[i][x] * p[j][y];
          }
  for (int i = 1; i <= n; i++) M[0][num[i][i]][num[i][i]] = 1;
  solve();
  for (int i = 1; i <= n; i++)
    printf("%.7f%c", M[cur][num[i][i]][num[a][b]], (i == n) ? ('\n') : (' '));
  return 0;
}
