#include <bits/stdc++.h>
using namespace std;
int x, y;
string prog[50];
int iter[50 * 50][4][2];
int inci[4] = {0, -1, 0, 1};
int incj[4] = {1, 0, -1, 0};
void advance(int i, int j, int &ii, int &jj, int dir) {
  char color = prog[i][j];
  int iii = i, jjj = j;
  while (true) {
    iii += inci[dir];
    jjj += incj[dir];
    if (iii < 0 || iii >= y || jjj < 0 || jjj >= x || prog[iii][jjj] != color)
      break;
    i = iii;
    j = jjj;
  }
  ii = i;
  jj = j;
}
int main(int narg, char **arg) {
  int n;
  cin >> y >> n;
  for (int i = 0; i < y; i++) cin >> prog[i];
  x = prog[0].size();
  memset(iter, 0xff, sizeof(iter));
  int i = 0, j = 0;
  int loop = 0, dp = 0, cp = 0, period = -1;
  while (true) {
    if (loop == n) {
      cout << prog[i][j] << endl;
      break;
    }
    int bp = i * x + j;
    if (iter[bp][dp][cp] >= 0 && period < 0) {
      period = loop - iter[bp][dp][cp];
      n = loop + ((n - loop) % period);
      if (loop == n) {
        cout << prog[i][j] << endl;
        break;
      }
    } else {
      iter[bp][dp][cp] = loop;
    }
    int ii, jj;
    advance(i, j, ii, jj, dp);
    advance(ii, jj, ii, jj, cp ? (dp - 1) & 3 : (dp + 1) & 3);
    i = ii;
    j = jj;
    ii = i + inci[dp];
    jj = j + incj[dp];
    if (ii < 0 || ii >= y || jj < 0 || jj >= x || prog[ii][jj] == '0') {
      if (!cp)
        cp = 1;
      else {
        cp = 0;
        dp = (dp - 1) & 3;
      }
    } else {
      i = ii;
      j = jj;
    }
    loop++;
  }
  return 0;
}
