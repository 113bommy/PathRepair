#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[101][101], an[101][101], m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) an[i][j] = 1;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      if (a[i][j] == 0) {
        for (int k = 0; k < n; k++) an[j][k] = 0;
        for (int k = 0; k < m; k++) an[k][j] = 0;
      }
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      bool t = 0;
      for (int k = 0; k < n; k++)
        if (an[j][k]) {
          t = 1;
          break;
        }
      for (int k = 0; k < m; k++)
        if (an[k][i] && !t) {
          t = 1;
          break;
        }
      if (t != a[i][j]) {
        cout << "NO";
        return 0;
      }
    }
  cout << "YES" << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cout << an[i][j] << " ";
    cout << endl;
  }
  return 0;
}
