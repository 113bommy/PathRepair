#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[101][101];
int main(void) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        if ((i + j) % 2 == 0)
          a[i][j] = 'W';
        else
          a[i][j] = 'B';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << "\n";
  }
}
