#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, r, i, n, b[4], g, j, k, f = 0;
  cin >> y;
  for (i = y; i <= 9000; i++) {
    g = 3, f = 0;
    n = i + 1;
    while (n != 0) {
      r = n % 10;
      b[g] = r;
      g--;
      n = n / 10;
    }
    for (j = 0; j < 3; j++) {
      for (k = j + 1; k < 4; k++) {
        if (b[j] == b[k]) {
          f = 1;
        }
      }
    }
    if (f == 0) break;
  }
  for (i = 0; i < 4; i++) {
    cout << b[i];
  }
  return 0;
}
