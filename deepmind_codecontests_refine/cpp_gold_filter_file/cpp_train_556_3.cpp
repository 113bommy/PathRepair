#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> a[i][j];
  for (int i = 0; i <= 100000; i++) {
    int r = a[0][1] + a[0][2] + i;
    if (r - a[1][0] - a[1][2] > 0 && r - a[2][0] - a[2][1] > 0 &&
        r - a[2][0] - a[2][1] + r - a[1][0] - a[1][2] + i == r &&
        a[2][0] + r - a[1][0] - a[1][2] + a[0][2] == r) {
      a[0][0] = i;
      a[1][1] = r - a[1][0] - a[1][2];
      a[2][2] = r - a[2][0] - a[2][1];
      break;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cout << a[i][j] << " ";
    cout << endl;
  }
}
