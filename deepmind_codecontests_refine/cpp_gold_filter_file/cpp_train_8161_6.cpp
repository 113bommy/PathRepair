#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  while (cin >> n >> k) {
    int a[n][n];
    for (int y = 0; y < n; y++) {
      for (int q = 0; q < n; q++) {
        a[y][q] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      a[i][i] = k;
    }
    for (int j = 0; j < n; j++) {
      for (int p = 0; p < n; p++) {
        cout << a[j][p] << " ";
      }
      cout << endl;
    }
  }
}
