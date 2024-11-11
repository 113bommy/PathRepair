#include <bits/stdc++.h>
using namespace std;
int x[8] = {-1, -2, -2, -1, +1, +2, +1, +2};
int y[8] = {-2, -1, +1, +2, -2, -1, +2, +1};
int b[10][10];
int main() {
  string r, k;
  cin >> r >> k;
  int xr, yr, xk, yk;
  xr = r[0] - 'a' + 1;
  yr = r[1] - '0';
  xk = k[0] - 'a' + 1;
  yk = k[1] - '0';
  b[yk][xk] = -1;
  for (int i = 1; i <= 8; i++) {
    b[yr][i] = -1;
    b[i][xr] = -1;
  }
  int v, u;
  for (int i = 0; i < 8; i++) {
    u = yr + x[i];
    v = xr + y[i];
    if (u >= 1 && u <= 8 && v >= 1 && v <= 8) b[u][v] = -1;
    u = yk + x[i];
    v = xk + y[i];
    if (u >= 1 && u <= 8 && v >= 1 && v <= 8) b[u][v] = -1;
  }
  int c = 0;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (b[i][j] != -1) c++;
    }
  }
  cout << c;
}
