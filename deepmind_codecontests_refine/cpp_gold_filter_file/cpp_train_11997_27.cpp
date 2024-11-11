#include <bits/stdc++.h>
using namespace std;
int r, c, n, sz;
pair<int, int> pnt[10000][5];
int gr[60][60];
char mat[60][60];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main() {
  while (cin >> r >> n) {
    sz = 0;
    for (int i = 0; i < r; i++) scanf("%s", mat[i]);
    c = strlen(mat[0]);
    memset(gr, -1, sizeof gr);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (mat[i][j] == '0' || gr[i][j] != -1) continue;
        int ni = i, nj = j;
        while (ni + 1 < r && mat[ni + 1][j] == mat[i][j]) ni++;
        while (nj + 1 < c && mat[i][nj + 1] == mat[i][j]) nj++;
        for (int a = i; a <= ni; a++)
          for (int b = j; b <= nj; b++) gr[a][b] = sz;
        pnt[sz][0] = pair<int, int>(i, j);
        pnt[sz][1] = pair<int, int>(i, nj);
        pnt[sz][2] = pair<int, int>(ni, nj);
        pnt[sz][3] = pair<int, int>(ni, j);
        sz++;
      }
    }
    int x = 0, y = 0;
    int d = 1, bc = 0;
    for (int i = 0; i < n; i++) {
      int g = gr[x][y];
      int p = (d + bc) & 3;
      int nx = pnt[g][p].first + dir[d][0];
      int ny = pnt[g][p].second + dir[d][1];
      if (nx >= 0 && nx < r && ny >= 0 && ny < c && gr[nx][ny] != -1) {
        x = nx;
        y = ny;
      } else {
        if (bc == 1) d = (d + 1) & 3;
        bc = 1 - bc;
      }
    }
    cout << mat[x][y] << endl;
  }
  return 0;
}
