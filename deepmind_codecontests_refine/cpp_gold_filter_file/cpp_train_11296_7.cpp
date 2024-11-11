#include <bits/stdc++.h>
using namespace std;
long long grid[1100][1100];
long long vis[1100][1100];
long long X[] = {0, 0, 1, -1};
long long Y[] = {-1, 1, 0, 0};
long long ans, n, m, k;
const long long sz = 1e6;
long long cc[sz];
map<pair<long long, long long>, long long> mp;
void dfs(long long x, long long y, long long cur) {
  vis[x][y] = 1;
  mp[{x, y}] = cur;
  for (int i = 0; i < 4; i++) {
    long long curX = x + X[i], curY = y + Y[i];
    if (curX >= 0 && curX < n && curY >= 0 && curY < m &&
        vis[curX][curY] == 0) {
      if (grid[curX][curY] == 0)
        ans++;
      else
        dfs(curX, curY, cur);
    }
  }
}
void compute() {
  long long cur = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == 0 && grid[i][j] == 1) {
        dfs(i, j, cur);
        cc[cur] = ans;
        cur++;
        ans = 0;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      if (x == '.') grid[i][j] = 1;
    }
  compute();
  while (k--) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    cout << cc[mp[{x, y}]] << "\n";
  }
}
