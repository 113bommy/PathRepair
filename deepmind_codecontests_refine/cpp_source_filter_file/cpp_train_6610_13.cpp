#include <bits/stdc++.h>
using namespace std;
const int MAXN = 151;
const int MAXBLOCKS = 7;
int n, m;
struct matrix {
  bool mat[MAXN][MAXN];
  unsigned int row[MAXN][MAXBLOCKS];
  unsigned int col[MAXN][MAXBLOCKS];
  matrix() {
    memset(mat, 0, sizeof mat);
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
  }
  void print() {
    for (int i = 0; i < n; ++i, printf("\n"))
      for (int j = 0; j < n; ++j) printf("%d ", mat[i][j]);
    printf("\n");
  }
  void set(int x, int y, int v) {
    if (v > 0) {
      mat[x][y] = 1;
      row[x][y / 32] |= (1U << (y % 32));
      col[y][x / 32] |= (1U << (x % 32));
    }
  }
};
matrix operator*(const matrix &A, const matrix &B) {
  matrix ret;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < MAXBLOCKS; ++k) {
        ret.set(i, j, A.row[i][k] & B.col[j][k]);
      }
  return ret;
}
matrix exp(matrix m, int pot, bool add = 1) {
  matrix ret;
  for (int i = 0; i < n; ++i) ret.set(i, i, 1);
  if (add)
    for (int i = 0; i < n; ++i) m.set(i, i, 1);
  while (pot) {
    if (pot & 1) ret = ret * m;
    m = m * m;
    pot >>= 1;
  }
  return ret;
}
struct edge {
  int x, y, d;
};
edge e[MAXN];
bool cmp(const edge &a, const edge &b) { return a.d < b.d; }
void find_solution(matrix &ans, matrix &paths, int last, int next) {
  int lo = 0;
  int hi = next - last + 1;
  while (lo < hi) {
    int mi = (lo + (hi - lo) / 2);
    matrix next = ans * exp(paths, mi);
    if (next.mat[0][n - 1])
      hi = mi;
    else
      lo = mi + 1;
  }
  printf("%d\n", last + lo);
}
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].d);
    --e[i].x;
    --e[i].y;
  }
  sort(e, e + m, cmp);
  matrix ans, paths;
  e[m].d = 2e9;
  int last = 0;
  ans.set(0, 0, 1);
  for (int i = 0; i < m; ++i) {
    ans = ans * exp(paths, e[i].d - last, 0);
    matrix paths_trans = paths;
    paths_trans.set(e[i].x, e[i].y, 1);
    matrix next = ans * exp(paths_trans, e[i + 1].d - e[i].d);
    if (next.mat[0][n - 1]) {
      find_solution(ans, paths_trans, e[i].d, e[i + 1].d);
      return 0;
    }
    paths = paths_trans;
    last = e[i].d;
  }
  printf("Impossible\n");
  return 0;
}
