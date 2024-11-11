#include <bits/stdc++.h>
using namespace std;
int grid[1003][1003];
int main() {
  long long r, testCase, x, y, m, l, k, b, c, z, n, totalStar = 0, a, q;
  vector<long long> ar;
  cin >> n >> m;
  string str;
  pair<int, int> source, target;
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) {
      if (str[j] == '.') {
        grid[i][j] = 0;
      } else if (str[j] == '*') {
        grid[i][j] = 1;
      } else if (str[j] == 'S') {
        grid[i][j] = 2;
        source = make_pair(i, j);
      } else if (str[j] == 'T') {
        grid[i][j] = 3;
        target = make_pair(i, j);
      }
    }
  }
  if (target.first < source.first) {
    pair<int, int> temp = target;
    target = source;
    source = target;
  }
  bool col[1005], row[1005];
  memset(col, false, sizeof(col));
  memset(row, false, sizeof(row));
  pair<int, int> sourcRowRange;
  for (int i = source.second; i >= 0; i--) {
    if (grid[source.first][i] == 1) {
      sourcRowRange.first = i + 1;
      break;
    }
    if (i == 0) sourcRowRange.first = 0;
  }
  for (int i = source.second; i < m; i++) {
    if (grid[source.first][i] == 1) {
      sourcRowRange.second = i - 1;
      break;
    }
    if (i == m - 1) {
      sourcRowRange.second = m - 1;
    }
  }
  for (int i = sourcRowRange.first; i <= sourcRowRange.second; i++) {
    for (int j = source.first; j <= target.first; j++) {
      if (grid[j][i] == 1) {
        break;
      }
      if (j == target.first) {
        col[i] = true;
      }
    }
  }
  bool ok = false;
  for (int i = target.second; i >= 0; i--) {
    if (grid[target.first][i] == 1) {
      break;
    } else if (col[i])
      ok = true;
  }
  for (int i = target.second; i < m; i++) {
    if (grid[target.first][i] == 1) {
      break;
    } else if (col[i])
      ok = true;
  }
  if (ok) {
    cout << "YES\n";
  } else {
    pair<int, int> sourceColRange, searchRange;
    searchRange.first = min(source.second, target.second);
    searchRange.second = max(source.second, target.second);
    for (int i = source.first; i >= 0; i--) {
      if (grid[i][source.second] == 1) {
        sourceColRange.first = i + 1;
        break;
      }
      if (i == 0) sourceColRange.first = i;
    }
    for (int i = source.first; i < m; i++) {
      if (grid[i][source.second] == 1) {
        sourceColRange.second = i - 1;
        break;
      }
      if (i == m - 1) sourceColRange.second = i;
    }
    for (int i = sourceColRange.first; i <= sourceColRange.second; i++) {
      for (int j = searchRange.first; j <= searchRange.second; j++) {
        if (grid[i][j] == 1) {
          break;
        }
        if (j == searchRange.second) {
          row[i] = true;
        }
      }
    }
    for (int i = target.first; i >= 0; i--) {
      if (grid[i][target.second] == 1) {
        break;
      }
      if (row[i]) {
        ok = true;
        break;
      }
    }
    for (int i = target.first; i < m; i++) {
      if (grid[i][target.second] == 1) {
        break;
      }
      if (row[i]) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
