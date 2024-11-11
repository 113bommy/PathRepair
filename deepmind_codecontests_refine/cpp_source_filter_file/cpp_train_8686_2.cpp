#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char c[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> c[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '.') {
        if ((i + j) % 2 == 0)
          c[i][j] = 'B';
        else
          c[i][j] = 'W';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << c[i][j];
    cout << endl;
  }
  return 0;
}
