#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;
int N, M, T, tp, tu, td;
int grid[MAXN][MAXN];
int row1[MAXN][MAXN], row2[MAXN][MAXN], col1[MAXN][MAXN], col2[MAXN][MAXN];
int main() {
  scanf("%d %d %d", &N, &M, &T);
  scanf("%d %d %d", &tp, &td, &tu);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%d", &grid[i][j]);
  for (int i = 0; i < N; i++)
    for (int j = 1; j < M; j++) {
      if (grid[i][j - 1] == grid[i][j]) {
        row1[i][j] = row1[i][j - 1] + tp;
        row2[i][j] = row2[i][j - 1] + tp;
      } else if (grid[i][j - 1] < grid[i][j]) {
        row1[i][j] = row1[i][j - 1] + tu;
        row2[i][j] = row2[i][j - 1] + td;
      } else {
        row1[i][j] = row1[i][j - 1] + td;
        row2[i][j] = row2[i][j - 1] + tu;
      }
    }
  for (int j = 0; j < M; j++)
    for (int i = 1; i < N; i++) {
      if (grid[i - 1][j] == grid[i][j]) {
        col1[i][j] = col1[i - 1][j] + tp;
        col2[i][j] = col2[i - 1][j] + tp;
      } else if (grid[i - 1][j] < grid[i][j]) {
        col1[i][j] = col1[i - 1][j] + tu;
        col2[i][j] = col2[i - 1][j] + td;
      } else {
        col1[i][j] = col1[i - 1][j] + td;
        col2[i][j] = col2[i - 1][j] + tu;
      }
    }
  int best = 1000000000;
  int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
  for (int r1 = 0; r1 < N; r1++)
    for (int r2 = r1 + 2; r2 < N; r2++) {
      set<pair<int, int> > bst;
      bst.insert(make_pair(col2[r2][0] - col2[r1][0], 0));
      pair<int, int> temp =
          make_pair(col2[r2][1] - col2[r1][1] - row1[r1][1] - row2[r2][1], 1);
      for (int i = 2; i < M; i++) {
        int cur = col1[r2][i] - col1[r1][i] + row1[r1][i] + row2[r2][i];
        int need = T - cur;
        set<pair<int, int> >::iterator it =
            bst.lower_bound(make_pair(need, -1));
        if (it == bst.end()) it--;
        if (best > abs(it->first + cur - T)) {
          best = abs(it->first + cur - T);
          a1 = r1, b1 = it->second, a2 = r2, b2 = i;
        }
        if (it != bst.begin()) {
          it--;
          if (best > abs(it->first + cur - T)) {
            best = abs(it->first + cur - T);
            a1 = r1, b1 = it->second, a2 = r2, b2 = i;
          }
        }
        bst.insert(temp);
        temp =
            make_pair(col2[r2][i] - col2[r1][i] - row1[r1][i] - row2[r2][i], i);
      }
    }
  printf("%d %d %d %d\n", a1 + 1, b1 + 1, a2 + 1, b2 + 1);
  return 0;
}
