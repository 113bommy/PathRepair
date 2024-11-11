#include <bits/stdc++.h>
using namespace std;
int main() {
  string arr[9];
  for (int i = 0; i < 8; i++) cin >> arr[i];
  int a = 100000, b = 100000, k = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (arr[i][j] == 'W') {
        for (k = i - 1; k >= 0; k--) {
          if (arr[k][j] != '.') break;
        }
        if (k == -1) a = min(a, i);
      } else if (arr[i][j] == 'B') {
        for (k = i + 1; k < 8; k++) {
          if (arr[k][j] != '.') break;
        }
        if (k == 8) b = min(b, 7 - i);
      }
    }
  }
  if (a <= b)
    printf("A");
  else
    printf("B");
  return 0;
}
