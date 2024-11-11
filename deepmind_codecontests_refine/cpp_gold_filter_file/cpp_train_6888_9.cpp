#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct node {
  int u, w;
};
bool vis[1004];
vector<node> v[1004];
int ans[1004][1004];
int Find(int u, int pre) {
  vis[u] = 1;
  if (v[u].size() == 1) return u;
  for (int i = 0; i < v[u].size(); ++i) {
    if (v[u][i].u == pre) continue;
    if (vis[v[u][i].u]) continue;
    return Find(v[u][i].u, u);
  }
}
void dfs(int u, int pre, int w) {
  if (w != 0) {
    if (v[u].size() != 1 && v[pre].size() != 1) {
      memset(vis, 0, sizeof(vis));
      int x = Find(u, pre);
      int y = Find(u, pre);
      int a = Find(pre, u);
      int b = Find(pre, u);
      ans[x][a] += w / 2;
      ans[y][b] += w / 2;
      ans[x][y] -= w / 2;
      ans[a][b] -= w / 2;
      ans[a][x] += w / 2;
      ans[b][y] += w / 2;
      ans[y][x] -= w / 2;
      ans[b][a] -= w / 2;
    } else if (v[u].size() != 1 && v[pre].size() == 1) {
      memset(vis, 0, sizeof(vis));
      int x = Find(u, pre);
      int y = Find(u, pre);
      ans[pre][x] += w / 2;
      ans[pre][y] += w / 2;
      ans[y][x] -= w / 2;
      ans[x][pre] += w / 2;
      ans[y][pre] += w / 2;
      ans[x][y] -= w / 2;
    } else if (v[u].size() == 1 && v[pre].size() != 1) {
      memset(vis, 0, sizeof(vis));
      int a = Find(pre, u);
      int b = Find(pre, u);
      ans[u][a] += w / 2;
      ans[u][b] += w / 2;
      ans[b][a] -= w / 2;
      ans[a][u] += w / 2;
      ans[b][u] += w / 2;
      ans[a][b] -= w / 2;
    } else if (v[u].size() == 1 && v[pre].size() == 1) {
      memset(vis, 0, sizeof(vis));
      ans[u][pre] += w;
      ans[pre][u] += w;
    }
  }
  for (int i = 0; i < v[u].size(); ++i) {
    if (v[u][i].u != pre) dfs(v[u][i].u, u, v[u][i].w);
  }
}
int main() {
  int n;
  cin >> n;
  int x, y, z;
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    v[x].push_back({y, z});
    v[y].push_back({x, z});
  }
  for (int i = 1; i <= n; ++i) {
    if (v[i].size() == 2) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  dfs(1, -1, 0);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (ans[i][j] != 0) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (ans[i][j] != 0) {
        printf("%d %d %d\n", i, j, ans[i][j]);
      }
    }
  }
}
