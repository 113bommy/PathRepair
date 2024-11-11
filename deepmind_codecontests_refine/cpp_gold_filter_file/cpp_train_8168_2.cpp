#include <bits/stdc++.h>
using namespace std;
const int N = 2015;
const int dx[] = {0, 1, 1, 0};
const int dy[] = {0, 0, 1, 1};
int used[N][N], n, m;
char board[N][N];
queue<pair<int, int> > q;
bool bad(int x, int y) {
  int dot = 0, flake = 0;
  for (int i = 0; i < 4; i++) {
    dot += board[x + dx[i]][y + dy[i]] == '.';
    flake += board[x + dx[i]][y + dy[i]] == '*';
  }
  if (dot == 3 && flake == 1)
    return true;
  else
    return false;
}
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) scanf("%c", &board[i][j]);
    scanf("\n");
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (bad(i, j)) q.push(make_pair(i, j));
    }
  }
  while (!q.empty()) {
    pair<int, int> v = q.front();
    q.pop();
    int x = v.first, y = v.second;
    if (board[x][y] != '*' && board[x + 1][y] != '*' &&
        board[x + 1][y + 1] != '*' && board[x][y + 1] != '*')
      continue;
    board[x][y] = '.';
    board[x + 1][y] = '.';
    board[x + 1][y + 1] = '.';
    board[x][y + 1] = '.';
    if (bad(x, y + 1)) q.push(make_pair(x, y + 1));
    if (bad(x + 1, y)) q.push(make_pair(x + 1, y));
    if (bad(x + 1, y + 1)) q.push(make_pair(x + 1, y + 1));
    if (bad(x - 1, y)) q.push(make_pair(x - 1, y));
    if (bad(x - 1, y - 1)) q.push(make_pair(x - 1, y - 1));
    if (bad(x, y - 1)) q.push(make_pair(x, y - 1));
    if (bad(x, y)) q.push(make_pair(x, y));
    if (bad(x - 1, y + 1)) q.push(make_pair(x - 1, y + 1));
    if (bad(x + 1, y - 1)) q.push(make_pair(x + 1, y - 1));
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%c", board[i][j]);
    printf("\n");
  }
  return 0;
}
