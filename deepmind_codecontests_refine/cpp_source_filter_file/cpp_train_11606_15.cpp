#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k = INT_MIN;
  cin >> n;
  int a[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == 0 || j == 0)
        a[i][j] = 1;
      else
        a[i][j] = a[i - 1][j] + a[i][j - 1];
    }
  }
  for (i = 1; i < n; i++) {
    for (j = 1; j < n; j++) {
      if (a[i][j] > k) k = a[i][j];
    }
  }
  cout << k;
  return 0;
}
