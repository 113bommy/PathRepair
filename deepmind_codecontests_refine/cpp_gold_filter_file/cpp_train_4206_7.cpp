#include <bits/stdc++.h>
using namespace std;
const int N = 605, INF = 0x3f3f3f3f;
int n, u, v, a[N], pos[N], dfn[N], id[N], lf, tot, b[N];
vector<int> e[N];
bool cmp(int x, int y) { return id[x] < id[y]; }
void dfs(int u, int fa) {
  int c = 0;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v == fa) continue;
    dfs(v, u);
    c++;
  }
  if (c == 0) lf++;
}
void dfs2(int u, int fa) {
  int c = 0;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v == fa) continue;
    dfs2(v, u);
    c++;
    id[u] = min(id[u], id[v]);
  }
  if (c == 0) id[u] = pos[u];
}
void dfs3(int u, int fa) {
  dfn[u] = ++tot;
  b[tot] = u;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v == fa) continue;
    dfs3(v, u);
    b[++tot] = u;
  }
}
int main() {
  scanf("%d", &n);
  memset(id, INF, sizeof id);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= lf; ++i) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  dfs2(1, -1);
  for (int i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end(), cmp);
  }
  dfs3(1, -1);
  bool ok = 1;
  for (int i = 1; i <= lf; ++i) {
    for (int j = i + 1; j <= lf; ++j) {
      if (dfn[a[i]] > dfn[a[j]]) {
        ok = 0;
      }
    }
  }
  if (!ok)
    puts("-1");
  else {
    for (int i = 1; i <= tot; ++i) {
      printf("%d%c", b[i], " \n"[i == tot]);
    }
  }
  return 0;
}
