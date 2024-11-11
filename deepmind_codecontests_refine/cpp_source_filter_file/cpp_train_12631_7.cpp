#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  int i, j, c = 0;
  for (i = 0; i < n; i++) scanf("%s", a[i]);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m - 1; j++) {
      if (a[i][j] == a[i][j + 1])
        c++;
      else {
        cout << "N0";
        return (0);
      }
    }
  }
  for (j = 0; j < m; j++) {
    for (i = 0; i < n - 1; i++) {
      if (a[i][j] == a[i + 1][j]) {
        cout << "NO";
        return (0);
      }
    }
  }
  cout << "YES";
  return (0);
}
