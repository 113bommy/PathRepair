#include <bits/stdc++.h>
using namespace std;
int a[1000000][3];
int main() {
  int n, m;
  cin >> n >> m;
  int i, j, k;
  map<int, int> mm;
  for (i = 0; i < m; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (j = 0; j < 3; j++) {
      if (mm.count(a[i][j]) != 0) break;
    }
    if (j == 3) {
      mm[a[i][0]] = 1;
      mm[a[i][1]] = 2;
      mm[a[i][2]] = 3;
    } else if (mm[a[i][j]] == 1) {
      int tt = 2;
      for (k = 0; k < 3; k++) {
        if (k == j) continue;
        mm[a[i][k]] = tt;
        tt++;
      }
    } else if (mm[a[i][j]] == 2) {
      int tt = 1;
      for (k = 0; k < 3; k++) {
        if (k == j) continue;
        mm[a[i][k]] = tt;
        tt = 3;
      }
    } else if (mm[a[i][j]] == 3) {
      int tt = 1;
      for (k = 0; k < 3; k++) {
        if (k == j) continue;
        mm[a[i][k]] = 1;
        tt = 2;
      }
    }
  }
  for (i = 1; i <= n; i++) cout << mm[i] << " ";
  return 0;
}
