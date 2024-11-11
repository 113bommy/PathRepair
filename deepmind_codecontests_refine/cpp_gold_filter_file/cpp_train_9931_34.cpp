#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1604;
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int img[MAXN][MAXN];
int bnd[MAXN][MAXN];
int ray[MAXN][MAXN];
int vis[MAXN][MAXN];
pair<int, int> q[MAXN * MAXN];
vector<int> ans;
int h, t;
bool isimg(int i, int j) { return i >= 0 && j >= 0 && img[i][j]; }
bool isbnd(int i, int j) { return i >= 0 && j >= 0 && bnd[i][j]; }
bool isray(int i, int j) { return i >= 0 && j >= 0 && ray[i][j]; }
int dfs(int i, int j) {
  int size = 1;
  int first, second;
  vis[i][j] = 1;
  q[t++] = make_pair(i, j);
  for (int d = 0; d < 8; d++) {
    first = i + dx[d];
    second = j + dy[d];
    if (isray(first, second) && !vis[first][second]) size += dfs(first, second);
  }
  return size;
}
void bfs(int i, int j) {
  int first, second;
  int ans = 0;
  h = t = 0;
  if (isray(i, j)) {
    if (dfs(i, j) >= 6) ans++;
  } else {
    q[t++] = make_pair(i, j);
    vis[i][j] = 1;
  }
  while (h < t) {
    i = q[h].first;
    j = q[h].second;
    h++;
    for (int d = 0; d < 8; d++) {
      first = i + dx[d];
      second = j + dy[d];
      if (isimg(first, second) && !vis[first][second])
        if (ray[first][second]) {
          if (dfs(first, second) >= 6) ans++;
        } else {
          q[t++] = make_pair(first, second);
          vis[first][second] = 1;
        }
    }
  }
  ::ans.push_back(ans);
}
int main() {
  int n, m;
  int i, j, k;
  int first, second;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &img[i][j]);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (isimg(i, j))
        for (int d = 0; d < 8; d++)
          if (!isimg(i + dx[d], j + dy[d])) {
            bnd[i][j] = 1;
            break;
          }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (isimg(i, j) && !isbnd(i, j))
        for (int d = 0; d < 4; d++)
          if (isbnd(i + dx[d], j + dy[d]) && isbnd(i - dx[d], j - dy[d])) {
            ray[i][j] = 1;
            break;
          }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (img[i][j] && !vis[i][j]) {
        bfs(i, j);
      }
    }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
