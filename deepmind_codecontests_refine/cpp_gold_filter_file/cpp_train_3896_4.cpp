#include <bits/stdc++.h>
using namespace std;
int r, c, x, y, d[8][8];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> r >> c >> x >> y;
  r--;
  c--;
  x--;
  y--;
  cout << (r != x) + (c != y) << "\n";
  if ((r + c) % 2 != (x + y) % 2) {
    cout << 0 << "\n";
  } else {
    int o = 0;
    int i = r, j = c;
    while (i >= 0 && j >= 0) {
      if (i == x && j == y) {
        o = 1;
        break;
      }
      i--;
      j--;
    }
    i = r, j = c;
    while (i < 8 && j >= 0) {
      if (i == x && j == y) {
        o = 1;
        break;
      }
      i++;
      j--;
    }
    i = r, j = c;
    while (i < 8 && j < 8) {
      if (i == x && j == y) {
        o = 1;
        break;
      }
      i++;
      j++;
    }
    i = r, j = c;
    while (i >= 0 && j < 8) {
      if (i == x && j == y) {
        o = 1;
        break;
      }
      i--;
      j++;
    }
    if (o) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
  cout << max(abs(r - x), abs(c - y)) << "\n";
  return 0;
}
