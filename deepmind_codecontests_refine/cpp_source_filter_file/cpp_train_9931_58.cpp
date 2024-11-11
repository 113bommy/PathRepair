#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1610][1610], b[1610][1610], c[1610][1610];
int v1[1610][1610], v2[1610][1610];
int q[2560010], t;
int Q[2560010][2], Qh, Qt;
int q2[2560010][2], q2h, q2t;
inline int Check(int x, int y) {
  for (int i = -4; i <= 4; ++i)
    for (int j = -4; j <= 4; ++j)
      if (a[x + i][y + j] != 1) return 0;
  return 1;
}
void Init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) b[i][j] = Check(i, j);
}
void Solve() {
  int x, y;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (!v1[i][j] && a[i][j]) {
        ++t;
        v1[i][j] = 1;
        Qh = 0;
        Qt = 1;
        Q[1][0] = i;
        Q[1][1] = j;
        while (Qh < Qt) {
          x = Q[++Qh][0], y = Q[Qh][1];
          for (int i = -1; i <= 1; ++i)
            for (int j = -1; j <= 1; ++j)
              if (a[x + i][y + j] == 1 && !v1[x + i][y + j]) {
                v1[x + i][y + j] = 1;
                Q[++Qt][0] = x + i;
                Q[Qt][1] = y + j;
              }
        }
        for (int id = 1; id <= Qt; ++id) {
          int p = 0;
          for (int i = -5; i <= 5; ++i)
            for (int j = -5; j <= 5; ++j)
              if (b[Q[id][0] + i][Q[id][1] + j]) ++p;
          if (p < 1) c[Q[id][0]][Q[id][1]] = 1;
        }
        for (int id = 1; id <= Qt; ++id)
          if (c[Q[id][0]][Q[id][1]] && !v2[Q[id][0]][Q[id][1]]) {
            ++q[t];
            x = Q[id][0];
            y = Q[id][1];
            v2[x][y] = 1;
            q2h = 0;
            q2t = 1;
            q2[1][0] = x;
            q2[1][1] = y;
            while (q2h < q2t) {
              x = q2[++q2h][0];
              y = q2[q2h][1];
              for (int i = -2; i <= 2; ++i)
                for (int j = -2; j <= 2; ++j)
                  if (c[x + i][y + j] && !v2[x + i][y + j]) {
                    v2[x + i][y + j] = 1;
                    q2[++q2t][0] = x + i;
                    q2[q2t][1] = y + j;
                  }
            }
          }
      }
  sort(q + 1, q + t + 1);
  printf("%d\n", t);
  for (int i = 1; i <= t - 1; ++i) printf("%d ", q[i]);
  printf("%d\n", q[t]);
}
int main() {
  Init();
  Solve();
  return 0;
}
