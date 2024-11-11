#include <bits/stdc++.h>
using namespace std;
bool rside(int a, int b, int c) {
  if ((c < a && c > b) || (c > a && c < b))
    return true;
  else
    return false;
}
bool rect(int x1, int y1, int x2, int y2, int x3, int y3) {
  if ((x3 == x2 && rside(y1, y2, y3)) || (x3 == x1 && rside(y1, y2, y3)) ||
      (y3 == y2 && rside(x1, x2, x3)) || (y3 == y1 && rside(x1, x2, x3)))
    return true;
  else
    return false;
}
int main() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))
    cout << "1";
  else {
    if (rect(x1, y1, x2, y2, x3, y3) || rect(x2, y2, x3, y3, x1, y1) ||
        rect(x3, y3, x1, y1, x2, y2))
      cout << "2";
    else
      cout << "3";
  }
  return 0;
}
