#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1},
    dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
bool visit[10][10];
string str[10];
bool check(int x, int y) {
  if (x < 0) return 0;
  if (y < 0 || y > 7 || x > 7 || visit[x][y] || str[x][y] == 'S') return 1;
  return 0;
}
int main() {
  for (int i = 0; i < 8; i++) cin >> str[i];
  queue<pair<int, int> > bfs;
  bfs.push(pair<int, int>(7, 0));
  while (bfs.size()) {
    int x = bfs.front().first, y = bfs.front().second;
    bfs.pop();
    if (check(x, y)) continue;
    if (x <= 0) return cout << "WIN\n", 0;
    visit[x][y] = 1;
    for (int i = 0; i < 9; i++) {
      if (x + dx[i] > 7 || y + dy[i] < 0 || y + dy[i] > 7) continue;
      if (str[x + dx[i]][y + dy[i]] != 'S')
        bfs.push(pair<int, int>(x + dx[i] - 1, y + dy[i]));
    }
  }
  cout << "LOSE\n";
  return 0;
}
