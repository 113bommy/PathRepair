#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110, inf = 0x3f3f3f3f;
char mp[MAXN][MAXN];
int n, m;
char button[4] = {
    'U',
    'D',
    'L',
    'R',
};
int x, y;
void Move(int i) {
  cout << button[i] << endl;
  cin >> x >> y;
  --x;
  --y;
}
bool check() { return mp[x][y] == 'F'; }
int d[MAXN][MAXN];
int last[MAXN][MAXN];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", mp[i]);
  if (mp[0][1] != '*' && mp[1][0] != '*') {
    {
      Move(1);
      if (check()) return 0;
    };
    if (x == 0 && y == 0)
      swap(button[0], button[1]);
    else {
      Move(0);
      if (check()) return 0;
    };
    {
      Move(3);
      if (check()) return 0;
    };
    if (x == 0 && y == 0)
      swap(button[2], button[3]);
    else {
      Move(2);
      if (check()) return 0;
    };
  } else if (mp[0][1] == '.') {
    {
      Move(3);
      if (check()) return 0;
    };
    if (x == 0 && y == 0)
      swap(button[2], button[3]);
    else {
      Move(2);
      if (check()) return 0;
    };
    while (mp[x + 1][y] != '.') {
      Move(3);
      if (check()) return 0;
    };
    {
      Move(1);
      if (check()) return 0;
    };
    if (x == 0) swap(button[0], button[1]);
  } else {
    {
      Move(1);
      if (check()) return 0;
    };
    if (x == 0 && y == 0)
      swap(button[0], button[1]);
    else {
      Move(0);
      if (check()) return 0;
    };
    while (mp[x][y + 1] != '.') {
      Move(1);
      if (check()) return 0;
    };
    {
      Move(3);
      if (check()) return 0;
    };
    if (y == 0) swap(button[2], button[2]);
  }
  memset(d, inf, sizeof(d));
  d[x][y] = 0;
  int x0 = x, y0 = y;
  queue<pair<int, int> > que;
  que.push(pair<int, int>(x0, y0));
  int dx[] = {
      -1,
      1,
      0,
      0,
  };
  int dy[] = {
      0,
      0,
      -1,
      1,
  };
  int fx, fy;
  while (!que.empty()) {
    pair<int, int> p = que.front();
    que.pop();
    if (mp[p.first][p.second] == 'F') {
      fx = p.first;
      fy = p.second;
      break;
    }
    for (int i = 0; i < 4; ++i) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (0 <= nx && nx < n && 0 <= ny && ny < m && mp[nx][ny] != '*' &&
          d[nx][ny] == inf) {
        que.push(pair<int, int>(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
        last[nx][ny] = i;
      }
    }
  }
  vector<int> path;
  auto f = [&](int i) {
    fx += dx[i];
    fy += dy[i];
  };
  while (true) {
    if (fx == x0 && fy == y0) break;
    if (last[fx][fy] == 0)
      path.push_back(0), f(1);
    else if (last[fx][fy] == 1)
      path.push_back(1), f(0);
    else if (last[fx][fy] == 2)
      path.push_back(2), f(3);
    else if (last[fx][fy] == 3)
      path.push_back(3), f(2);
  }
  for (int i = int(path.size() - 1); i >= 0; --i) {
    {
      Move(path[i]);
      if (check()) return 0;
    };
  }
  return 0;
}
