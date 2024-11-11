#include <bits/stdc++.h>
using namespace std;
int vis[55][55];
char arr[55][55];
int n, m;
int func(int i, int j, int previ, int prevj) {
  vis[i][j] = 1;
  int k = 0;
  if (j > 0) {
    if ((j - 1) != prevj && (arr[i][j - 1] == arr[i][j] && vis[i][j - 1] != 0))
      return 1;
    else if ((j - 1) != prevj &&
             (arr[i][j - 1] == arr[i][j] && vis[i][j - 1] == 0))
      k = func(i, j - 1, i, j);
  }
  if (j < m - 1) {
    if ((j + 1) != prevj && (arr[i][j + 1] == arr[i][j] && vis[i][j + 1] != 0))
      return 1;
    else if ((j + 1) != prevj &&
             (arr[i][j + 1] == arr[i][j] && vis[i][j + 1] == 0))
      k = func(i, j + 1, i, j);
  }
  if (i > 0) {
    if ((i - 1) != previ && (arr[i - 1][j] == arr[i][j] && vis[i - 1][j] != 0))
      return 1;
    else if ((i - 1) != previ &&
             (arr[i - 1][j] == arr[i][j] && vis[i - 1][j] == 0))
      k = func(i - 1, j, i, j);
  }
  if (i < n - 1 && (i + 1) != previ) {
    if (arr[i + 1][j] == arr[i][j] && vis[i + 1][j] != 0)
      return 1;
    else if (arr[i + 1][j] == arr[i][j] && vis[i + 1][j] == 0)
      k = func(i + 1, j, i, j);
  }
  return k;
}
int main() {
  cin >> n >> m;
  int i, j, k = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      cin >> arr[i][j];
      vis[i][j] = 0;
    }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (vis[i][j] == 0) {
        k = func(i, j, i, j);
      }
      if (k == 1) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
