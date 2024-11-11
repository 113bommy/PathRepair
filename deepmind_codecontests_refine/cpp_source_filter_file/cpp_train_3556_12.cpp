#include <bits/stdc++.h>
using namespace std;
int n, m;
void solve() {
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  int ctr = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'W') {
        int up = max(0, i - 1);
        int down = min(i + 1, m - 1);
        int left = max(0, j - 1);
        int right = min(j + 1, n - 1);
        if (a[up][j] == 'P' || a[down][j] == 'P' || a[i][left] == 'P' ||
            a[i][right] == 'P')
          ctr++;
      }
    }
  }
  cout << ctr;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
