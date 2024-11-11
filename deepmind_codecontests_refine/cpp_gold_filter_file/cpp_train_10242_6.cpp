#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a[3][3];
  int temp[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      temp[i][j] = 1;
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (a[i][j] % 2 == 1) {
        temp[i][j] = !temp[i][j];
        if (i + 1 < 3) {
          temp[i + 1][j] = !temp[i + 1][j];
        }
        if (j + 1 < 3) {
          temp[i][j + 1] = !temp[i][j + 1];
        }
        if (i - 1 >= 0) {
          temp[i - 1][j] = !temp[i - 1][j];
        }
        if (j - 1 >= 0) {
          temp[i][j - 1] = !temp[i][j - 1];
        }
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << temp[i][j];
    }
    cout << "\n";
  }
  return 0;
}
