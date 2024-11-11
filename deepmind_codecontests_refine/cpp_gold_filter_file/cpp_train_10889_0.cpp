#include <bits/stdc++.h>
using namespace std;
int grd[109][109], minn[109], minm[109];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < 109; i++) {
    minn[i] = minm[i] = 999;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grd[i][j];
      minn[i] = min(minn[i], grd[i][j]);
      minm[j] = min(minm[j], grd[i][j]);
    }
  }
  int flag = 0, k = 0, aro[109], aco[109];
  if (n <= m) {
    for (int i = 1; i <= n; i++) {
      aro[i] = minn[i];
      k += aro[i];
      if (minn[i] > 0) {
        for (int j = 1; j <= m; j++) {
          grd[i][j] -= minn[i];
        }
      }
    }
    for (int j = 1; j <= m; j++) {
      minm[j] = grd[1][j];
      for (int i = 2; i <= n; i++) {
        if (grd[i][j] != grd[i - 1][j]) flag++;
      }
      aco[j] = minm[j];
      k += aco[j];
    }
  } else {
    for (int j = 1; j <= m; j++) {
      aco[j] = minm[j];
      k += aco[j];
      if (minm[j] > 0) {
        for (int i = 1; i <= n; i++) {
          grd[i][j] -= minm[j];
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      minn[i] = grd[i][1];
      for (int j = 2; j <= m; j++) {
        if (grd[i][j] != grd[i][j - 1]) flag++;
      }
      aro[i] = minn[i];
      k += aro[i];
    }
  }
  if (flag > 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << k << endl;
  int r = 1;
  while (r < n + 1) {
    while (aro[r] > 0) {
      cout << "row " << r << endl;
      aro[r]--;
    }
    r++;
  }
  int c = 1;
  while (c < m + 1) {
    while (aco[c] > 0) {
      cout << "col " << c << endl;
      aco[c]--;
    }
    c++;
  }
  return 0;
}
