#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  char arr[100][100];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '.') {
        if (i + j % 2 == 0)
          arr[i][j] = 'B';
        else
          arr[i][j] = 'W';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j != m - 1)
        cout << arr[i][j];
      else
        cout << arr[i][j] << endl;
    }
  }
  return 0;
}
