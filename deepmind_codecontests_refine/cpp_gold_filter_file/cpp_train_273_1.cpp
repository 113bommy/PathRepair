#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, m, tot, Index, cnt, top, f[M], dfn[M], low[M], st[3 * M];
set<int> nd[M], eg[M], ans;
struct edge {
  int v, next;
} e[2 * M];
void dfs(int u, int p) {
  dfn[u] = low[u] = ++Index;
  for (int i = f[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == p) continue;
    if (!dfn[v]) {
      st[++top] = i >> 1;
      st[++top] = u;
      st[++top] = v;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u]) {
        cnt++;
        while (1) {
          int t1 = st[top--], t2 = st[top--];
          nd[cnt].insert(t1);
          nd[cnt].insert(t2);
          eg[cnt].insert(st[top--]);
          if (t1 == v && t2 == u) break;
        }
      }
    } else if (dfn[v] < dfn[u]) {
      st[++top] = i >> 1;
      st[++top] = u;
      st[++top] = v;
      low[u] = min(low[u], dfn[v]);
    }
  }
}
signed main() {
  n = read();
  m = read();
  tot = 1;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    e[++tot] = edge{v, f[u]}, f[u] = tot;
    e[++tot] = edge{u, f[v]}, f[v] = tot;
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i, 0);
  for (int i = 1; i <= cnt; i++) {
    if (eg[i].size() == nd[i].size()) ans.insert(eg[i].begin(), eg[i].end());
  }
  printf("%d\n", ans.size());
  for (set<int>::iterator i = ans.begin(); i != ans.end(); i++)
    printf("%d ", *i);
}
