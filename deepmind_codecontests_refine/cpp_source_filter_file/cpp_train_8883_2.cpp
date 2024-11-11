#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int i, j, k, a, b;
  int S12, S13, S14;
  int S23, S24;
  int S34;
  int mat[7][7];
  int v[7], c0, c1;
  int vv[7];
  cin >> S12 >> S13 >> S14;
  cin >> S23 >> S24;
  cin >> S34;
  for (i = 0; i < 100000 * 10; i++) {
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[0][2] = 1;
    mat[0][3] = 1;
    mat[0][4] = 1;
    mat[0][5] = 1;
    mat[0][6] = 1;
    mat[1][0] = 0;
    mat[1][1] = 0;
    mat[1][2] = 0;
    mat[1][3] = 1;
    mat[1][4] = 1;
    mat[1][5] = 1;
    mat[1][6] = 1;
    mat[2][0] = 1;
    mat[2][1] = 1;
    mat[2][2] = 1;
    mat[2][3] = 0;
    mat[2][4] = 0;
    mat[2][5] = 1;
    mat[2][6] = 1;
    mat[3][0] = 0;
    mat[3][1] = 0;
    mat[3][2] = 1;
    mat[3][3] = 0;
    mat[3][4] = 1;
    mat[3][5] = 0;
    mat[3][6] = 1;
    mat[4][0] = 0;
    mat[4][1] = 1;
    mat[4][2] = 1;
    mat[4][3] = 1;
    mat[4][4] = 1;
    mat[4][5] = 0;
    mat[4][6] = 0;
    mat[5][0] = 1;
    mat[5][1] = 0;
    mat[5][2] = 1;
    mat[5][3] = 1;
    mat[5][4] = 0;
    mat[5][5] = 1;
    mat[5][6] = 0;
    mat[6][0] = 1;
    mat[6][1] = 1;
    mat[6][2] = 0;
    mat[6][3] = 0;
    mat[6][4] = 1;
    mat[6][5] = 1;
    mat[6][6] = 0;
    v[0] = i;
    v[1] = S12;
    v[2] = S13;
    v[3] = S14;
    v[4] = S23;
    v[5] = S24;
    v[6] = S34;
    for (j = 0; j < 7; j++) {
      if (mat[j][j] == 0) {
        for (k = j + 1; k < 7; k++) {
          if (mat[k][j]) break;
        }
        for (a = 0; a < 7; a++) {
          swap(mat[j][a], mat[k][a]);
        }
        swap(v[j], v[k]);
      }
      c0 = mat[j][j];
      for (k = j + 1; k < 7; k++) {
        if (mat[k][j]) {
          c1 = mat[k][j];
          for (a = 0; a < 7; a++) {
            mat[k][a] *= c0;
            mat[k][a] -= mat[j][a] * c1;
          }
          v[k] *= c0;
          v[k] -= v[j] * c1;
        }
      }
    }
    bool ok = true;
    for (j = 6; j >= 0; j--) {
      vv[j] = v[j];
      for (k = 6; k > j; k--) {
        v[j] -= (vv[k] * mat[j][k]);
      }
      if (abs(vv[j]) % abs(mat[j][j])) {
        ok = false;
        break;
      }
      vv[j] = v[j] / mat[j][j];
      if (vv[j] < 0) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    break;
  }
  if (i == 100000 * 10) {
    printf("-1\n");
  } else {
    int cnt;
    char tbl[7][4] = {'a', 'a', 'a', 'b', 'a', 'a', 'b', 'a', 'a', 'a',
                      'b', 'b', 'a', 'b', 'a', 'a', 'a', 'b', 'a', 'b',
                      'a', 'b', 'b', 'a', 'a', 'b', 'b', 'b'};
    char ret[4][i + 10];
    cnt = 0;
    for (j = 0; j < 7; j++) {
      memset(&ret[0][cnt], tbl[j][0], vv[j]);
      memset(&ret[1][cnt], tbl[j][1], vv[j]);
      memset(&ret[2][cnt], tbl[j][2], vv[j]);
      memset(&ret[3][cnt], tbl[j][3], vv[j]);
      cnt += vv[j];
    }
    ret[0][cnt] = '\0';
    ret[1][cnt] = '\0';
    ret[2][cnt] = '\0';
    ret[3][cnt] = '\0';
    printf("%d\n", i);
    printf("%s\n", ret[0]);
    printf("%s\n", ret[1]);
    printf("%s\n", ret[2]);
    printf("%s\n", ret[3]);
  }
  return 0;
}
