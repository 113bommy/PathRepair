#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, h, r, l, a[10];
  cin >> r >> l;
  for (i = r + 1; i < l; i++) {
    for (j = 0; j <= 9; j++) a[j] = 0;
    j = i;
    a[j % 10] = 1;
    while (j > 0) {
      j /= 10;
      if (a[j % 10] == 1 || j == 0) {
        if (j != 0) j = 1;
        break;
      }
      a[j % 10] = 1;
    }
    if (j == 0) {
      cout << i << endl;
      break;
    } else if (i == l - 1) {
      cout << "-1" << endl;
      break;
    }
  }
}
