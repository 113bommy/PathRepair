#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 20;
int a[4][MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
  }
  if (n % 2 == 0) {
    int cnt = 0;
    for (int j = 0; j < n - 1; j += 2, cnt++) {
      if (cnt % 2 == 0)
        a[0][j] = 1, a[0][j + 1] = 1;
      else
        a[0][j] = 2, a[0][j + 1] = 2;
    }
    cnt = 0;
    for (int j = 0; j < n - 1; j += 2, cnt++) {
      if (cnt % 2 == 0)
        a[1][j] = 2, a[1][j + 1] = 2;
      else
        a[1][j] = 1, a[1][j + 1] = 1;
    }
    cnt = 0;
    a[2][0] = 26, a[3][0] = 26, a[2][n - 1] = 25, a[3][n - 1] = 25;
    for (int j = 1; j < n - 2; j += 2, cnt++) {
      if (cnt % 2 == 0)
        a[2][j] = 7, a[2][j + 1] = 7;
      else
        a[2][j] = 8, a[2][j + 1] = 8;
    }
    cnt = 0;
    for (int j = 1; j < n - 2; j += 2, cnt++) {
      if (cnt % 2 == 0)
        a[3][j] = 8, a[3][j + 1] = 8;
      else
        a[3][j] = 7, a[3][j + 1] = 7;
    }
  } else {
    a[0][n - 1] = 17, a[1][n - 1] = 17, a[2][0] = 18, a[3][0] = 18;
    int cnt = 0;
    for (int j = 0; j < n - 2; j += 2, cnt++) {
      if (cnt % 2 == 0)
        a[0][j] = 7, a[0][j + 1] = 7;
      else
        a[0][j] = 8, a[0][j + 1] = 8;
    }
    cnt = 0;
    for (int j = 0; j < n - 2; j += 2, cnt++) {
      if (cnt % 2 == 0)
        a[1][j] = 8, a[1][j + 1] = 8;
      else
        a[1][j] = 7, a[1][j + 1] = 7;
    }
    cnt = 0;
    for (int j = 1; j < n - 1; j += 2, cnt++) {
      if (cnt % 2 == 0)
        a[2][j] = 13, a[2][j + 1] = 13;
      else
        a[2][j] = 14, a[2][j + 1] = 14;
    }
    cnt = 0;
    for (int j = 1; j < n - 1; j += 2, cnt++) {
      if (cnt % 2 == 0)
        a[3][j] = 14, a[3][j + 1] = 14;
      else
        a[3][j] = 13, a[3][j + 1] = 13;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      char y = a[i][j] + 96;
      cout << y;
    }
    cout << '\n';
  }
}
