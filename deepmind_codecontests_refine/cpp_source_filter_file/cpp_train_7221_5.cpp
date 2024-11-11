#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5][5], x, y;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        x = i;
        y = j;
      }
    }
  }
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; j++) {
      if (a[i][j] == 1) {
        x = i;
        y = j;
      }
    }
  }
  int swaps = 0;
  for (int i = 0; i < 5; ++i) {
    if (x == 2) {
      break;
    } else if (x > 3) {
      x--;
    } else {
      x++;
    }
    swaps++;
  }
  for (int i = 0; i < 5; ++i) {
    if (y == 2) {
      break;
    } else if (y > 3) {
      y--;
    } else {
      y++;
    }
    swaps++;
  }
  cout << swaps << endl;
}
