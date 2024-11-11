#include <bits/stdc++.h>
using namespace std;
int main() {
  queue<pair<int, int> > amoves;
  int n, m;
  cin >> n >> m;
  char matrix[n + 2][m + 2];
  int visited[n + 2][m + 2];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      matrix[i][j] = 'O';
      visited[i][j] = false;
    }
  }
  for (int i = 0; i <= m + 1; i++) {
    matrix[0][i] = 'X';
    matrix[n + 1][i] = 'X';
  }
  for (int i = 0; i <= n + 1; i++) {
    matrix[i][0] = 'X';
    matrix[i][m + 1] = 'X';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> matrix[i][j];
      visited[i][j] = false;
    }
  }
  int sx, sy;
  int ex, ey;
  cin >> sx >> sy;
  cin >> ex >> ey;
  if (sx == ex && sy == ey) {
    if (matrix[sx][sy - 1] != 'X' || matrix[sx][sy + 1] != 'X' ||
        matrix[sx - 1][sy] != 'X' || matrix[sx + 1][sy] != 'X') {
      cout << "YES" << endl;
      return 0;
    }
    cout << "NO" << endl;
    return 0;
  }
  amoves.push(make_pair(sx, sy));
  while (amoves.size() > 0) {
    pair<int, int> pos = amoves.front();
    amoves.pop();
    visited[pos.first][pos.second] = true;
    int xx = pos.first;
    int yy = pos.second;
    if (matrix[xx][yy - 1] != 'X' && visited[xx][yy - 1] == false) {
      amoves.push(make_pair(xx, yy - 1));
      matrix[xx][yy - 1] = 'X';
      visited[xx][yy - 1] = true;
    } else if (xx == ex && yy - 1 == ey) {
      cout << "YES" << endl;
      return 0;
    }
    if (matrix[xx][yy + 1] != 'X' && visited[xx][yy + 1] == false) {
      amoves.push(make_pair(xx, yy + 1));
      matrix[xx][yy + 1] = 'X';
      visited[xx][yy + 1] = true;
    } else if (xx == ex && yy + 1 == ey) {
      cout << "YES" << endl;
      return 0;
    }
    if (matrix[xx - 1][yy] != 'X' && visited[xx - 1][yy] == false) {
      amoves.push(make_pair(xx - 1, yy));
      matrix[xx - 1][yy] = 'X';
      visited[xx - 1][yy] = true;
    } else if (xx + 1 == ex && yy == ey) {
      cout << "YES" << endl;
      return 0;
    }
    if (matrix[xx + 1][yy] != 'X' && visited[xx + 1][yy] == false) {
      visited[xx + 1][yy] = true;
      matrix[xx + 1][yy] = 'X';
      amoves.push(make_pair(xx + 1, yy));
    } else if (xx + 1 == ex && yy == ey) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      cout << matrix[i][j];
    }
    cout << endl;
  }
  return 0;
}
