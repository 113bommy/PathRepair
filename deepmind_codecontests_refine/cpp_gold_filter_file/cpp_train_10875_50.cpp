#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, a, b, min, count;
  cin >> n >> m;
  int g[n][m];
  min = m * n;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) cin >> g[i][j];
  }
  cin >> a >> b;
  for (i = 0; i < n - a + 1; ++i) {
    for (j = 0; j < m - b + 1; ++j) {
      int r, s;
      count = 0;
      for (r = 0; r < a; ++r) {
        for (s = 0; s < b; ++s)
          if (g[i + r][j + s] == 1) count = count + 1;
      }
      if (count < min) min = count;
    }
  }
  for (i = 0; i < n - b + 1; ++i) {
    for (j = 0; j < m - a + 1; ++j) {
      int r, s;
      count = 0;
      for (r = 0; r < b; ++r) {
        for (s = 0; s < a; ++s)
          if (g[i + r][j + s] == 1) count = count + 1;
      }
      if (count < min) min = count;
    }
  }
  cout << min;
}
