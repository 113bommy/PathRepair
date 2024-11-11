#include <bits/stdc++.h>
using namespace std;
const int mn = 1010;
int n, m, tot;
int vis[mn], nc = 0;
bool g[mn][mn];
vector<int> e[mn];
void dfs(int r) {
  vis[r] = nc;
  for (int p = 0; p < e[r].size(); ++p) {
    int i = e[r][p];
    if (vis[i] != nc) {
      dfs(i);
      break;
    }
  }
}
bool cmp(int i, int j) {
  if (e[i].size() == e[j].size()) return i < j;
  return e[i].size() > e[j].size();
}
int main() {
  scanf("%d%d", &n, &m);
  int i, j, k;
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &j, &k);
    if (j != k && !g[j][k]) {
      g[j][k] = g[k][j] = 1;
      e[j].push_back(k), e[k].push_back(j);
    }
  }
  for (i = 1; i <= n; ++i) sort(e[i].begin(), e[i].end(), cmp);
  for (i = 1; i <= n; ++i) {
    ++nc, tot = 0;
    dfs(i);
    for (j = 1; j <= n; ++j) tot += vis[j] == nc;
    if (tot == n) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
