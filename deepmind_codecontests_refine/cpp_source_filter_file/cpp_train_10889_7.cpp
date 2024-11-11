#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int g[maxn][maxn] = {0};
int main() {
  ios_base ::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> g[i][j];
  int row[maxn] = {0};
  int col[maxn] = {0};
  int cnt = 0;
  if (n >= m) {
    for (int i = 1; i <= n; ++i) {
      int mx = 100000007;
      for (int j = 1; j <= m; ++j) {
        mx = min(mx, g[i][j]);
      }
      row[i] = mx;
      cnt += mx;
      for (int j = 1; j <= m; ++j) g[i][j] -= mx;
    }
    for (int i = 1; i <= m; ++i) {
      int mx = 100000007;
      for (int j = 1; j <= n; ++j) {
        mx = min(mx, g[j][i]);
      }
      col[i] = mx;
      cnt += mx;
      for (int j = 1; j <= n; ++j) g[j][i] -= mx;
    }
  } else {
    for (int i = 1; i <= m; ++i) {
      int mx = 100000007;
      for (int j = 1; j <= n; ++j) {
        mx = min(mx, g[j][i]);
      }
      col[i] = mx;
      cnt += mx;
      for (int j = 1; j <= n; ++j) g[j][i] -= mx;
    }
    for (int i = 1; i <= n; ++i) {
      int mx = 100000007;
      for (int j = 1; j <= m; ++j) {
        mx = min(mx, g[i][j]);
      }
      row[i] = mx;
      cnt += mx;
      for (int j = 1; j <= m; ++j) g[i][j] -= mx;
    }
  }
  int ok = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (g[i][j]) {
        ok = 0;
        break;
      }
    }
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  cout << cnt << endl;
  for (int i = 1; i <= n; ++i) {
    if (row[i]) {
      for (int j = 0; j < row[i]; ++j) {
        cout << "row " << i << endl;
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (col[i]) {
      for (int j = 0; j < col[i]; ++j) {
        cout << "col " << i << endl;
      }
    }
  }
  return 0;
}
