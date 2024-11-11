#include <bits/stdc++.h>
using namespace std;
bool liesOnLine(int p, int q, int r, int s) {
  int c;
  if ((r > p && s > q) || (r < p && s < q)) {
    c = q - p;
    if ((r + c) == s)
      return true;
    else
      return false;
  } else if ((r > p && s < q) || (r < p && s > q)) {
    c = q + p;
    if (s == (c - r))
      return true;
    else
      return false;
  }
}
int main(void) {
  bool check;
  int x1, y1, x2, y2, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  check = liesOnLine(x1, y1, x2, y2);
  if (x1 != x2 && y1 != y2) {
    int x_a = max(x1, x2);
    int x_b = min(x1, x2);
    int side = x_a - x_b;
    if (check) {
      if (x2 > x1 && y2 > y1) {
        x4 = x1;
        y4 = y2;
        x3 = x2;
        y3 = y1;
      } else if (x1 > x2 && y1 > y2) {
        x4 = x2;
        y4 = y1;
        x3 = x1;
        y3 = y2;
      } else if (x2 > x1 && y2 < y1) {
        x3 = x2;
        y3 = y1;
        x4 = x1;
        y4 = y2;
      } else if (x1 > x2 && y1 < y2) {
        x3 = x1;
        y3 = y2;
        x4 = x2;
        y4 = y1;
      }
    } else {
      cout << -1 << "\n";
      return 0;
    }
  } else {
    int side = 0;
    if (y1 == y2) {
      int x_a = max(x1, x2);
      int x_b = min(x1, x2);
      side = (x_a) - (x_b);
      if (y1 + side <= 1000) {
        x3 = x1;
        y3 = y1 + side;
        x4 = x2;
        y4 = y2 + side;
      } else if (y1 - side >= 1000) {
        x3 = x1;
        y3 = y1 - side;
        x4 = x2;
        y4 = y2 - side;
      } else {
        cout << -1 << "\n";
        return 0;
      }
    } else {
      int y_a = max(y1, y2);
      int y_b = min(y1, y2);
      side = y_a - y_b;
      if (x1 + side <= 1000) {
        y3 = y2;
        x3 = x2 + side;
        y4 = y1;
        x4 = x1 + side;
      } else if (x1 - side >= 1000) {
        y3 = y2;
        x3 = x1 - side;
        y4 = y1;
        x4 = x2 - side;
      } else {
        cout << -1 << "\n";
        return 0;
      }
    }
  }
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
  return 0;
}
