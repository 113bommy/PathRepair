#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[505][505];
bool vis[505][505];
bool vis2[250005];
int val[250005];
int ans[505][505];
vector<int> g[250005];
int idx[505][505], id = 1;
void dfs(int x, int y) {
  vis[x][y] = 1;
  idx[x][y] = id;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (1 <= x + i && x + i <= n && 1 <= y + j && y + j <= m &&
          !vis[x + i][y + j] && s[x + i][y + j] == '.')
        dfs(x + i, y + j);
    }
  }
}
void dfs2(int u, int c) {
  val[u] = c;
  vis2[u] = 1;
  for (int i = 0; i < (int)(g[u]).size(); i++) {
    int v = g[u][i];
    if (vis2[v]) continue;
    dfs2(v, c ^ 1);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.' && !vis[i][j]) {
        dfs(i, j);
        id++;
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      ans[i][j] = j % 2;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        int cnt = (s[i][j - 1] == '.') + (s[i][j + 1] == '.') +
                  (s[i - 1][j] == '.') + (s[i + 1][j] == '.');
        if (cnt % 2 == 1) {
          printf("NO\n");
          return 0;
        }
        if (cnt == 2 && s[i][j - 1] == '.' && s[i][j + 1] == '.' &&
            idx[i][j - 1] != idx[i][j + 1]) {
          g[idx[i][j - 1]].emplace_back(idx[i][j + 1]);
          g[idx[i][j + 1]].emplace_back(idx[i][j - 1]);
        }
        if (cnt == 2 && s[i - 1][j] == '.' && s[i + 1][j] == '.' &&
            idx[i - 1][j] != idx[i + 1][j]) {
          g[idx[i - 1][j]].emplace_back(idx[i + 1][j]);
          g[idx[i + 1][j]].emplace_back(idx[i - 1][j]);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis2[idx[i][j]]) continue;
      dfs2(idx[i][j], 0);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.' && val[idx[i][j]] == 1) {
        ans[i][j] ^= 1;
      }
      if (s[i][j] == '.') {
        if (!ans[i][j]) ans[i][j] = 4;
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        ans[i][j] = 0;
        if (s[i][j - 1] == '.') ans[i][j] += ans[i][j - 1];
        if (s[i][j + 1] == '.') ans[i][j] += ans[i][j + 1];
        if (s[i - 1][j] == '.') ans[i][j] += ans[i - 1][j];
        if (s[i + 1][j] == '.') ans[i][j] += ans[i + 1][j];
      }
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
}
