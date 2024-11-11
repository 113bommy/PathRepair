#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1100][1100];
  int core[1100], cell[1100], change[1100];
  int n, m, k;
  memset(core, 0, sizeof(core));
  memset(cell, 0, sizeof(cell));
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    memset(change, 0, sizeof(change));
    for (int i = 1; i <= n; i++) {
      if (core[i] != 0) continue;
      if (a[i][j] == 0) continue;
      if (cell[a[i][j]] != 0) {
        core[i] = j;
        continue;
      }
      if (change[a[i][j]] != 0) {
        core[i] = j;
        cell[a[i][j]] = 1;
        core[change[a[i][j]]] = j;
      } else
        change[a[i][j]] = i;
    }
  }
  for (int i = 1; i <= n; i++) cout << core[i] << endl;
  return 0;
}
