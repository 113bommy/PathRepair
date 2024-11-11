#include <bits/stdc++.h>
using namespace std;
namespace flyinthesky {
const int MAXN = 750 + 5, MAXV = 10000000 + 5;
int n, sz, G[MAXN][MAXN], ch[MAXV][2], id[MAXV], f[MAXV];
char s[MAXV];
string str[MAXN];
void ins(int ith) {
  int now = 0, len = strlen(s);
  for (int i = 0; i < len; ++i) {
    int c = s[i] - 'a';
    if (!ch[now][c]) ch[now][c] = ++sz;
    now = ch[now][c];
    if (i == len - 1) id[now] = ith;
  }
}
void getFail() {
  queue<int> q;
  f[0] = 0;
  for (int c = 0; c < 2; ++c) {
    int v = ch[0][c];
    if (v) q.push(v), f[v] = 0;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int c = 0; c < 2; ++c) {
      int v = ch[u][c];
      if (!ch[u][c]) {
        ch[u][c] = ch[f[u]][c];
        continue;
      }
      q.push(v);
      int j = f[u];
      while (j && !ch[j][c]) j = f[j];
      f[v] = ch[j][c];
      if (!id[v]) id[v] = id[f[v]];
    }
  }
}
void find(int ith) {
  int now = 0;
  for (int i = 0; i < (int)str[ith].length(); ++i) {
    int c = str[ith][i] - 'a';
    now = ch[now][c];
    if (id[now]) G[ith][id[now]] = 1;
    if (id[f[now]]) G[ith][id[f[now]]] = 1;
  }
}
int vis[MAXN], lk[MAXN], to[MAXN], cnt;
bool hungary(int u) {
  for (int v = 1; v <= n; ++v)
    if (G[u][v]) {
      if (vis[v] != cnt) {
        vis[v] = cnt;
        if (!lk[v] || hungary(lk[v])) {
          lk[v] = u, to[u] = v;
          return true;
        }
      }
    }
  return false;
}
int mx[MAXN], my[MAXN];
void dfs(int u) {
  if (mx[u]) return;
  mx[u] = 1;
  for (int v = 1; v <= n; ++v)
    if (G[u][v]) {
      if (!my[v]) my[v] = 1, dfs(lk[v]);
    }
}
void clean() {}
int solve() {
  clean();
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%s", s), ins(i), str[i] = s;
  getFail();
  for (int i = 1; i <= n; ++i) find(i);
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (i != j && i != k && j != k) G[i][j] |= G[i][k] && G[k][j];
  for (int i = 1; i <= n; ++i) G[i][i] = 0;
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += hungary(cnt = i);
  printf("%d\n", n - ans);
  for (int i = 1; i <= n; ++i)
    if (!to[i]) dfs(i);
  for (int i = 1; i <= n; ++i)
    if (mx[i] && !my[i]) printf("%d ", i);
  return 0;
}
}  // namespace flyinthesky
int main() {
  flyinthesky::solve();
  return 0;
}
