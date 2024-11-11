#include <bits/stdc++.h>
using namespace std;
long a[120][120];
long b[120][120];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long m, n, j, i;
  cin >> n >> m;
  vector<long> row, col;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> a[i][j];
  long mn;
  if (n >= m) {
    for (i = 1; i <= n; i++) {
      mn = 1000;
      for (j = 1; j <= m; j++) mn = min(mn, a[i][j]);
      for (j = 1; j <= m; j++) a[i][j] -= mn;
      while (mn--) row.push_back(i);
    }
    for (i = 1; i <= m; i++) {
      mn = 1000;
      for (j = 1; j <= n; j++) mn = min(mn, a[j][i]);
      for (j = 1; j <= n; j++) a[j][i] -= mn;
      while (mn--) col.push_back(i);
    }
  } else {
    for (i = 1; i <= m; i++) {
      mn = 1000;
      for (j = 1; j <= n; j++) mn = min(mn, a[j][i]);
      for (j = 1; j <= n; j++) a[j][i] -= mn;
      while (mn--) col.push_back(i);
    }
    for (i = 1; i <= n; i++) {
      mn = 1000;
      for (j = 1; j <= m; j++) mn = min(mn, a[i][j]);
      for (j = 1; j <= m; j++) a[i][j] -= mn;
      while (mn--) row.push_back(i);
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++)
      if (a[i][j]) {
        cout << -1;
        return 0;
      }
  }
  cout << row.size() + col.size() << endl;
  long r = row.size();
  long c = col.size();
  for (i = 0; i <= r - 1; i++) cout << "row " << row[i] << endl;
  for (i = 0; i <= c - 1; i++) cout << "col " << col[i] << endl;
  return 0;
}
