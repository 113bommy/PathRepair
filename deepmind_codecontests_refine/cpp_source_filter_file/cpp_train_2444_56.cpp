#include <bits/stdc++.h>
using namespace std;
int n, m, arr[52][52], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, ans;
pair<int, int> vis[52][52];
stack<pair<int, pair<int, pair<int, int>>>> st;
char ch;
int dfs(int sx, int sy) {
  vis[sx][sy] = {-1, -1};
  st.push({sx, {sy, {-1, -1}}});
  while (!st.empty()) {
    int px = st.top().first;
    int py = st.top().second.first;
    int gx = st.top().second.second.first;
    int gy = st.top().second.second.second;
    st.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = px + dx[i], ny = py + dy[i];
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m &&
          arr[nx][ny] == arr[sx][sy]) {
        if (vis[nx][ny].first == 0 && vis[nx][ny].second == 0) {
          vis[nx][ny] = {px, py};
          st.push({nx, {ny, {px, py}}});
        } else {
          if (gx != nx || gy != ny) ans++;
        }
      }
    }
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> ch;
      arr[i][j] = (ch - 'A') + 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (vis[i][j].first == 0 && vis[i][j].second == 0) {
        ans = 0;
        if (dfs(i, j) > 0) return puts("YES"), 0;
      }
    }
  }
  puts("NO");
}
