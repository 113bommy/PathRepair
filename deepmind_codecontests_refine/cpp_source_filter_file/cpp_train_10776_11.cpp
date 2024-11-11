#include <bits/stdc++.h>
using namespace std;
int adj[555][555], x, y, n, m;
char value[555];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    adj[x][y] = adj[y][x] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (!adj[i][j]) {
        if (value[i]) {
          if (value[i] == 'a')
            value[j] = 'c';
          else
            value[j] = 'a';
        } else if (value[j]) {
          if (value[j] == 'a')
            value[i] = 'c';
          else
            value[i] = 'a';
        } else {
          value[i] = 'a';
          value[j] = 'b';
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!value[i]) value[i] = 'b';
  }
  int is_valid = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (adj[i][j] && abs(value[i] - value[j]) > 1)
        is_valid = 0;
      else if (!adj[i][j] && abs(value[i] - value[j]) <= 1)
        is_valid = 0;
    }
  }
  if (is_valid) {
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i) cout << value[i];
    cout << endl;
  } else
    cout << "No" << endl;
  return 0;
}
