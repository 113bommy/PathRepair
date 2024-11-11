#include <bits/stdc++.h>
using namespace std;
char matrix[1005][2 * 1005];
bool xs[1005], ys[2 * 1005];
int valX[1005], valY[1005];
void Draw(int x1, int y1, int x2, int y2) {
  if (y2 > y1) {
    for (int(i) = x1; (i) < (x2); i++) {
      ys[y1] = true;
      matrix[i][y1++] = '\\';
      xs[i] = true;
    }
  } else {
    for (int(i) = x1; (i) < (x2); i++) {
      matrix[i][--y1] = '/';
      xs[i] = true;
      ys[y1] = true;
    }
  }
}
int main() {
  for (int(i) = 0; (i) < (1005); i++)
    for (int(j) = 0; (j) < (2 * 1005); j++) matrix[i][j] = ' ';
  for (int(i) = 0; (i) < (1005); i++) xs[i] = false;
  for (int(i) = 0; (i) < (2 * 1005); i++) ys[i] = false;
  int n;
  cin >> n;
  int tmp, sign = 1, xtmp = 0, ytmp = 0;
  for (int(i) = 0; (i) < (n); i++) {
    cin >> tmp;
    xtmp += tmp;
    ytmp += tmp * sign;
    sign *= -1;
    valX[i + 1] = xtmp;
    valY[i + 1] = ytmp;
  }
  valX[0] = 0;
  valY[0] = 0;
  for (int(i) = 0; (i) < (n); i++) {
    Draw(valX[i], 1005 - valY[i], valX[i + 1], 1005 - valY[i + 1]);
  }
  int ymin = 0;
  for (int(i) = 0; (i) < (2 * 1005); i++) {
    if (ys[i]) {
      ymin = i;
      break;
    }
  }
  int ymax = 0;
  for (int(i) = ymin; (i) < (2 * 1005); i++) {
    if (ys[i]) ymax = i;
  }
  int xmax = 0;
  for (int(i) = 0; (i) < (1005); i++) {
    if (xs[i]) xmax = i;
  }
  for (int y = ymin; y <= ymax; y++) {
    for (int x = 0; x <= xmax; x++) {
      cout << matrix[x][y];
    }
    cout << endl;
  }
  return 0;
}
