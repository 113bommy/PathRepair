#include <bits/stdc++.h>
using namespace std;
const int N = 111;
const int MOVE[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int n, m, a, b, c;
int mat[N][N];
void check(int a, int b, int c) {
  if (a < 0 || b < 0 || c < 0) {
    puts("IMPOSSIBLE");
    exit(0);
  }
}
int getColor(int x1, int y1, int x2, int y2) {
  int used = 0;
  for (int i = x1; i <= x2; ++i)
    for (int j = y1; j <= y2; ++j)
      for (int k = 0; k < 4; ++k) {
        int x = i + MOVE[k][0];
        int y = j + MOVE[k][1];
        if (mat[x][y]) used |= 1 << mat[x][y] - 1;
      }
  for (int i = 0; i < 26; ++i)
    if (~used >> i & 1) return i + 1;
  assert(false);
}
int main() {
  cin >> n >> m >> a >> b >> c;
  if ((n & 1) && (m & 1)) return puts("IMPOSSIBLE"), 0;
  int tn = n, tm = m;
  if (n & 1) {
    int add = 1;
    for (int j = 1; j <= m; j += 2)
      mat[tn][j] = mat[tn][j + 1] = 1 + (add ^= 1);
    tn--;
    check(a -= m / 2, b, c);
  } else if (m & 1) {
    int add = 1;
    for (int i = 1; i <= n; i += 2)
      mat[i][tm] = mat[i + 1][tm] = 1 + (add ^= 1);
    tm--;
    check(a, b -= n / 2, c);
  }
  for (int i = 1; i <= tn; i += 2)
    for (int j = 1; j <= tm; j += 2) {
      if (a > 1) {
        a -= 2;
        mat[i][j] = mat[i][j + 1] = getColor(i, j, i, j + 1);
        mat[i + 1][j] = mat[i + 1][j + 1] = getColor(i + 1, j, i + 1, j + 1);
        continue;
      }
      if (b > 1) {
        b -= 2;
        mat[i][j] = mat[i + 1][j] = getColor(i, j, i + 1, j);
        mat[i][j + 1] = mat[i + 1][j + 1] = getColor(i, j + 1, i + 1, j + 1);
        continue;
      }
      if (c > 0) {
        c--;
        mat[i][j] = mat[i][j + 1] = mat[i + 1][j] = mat[i + 1][j + 1] =
            getColor(i, j, i + 1, j + 1);
        continue;
      }
      check(-1, 0, 0);
    }
  for (int i = 1; i <= n; ++i, puts(""))
    for (int j = 1; j <= m; ++j) putchar(char(mat[i][j] + 'a' - 1));
}
