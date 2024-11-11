#include <bits/stdc++.h>
using namespace std;
int rescol[128];
int resrow[128];
long long int level = 0;
int g[128][128];
int n, m;
void row() {
  for (int i = 0; i < n; ++i) {
    if (g[i][0] > 0) {
      int mn = g[i][0];
      for (int k = 0; k < m; ++k) {
        if (mn > g[i][k]) {
          mn = g[i][k];
        }
        if (mn == 0) {
          break;
        }
      }
      resrow[i] = mn;
      level += mn;
      for (int k = 0; k < m; ++k) g[i][k] -= mn;
    }
  }
}
void col() {
  for (int i = 0; i < m; ++i) {
    if (g[0][i] > 0) {
      int mn = g[0][i];
      for (int k = 0; k < n; ++k) {
        if (mn > g[k][i]) {
          mn = g[k][i];
        }
        if (mn == 0) {
          break;
        }
      }
      rescol[i] = mn;
      level += mn;
      for (int k = 0; k < m; ++k) g[k][i] -= mn;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  if (n < m) {
    col();
    row();
  } else {
    row();
    col();
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (g[i][j] > 0) {
        level = -1;
        break;
      }
    }
    if (level < 0) {
      break;
    }
  }
  if (level < 0) {
    cout << level;
    return 0;
  }
  cout << level << endl;
  for (int i = 0; i < n; ++i) {
    while (resrow[i]-- > 0) {
      cout << "row " << i + 1 << endl;
    }
  }
  for (int i = 0; i < m; ++i) {
    while (rescol[i]-- > 0) cout << "col " << i + 1 << endl;
  }
  return 0;
}
