#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 100;
int n, m, dfn[N], low[N], cnt, in[N];
int b[N], t[N], w, id[2][N], col[N];
int tot, first[N], nxt[N * 4], point[N * 4];
vector<int> e[N];
stack<int> st;
struct node {
  int u, v, c, t;
} sh[N];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
inline void add_edge(int x, int y) {
  nxt[++tot] = first[x];
  first[x] = tot;
  point[tot] = y;
}
void dfs(int x) {
  dfn[x] = low[x] = ++cnt;
  in[x] = 1;
  st.push(x);
  for (int i = first[x]; i != -1; i = nxt[i]) {
    int u = point[i];
    if (!dfn[u])
      dfs(u), low[x] = min(low[x], low[u]);
    else if (in[u])
      low[x] = min(low[x], dfn[u]);
  }
  if (dfn[x] == low[x]) {
    w++;
    while (st.top() != x) col[st.top()] = w, in[st.top()] = 0, st.pop();
    col[x] = w, in[x] = 0, st.pop();
  }
}
inline bool check(int mid) {
  tot = -1;
  w = 0;
  memset(dfn, 0, sizeof(dfn));
  memset(first, -1, sizeof(first));
  int k = 2 * m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)e[i].size(); j++) id[0][j] = ++k, id[1][j] = ++k;
    for (int j = 0; j < (int)e[i].size(); j++) {
      int x = e[i][j];
      add_edge(x, id[0][j]);
      add_edge(id[1][j], x + m);
      if (j != (int)e[i].size() - 1) add_edge(id[0][j], e[i][j + 1] + m);
      if (j != 0) add_edge(x, id[1][j - 1]);
    }
    for (int j = 0; j < (int)e[i].size() - 1; j++)
      add_edge(id[0][j], id[0][j + 1]), add_edge(id[1][j + 1], id[1][j]);
    for (int j = 0; j < (int)e[i].size(); j++) {
      int x = e[i][j];
      if (t[sh[x].c])
        add_edge(x + m, t[sh[x].c]), add_edge(t[sh[x].c] + m, x);
      else
        t[sh[x].c] = x;
    }
    for (int j = 0; j < (int)e[i].size(); j++) t[sh[e[i][j]].c] = 0;
  }
  for (int i = 1; i <= m; i++)
    if (sh[i].t > mid) add_edge(i, i + m);
  for (int i = 1; i <= k; i++)
    if (!dfn[i]) dfs(i);
  for (int i = 1; i <= m; i++)
    if (col[i] == col[m + i]) return 0;
  return 1;
}
signed main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) sh[i] = (node){read(), read(), read(), read()};
  for (int i = 1; i <= m; i++) {
    int u = sh[i].u, v = sh[i].v;
    e[u].push_back(i);
    e[v].push_back(i);
  }
  for (int i = 1; i <= m; i++) b[++w] = sh[i].c;
  sort(b + 1, b + 1 + w);
  w = unique(b + 1, b + 1 + w) - b - 1;
  for (int i = 1; i <= m; i++)
    sh[i].c = lower_bound(b + 1, b + 1 + w, sh[i].c) - b;
  bool bl = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)e[i].size(); j++) {
      int x = e[i][j];
      t[sh[x].c]++;
      if (t[sh[x].c] > 2) bl = 0;
    }
    if (!bl) break;
    for (int j = 0; j < (int)e[i].size(); j++) t[sh[e[i][j]].c] = 0;
  }
  if (!bl) {
    printf("No\n");
    return 0;
  }
  int MAX = 0;
  for (int i = 1; i <= m; i++) MAX = max(MAX, sh[i].t);
  int l = 0, r = MAX + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (r == MAX + 1) {
    printf("No\n");
    return 0;
  }
  check(r);
  printf("Yes\n");
  vector<int> ans;
  for (int i = 1; i <= m; i++)
    if (col[i] < col[m + i]) ans.push_back(i);
  printf("%d %d\n", r, (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i]);
  printf("\n");
}
