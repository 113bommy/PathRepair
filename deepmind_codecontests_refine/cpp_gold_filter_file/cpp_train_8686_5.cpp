#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char insert[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> insert[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (insert[0][0] == '.') {
      insert[i][0] = 'B';
      cout << 'B';
    } else if (insert[0][0] == '-') {
      cout << '-';
      insert[0][0] = 'B';
    } else if (insert[i - 1][0] == 'B' && i >= 1 && insert[i][0] != '-') {
      insert[i][0] = 'W';
      cout << 'W';
    } else if (insert[i - 1][0] == 'W' && i >= 1 && insert[i][0] != '-') {
      insert[i][0] = 'B';
      cout << 'B';
    } else if (insert[i - 1][0] == 'B' && i >= 1 && insert[i][0] == '-') {
      insert[i][0] = 'W';
      cout << '-';
    } else if (insert[i - 1][0] == 'W' && i >= 1 && insert[i][0] == '-') {
      insert[i][0] = 'B';
      cout << '-';
    }
    for (int j = 1; j < m; j++) {
      if (insert[i][j] == '-') {
        cout << '-';
        if (insert[i][j - 1] == 'B') {
          insert[i][j] = 'W';
        } else if (insert[i][j - 1] == 'W') {
          insert[i][j] = 'B';
        }
        continue;
      } else if (insert[i][j - 1] == 'B') {
        insert[i][j] = 'W';
      } else if (insert[i][j - 1] == 'W') {
        insert[i][j] = 'B';
      }
      cout << insert[i][j];
    }
    cout << endl;
  }
}
