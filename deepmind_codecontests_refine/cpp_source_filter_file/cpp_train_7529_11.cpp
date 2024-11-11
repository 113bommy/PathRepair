#include <bits/stdc++.h>
using namespace std;
int i, j, n, sum, a[105][105];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  sum = 0;
  for (i = 0; i < n; i++) {
    sum += a[i][i];
  }
  for (i = 0; i < n; i++) {
    sum += a[i][n - 1 - i];
  }
  for (i = 0; i < n; i++) {
    sum += a[i][(n + 1) / 2];
  }
  for (i = 0; i < n; i++) {
    sum += a[(n + 1) / 2][i];
  }
  sum -= 3 * a[(n + 1) / 2][(n + 1) / 2];
  cout << sum << endl;
  return 0;
}
