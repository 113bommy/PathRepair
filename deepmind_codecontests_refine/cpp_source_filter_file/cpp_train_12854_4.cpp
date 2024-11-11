#include <bits/stdc++.h>
using namespace std;
int n, cnt, m;
int ln, lev, rn, tn, down[2010];
vector<int> edg[2010];
set<int> tree[2010];
int vis[2010], low[2010], dfn[2010];
int p, sp, st[2010], idx[2010];
void CutEdge(int u, int father, int deep) {
  vis[u] = 1;
  dfn[u] = low[u] = deep;
  st[++p] = u;
  for (int i = 0; i < edg[u].size(); i++) {
    int v = edg[u][i];
    if (v == father) continue;
    if (vis[v] == 1) {
      low[u] = min(low[u], dfn[v]);
    } else if (vis[v] == -1) {
      CutEdge(v, u, deep + 1);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        cnt += 1;
        while (st[p] != u) {
          idx[st[p]] = cnt;
          p -= 1;
        }
      }
    }
  }
  vis[u] = 2;
}
void ClearCircle() {
  memset(vis, -1, sizeof(vis));
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] != -1) continue;
    p = 0;
    CutEdge(i, -1, 1);
    cnt += 1;
    while (p) {
      idx[st[p]] = cnt;
      p -= 1;
    }
  }
  for (int i = 1; i <= cnt; i++) tree[i].clear();
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < edg[u].size(); i++) {
      int v = edg[u][i];
      if (idx[u] == idx[v]) continue;
      tree[idx[u]].insert(idx[v]);
    }
  }
}
void dfs(int u, int pre, int deep, int& m) {
  vis[u] = 1;
  low[u] = dfn[u] = deep;
  st[sp++] = u;
  for (int i = 0; i < edg[u].size(); i++) {
    int v = edg[u][i];
    if (v == pre) continue;
    if (vis[v] == 1) {
      low[u] = min(low[u], dfn[v]);
    } else if (vis[v] == -1) {
      dfs(v, u, deep + 1, m);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        do {
          idx[st[--sp]] = m;
        } while (st[sp] != v);
        m++;
      }
    }
  }
  vis[u] = 2;
}
int clearCircle() {
  memset(vis, -1, sizeof(vis));
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] != -1) continue;
    sp = 0;
    dfs(i, -1, 0, m);
    while (sp) idx[st[--sp]] = m;
    m++;
  }
  for (int u = 0; u < n; u++) {
    for (int j = 0; j < edg[u].size(); j++) {
      int v = edg[u][j];
      if (idx[u] != idx[v]) {
        tree[idx[u]].insert(idx[v]);
      }
    }
  }
  return m;
}
void MaxLine(int u, int father) {
  vis[u] = 1;
  if (tree[u].size() <= 1) lev += 1;
  int a = 0, b = 0;
  for (set<int>::iterator it = tree[u].begin(); it != tree[u].end(); it++) {
    int v = *it;
    if (v == father) continue;
    if (vis[v] == -1) {
      MaxLine(v, u);
    }
    if (down[v] > a) {
      b = a;
      a = down[v];
    } else if (down[v] > b) {
      b = down[v];
    }
  }
  down[u] = a + 1;
  ln = max(ln, a + b + 1);
}
int max1[2010], max2[2010];
int leave;
int dfs(int u) {
  int add = 0;
  if (tree[u].size() > 1)
    add = 1;
  else
    leave++;
  int ret = 0;
  for (set<int>::iterator it = tree[u].begin(); it != tree[u].end(); it++) {
    int v = *it;
    if (vis[v] != -1) continue;
    vis[v] = 1;
    ret = max(ret, dfs(v));
    if (max1[u] < max1[v]) {
      max2[u] = max1[u];
      max1[u] = max1[v];
    } else if (max2[u] < max1[v]) {
      max2[u] = max1[v];
    }
  }
  max1[u] += add;
  ret = max(ret, max1[u] + max2[u]);
  return ret;
}
int main(int argc, char** argv) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) edg[i].clear();
  int a, b;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    edg[a].push_back(b);
    edg[b].push_back(a);
  }
  cnt = clearCircle();
  int ans = n;
  memset(vis, -1, sizeof(vis));
  for (int i = 1; i <= cnt; i++) {
    if (vis[i] == 1) continue;
    leave = 0;
    vis[i] = 1;
    ans -= leave + dfs(i) - 1;
  }
  cout << ans - 1 << endl;
  return (EXIT_SUCCESS);
}
