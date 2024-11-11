#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n][m];
  int temp = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (j == 0) temp ^= arr[i][j];
    }
  }
  int a[n];
  for (int i = 0; i < n; i++) a[i] = 1;
  int flag;
  if (temp) {
    cout << "TAX\n";
    for (int i = 0; i < n; i++) {
      cout << "1 ";
    }
  } else {
    for (int i = 0; i < n; i++) {
      flag = 0;
      for (int j = 0; j < m; j++) {
        if (arr[i][j] != arr[i][0]) {
          a[i] = j + 1;
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (flag) {
      cout << "TAX\n";
      for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
    } else {
      cout << "NIE";
    }
  }
  return 0;
}
