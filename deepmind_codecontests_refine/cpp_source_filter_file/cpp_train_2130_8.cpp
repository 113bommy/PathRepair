#include <bits/stdc++.h>
using namespace std;
long long morcha = 0, i, j, w[20], mi, a[20][5], b[10][5];
void go(long long z) {
  if (morcha == 1) return;
  for (long long l = 1; l <= 6; l++) {
    if (morcha == 1) return;
    w[z] = l;
    if (z < 8)
      go(z + 1);
    else {
      mi = 3000000000000;
      long long x1, x2, x3, r1 = 0, r2 = 0, r3 = 0;
      for (long long i = 1; i <= 8; i++)
        for (long long j = i + 1; j <= 8; j++) {
          x1 = a[i][b[w[i]][1]] - a[j][b[w[j]][1]];
          x2 = a[i][b[w[i]][2]] - a[j][b[w[j]][2]];
          x3 = a[i][b[w[i]][3]] - a[j][b[w[j]][3]];
          x1 *= x1;
          x2 *= x2;
          x3 *= x3;
          mi = min(mi, x1 + x2 + x3);
        }
      for (long long i = 1; i <= 8; i++)
        for (long long j = i + 1; j <= 8; j++) {
          x1 = a[i][b[w[i]][1]] - a[j][b[w[j]][1]];
          x2 = a[i][b[w[i]][2]] - a[j][b[w[j]][2]];
          x3 = a[i][b[w[i]][3]] - a[j][b[w[j]][3]];
          x1 *= x1;
          x2 *= x2;
          x3 *= x3;
          x1 = x1 + x2 + x3;
          if (x1 == mi) r1++;
          if (x1 == 2 * mi) r2++;
          if (x1 == 3 * mi) r3++;
        }
      if (r1 == 12 && r2 == 12 && r3 == 4) {
        cout << "YES" << endl;
        for (long long i = 1; i <= 8; i++)
          cout << a[i][b[w[i]][1]] << " " << a[i][b[w[i]][2]] << " "
               << a[i][b[w[i]][3]] << endl;
        morcha = 1;
      }
      if (morcha == 1) return;
    }
  }
}
int main() {
  for (i = 1; i <= 8; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
  b[1][1] = 1;
  b[1][2] = 2;
  b[1][3] = 3;
  b[2][1] = 1;
  b[2][2] = 3;
  b[2][3] = 2;
  b[3][1] = 2;
  b[3][2] = 1;
  b[3][3] = 3;
  b[4][1] = 2;
  b[4][2] = 3;
  b[4][3] = 1;
  b[5][1] = 3;
  b[5][2] = 1;
  b[5][3] = 2;
  b[6][1] = 3;
  b[6][2] = 2;
  b[6][3] = 1;
  w[1] = 1;
  go(2);
  if (morcha == 0) cout << "NO" << endl;
}
