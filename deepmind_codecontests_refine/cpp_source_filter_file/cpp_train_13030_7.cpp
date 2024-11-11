#include <bits/stdc++.h>
using namespace std;
template <typename elemType>
inline void Read(elemType &T) {
  elemType X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  T = (w ? -X : X);
}
struct Graph {
  struct edge {
    int Next, to, w;
  };
  edge G[200010];
  int head[10010];
  int cnt;
  Graph() : cnt(2) {}
  void clear(int node_num = 0) {
    cnt = 2;
    if (node_num == 0)
      memset(head, 0, sizeof(head));
    else
      fill(head, head + node_num + 5, 0);
  }
  void add_edge(int u, int v, int w) {
    G[cnt].w = w;
    G[cnt].to = v;
    G[cnt].Next = head[u];
    head[u] = cnt++;
  }
};
struct Edge {
  int u, v;
};
Edge E[300010];
Graph G;
int DFN[200010], dp[200010];
bool vis[200010];
int N, M, Index = 0;
bool flag;
void DFS(int u, int fa, int id) {
  vis[u] = true;
  DFN[u] = ++Index;
  dp[u] = 0;
  for (int i = G.head[u]; i; i = G.G[i].Next) {
    int v = G.G[i].to;
    int x = G.G[i].w;
    if (!vis[v]) {
      DFS(v, u, G.G[i].w);
      dp[u] += dp[v];
      E[x].u = u;
      E[x].v = v;
    } else if (v != fa || (v == fa && id != G.G[i].w)) {
      if (DFN[v] < DFN[u]) {
        ++dp[u];
        E[x].u = u;
        E[x].v = v;
      } else {
        --dp[u];
        E[x].u = v;
        E[x].v = u;
      }
    }
  }
  if (dp[u] == 0 && fa != 0) flag = true;
  return;
}
int main() {
  Read(N);
  Read(M);
  for (register int i = 1; i <= M; ++i) {
    int u, v;
    Read(u);
    Read(v);
    G.add_edge(u, v, i);
    G.add_edge(v, u, i);
    E[i].u = u;
    E[i].v = v;
  }
  DFS(1, 0, 0);
  if (flag) {
    printf("0\n");
    return 0;
  }
  for (register int i = 1; i <= M; ++i) printf("%d %d\n", E[i].u, E[i].v);
  return 0;
}
