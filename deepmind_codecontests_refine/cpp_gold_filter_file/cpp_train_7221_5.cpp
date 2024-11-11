#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[5][5], x, y, p, q, sum;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> A[i][j];
      if (A[i][j] == 1) {
        x = i;
        y = j;
      }
    }
    cout << endl;
  }
  if (x == 2 && y == 2) {
    p = 0;
    q = 0;
  } else if (x >= 2 && y >= 2) {
    p = x - 2;
    q = y - 2;
  } else if (x >= 2 && y <= 2) {
    p = x - 2;
    q = 2 - y;
  } else if (x <= 2 && y >= 2) {
    p = 2 - x;
    q = y - 2;
  } else if (x <= 2 && y <= 2) {
    p = 2 - x;
    q = 2 - y;
  }
  sum = p + q;
  cout << sum << endl;
  return 0;
}
