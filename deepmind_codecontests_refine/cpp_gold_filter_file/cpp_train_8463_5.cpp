#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, nmin, nmax, min, max;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  nmin = n;
  nmax = 0;
  min = m;
  max = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        if (nmin > i) nmin = i;
        if (nmax < i) nmax = i;
        if (min > j) min = j;
        if (max < j) max = j;
      }
    }
  }
  for (int i = nmin; i <= nmax; i++) {
    for (int j = min; j <= max; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
