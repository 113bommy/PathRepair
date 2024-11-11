#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n][n];
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        a[i][j] = k;
      } else
        a[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << a[i][j] << "\t";
    }
    cout << endl;
  }
  return 0;
}
