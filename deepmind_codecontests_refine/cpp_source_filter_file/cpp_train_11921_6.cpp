#include <bits/stdc++.h>
using namespace std;
const int N = 755;
const int M = 1e7 + 5;
int n, size;
int ed[N], gt[M], trie[M][2], fa[M], d[N][N], f[N], vis[N], fail[M];
char s[M];
queue<int> q;
inline bool dfs(int x) {
  for (int i = 1; i <= n; ++i) {
    if (d[x][i] && !vis[i]) {
      vis[i] = 1;
      if (!f[i] || dfs(f[i])) return (f[i] = x);
    }
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  size = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int p = 1;
    for (int j = 1; j <= len; ++j) {
      int ch = s[j] - 'a';
      if (!trie[p][ch]) trie[p][ch] = ++size, fa[size] = p;
      p = trie[p][ch];
    }
    ed[i] = p, gt[p] = i;
  }
  for (int i = 0; i < 2; ++i)
    if (trie[1][i])
      fail[trie[1][i]] = 1, q.push(trie[1][i]);
    else
      trie[1][i] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 2; ++i) {
      if (trie[u][i]) {
        fail[trie[u][i]] = trie[fail[u]][i];
        q.push(trie[u][i]);
      } else
        trie[u][i] = trie[fail[u]][i];
    }
  }
  gt[1] = -1;
  vector<int> o;
  o.clear();
  for (int i = 1; i <= n; ++i) {
    for (int j = ed[i]; j != 1; j = fa[j]) {
      int x = fail[j];
      o.clear();
      while (!gt[x]) o.emplace_back(x), x = fail[x];
      while (o.size()) fail[o.back()] = x, o.pop_back();
      fail[j] = x;
      if (j != ed[i] && gt[j]) x = j;
      if (x != 1) d[i][gt[x]] = 1;
    }
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) d[i][j] |= d[i][k] & d[k][j];
  for (int i = 1; i <= n; ++i) d[i][i] = 0;
  int ans = n;
  for (int i = 1; i <= n; ++i) ans -= dfs(i);
  memset(vis, 0, sizeof(vis));
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) vis[f[i]] = 1;
  vector<int> s;
  s.clear();
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) s.emplace_back(i);
  memset(vis, 0, sizeof(vis));
  bool ok = 1;
  while (ok) {
    ok = 0;
    for (int x : s)
      for (int y = 1; y <= n; ++y)
        if (d[x][y]) vis[y] = 1;
    for (int &x : s)
      if (vis[x]) {
        ok = 1;
        while (vis[x]) x = f[x];
      }
  }
  for (int x : s) printf("%d ", x);
  printf("\n");
  return 0;
}
