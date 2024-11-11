#include <bits/stdc++.h>
using namespace std;
int n, a[4][101];
int main() {
  cin >> n;
  if (!(n & 1)) {
    for (int j = 0; j < n; j += 2) a[0][j] = a[0][j + 1] = ((j >> 1) & 1);
    for (int j = 0; j < n; j += 2) a[3][j] = a[3][j + 1] = 6 + ((j >> 1) & 1);
    a[1][0] = a[2][0] = 10, a[1][n - 1] = a[2][n - 1] = 11;
    for (int j = 1; j < n - 1; j += 2)
      a[1][j] = a[1][j + 1] = 12 + ((j >> 1) & 1);
    for (int j = 1; j < n - 1; j += 2)
      a[2][j] = a[2][j + 1] = 14 + ((j >> 1) & 1);
  } else {
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < n - 1; j += 2)
        a[i][j] = a[i][j + 1] = i * 2 + ((j >> 1) & 1);
    a[0][n - 1] = a[1][n - 1] = 10;
    for (int i = 2; i < 4; ++i)
      for (int j = 1; j < n; j += 2)
        a[i][j] = a[i][j + 1] = i * 2 + ((j >> 1) & 1);
    a[2][0] = a[2][0] = 11;
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n; ++j) cout << (char)(a[i][j] + 'a');
    cout << endl;
  }
  return 0;
}
