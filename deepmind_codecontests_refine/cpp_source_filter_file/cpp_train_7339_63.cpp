#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  char a[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> a[i][j];
    }
  }
  int wx = 10, wy, bx = -1, by;
  int flag = 1;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (a[j][i] == 'B') break;
      if (a[j][i] == 'W') {
        wx = min(wx, j);
        break;
      }
    }
  }
  for (int i = 7; i >= 0; i--) {
    for (int j = 7; j >= 0; j--) {
      if (a[j][i] == 'W') break;
      if (a[j][i] == 'B') {
        bx = max(bx, j);
        break;
      }
    }
  }
  if (8 - bx < wx)
    cout << "B" << endl;
  else
    cout << "A" << endl;
  return 0;
  return 0;
}
