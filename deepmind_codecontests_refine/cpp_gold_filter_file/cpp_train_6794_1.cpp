#include <bits/stdc++.h>
using namespace std;
int n, m, k, chu[200010];
int hah[10][10][10][10], haha[10][10];
int st[10], ans, vis[200010];
vector<int> g[10];
vector<pair<int, int> > f1[200010];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool pd() {
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      if (i != j) {
        if (hah[i][st[i]][j][st[j]] || haha[i][st[i]] || haha[j][st[j]])
          return false;
      }
    }
  }
  if (k == 1)
    if (haha[1][1]) return false;
  return true;
}
void dfs(int now) {
  if (now > k) {
    if (pd()) ans++;
    return;
  }
  for (int i = 1; i <= now; i++) {
    st[now] = i;
    dfs(now + 1);
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    chu[u]++;
    f1[u].push_back(make_pair(v, w));
  }
  for (int i = 1; i <= n; i++) sort(f1[i].begin(), f1[i].end(), cmp);
  for (int i = 1; i <= n; i++) g[chu[i]].push_back(i);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= i; j++) {
      for (int x = 1; x <= k; x++) {
        for (int y = 1; y <= x; y++) {
          for (unsigned l = 0; l < g[i].size(); l++) {
            int now = g[i][l];
            vis[f1[now][j - 1].first]++;
          }
          if (i != x) {
            for (unsigned l = 0; l < g[x].size(); l++) {
              int now = g[x][l];
              vis[f1[now][y - 1].first]++;
            }
          }
          for (int l = 1; l <= n; l++) {
            if (vis[l] > 1) {
              if (i == x && j == y)
                haha[i][j] = 1;
              else
                hah[i][j][x][y] = 1;
            }
            vis[l] = 0;
          }
        }
      }
    }
  }
  dfs(1);
  printf("%d\n", ans);
  return 0;
}
