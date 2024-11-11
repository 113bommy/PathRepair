#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, u, U, L, S, T, ans;
int l[200][200], p[200][200][200], dl[200], a[200][200][200], b[200][200][200];
vector<int> R[200], Rw[200], A[200], Aw[200], B[200], Bw[200], G[200];
inline void upd(int &x, int y) {
  x += y;
  if (x >= 1000000007) x -= 1000000007;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) b[i][i][0] = 1;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) l[i][j] = -1;
  for (int i = (1); i <= (m); i++) {
    scanf("%d%d", &x, &y);
    scanf("%d", &l[x][y]);
    if (!l[x][y]) G[x].push_back(y);
    for (int j = (1); j <= (l[x][y]); j++) scanf("%d", &p[x][y][j]);
  }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) {
      u = 0;
      for (int k = (1); k <= (l[i][j] - 1); k++)
        if (p[i][j][k] == i && p[i][j][k + 1] == j) u = k;
      if (!u) continue;
      L = 1;
      S = 1;
      T = 0;
      U = 0;
      dl[0] = p[i][j][u];
      for (int k = (u - 1); k >= (1); k--) dl[++T] = p[i][j][k], L++;
      for (; S <= T; S++) {
        if (L > 2 * n) break;
        int X = dl[S - 1], Y = dl[S];
        if (l[Y][X] == -1) {
          u = 1;
          break;
        }
        for (int k = (l[Y][X]); k >= (1); k--) dl[++T] = p[Y][X][k], L++;
      }
      if (U) continue;
      x = dl[T];
      S = 1;
      T = 0;
      dl[0] = p[i][j][u + 1];
      for (int k = (u + 2); k <= (l[i][j]); k++) dl[++T] = p[i][j][k], L++;
      for (; S <= T; S++) {
        if (L > 2 * n) break;
        int X = dl[S - 1], Y = dl[S];
        if (l[X][Y] == -1) {
          u = 1;
          break;
        }
        for (int k = (1); k <= (l[X][Y]); k++) dl[++T] = p[X][Y][k], L++;
      }
      if (U) continue;
      if (L <= 2 * n) {
        R[x].push_back(dl[T]);
        Rw[x].push_back(L);
      }
    }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (p[i][j][l[i][j]] == i) {
        L = 1;
        S = 1;
        T = 0;
        u = 0;
        dl[0] = i;
        for (int k = (l[i][j] - 1); k >= (1); k--) dl[++T] = p[i][j][k], L++;
        for (; S <= T; S++) {
          if (L > 2 * n) break;
          int X = dl[S - 1], Y = dl[S];
          if (l[Y][X] == -1) {
            u = 1;
            break;
          }
          for (int k = (l[Y][X]); k >= (1); k--) dl[++T] = p[Y][X][k], L++;
        }
        if (u) continue;
        if (L <= 2 * n) {
          A[dl[T]].push_back(j);
          Aw[dl[T]].push_back(L);
        }
      }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (p[i][j][1] == j) {
        L = 1;
        S = 1;
        T = 0;
        u = 0;
        dl[0] = j;
        for (int k = (2); k <= (l[i][j]); k++) dl[++T] = p[i][j][k], L++;
        for (; S <= T; S++) {
          if (L > 2 * n) break;
          int X = dl[S - 1], Y = dl[S];
          if (l[X][Y] == -1) {
            u = 1;
            break;
          }
          for (int k = (1); k <= (l[X][Y]); k++) dl[++T] = p[X][Y][k], L++;
        }
        if (u) continue;
        if (L <= 2 * n) {
          B[i].push_back(dl[T]);
          Bw[i].push_back(L);
        }
      }
  for (int le = (0); le <= (2 * n); le++)
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (n); j++) {
        int sz;
        sz = R[j].size() - 1;
        for (int k = (0); k <= (sz); k++)
          upd(a[i][R[j][k]][le + Rw[j][k]], b[i][j][le]);
        sz = A[j].size() - 1;
        for (int k = (0); k <= (sz); k++)
          upd(b[i][A[j][k]][le + Aw[j][k]], b[i][j][le]);
        sz = B[j].size() - 1;
        for (int k = (0); k <= (sz); k++)
          upd(a[i][B[j][k]][le + Bw[j][k]], a[i][j][le]);
        sz = G[j].size() - 1;
        for (int k = (0); k <= (sz); k++)
          upd(b[i][G[j][k]][le + 1], a[i][j][le]);
      }
  for (int l = (1); l <= (2 * n); l++) {
    ans = 0;
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (n); j++) upd(ans, a[i][j][l]);
    printf("%d\n", ans);
  }
}
