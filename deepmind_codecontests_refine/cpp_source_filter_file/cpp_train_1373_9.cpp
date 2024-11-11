#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  int x5, y5, x6, y6;
  int f = 0;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  cin >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
  if (x3 <= x1 && y3 <= y1 && x4 >= x2 && y4 >= y2) {
    f = 1;
  } else if (x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y2) {
    f = 1;
  } else if (x3 <= x1 && y3 <= y2 && x4 >= x2 && y4 >= y2) {
    if (x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y3) {
      f = 1;
    }
  } else if (x3 <= x1 && y3 <= y1 && x4 >= x2 && y4 >= y1) {
    if (x5 <= x1 && y5 <= y3 && x6 >= x2 && y6 >= y3) {
      f = 1;
    }
  } else if (x3 <= x2 && y3 <= y1 && x4 >= x2 && y4 >= y2) {
    if (x5 <= x3 && y5 <= y1 && x6 >= x2 && y6 >= y2) {
      f = 1;
    }
  } else if (x3 <= x1 && y3 <= y1 && x4 >= x1 && y4 >= y2) {
    if (x5 <= x4 && y5 <= y1 && x6 >= x2 && y6 >= y2) {
      f = 1;
    }
  }
  if (f == 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
