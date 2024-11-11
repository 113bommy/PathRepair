#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int dfs_clock = 0;
int dfn[maxn], low[maxn], stk[maxn];
int deg[maxn];
int top = 0;
vector<int> E[maxn];
int mark[maxn], cnt = 0;
int vis[maxn];
int a[maxn], b[maxn];
int n, sum = 0;
int ans[maxn];
bool v[maxn];
int q[maxn], d[maxn];
void dfs(int x) {
  dfn[x] = low[x] = ++dfs_clock;
  stk[++top] = x;
  for (int i = 0; i < (int)E[x].size(); i++)
    if (!dfn[E[x][i]]) {
      dfs(E[x][i]);
      low[x] = min(low[x], low[E[x][i]]);
    } else if (!mark[E[x][i]])
      low[x] = min(low[x], dfn[E[x][i]]);
  if (low[x] == dfn[x]) {
    ++sum;
    int tmp = 0;
    do {
      tmp = stk[top--];
      mark[tmp] = sum;
    } while (tmp != x);
  }
}
int bfs(int x, int y, int id) {
  int h = 0, t = 1;
  q[t] = x;
  d[x] = 0;
  v[x] = true;
  while (h < t) {
    int k = q[++h];
    for (int i = 0; i < (int)E[k].size(); i++) {
      int to = E[k][i];
      if (mark[to] != id) continue;
      if (v[to]) continue;
      d[to] = d[k] + 1;
      q[++t] = to;
      v[to] = true;
    }
  }
  for (int i = 1; i <= n; i++) v[i] = false;
  return d[y];
}
int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &a[i], &b[i]);
    E[a[i]].push_back(b[i]);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i);
  for (int i = 1; i <= m; i++)
    if (mark[a[i]] != mark[b[i]]) ++deg[mark[a[i]]];
  for (int i = 1; i <= sum; i++) ans[i] = 0x3f3f3f3f;
  int Ans = 0;
  for (int i = 1; i <= m; i++) {
    if (mark[a[i]] != mark[b[i]]) continue;
    if (deg[mark[a[i]]]) continue;
    ans[mark[a[i]]] = min(ans[mark[a[i]]], bfs(b[i], a[i], mark[a[i]]) + 1);
  }
  for (int i = 1; i <= sum; i++) {
    if (deg[i]) continue;
    if (ans[i] == 0x3f3f3f3f) continue;
    Ans += ans[i] * 998 + 1;
  }
  Ans += n;
  printf("%d\n", Ans);
  return 0;
}
