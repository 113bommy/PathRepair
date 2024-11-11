#include <bits/stdc++.h>
using namespace std;
int M[20][20];
int C[1005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    int a;
    cin >> a;
    C[a]++;
  }
  int i4 = 0, j4 = 0, i2 = 0, j2 = n / 2;
  bool ok = true, flag = false;
  for (int i = 1; i <= 1000; i++) {
    while (C[i] >= 4 && i4 < n / 2 && j4 < n / 2) {
      M[i4][j4] = M[i4][n - j4 - 1] = M[n - i4 - 1][j4] =
          M[n - i4 - 1][n - j4 - 1] = i;
      C[i] -= 4;
      i4++;
      if (i4 >= n / 2) {
        i4 = 0;
        j4++;
      }
    }
    if (C[i] && n % 2 == 0) {
      ok = false;
      break;
    }
    while (C[i] >= 2 && i2 < n / 2) {
      if (flag) {
        M[j2][i2] = M[j2][n - i2 - 1] = i;
        i2++;
      } else
        M[i2][j2] = M[n - i2 - 1][j2] = i;
      flag = !flag;
      C[i] -= 2;
    }
    if (C[i]) {
      if (M[n / 2][n / 2]) {
        ok = false;
        break;
      } else
        M[n / 2][n / 2] = i;
    }
  }
  if (ok) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << M[i][0];
      for (int j = 1; j < n; j++) cout << " " << M[i][j];
      cout << endl;
    }
  } else
    cout << "NO" << endl;
  return 0;
}
