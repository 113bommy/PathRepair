#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[105][105], b[105] = {0}, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (i > 1 && j == 1 || i == 1 && j == 2) b[i] = a[i][j];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i != j) b[i] |= a[i][j];
    }
  }
  for (i = 1; i <= n; i++) cout << b[i] << " ";
  return 0;
}
