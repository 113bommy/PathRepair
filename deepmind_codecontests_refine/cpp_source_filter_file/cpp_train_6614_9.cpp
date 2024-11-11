#include <bits/stdc++.h>
using namespace std;
pair<int, int> mp[101][101];
int mat[101][101];
int n, m;
void shiftLeft(int r) {
  for (int i = 0; i < n - 1; ++i) swap(mp[r][i], mp[r][(i - 1 + n) % n]);
}
void shiftUp(int c) {
  for (int i = 0; i < m - 1; ++i) swap(mp[i][c], mp[(i - 1 + m) % m][c]);
}
int main() {
  int q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      mp[i][j] = {i, j};
    }
  }
  while (q--) {
    int t, x, y, v;
    scanf("%d", &t);
    if (t == 3) {
      scanf("%d%d%d", &x, &y, &v);
      pair<int, int> p = mp[x - 1][y - 1];
      mat[p.first][p.second] = v;
    } else {
      scanf("%d", &x);
      if (t == 1)
        shiftLeft(x - 1);
      else
        shiftUp(x - 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  return 0;
}
