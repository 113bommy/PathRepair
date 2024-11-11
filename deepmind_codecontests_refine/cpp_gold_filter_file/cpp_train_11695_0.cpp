#include <bits/stdc++.h>
using namespace std;
int n, i, a[102][102], res, j;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) cin >> a[i][j];
  for (i = 1; i <= n; i++) {
    res += a[i][i];
    a[i][i] = 0;
  }
  for (i = 1; i <= n; i++) {
    res += a[i][n - i + 1];
    a[i][n - i + 1] = 0;
  }
  for (i = 1; i <= n; i++) {
    res += a[i][n / 2 + 1];
    a[i][n / 2 + 1] = 0;
    res += a[n / 2 + 1][i];
    a[n / 2 + 1][i] = 0;
  }
  cout << res;
}
