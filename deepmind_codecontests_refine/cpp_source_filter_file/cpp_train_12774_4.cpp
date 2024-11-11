#include <bits/stdc++.h>
using namespace std;
int main() {
  char col[4] = {'A', 'B', 'C', 'D'};
  char mat[32][50];
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 50; j++) {
      mat[i][j] = col[i / 8];
    }
  }
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for (int i = 0; i < 8; i += 2) {
    for (int j = 0; j < 50; j += 2) {
      if (c > 1) {
        mat[i][j] = 'C';
        c--;
      } else {
        break;
      }
    }
  }
  for (int i = 8; i < 16; i += 2) {
    for (int j = 0; j < 50; j += 2) {
      if (d > 1) {
        mat[i][j] = 'D';
        d--;
      } else {
        break;
      }
    }
  }
  for (int i = 16; i < 24; i += 2) {
    for (int j = 0; j < 50; j += 2) {
      if (a > 1) {
        mat[i][j] = 'A';
        a--;
      } else {
        break;
      }
    }
  }
  for (int i = 24; i < 32; i += 2) {
    for (int j = 0; j < 50; j += 2) {
      if (b > 1) {
        mat[i][j] = 'B';
        b--;
      } else {
        break;
      }
    }
  }
  cout << 32 << " " << 50 << endl;
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 10; j++) {
      cout << mat[i][j];
    }
    cout << endl;
  }
}
