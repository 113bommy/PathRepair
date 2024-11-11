#include <bits/stdc++.h>
using namespace std;
bool found = false;
int i, j, n, m;
char a[101][101];
bool fun() {
  for (int r = i + 1; r < n; r++)
    if (a[i][j] == a[r][j]) return 0;
  for (int r = i - 1; r >= 0; r--)
    if (a[i][j] == a[r][j]) return 0;
  for (int c = j + 1; c < m; c++)
    if (a[i][j] == a[i][c]) return 0;
  for (int c = j - 1; c >= 0; c--)
    if (a[i][j] == a[i][c]) return 0;
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  for (; i < n; i++) {
    j = 0;
    for (; j < m; j++) {
      if (fun()) cout << a[i][j];
    }
  }
  return 0;
}
