#include <bits/stdc++.h>
using namespace std;
int st, ed;
queue<int> q;
int edgenum, du[404040], yes[404040], jl[404040], tot, num, flag[404040], n,
    head[404040], vet[404040], jie[404040];
long long dis1[404040], dis2[404040], dis[404040];
long long ans = 0;
struct node {
  int u, v, w;
} a[404040];
void add(int u, int v) {
  edgenum++;
  vet[edgenum] = v;
  jie[edgenum] = head[u];
  head[u] = edgenum;
}
void dfs(int u, int ff, int dep) {
  int e = head[u];
  dis[u] = dep;
  while (e > 0) {
    int v = vet[e];
    if (v != ff) dfs(v, u, dep + 1);
    e = jie[e];
  }
}
void solve(int u, int ff) {
  int e = head[u];
  if (u == ed) {
    yes[u] = 1;
    num++;
    jl[num] = u;
    return;
  }
  while (e > 0) {
    int v = vet[e];
    if (v != ff) {
      solve(v, u);
      if (yes[v]) {
        yes[u] = 1;
        num++;
        jl[num] = u;
        return;
      }
    }
    e = jie[e];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
    du[u]++;
    du[v]++;
  }
  dfs(1, 0, 0);
  st = 1;
  ed = 1;
  for (int i = 1; i <= n; i++)
    if (dis[i] > dis[st]) st = i;
  dfs(st, 0, 0);
  for (int i = 1; i <= n; i++)
    if (dis[i] > dis[ed]) ed = i;
  for (int i = 1; i <= n; i++) dis1[i] = dis[i];
  dfs(ed, 0, 0);
  for (int i = 1; i <= n; i++) dis2[i] = dis[i];
  for (int i = 1; i <= n; i++)
    if (du[i] == 1 && i != st && i != ed) {
      q.push(i);
    }
  while (!q.empty()) {
    int u = q.front();
    flag[u] = 1;
    q.pop();
    if (dis1[u] > dis2[u]) {
      ans += dis1[u];
      tot++;
      a[tot].u = u;
      a[tot].v = st;
      a[tot].w = u;
    } else {
      ans += dis2[u];
      tot++;
      a[tot].u = u;
      a[tot].v = ed;
      a[tot].w = u;
    }
    int e = head[u];
    while (e > 0) {
      int v = vet[e];
      if (flag[v] == 0) {
        du[v]--;
        if (du[v] == 1) q.push(v);
      }
      e = jie[e];
    }
  }
  solve(st, 0);
  int tmp = dis1[ed];
  for (int i = 1; i < num; i++) {
    ans += tmp;
    tmp--;
    tot++;
    a[tot].u = jl[i];
    a[tot].v = jl[num];
    a[tot].w = a[tot].u;
  }
  printf("%I64d\n", ans);
  for (int i = 1; i <= tot; i++) printf("%d %d %d\n", a[i].u, a[i].v, a[i].w);
  return 0;
}
