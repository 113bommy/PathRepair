#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<char>> array(m, vector<char>(n, '#'));
  for (int i = 0; i < m; i++) {
    if ((i + 1) % 4 == 0) {
      for (int j = 1; j < n; j++) {
        array[i][j] = '.';
      }
    }
    if ((i + 1) % 4 != 0 && (i + 1) % 2 == 0) {
      for (int j = 0; j < n - 1; j++) {
        array[i][j] = '.';
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
}
