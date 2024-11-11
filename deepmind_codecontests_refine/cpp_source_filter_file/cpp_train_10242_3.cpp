#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int a[3][3];
  int r[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      r[i][j] = 1;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
      a[i][j] %= 2;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (a[i][j] != 0) {
        r[i][j] = 1 - r[i][j];
        if (i + 1 <= 1) {
          r[i + 1][j] = 1 - r[i + 1][j];
        }
        if (i - 1 >= 0) r[i - 1][j] = 1 - r[i - 1][j];
        if (j + 1 <= 2) r[i][j + 1] = 1 - r[i][j + 1];
        if (j - 1 >= 0) {
          r[i][j - 1] = 1 - r[i][j - 1];
        }
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << r[i][j];
    }
    cout << endl;
  }
  return 0;
}
