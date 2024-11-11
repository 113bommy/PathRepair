#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  vector<vector<long long> > grid(n, vector<long long>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cin >> grid[i][j];
  }
  map<long long, long long> rows[n], cols[m];
  long long max_row[n], max_col[m];
  for (long long i = 0; i < n; i++) {
    set<long long> ss;
    for (long long j = 0; j < m; j++) {
      ss.insert(grid[i][j]);
    }
    long long cur = 1;
    for (long long x : ss) {
      rows[i][x] = cur;
      cur++;
    }
    max_row[i] = cur - 1;
  }
  for (long long i = 0; i < m; i++) {
    set<long long> ss;
    for (long long j = 0; j < n; j++) {
      ss.insert(grid[j][i]);
    }
    long long cur = 1;
    for (long long x : ss) {
      cols[i][x] = cur;
      cur++;
    }
    max_col[i] = cur - 1;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (rows[i][grid[i][j]] == cols[j][grid[i][j]]) {
        long long res = max(max_row[i], max_col[j]);
        cout << res << ' ';
      } else {
        long long diff = abs(rows[i][grid[i][j]] - cols[j][grid[i][j]]);
        if (rows[i][grid[i][j]] < cols[j][grid[i][j]]) {
          cout << max(max_row[i] + diff, max_col[j]) << " ";
        } else {
          cout << max(max_row[i], max_col[j] + diff) << " ";
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
