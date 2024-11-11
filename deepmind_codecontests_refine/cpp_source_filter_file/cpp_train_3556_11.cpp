#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  int row[] = {0, 0, -1, 1};
  int col[] = {-1, 1, 0, 0};
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'W') {
        for (int move = 0; move < 4; move++) {
          int ro = i + row[move];
          int co = j + col[move];
          if (ro >= 0 && ro <= n && co >= 0 && co <= m && a[ro][co] == 'P') {
            count++;
            a[ro][co] = '.';
            break;
          }
        }
      }
    }
  }
  cout << count;
  return 0;
}
