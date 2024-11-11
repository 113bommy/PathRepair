#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, +1, 0, 0}, dy[4] = {0, 0, -1, +1};
int main() {
  int n, m;
  cin >> n >> m;
  char gr[n][m];
  int sx, sy, fx, fy;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> gr[i][j];
      if (gr[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (gr[i][j] == 'E') {
        fx = i;
        fy = j;
      }
    }
  }
  string s;
  cin >> s;
  int ln = s.size();
  int dr[4] = {0, 1, 2, 3};
  int cnt = 0;
  do {
    int x = sx, y = sy;
    for (int i = 0; i < ln; i++) {
      x += dx[dr[s[i] - '0']];
      y += dy[dr[s[i] - '0']];
      if (x > n - 1 || x < 0 || y > m - 1 || y < 0) {
        break;
      } else if (gr[x][y] == '#') {
        break;
      } else if (gr[x][y] == 'E') {
        cnt++;
        break;
      }
    }
  } while (next_permutation(dr, dr + 4));
  cout << cnt;
}
