#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  char f[101][101], c;
  cin >> n >> m;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      c = int(c) - int('0');
      f[i][j] = c;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (f[i][j] != f[i][j + 1]) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
  }
  if (flag) {
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n - 1; i++) {
        if (f[i][j] == f[i + 1][j]) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
