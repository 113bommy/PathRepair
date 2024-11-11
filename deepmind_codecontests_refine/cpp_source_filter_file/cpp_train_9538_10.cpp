#include <bits/stdc++.h>
using namespace std;
int head[500007], tot, deep[500007], dep[500007], son[500007], rt, n;
long long ans[500007];
inline long long rd() {
  long long x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}
struct edge {
  int n, to;
} e[500007 << 1];
struct ed {
  int to;
  long long l;
};
std::vector<ed> vec[500007];
struct node {
  int cnt, id;
};
node tmp[500007 << 1], *f[500007], *now = tmp;
inline void add(int u, int v) {
  e[++tot].n = head[u];
  e[tot].to = v;
  head[u] = tot;
}
void dfs(int u, int fa) {
  deep[u] = deep[fa] + 1;
  for (int i = head[u]; i; i = e[i].n)
    if (e[i].to != fa) {
      int v = e[i].to;
      dfs(v, u);
      if (dep[v] > dep[son[u]]) son[u] = v;
    }
  dep[u] = dep[son[u]] + 1;
}
void dfs2(int u, int fa) {
  if (son[u]) {
    f[son[u]] = f[u] + 1;
    dfs2(son[u], u);
  }
  f[u][0] = node{1, u};
  ans[u] = deep[u] - 1;
  for (int i = head[u]; i; i = e[i].n)
    if (e[i].to != fa && son[u] != e[i].to) {
      int v = e[i].to;
      f[v] = now;
      now += dep[v];
      dfs2(v, u);
      for (int j = 0; j < dep[v]; ++j) {
        ans[f[v][j].id] += deep[u] * f[u][j + 1].cnt;
        ans[f[u][j + 1].id] += deep[u] * f[v][j].cnt;
        f[u][j + 1].cnt += f[v][j].cnt;
        vec[f[u][j + 1].id].push_back(ed{f[v][j].id, -ans[f[v][j].id]});
      }
    }
}
void dfs3(int u) {
  for (vector<ed>::iterator it = vec[u].begin(); it != vec[u].end(); ++it) {
    int v = it->to;
    ans[v] += ans[u] + it->l;
    dfs3(v);
  }
}
void dfs4(int u, int fa) {
  for (int i = head[u]; i; i = e[i].n)
    if (e[i].to != fa) {
      int v = e[i].to;
      ans[v] += ans[u];
      dfs4(v, u);
    }
}
int main() {
  n = rd();
  int x, y;
  for (int i = 1; i <= n; ++i) {
    x = rd();
    if (!x)
      rt = i;
    else
      add(i, x), add(x, i);
  }
  dfs(rt, 0);
  f[rt] = now;
  now += dep[rt];
  dfs2(rt, 0);
  for (int i = 0; i < dep[rt]; ++i) dfs3(f[rt][i].id);
  dfs4(rt, 0);
  for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
  return 0;
}
