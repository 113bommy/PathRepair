#include <bits/stdc++.h>
using namespace std;
bool possible(int x, int y) {
  return ((x >= 2 && y >= 2) || (y >= 22) || (x >= 1 && y >= 12)) ? true
                                                                  : false;
}
int main() {
  int x, y, winner = 1;
  cin >> x >> y;
  while (possible(x, y)) {
    if (winner == 1) {
      if (x >= 2 && y >= 2) {
        x -= 2;
        y -= 2;
      } else if (x >= 1 && y >= 12) {
        x--;
        y -= 12;
      } else {
        y -= 22;
      }
    } else {
      if (y >= 22) {
        y -= 22;
      } else if (y >= 12 && x >= 1) {
        y -= 12;
        x -= 1;
      } else {
        x -= 2;
        y -= 2;
      }
    }
    winner = (winner == 0) ? 1 : 0;
  }
  cout << ((winner == 1) ? "Hanako" : "Ciel") << endl;
  return 0;
}
