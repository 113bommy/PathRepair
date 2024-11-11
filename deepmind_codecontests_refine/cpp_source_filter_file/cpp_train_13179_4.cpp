#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n][n];
  bool flag = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1)
        continue;
      else {
        flag = false;
        for (int k = 0; k < n; k++) {
          if (k == i) continue;
          long long int x, y;
          x = a[k][j];
          for (int l = 0; l < n; l++) {
            if (l == j) continue;
            y = a[i][l];
            if (x + y == a[i][j]) {
              flag = true;
              break;
            }
          }
          if (flag) break;
        }
      }
      if (flag == false) break;
    }
    if (flag == false) break;
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
