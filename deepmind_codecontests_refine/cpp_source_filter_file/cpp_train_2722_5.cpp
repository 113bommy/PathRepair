#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char arr[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[i][j] != '#') {
        if (arr[i + 1][j - 1] == '.' && arr[i + 1][j] == '.' &&
            arr[i + 1][j + 1] == '.' && arr[i + 2][j] == '.') {
          arr[i + 1][j - 1] = '#';
          arr[i + 1][j] = '#';
          arr[i + 1][j + 1] = '#';
          arr[i + 2][j] = '#';
          arr[i][j] = '#';
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == '.') {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}
