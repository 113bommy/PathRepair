#include <bits/stdc++.h>
using namespace std;
char c[8][8];
bool arr[8][8];
int main() {
  int p1 = 8, p2 = 1;
  for (int i = 0; i < 8; i++) {
    for (int y = 0; y < 8; y++) {
      cin >> c[i][y];
      if (c[i][y] != '.') {
        arr[i][y] = 1;
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    for (int y = 0; y < 8; y++) {
      if (c[i][y] == 'W') {
        int k;
        for (k = i - 1; y >= 0; k--) {
          if (arr[k][y]) {
            break;
          }
        }
        if (k < 0) {
          p1 = min(p1, i + 1);
        }
      } else if (c[i][y] == 'B') {
        int k;
        for (k = i + 1; k < 8; k++) {
          if (arr[k][y]) {
            break;
          }
        }
        if (k == 8) {
          p2 = max(p2, i + 1);
        }
      }
    }
  }
  if (p1 - 1 <= 8 - p2) {
    cout << 'A' << endl;
  } else if (p1 - 1 > 8 - p2) {
    cout << 'B' << endl;
  }
  return 0;
}
