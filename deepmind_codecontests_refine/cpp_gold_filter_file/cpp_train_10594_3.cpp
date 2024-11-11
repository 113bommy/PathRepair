#include <bits/stdc++.h>
using namespace std;
bool isIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                 int y4) {
  double t1 = (y3 - y4) * (x1 - x3) + (x4 - x3) * (y1 - y3);
  double t2 = (x4 - x3) * (y1 - y2) - (x1 - x2) * (y4 - y3);
  double r1 = t1 / t2;
  double f1 = (y1 - y2) * (x1 - x3) + (x2 - x1) * (y1 - y3);
  double f2 = (x4 - x3) * (y1 - y2) - (x1 - x2) * (y4 - y3);
  double r2 = f1 / f2;
  if (r1 >= 0 && r1 <= 1 && r2 >= 0 && r2 <= 1) {
    return true;
  }
  return false;
}
double isInside(int x0, int y0, int x1, int y1, int x2, int y2) {
  double num = (y2 - y1) * x0 - (x2 - x1) * y0 + x2 * y1 - y2 * x1;
  num = abs(num);
  double den = sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
  return num / den;
}
int main() {
  int first[4][2];
  int second[4][2];
  int minX = 200;
  int maxY = -200;
  int minY = 200;
  int maxX = -200;
  int min1X = 200;
  int max1X = -200;
  int min2Y = 200;
  int max2Y = -200;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> first[i][j];
      if (j == 0) {
        minX = min(minX, first[i][j]);
        maxX = max(maxX, first[i][j]);
      } else {
        minY = min(minY, first[i][j]);
        maxY = max(maxY, first[i][j]);
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> second[i][j];
      if (j == 0) {
        min1X = min(min1X, second[i][j]);
        max1X = max(max1X, second[i][j]);
      } else {
        min2Y = min(min2Y, second[i][j]);
        max2Y = max(max2Y, second[i][j]);
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    if (second[i][0] >= minX && second[i][0] <= maxX && second[i][1] >= minY &&
        second[i][1] <= maxY) {
      cout << "YES";
      return 0;
    }
    if (isInside(first[i][0], first[i][1], second[0][0], second[0][1],
                 second[2][0], second[2][1]) +
            isInside(first[i][0], first[i][1], second[1][0], second[1][1],
                     second[3][0], second[3][1]) <=
        (max2Y - min2Y) / 2) {
      cout << "YES";
      return 0;
    }
  }
  for (int i = 0; i < 4; i++) {
    int j = (i + 1) % 4;
    for (int ii = 0; ii < 4; ii++) {
      int jj = (ii + 1) % 4;
      if (isIntersect(first[i][0], first[i][1], first[j][0], first[j][1],
                      second[ii][0], second[ii][1], second[jj][0],
                      second[jj][1])) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
