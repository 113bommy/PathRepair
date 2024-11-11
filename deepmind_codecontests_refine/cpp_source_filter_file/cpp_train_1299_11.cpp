#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  int row[n];
  int col[m];
  memset(row, 0, sizeof(int) * n);
  memset(col, 0, sizeof(int) * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = (c == '*');
      if (a[i][j]) {
        col[j]++;
        row[i]++;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j]) {
        ans += (row[i] - 1) * (col[j] - 1);
      }
    }
  }
  cout << ans;
}
