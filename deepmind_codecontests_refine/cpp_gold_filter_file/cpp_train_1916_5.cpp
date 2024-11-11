#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;
const int N = 1e3 + 5;
char field[N][N];
int d[N][N];
int main() {
  int _start = clock();
  int r, c;
  cin >> r >> c;
  int from_x, from_y, to_x, to_y;
  for (int i = 0; i < r; ++i) {
    scanf("\n%s\n", field[i]);
    for (int j = 0; j < c; ++j) {
      d[i][j] = INF;
      if (field[i][j] == 'S') {
        from_x = i;
        from_y = j;
      }
      if (field[i][j] == 'E') {
        to_x = i;
        to_y = j;
      }
    }
  }
  queue<pair<int, int> > q;
  q.push(make_pair(to_x, to_y));
  d[to_x][to_y] = 0;
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (d[nx][ny] == INF && field[nx][ny] != 'T' && d[nx][ny] > d[x][y] + 1) {
        q.push(make_pair(nx, ny));
        d[nx][ny] = d[x][y] + 1;
      }
    }
  }
  int my_d = d[from_x][from_y];
  int answer = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (d[i][j] <= my_d && field[i][j] >= '0' && field[i][j] <= '9') {
        answer += field[i][j] - '0';
      }
    }
  }
  cout << answer << endl;
  cerr << endl
       << endl
       << "Time: " << (double)(clock() - _start) / CLOCKS_PER_SEC << endl;
  return 0;
}
