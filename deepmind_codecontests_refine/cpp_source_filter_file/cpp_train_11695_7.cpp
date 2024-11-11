#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a[102][102], s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0, j = n - 1, k = 0; i < n; i++, j--) {
    s += a[i][i] + a[j][j] + a[i][n / 2] + a[n / 2][i];
  }
  cout << s - (3 * a[n / 2][n / 2]);
  return 0;
}
