#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, m, j, i;
  cin >> n >> m;
  bool ok = false;
  long long int a[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j == 0 || i == 0 || j == n - 1 || i == n - 1) {
        if (a[i][j] == 1) {
          ok = true;
          break;
        }
      }
    }
  }
  if (ok) {
    cout << "2";
  } else
    cout << "4";
  return 0;
}
