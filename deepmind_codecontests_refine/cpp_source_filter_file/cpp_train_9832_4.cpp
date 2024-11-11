#include <bits/stdc++.h>
using namespace std;
struct Node {
  int a, b, c;
} node[200050];
int m;
struct Edge {
  int v, w, next;
} edge[100050 * 2];
int e, ft[100050];
int n, cnt, pre[100050];
bool flag[100050];
int dep[100050], up[20][100050], upw[20][100050];
long long sum;
bool cmp(const Node &a, const Node &b) { return a.c < b.c; }
void init_edge() {
  e = 0;
  memset(ft, -1, sizeof(ft));
}
void add_edge(int u, int v, int w) {
  edge[e].v = v;
  edge[e].w = w;
  edge[e].next = ft[u];
  ft[u] = e++;
}
void insert(int u, int v, int w) {
  add_edge(u, v, w);
  add_edge(v, u, w);
}
int find(int u) {
  if (pre[u] ^ u) pre[u] = find(pre[u]);
  return pre[u];
}
void dfs(int u) {
  flag[u] = true;
  int v = up[0][u];
  for (int i = 0; i + 1 < 20 && v != -1; i++) {
    up[i + 1][u] = up[i][v];
    upw[i + 1][u] = max(upw[i][u], upw[i][v]);
    v = up[i + 1][u];
  }
  for (int i = ft[u]; i != -1; i = edge[i].next) {
    v = edge[i].v;
    if (flag[v]) continue;
    dep[v] = dep[u] + 1;
    up[0][v] = u;
    upw[0][v] = edge[i].w;
    dfs(v);
  }
}
long long quary(int a, int b) {
  if (cnt > 2) return -1;
  if (cnt == 2) {
    if (find(a) == find(b))
      return -1;
    else
      return sum;
  }
  if (dep[a] < dep[b]) swap(a, b);
  int ans = 0;
  for (int i = 19; i >= 0; i--)
    if (up[i][a] != -1 && dep[up[i][a]] >= dep[b]) {
      ans = max(upw[i][a], ans);
      a = up[i][a];
    }
  if (a == b) return sum - ans;
  for (int i = 19; i >= 0; i--)
    if (up[i][a] != up[i][b]) {
      ans = max(upw[i][a], ans);
      ans = max(upw[i][b], ans);
      a = up[i][a];
      b = up[i][b];
    }
  ans = max(upw[a][0], ans);
  ans = max(upw[b][0], ans);
  return sum - ans;
}
int main() {
  int q, a, b;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < m; i++)
      scanf("%d%d%d", &node[i].a, &node[i].b, &node[i].c);
    sort(node, node + m, cmp);
    init_edge();
    for (int i = 1; i <= n; i++) pre[i] = i;
    sum = 0;
    for (int i = 0; i < m; i++) {
      a = node[i].a;
      b = node[i].b;
      if (find(a) != find(b)) {
        sum += node[i].c;
        pre[find(a)] = find(b);
        insert(a, b, node[i].c);
      }
    }
    cnt = 0;
    memset(flag, false, sizeof(flag));
    memset(up, -1, sizeof(up));
    for (int i = 1; i <= n; i++)
      if (!flag[i]) {
        cnt++;
        dep[i] = 1;
        dfs(i);
      }
    scanf("%d", &q);
    while (q--) {
      scanf("%d%d", &a, &b);
      printf("%I64d\n", quary(a, b));
    }
  }
  return 0;
}
