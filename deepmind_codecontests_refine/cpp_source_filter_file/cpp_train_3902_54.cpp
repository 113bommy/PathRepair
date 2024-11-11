#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char ch[n][m];
  bool alt = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i % 2 == 0) {
        ch[i][j] = '#';
      } else {
        ch[i][j] = '.';
      }
    }
    if (i % 2) {
      if (alt)
        ch[i][m - 1] = '#';
      else
        ch[i][0] = '#';
      alt = (alt == true ? false : true);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ch[i][j] << ' ';
    }
    cout << '\n';
  }
}
