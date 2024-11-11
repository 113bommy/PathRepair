#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 5;
char a[2][nax];
bool visited[2][nax];
bool path(int x, int y, int water_lvl) {
  return (y > (water_lvl) && a[x][y] != 'X');
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  queue<pair<int, pair<int, int>>> q;
  q.push(make_pair(0, make_pair(0, 1)));
  visited[0][1] = true;
  while (!q.empty()) {
    int cur_wall = q.front().second.first;
    int cur_h = q.front().second.second;
    int cur_w = q.front().first;
    if (cur_h >= n) {
      cout << "YES" << endl;
      return 0;
    }
    q.pop();
    if (cur_wall == 0) {
      if (path(cur_wall, cur_h + 1, cur_w + 1) &&
          !visited[cur_wall][cur_h + 1]) {
        q.push({cur_w + 1, {cur_wall, cur_h + 1}});
        visited[cur_wall][cur_h + 1] = true;
      }
      if (path(cur_wall, cur_h - 1, cur_w + 1) &&
          !visited[cur_wall][cur_h - 1]) {
        q.push({cur_w + 1, {cur_wall, cur_h - 1}});
        visited[cur_wall][cur_h - 1] = true;
      }
      if (path(1, cur_h + k, cur_w + 1) && !visited[1][cur_h - 1]) {
        q.push({cur_w + 1, {1, cur_h + k}});
        visited[1][cur_h - 1] = true;
      }
    }
    if (cur_wall == 1) {
      if (path(cur_wall, cur_h + 1, cur_w + 1) &&
          !visited[cur_wall][cur_h + 1]) {
        q.push({cur_w + 1, {cur_wall, cur_h + 1}});
        visited[cur_wall][cur_h + 1] = true;
      }
      if (path(cur_wall, cur_h - 1, cur_w + 1) &&
          !visited[cur_wall][cur_h - 1]) {
        q.push({cur_w + 1, {cur_wall, cur_h - 1}});
        visited[cur_wall][cur_h - 1] = true;
      }
      if (path(0, cur_h + k, cur_w + 1) && !visited[0][cur_h + k]) {
        q.push({cur_w + 1, {0, cur_h + k}});
        visited[0][cur_h + k] = true;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
