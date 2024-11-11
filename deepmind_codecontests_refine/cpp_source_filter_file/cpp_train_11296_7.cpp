#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int vis[1005][1005];
int res[1005];
int ans, n, m;
vector<string> v;
bool valid(int x, int y) {
  if (x >= 0 && y >= 0 && x < n && y < m && v[x][y] != '*') return 1;
  return 0;
}
void dfs(pair<int, int> source, int num) {
  vis[source.first][source.second] = num;
  for (int i = 0; i < 4; i++) {
    pair<int, int> u = make_pair(source.first + dx[i], source.second + dy[i]);
    if (!valid(u.first, u.second))
      ans++;
    else if (!vis[u.first][u.second])
      dfs(u, num);
  }
}
int main() {
  memset(vis, 0, sizeof(vis));
  memset(res, -1, sizeof(res));
  int k, x, y;
  scanf("%d %d %d", &n, &m, &k);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  for (int i = 1; i < k + 1; i++) {
    ans = 0;
    scanf("%d %d", &x, &y);
    if (!vis[x - 1][y - 1]) {
      dfs(make_pair(x - 1, y - 1), i);
      res[i] = ans;
      cout << ans << '\n';
    } else
      cout << res[vis[x - 1][y - 1]] << '\n';
  }
  return 0;
}
