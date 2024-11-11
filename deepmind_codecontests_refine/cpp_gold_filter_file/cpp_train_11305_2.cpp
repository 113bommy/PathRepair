#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100][100], n, k, i, j;
  cin >> n >> k;
  if (k > n * n) {
    cout << -1;
    return 0;
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      a[i][j] = 0;
    }
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (i != j && k >= 2 && a[i][j] == 0) {
        k -= 2;
        a[i][j] = 1;
        a[j][i] = 1;
      }
      if (i == j && k >= 1 && a[i][j] == 0) {
        k--;
        a[i][j] = 1;
      }
    }
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
