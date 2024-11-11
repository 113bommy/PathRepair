#include <bits/stdc++.h>
using namespace std;
int a[5][5];
int b[5][5];
int main() {
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      cin >> a[i][j];
      b[i][j] = 1;
    }
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      if (a[i][j] & 1) {
        b[i - 1][j] ^= 1;
        b[i + 1][j] ^= 1;
        b[i][j - 1] ^= 1;
        b[i][j + 1] ^= 1;
        b[i][j] ^= 1;
      }
    }
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
}
