#include <bits/stdc++.h>
using namespace std;
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
char board[20][20];
pair<int, int> pos[10];
int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
char bobord[20][20];
int n, m;
bool find(int x, int y) {
  if (bobord[x][y] == '@') return true;
  bobord[x][y] = '#';
  int x1, y1;
  bool res = false;
  for (int i = 0; i < 4; i++) {
    x1 = x + dir[0][i];
    y1 = y + dir[1][i];
    if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && bobord[x1][y1] != '#')
      res |= find(x1, y1);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int moxo = 0, va;
  deque<pair<int, int>> v;
  int x, y;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] >= '1' && board[i][j] <= '9') {
        va = board[i][j] - '1';
        moxo = max(moxo, va);
        pos[va] = make_pair(i, j);
        board[i][j] = '.';
      } else if (board[i][j] == '@') {
        x = i;
        y = j;
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) bobord[i][j] = board[i][j];
  if (!find(pos[0].first, pos[0].second)) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < moxo + 1; i++) v.push_back(pos[i]);
  map<deque<pair<int, int>>, bool> visited;
  visited[v] = 1;
  priority_queue<pair<pair<int, int>, deque<pair<int, int>>>> que;
  que.push(make_pair(make_pair(0, 0), v));
  int pas;
  pair<int, int> ax, neo;
  while (!que.empty()) {
    pas = que.top().first.second;
    if (pas < -300) break;
    v = que.top().second;
    que.pop();
    for (int i = 1; i < v.size() - 1; i++) board[v[i].first][v[i].second] = '#';
    for (int i = 0; i < 4; i++) {
      neo = {v.front().first + dir[0][i], v.front().second + dir[1][i]};
      if (neo.first >= 0 && neo.first < n && neo.second >= 0 &&
          neo.second < m) {
        if (board[neo.first][neo.second] == '.') {
          ax = v.back();
          v.pop_back();
          v.push_front(neo);
          if (!visited[v]) {
            que.push(
                {{-abs(neo.first - x) - abs(neo.second - y) + pas - 1, pas - 1},
                 v});
            visited[v] = 1;
          }
          v.pop_front();
          v.push_back(ax);
        } else if (board[neo.first][neo.second] == '@') {
          cout << -pas + 1;
          return 0;
        }
      }
    }
    for (int i = 1; i < v.size() - 1; i++) board[v[i].first][v[i].second] = '.';
  }
  cout << "-1";
  return 0;
}
