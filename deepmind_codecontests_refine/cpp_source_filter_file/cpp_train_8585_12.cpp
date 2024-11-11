#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n, m, tot = -1, x, y, head[maxn + 1], suc[maxn << 1 | 1],
          from[maxn << 1 | 1], to[maxn << 1 | 1], parent[maxn + 1],
          tag[maxn + 1], up[maxn + 1], path[maxn + 1], nowpath[maxn + 1],
          depth[maxn + 1];
bool check, tree[maxn << 1 | 1], vis[maxn + 1];
vector<int> edge[maxn + 1];
inline void add_edge(int x, int y) {
  suc[++tot] = head[x];
  head[x] = tot;
  to[tot] = y;
  from[tot] = x;
  return;
}
void dfs(int now) {
  vis[now] = true;
  depth[now] = depth[parent[now]] + 1;
  for (int i = head[now]; ~i; i = suc[i])
    if (!vis[to[i]]) {
      tree[i] = tree[i ^ 1] = true;
      parent[to[i]] = now;
      up[to[i]] = i;
      dfs(to[i]);
    }
  return;
}
int LCA(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  while (depth[x] > depth[y]) x = parent[x];
  while (x != y) {
    x = parent[x];
    y = parent[y];
  }
  return x;
}
void get_path(int from, int to, bool opt) {
  path[0] = 0;
  while (from != to) {
    path[++path[0]] = from;
    from = parent[from];
  }
  path[++path[0]] = to;
  if (!opt)
    for (int i = 1; i <= path[0]; ++i) nowpath[++nowpath[0]] = path[i];
  else
    for (int i = path[0]; i; --i) nowpath[++nowpath[0]] = path[i];
  return;
}
void print(void) {
  printf("%d ", nowpath[0]);
  for (int j = 1; j <= nowpath[0]; ++j) printf("%d ", nowpath[j]);
  puts("");
  nowpath[0] = 0;
  return;
}
int main() {
  memset(head, -1, sizeof head);
  memset(tag, -1, sizeof tag);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i);
  for (int i = 0; i <= tot && !check; i += 2)
    if (!tree[i]) {
      x = from[i];
      y = to[i];
      if (depth[x] < depth[y]) swap(x, y);
      int now = x;
      while (tag[up[now]] == -1 && now != y) {
        tag[up[now]] = i;
        now = parent[now];
      }
      if (now != y) {
        int t1 = from[tag[up[now]]], t2 = to[tag[up[now]]];
        if (depth[t1] < depth[t2]) swap(t1, t2);
        if (depth[y] < depth[t2]) {
          swap(y, t2);
          swap(x, t1);
        }
        puts("YES");
        int ancestor = LCA(t1, x);
        get_path(ancestor, y, 0);
        print();
        get_path(x, ancestor, 1);
        get_path(y, y, 0);
        print();
        get_path(t1, ancestor, 1);
        get_path(y, t2, 1);
        print();
        check = true;
      }
    }
  if (!check) puts("NO");
  return 0;
}
