#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, g[2505][2505], h, i, j, k;
char w[2505];
int H[2505][2505];
int an;
int Sigma(int x1, int y1, int x2, int y2) {
  return H[x2][y2] - H[x2][y1 - 1] - H[x1 - 1][y2] + H[x1 - 1][y1 - 1];
}
void FZ(int x1, int y1, int x2, int y2) {
  int ii, jj, kk;
  int tmp[2][10];
  int mid;
  if (x1 == x2) {
    for (ii = y1; ii <= y2; ii++)
      for (jj = ii; jj <= y2; jj++)
        if (Sigma(x1, ii, x2, jj) == c) an++;
    return;
  }
  if (y1 == y2) {
    for (ii = x1; ii <= x2; ii++)
      for (jj = ii; jj <= x2; jj++)
        if (Sigma(ii, y1, jj, y2) == c) an++;
    return;
  }
  if (x2 - x1 >= y2 - y1) {
    mid = (x1 + x2) >> 1;
    for (ii = y1; ii <= y2; ii++) {
      for (kk = 0; kk <= c; kk++) tmp[0][kk] = 0, tmp[1][kk] = 1;
      for (jj = y2; jj >= ii; jj--) {
        for (kk = 0; kk <= c; kk++) {
          while (mid - tmp[0][kk] >= x1 &&
                 Sigma(mid - tmp[0][kk], ii, mid, jj) <= kk)
            ++tmp[0][kk];
          while (mid + tmp[1][kk] <= x2 &&
                 Sigma(mid + 1, ii, mid + tmp[1][kk], jj) <= kk)
            ++tmp[1][kk];
        }
        for (kk = 0; kk <= c; kk++) {
          int cc = tmp[0][kk];
          int dd = tmp[1][c - kk];
          if (kk != 0) cc -= tmp[0][kk - 1];
          if (c - kk != 0)
            dd -= tmp[1][c - kk - 1];
          else
            dd--;
          an += cc * dd;
        }
      }
    }
    FZ(x1, y1, mid, y2);
    FZ(mid + 1, y1, x2, y2);
  } else {
    mid = (y1 + y2) >> 1;
    for (ii = x1; ii <= x2; ii++) {
      for (kk = 0; kk <= c; kk++) tmp[0][kk] = 0, tmp[1][kk] = 1;
      for (jj = x2; jj >= ii; jj--) {
        for (kk = 0; kk <= c; kk++) {
          while (mid - tmp[0][kk] >= y1 &&
                 Sigma(ii, mid - tmp[0][kk], jj, mid) <= kk)
            ++tmp[0][kk];
          while (mid + tmp[1][kk] <= y2 &&
                 Sigma(ii, mid + 1, jj, mid + tmp[1][kk]) <= kk)
            ++tmp[1][kk];
        }
        for (kk = 0; kk <= c; kk++) {
          int cc = tmp[0][kk];
          int dd = tmp[1][c - kk];
          if (kk != 0) cc -= tmp[0][kk - 1];
          if (c - kk != 0)
            dd -= tmp[1][c - kk - 1];
          else
            --dd;
          an += cc * dd;
        }
      }
    }
    FZ(x1, y1, x2, mid);
    FZ(x1, mid + 1, x2, y2);
  }
}
int main() {
  cin >> a >> b >> c;
  for (i = 1; i <= a; i++) {
    scanf("%s", w + 1);
    for (j = 1; j <= b; j++) g[i][j] = w[j] - '0';
  }
  for (i = 1; i <= a; i++)
    for (j = 1; j <= b; j++)
      H[i][j] = H[i - 1][j] + H[i][j - 1] - H[i - 1][j - 1] + g[i][j];
  FZ(1, 1, a, b);
  cout << an << endl;
  return 0;
}
