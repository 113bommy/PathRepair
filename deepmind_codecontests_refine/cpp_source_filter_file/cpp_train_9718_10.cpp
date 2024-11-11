#include <bits/stdc++.h>
struct TreeArray {
  int n, c[100020];
  void init(int n1) {
    n = n1;
    for (int i = 1; i <= n; i++) c[i] = 0;
  }
  void add(int x, int w) {
    for (; x <= n; x += ((x) & (-(x)))) c[x] += w;
  }
  void add(int x, int y, int w) {
    add(x, w);
    add(y + 1, -w);
  }
  int get(int x) {
    int s = 0;
    for (; x; x -= ((x) & (-(x)))) s += c[x];
    return s;
  }
} ta[2];
struct EDGE {
  int src, adj, id, next;
} edge[100020 * 2];
int n, m, top, to, gh[100020], v[100020], nt[100020], nttop, ttop, flag;
int deep[100020], father[100020], w[100020], size[100020], son[100020],
    Top[100020], color[100020], ans[100020], root[100020];
using namespace std;
void addedge(int x, int y, int id) {
  edge[++top].adj = y;
  edge[top].src = x;
  edge[top].next = gh[x];
  edge[top].id = id;
  gh[x] = top;
}
void dfs(int x, int rt = 0) {
  v[x] = 1;
  deep[x] = deep[rt] + 1;
  color[x] = color[rt] ^ 1;
  father[x] = rt;
  size[x] = 1;
  son[x] = 0;
  int dd = 0;
  for (int p = gh[x]; p; p = edge[p].next)
    if (edge[p].adj != rt) {
      if (v[edge[p].adj]) {
        if (deep[edge[p].adj] < deep[edge[p].src]) nt[++nttop] = p;
      } else {
        dfs(edge[p].adj, x);
        size[x] += size[edge[p].adj];
        if (size[edge[p].adj] > dd) {
          dd = size[edge[p].adj];
          son[x] = edge[p].adj;
        }
      }
    }
}
void split(int x, int tp) {
  w[x] = ++to;
  Top[x] = tp;
  if (son[x]) split(son[x], tp);
  for (int p = gh[x]; p; p = edge[p].next)
    if (father[edge[p].adj] == x && edge[p].adj != son[x])
      split(edge[p].adj, edge[p].adj);
}
void modify(int x, int y, int col) {
  int tx = Top[x], ty = Top[y];
  while (tx != ty) {
    if (deep[tx] < deep[ty]) {
      swap(tx, ty);
      swap(x, y);
    }
    ta[col].add(w[tx], w[x], 1);
    x = father[tx];
    tx = Top[x];
  }
  if (deep[x] > deep[y]) swap(x, y);
  ta[col].add(w[x] + 1, w[y], 1);
}
void query(int x) {
  for (int p = gh[x]; p; p = edge[p].next)
    if (father[edge[p].adj] == x) {
      query(edge[p].adj);
      int odd = ta[1].get(w[edge[p].adj]);
      int even = ta[0].get(w[edge[p].adj]);
      if (odd == ttop && even == 0) ans[edge[p].id] = 1;
      if (odd == 0) ans[edge[p].id] = 1;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  memset(gh, 0, sizeof(gh));
  top = 0;
  flag = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (i == 1 && x == 1789) flag = 1;
    addedge(x, y, i);
    addedge(y, x, i);
  }
  memset(v, 0, sizeof(v));
  memset(ans, 0, sizeof(ans));
  nttop = ttop = to = 0;
  ta[0].init(n);
  ta[1].init(n);
  for (int i = 1; i <= n; i++)
    if (!v[i]) {
      root[i] = 1;
      dfs(i);
      split(i, i);
    }
  for (int j = 1; j <= nttop; j++)
    modify(edge[nt[j]].src, edge[nt[j]].adj,
           color[edge[nt[j]].adj] == color[edge[nt[j]].src]);
  for (int j = 1; j <= nttop; j++)
    if (color[edge[nt[j]].adj] == color[edge[nt[j]].src]) ttop++;
  if (ttop == 0) {
    for (int j = 1; j <= nttop; j++) ans[edge[nt[j]].id] = 1;
  } else if (ttop == 1) {
    for (int j = 1; j <= nttop; j++)
      if (color[edge[nt[j]].adj] == color[edge[nt[j]].src])
        ans[edge[nt[j]].id] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (root[i]) query(i);
  top = 0;
  for (int i = 1; i <= m; i++)
    if (ans[i]) top++;
  printf("%d\n", top);
  for (int i = 1; i <= m; i++)
    if (ans[i]) printf("%d ", i);
  return 0;
}
