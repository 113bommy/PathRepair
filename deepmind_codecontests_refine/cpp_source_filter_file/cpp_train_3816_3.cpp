#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char c[n + 1][m + 1];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == 'W') {
        if (c[i][j - 1] == 'S' || c[i - 1][j] == 'S' || c[i + 1][j] == 'S' ||
            c[i][j + 1] == 'S') {
          cout << "NO";
          break;
        }
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '.')
        cout << 'D';
      else
        cout << c[i][j];
    }
    cout << endl;
  }
}
