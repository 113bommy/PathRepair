#include <bits/stdc++.h>
using namespace std;
int N, M;
int fa[600005];
long long sz[600005];
int findR(int x) {
  if (x == fa[x])
    return x;
  else
    return fa[x] = findR(fa[x]);
}
bool chk(int u, int v) { return findR(u) == findR(v); }
void merge(int u, int v) {
  int ru = findR(u), rv = findR(v);
  if (ru != rv) {
    sz[rv] += sz[ru];
    fa[ru] = rv;
  }
}
int vis[600005];
vector<int> adj[600005];
char s[600005];
int main() {
  scanf("%d%d", &N, &M);
  scanf("%s", s + 1);
  for (int i = 1; i <= 2 * M; i++) {
    fa[i] = i;
    if (i <= M) sz[i] = 1;
  }
  int n, j;
  for (int i = 1; i <= M; i++) {
    scanf("%d", &n);
    while (n--) {
      scanf("%d", &j);
      adj[j].push_back(i);
    }
  }
  int ans = 0;
  int x, y;
  for (int i = 1; i <= N; i++) {
    if (adj[i].size() == 1) {
      x = adj[i][0];
      if (vis[x]) ans -= min(sz[findR(x)], sz[findR(x + N)]);
      if (s[i] == '0')
        sz[findR(x + M)] = int(1e6);
      else
        sz[findR(x)] = int(1e6);
      ans += min(sz[findR(x)], sz[findR(x + M)]);
      vis[x] = 1;
    } else if (adj[i].size() == 2) {
      x = adj[i][0];
      y = adj[i][1];
      if (chk(x, y) || chk(x, y + M))
        ans -= min(sz[findR(x)], sz[findR(x + M)]);
      else {
        if (vis[x]) ans -= min(sz[findR(x)], sz[findR(x + M)]);
        if (vis[y]) ans -= min(sz[findR(y)], sz[findR(y + M)]);
      }
      if (s[i] == '1') {
        merge(x, y);
        merge(x + M, y + M);
      } else {
        merge(x, y + M);
        merge(x + M, y);
      }
      ans += min(sz[findR(x)], sz[findR(x + M)]);
      vis[x] = vis[y] = 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
