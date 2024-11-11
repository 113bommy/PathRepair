#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  int i, j, k, p;
  int map[n][m];
  char c;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> c;
      map[i][j] = (c == '*');
    }
  }
  int count = 0;
  int dprow[n];
  int dpcol[m];
  for (i = 0; i < n; i++) {
    dprow[i] = 0;
    for (j = 0; j < m; j++) {
      if (map[i][j]) {
        dprow[i]++;
      }
    }
  }
  for (j = 0; j < m; j++) {
    dpcol[j] = 0;
    for (i = 0; i < n; i++) {
      if (map[i][j]) {
        dpcol[j]++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (map[i][j]) {
        count += (dprow[i] - 1) * (dpcol[j] - 1);
      }
    }
  }
  cout << count << endl;
  return 0;
}
