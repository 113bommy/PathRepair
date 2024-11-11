#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, a, b, total = 0, min = 10000;
  cin >> i >> j;
  int array[i][j];
  for (int k = 0; k < i; k++) {
    for (int l = 0; l < j; l++) cin >> array[k][l];
  }
  cin >> a >> b;
  for (int m = 0; m <= i - a; m++) {
    for (int n = 0; n <= j - b; n++) {
      total = 0;
      for (int o = m; o < m + a; o++) {
        for (int p = n; p < n + b; p++) {
          total += array[o][p];
        }
      }
      if (total < min) min = total;
    }
  }
  for (int m = 0; m <= i - b; m++) {
    for (int n = 0; n <= j - a; n++) {
      total = 0;
      for (int o = m; o < m + b; o++) {
        for (int p = n; p < n + a; p++) {
          total += array[o][p];
        }
      }
      if (total < min) min = total;
    }
  }
  cout << min;
  return 0;
}
