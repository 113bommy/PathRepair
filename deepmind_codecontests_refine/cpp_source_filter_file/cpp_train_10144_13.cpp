#include <bits/stdc++.h>
using namespace std;
map<int, int> valcol;
int n, m, t, tp, tu, td;
int h[305][305];
int r1[305][305];
int r2[305][305];
int c1[305][305];
int c2[305][305];
int best_dif = -1;
int best_i1, best_i2, best_j1, best_j2;
int ifunc(int h1, int h2) { return h1 == h2 ? tp : (h1 < h2 ? tu : td); }
int iabs(int a) { return a > 0 ? a : -a; }
int main(int argc, char const *argv[]) {
  scanf("%d%d%d", &n, &m, &t);
  scanf("%d%d%d", &tp, &tu, &td);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &h[i][j]);
  for (int i = 0; i < n; ++i)
    for (int j = 1; j < m; ++j)
      r1[i][j] = r1[i][j - 1] + ifunc(h[i][j - 1], h[i][j]);
  for (int i = 0; i < n; ++i)
    for (int j = m - 2; j >= 0; --j)
      r2[i][j] = r2[i][j + 1] + ifunc(h[i][j + 1], h[i][j]);
  for (int j = 0; j < m; ++j)
    for (int i = 1; i < n; ++i)
      c1[i][j] = c1[i - 1][j] + ifunc(h[i - 1][j], h[i][j]);
  for (int j = 0; j < m; ++j)
    for (int i = n - 2; i >= 0; --i)
      c2[i][j] = c2[i + 1][j] + ifunc(h[i + 1][j], h[i][j]);
  for (int i1 = 0; i1 < n - 2; ++i1) {
    for (int i2 = i1 + 2; i2 < n; ++i2) {
      valcol.clear();
      valcol[t - ((c2[i1][0] - c2[i2][0]) - 0 - 0)] = 0;
      for (int j2 = 2; j2 < n; ++j2) {
        int val =
            r1[i1][j2] + (c1[i2][j2] - c1[i1][j2]) + (r2[i2][0] - r2[i2][j2]);
        map<int, int>::iterator it = valcol.lower_bound(val);
        int j1, dif;
        if (it == valcol.end()) {
          it--;
          j1 = it->second;
          dif = iabs(val - it->first);
        } else if (it->first == val) {
          j1 = it->second;
          dif = 0;
          printf("%d %d %d %d\n", i1 + 1, j1 + 1, i2 + 1, j2 + 1);
          return 0;
        } else if (it == valcol.begin()) {
          j1 = it->second;
          dif = iabs(val - it->first);
        } else {
          int cur_dif = iabs(val - it->first);
          int cur_col = it->second;
          it--;
          int pre_dif = iabs(val - it->first);
          int pre_col = it->second;
          if (cur_dif < pre_dif) {
            j1 = cur_col;
            dif = cur_dif;
          } else {
            j1 = pre_col;
            dif = pre_dif;
          }
        }
        if (best_dif == -1 || dif < best_dif) {
          best_dif = dif;
          best_i1 = i1;
          best_i2 = i2;
          best_j1 = j1;
          best_j2 = j2;
        }
        valcol[t - ((c2[i1][j2 - 1] - c2[i2][j2 - 1]) - r1[i1][j2 - 1] -
                    (r2[i2][0] - r2[i2][j2 - 1]))] = j2 - 1;
      }
    }
  }
  printf("%d %d %d %d\n", best_i1 + 1, best_j1 + 1, best_i2 + 1, best_j2 + 1);
  return 0;
}
