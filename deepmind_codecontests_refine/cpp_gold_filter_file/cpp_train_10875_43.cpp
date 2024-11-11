#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int grid[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> grid[i][j];
  int k, l, mn = 1e9;
  cin >> k >> l;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if ((i + k) <= n && (l + j) <= m) {
        int s = 0;
        for (int ll = i; ll < k + i; ll++)
          for (int ii = j; ii < l + j; ii++) s += grid[ll][ii];
        mn = min(mn, s);
      }
      if ((i + l) <= n && (k + j) <= m) {
        int s = 0;
        for (int ll = i; ll < l + i; ll++)
          for (int ii = j; ii < k + j; ii++) s += grid[ll][ii];
        mn = min(mn, s);
      }
    }
  cout << mn;
}
