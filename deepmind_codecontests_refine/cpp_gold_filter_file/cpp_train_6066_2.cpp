#include <bits/stdc++.h>
using namespace std;
long long x[4][2];
long long y[4][2];
bool onsegm(long long x1, long long y1, long long x2, long long y2,
            long long x3, long long y3) {
  return x3 >= min(x1, x2) && x3 <= max(x1, x2) && y3 >= min(y1, y2) &&
         y3 <= max(y1, y2) &&
         (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) == 0;
}
bool checkang(long long x1, long long y1, long long x2, long long y2,
              long long x3, long long y3) {
  return (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) >= 0 &&
         (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) != 0;
}
bool checkdist(long long x1, long long y1, long long x2, long long y2,
               long long x3, long long y3) {
  if (x1 == x2) {
    return abs(y3 - y1) <= 4 * abs(y3 - y2) && abs(y3 - y2) <= 4 * abs(y3 - y1);
  } else {
    return abs(x3 - x1) <= 4 * abs(x3 - x2) && abs(x3 - x2) <= 4 * abs(x3 - x1);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 2; ++j) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        x[i][j] = xx;
        y[i][j] = yy;
      }
    }
    bool common = false;
    for (int i1 = 0; i1 < 3; ++i1) {
      for (int j1 = 0; j1 < 2; ++j1) {
        for (int i2 = i1 + 1; i2 < 3; ++i2) {
          for (int j2 = 0; j2 < 2; ++j2) {
            if (x[i1][j1] == x[i2][j2] && y[i1][j1] == y[i2][j2]) {
              common = true;
              for (int j = 0; j < 2; ++j) {
                swap(x[0][j], x[i1][j]);
                swap(y[0][j], y[i1][j]);
              }
              swap(x[0][0], x[0][j1]);
              swap(y[0][0], y[0][j1]);
              for (int j = 0; j < 2; ++j) {
                swap(x[1][j], x[i2][j]);
                swap(y[1][j], y[i2][j]);
              }
              swap(x[1][0], x[1][j2]);
              swap(y[1][0], y[1][j2]);
              break;
            }
          }
          if (common) break;
        }
        if (common) break;
      }
      if (common) break;
    }
    if (!onsegm(x[0][0], y[0][0], x[0][1], y[0][1], x[2][0], y[2][0])) {
      swap(x[2][0], x[2][1]);
      swap(y[2][0], y[2][1]);
    }
    if (common &&
        checkang(x[0][0], y[0][0], x[0][1], y[0][1], x[1][1], y[1][1]) &&
        onsegm(x[0][0], y[0][0], x[0][1], y[0][1], x[2][0], y[2][0]) &&
        onsegm(x[1][0], y[1][0], x[1][1], y[1][1], x[2][1], y[2][1]) &&
        checkdist(x[0][0], y[0][0], x[0][1], y[0][1], x[2][0], y[2][0]) &&
        checkdist(x[1][0], y[1][0], x[1][1], y[1][1], x[2][1], y[2][1])) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
