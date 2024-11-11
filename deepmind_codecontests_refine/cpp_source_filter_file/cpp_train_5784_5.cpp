#include <bits/stdc++.h>
using namespace std;
const int maxn = 512345;
const int INF = INT_MAX / 2;
struct Edge {
  int next;
  int to;
  int cap;
  int index;
  Edge() {}
  Edge(int next, int to, int cap, int index)
      : next(next), to(to), cap(cap), index(index) {}
};
int n;
int m;
int cntEdges;
Edge edges[maxn];
int head[maxn];
int s;
int t;
bool vis[maxn];
int curTimes;
int low[maxn];
int dfn[maxn];
bool needed[maxn];
int parser1;
int parser2;
int ansMin;
int cntAns;
int ans1;
int ans2;
void tarjanInit() {
  curTimes = 0;
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
}
void init() {
  cntEdges = 0;
  memset(head, -1, sizeof(head));
  memset(vis, false, sizeof(vis));
  tarjanInit();
  memset(needed, false, sizeof(needed));
  ansMin = INF;
}
inline void addEdge(int from, int to, int cap, int index) {
  edges[cntEdges] = Edge(head[from], to, cap, index);
  head[from] = cntEdges++;
}
inline void addDoubleEdge(int a, int b, int cap, int index) {
  addEdge(a, b, cap, index);
  addEdge(b, a, cap, index);
}
bool dfs(int u) {
  vis[u] = true;
  if (u == t) {
    return true;
  }
  for (int i = head[u]; i != -1; i = edges[i].next) {
    Edge &e = edges[i];
    if (vis[e.to]) {
      continue;
    }
    if (dfs(e.to)) {
      needed[i] = true;
      return true;
    }
  }
  return false;
}
void found() {
  if (parser2 < 0) {
    if (ansMin > edges[parser1].cap) {
      cntAns = 1;
      ans1 = edges[parser1].index;
      ansMin = edges[parser1].cap;
    }
  } else {
    if (ansMin > edges[parser1].cap + edges[parser2].cap) {
      cntAns = 2;
      ans1 = edges[parser1].index;
      ans2 = edges[parser2].index;
      if (ans1 > ans2) {
        swap(ans1, ans2);
      }
      ansMin = edges[parser1].cap + edges[parser2].cap;
    }
  }
}
void tarjan(int u, int fa) {
  low[u] = dfn[u] = ++curTimes;
  for (int i = head[u]; i != -1; i = edges[i].next) {
    int v = edges[i].to;
    if (!vis[i] || (i ^ 1) == fa) {
      continue;
    }
    if (dfn[v] == 0) {
      tarjan(v, i);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u] && dfn[t] >= dfn[v]) {
        parser2 = i;
        found();
      }
    } else {
      low[u] = min(low[u], dfn[v]);
    }
  }
}
void epoch() {
  if (!dfs(s)) {
    printf("0\n0\n");
    return;
  }
  for (int i = 0; i < maxn; i++) {
    vis[i] = true;
  }
  for (int i = 0; i < cntEdges; i++) {
    if (needed[i] == true) {
      tarjanInit();
      vis[i] = false;
      vis[i ^ 1] = false;
      parser1 = i;
      tarjan(s, -1);
      vis[i] = true;
      vis[i ^ 1] = true;
      if (dfn[t] == 0) {
        parser2 = -1;
        found();
      }
    }
  }
  if (ansMin >= INF) {
    printf("-1\n");
  } else {
    printf("%d\n", ansMin);
    if (cntAns == 1) {
      printf("%d\n%d\n", cntAns, ans1);
    } else {
      printf("%d\n%d %d\n", cntAns, ans1, ans2);
    }
  }
}
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    init();
    scanf("%d%d", &s, &t);
    for (int i = 1; i <= m; i++) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      addDoubleEdge(x, y, w, i);
    }
    epoch();
  }
  return 0;
}
