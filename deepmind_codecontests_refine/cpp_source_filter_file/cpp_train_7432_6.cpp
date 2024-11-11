#include <bits/stdc++.h>
using namespace std;
int n, m, k, xa, xb, ya, yb, fi, fr, ii, e, b[110][110], c[110], qx[100010],
    qy[100010];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool a[110][110][4];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> xa >> ya >> xb >> yb;
    if (xa == xb) {
      for (int j = ya; j < yb; j++) {
        a[xa][j][0] = true;
        a[xa - 1][j][2] = true;
      }
    } else {
      for (int j = xa; j < xb; j++) {
        a[j][ya][1] = true;
        a[j][ya - 1][3] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] == 0) {
        ii++;
        b[i][j] = ii;
        fi = 0;
        fr = 1;
        qx[fi] = i;
        qy[fi] = j;
        while (fi < fr) {
          int x = qx[fi], y = qy[fi];
          fi++;
          for (k = 0; k < 4; k++) {
            if (!a[x][y][k]) {
              int xx = x + dx[k];
              int yy = y + dy[k];
              if (xx >= 0 && xx < n && yy >= 0 && yy < m && b[xx][yy] == 0) {
                b[xx][yy] = ii;
                qx[fr] = xx;
                qy[fr] = yy;
                fr++;
              }
            }
          }
        }
        c[e] = fr;
        e++;
      }
    }
  }
  sort(c, c + k + 1);
  for (int i = 0; i <= k; i++) {
    cout << c[i] << " ";
  }
  return 0;
}
