#include <bits/stdc++.h>
using namespace std;
int n;
int a[3][6];
bool b[1000];
void check2(int x, int y) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (a[x][i] != 0) {
        b[10 * a[x][i] + a[y][j]] = true;
      }
    }
  }
}
void check3(int x, int y, int z) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 6; k++) {
        if (a[x][i] != 0) {
          b[100 * a[x][i] + 10 * a[y][j] + a[z][k]] = true;
        }
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> a[i][j];
      b[a[i][j]] = true;
    }
  }
  if (n == 2) {
    check2(0, 1);
    check2(1, 0);
  } else if (n == 3) {
    check2(0, 1);
    check2(1, 0);
    check2(1, 2);
    check2(2, 1);
    check2(2, 0);
    check2(0, 2);
    check3(0, 1, 2);
    check3(0, 2, 1);
    check3(1, 0, 2);
    check3(1, 2, 0);
    check3(2, 0, 1);
    check3(2, 1, 0);
  }
  int res = 0;
  while (b[res]) {
    res++;
  }
  cout << res - 1;
  return 0;
}
