#include <bits/stdc++.h>
using namespace std;
inline int next_int() {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  int r = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') r = r * 10 + c - '0';
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  int arr[105][105];
  int row[105];
  int col[105];
  while (cin >> n >> m) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> arr[i][j];
      }
    }
    if (n <= m) {
      for (int i = 0; i < n; ++i) {
        row[i] = 0x3f3f3f3f;
        for (int j = 0; j < m; ++j) {
          row[i] = min(row[i], arr[i][j]);
        }
        if (row[i]) {
          for (int j = 0; j < m; ++j) {
            arr[i][j] -= row[i];
          }
        }
        ans += row[i];
      }
      for (int j = 0; j < m; ++j) {
        col[j] = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
          col[j] = min(col[j], arr[i][j]);
        }
        if (col[j]) {
          for (int i = 0; i < n; ++i) {
            arr[i][j] -= col[j];
          }
        }
        ans += col[j];
      }
    } else {
      for (int j = 0; j < m; ++j) {
        col[j] = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
          col[j] = min(col[j], arr[i][j]);
        }
        if (col[j]) {
          for (int i = 0; i < n; ++i) {
            arr[i][j] -= col[j];
          }
        }
        ans += col[j];
      }
      for (int i = 0; i < n; ++i) {
        row[i] = 0x3f3f3f3f;
        for (int j = 0; j < m; ++j) {
          row[i] = min(row[i], arr[i][j]);
        }
        if (row[i]) {
          for (int j = 0; j < m; ++j) {
            arr[i][j] -= row[i];
          }
        }
        ans += row[i];
      }
    }
    bool type = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (arr[i][j]) {
          cout << "-1" << endl;
          type = true;
          break;
        }
      }
      if (type) break;
    }
    if (!type) {
      cout << ans << endl;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < row[i]; ++j) {
          cout << "row " << i + 1 << endl;
        }
      }
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < col[i]; ++j) {
          cout << "col " << i + 1 << endl;
        }
      }
    }
  }
  return 0;
}
