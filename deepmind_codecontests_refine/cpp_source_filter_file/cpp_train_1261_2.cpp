#include <bits/stdc++.h>
using namespace std;
char x;
int n, m, y, z;
const int N = 1005;
vector<pair<char, int> > dir;
vector<pair<int, int> > to;
char grid[N][N];
int north[N][N];
int south[N][N];
int east[N][N];
int west[N][N];
bool valid(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
bool dfs(int x, int y, int inst) {
  if (inst == dir.size()) return 1;
  if (dir[inst].first == 'N') {
    if (valid(x - dir[inst].second, y) && north[x][y] >= dir[inst].second)
      return dfs(x - dir[inst].second, y, inst + 1);
  } else if (dir[inst].first == 'S') {
    if (valid(x + dir[inst].second, y) && south[x][y] >= dir[inst].second)
      return dfs(x + dir[inst].second, y, inst + 1);
  } else if (dir[inst].first == 'E') {
    if (valid(x, y + dir[inst].second) && east[x][y] >= dir[inst].second)
      return dfs(x, y + dir[inst].second, inst + 1);
  } else if (dir[inst].first == 'W') {
    if (valid(x, y - dir[inst].second) && west[x][y] >= dir[inst].second)
      return dfs(x, y + dir[inst].second, inst + 1);
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (isalpha(grid[i][j])) to.push_back({i, j});
    }
  }
  for (int j = 0; j < m; j++) {
    int counter = 0, counter2 = 0;
    for (int i = 0; i < n; i++) {
      north[i][j] = counter;
      south[n - i - 1][j] = counter2;
      if (grid[i][j] == '#')
        counter = 0;
      else
        counter++;
      if (grid[n - 1 - i][j] == '#')
        counter2 = 0;
      else
        counter2++;
    }
  }
  for (int i = 0; i < n; i++) {
    int counter = 0, counter2 = 0;
    for (int j = 0; j < m; j++) {
      east[i][m - 1 - j] = counter;
      west[i][j] = counter2;
      if (grid[i][m - 1 - j] == '#')
        counter = 0;
      else
        counter++;
      if (grid[i][j] == '#')
        counter2 = 0;
      else
        counter2++;
    }
  }
  cin >> z;
  while (z--) {
    cin >> x >> y;
    dir.push_back({x, y});
  }
  string ans;
  for (auto i : to) {
    if (dfs(i.first, i.second, 0)) ans += grid[i.first][i.second];
  }
  if (ans.empty()) return cout << "no solution", 0;
  sort(ans.begin(), ans.end());
  cout << ans;
  return 0;
}
