#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int A[2005];
  int maxX = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    maxX += A[i];
  }
  char B[2005][2005];
  memset(B, 0, sizeof(B));
  int x = -1;
  int y = 1000;
  bool up = true;
  int maxY = 1000;
  int minY = 1000;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < A[i]; ++j) {
      if (up) {
        ++x;
        --y;
        B[y][x] = '/';
        if (maxY > y) maxY = y;
      } else {
        ++x;
        ++y;
        B[y][x] = '\\';
        if (minY < y) minY = y;
      }
    }
    if (up)
      --y;
    else
      ++y;
    up ^= true;
  }
  for (int i = maxY; i <= minY; ++i) {
    for (int j = 0; j < maxX; ++j) {
      if (B[i][j] == 0)
        cout << " ";
      else
        cout << B[i][j];
    }
    cout << endl;
  }
  return 0;
}
