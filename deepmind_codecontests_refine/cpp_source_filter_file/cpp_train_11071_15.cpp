#include <bits/stdc++.h>
using namespace std;
double len(int x1, int stupid_cmath, int x2, int y2) {
  return sqrt(0.0 + ((x1 - x2) * (x1 - x2)) +
              ((stupid_cmath - y2) * (stupid_cmath - y2)));
}
int main() {
  int a, b, c, d, mm[4][3], i, j;
  double l;
  cin >> a >> b >> c >> d;
  mm[0][0] = a;
  mm[0][1] = b;
  mm[0][2] = c;
  mm[1][0] = a;
  mm[1][1] = b;
  mm[1][2] = d;
  cin >> a >> b >> c >> d;
  mm[2][0] = a;
  mm[2][1] = b;
  mm[2][2] = c;
  mm[3][0] = a;
  mm[3][1] = b;
  mm[3][2] = d;
  a = 0;
  for (i = 0; i < 2; ++i) {
    for (j = 2; j < 4; ++j) {
      l = len(mm[i][0], mm[i][1], mm[j][0], mm[j][1]);
      if ((l > (((mm[i][2]) > (mm[j][2])) ? (mm[i][2]) : (mm[j][2])) &&
           l < mm[i][2] + mm[j][2]) ||
          (l <= (((mm[i][2]) > (mm[j][2])) ? (mm[i][2]) : (mm[j][2])) &&
           l + (((mm[i][2]) < (mm[j][2])) ? (mm[i][2]) : (mm[j][2])) >
               (((mm[i][2]) > (mm[j][2])) ? (mm[i][2]) : (mm[j][2]))))
        break;
    }
    if (j == 4) {
      ++a;
      if (l < mm[i][2] && mm[2][2] < mm[i][2] && mm[3][2] > mm[i][2]) --a;
      if (l > mm[i][2] && mm[2][2] < l - mm[i][2] && mm[3][2] > l + mm[i][2])
        --a;
    }
  }
  for (i = 2; i < 4; ++i) {
    for (j = 0; j < 2; ++j) {
      l = len(mm[i][0], mm[i][1], mm[j][0], mm[j][1]);
      if ((l > (((mm[i][2]) > (mm[j][2])) ? (mm[i][2]) : (mm[j][2])) &&
           l < mm[i][2] + mm[j][2]) ||
          (l <= (((mm[i][2]) > (mm[j][2])) ? (mm[i][2]) : (mm[j][2])) &&
           l + (((mm[i][2]) < (mm[j][2])) ? (mm[i][2]) : (mm[j][2])) >
               (((mm[i][2]) > (mm[j][2])) ? (mm[i][2]) : (mm[j][2]))))
        break;
    }
    if (j == 2) {
      ++a;
      if (l < mm[i][2] && mm[0][2] < mm[i][2] && mm[1][2] > mm[i][2]) --a;
      if (l > mm[i][2] && mm[0][2] < l - mm[i][2] && mm[1][2] > l + mm[i][2])
        --a;
    }
  }
  cout << a;
  return 0;
}
