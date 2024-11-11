#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool> > sig(n, vector<bool>(m)), temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '\n')
        j--;
      else if (c == '#')
        sig[i][j] = true;
      else
        sig[i][j] = false;
    }
  }
  temp = sig;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (sig[i][j]) {
        if (i + 2 >= n || j + 2 >= m) {
          cout << "NO";
          return 0;
        }
        for (int ii = 0; ii < 3; ii++) {
          for (int jj = 0; jj < 3; jj++) {
            if (ii == 1 && jj == 1) continue;
            if (temp[i + ii][j + jj] == false) {
              cout << "NO";
              return 0;
            }
            sig[i + ii][j + jj] = false;
          }
        }
      } else if (temp[i][j]) {
        if (i + 2 >= n || j + 2 >= m)
          continue;
        else {
          bool p = true;
          for (int ii = 0; ii < 3; ii++) {
            for (int jj = 0; jj < 3; jj++) {
              if (ii == 1 && jj == 1) continue;
              if (!temp[i + ii][j + jj]) p = false;
            }
          }
          if (p) {
            for (int ii = 0; ii < 3; ii++) {
              for (int jj = 0; jj < 3; jj++) {
                if (ii == 1 && jj == 1) continue;
                sig[i + ii][j + jj] = false;
              }
            }
          }
        }
      }
    }
  }
  cout << "YES";
  return 0;
}
