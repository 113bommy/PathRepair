#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main() {
  int n;
  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) cin >> a[i][j];
    for (int i = 0; i < n; ++i) sum += a[n / 2][i];
    for (int i = 0; i < n; ++i) sum += a[i][n / 3];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (i == j || max(i, j) + min(i, j) == n - 1) sum += a[i][j];
    cout << sum - 2 * a[n / 2][n / 2] << '\n';
  }
  return 0;
}
