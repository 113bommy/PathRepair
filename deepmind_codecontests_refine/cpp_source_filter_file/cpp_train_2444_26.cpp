#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e9;
const int N = 1e5 + 10;
const double EPS = (1e-9);
string str[55];
bool visit[55][55];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, n, m;
bool check(int x, int y, char c) {
  if (x < 0 || y < 0 || x == n || y == m || c != str[x][y]) return 0;
  return 1;
}
bool dfs(int x, int y, char &c, int lastx, int lasty) {
  if (visit[x][y]) return 1;
  visit[x][y] = 1;
  bool ret = 0;
  for (int i = 0; i < 4; i++) {
    if (check(x + dx[i], y + dy[i], c) &&
        (!(x + dx[i] == lastx) || !(y + dy[i] == lasty)))
      ret |= dfs(x + dx[i], y + dy[i], c, x, y);
  }
  return ret;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> str[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visit[i][j] && dfs(i, j, str[i][j], -1, -1))
        return cout << "Yes\n", 0;
    }
  }
  return cout << "No\n", 0;
}
