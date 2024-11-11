#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  cin >> m >> n;
  char ar[m][n];
  bool flag = true;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i & 1) {
        ar[i][j] = '.';
      } else {
        ar[i][j] = '#';
      }
    }
    if (i & 1) {
      if (flag) {
        ar[i][n - 1] = '#';
      } else {
        ar[i][0] = '#';
      }
      flag = !flag;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << ar[i][j] << " ";
    }
    cout << endl;
  }
}
