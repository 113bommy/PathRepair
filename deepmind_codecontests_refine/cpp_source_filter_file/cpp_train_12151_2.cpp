#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int MAX = 1e9 + 1;
int n, m;
char mp[100][100];
int c(int x, int y) {
  int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int cnt = 0;
  for (int i = 0; i < 8; ++i) {
    int tx = dx[i] + x;
    int ty = dy[i] + y;
    if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
    if (mp[tx][ty] == '*') ++cnt;
  }
  return cnt;
}
bool ok() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '*') continue;
      if (mp[i][j] == '.') {
        if (c(i, j) != 0) return 0;
      } else {
        if (c(i, j) != mp[i][j] - '0') return 0;
      }
    }
  }
  return 1;
}
int main() {
  int i, j;
  cin >> n >> m;
  for (i = 0; i < n; ++i) {
    cin >> mp[i];
  }
  if (ok()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
