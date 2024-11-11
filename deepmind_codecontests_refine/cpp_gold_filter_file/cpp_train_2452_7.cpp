#include <bits/stdc++.h>
using namespace std;
const signed int MAXE = 30000 + 5;
const signed int MAXV = 1000 + 5;
const signed int INF = 2e9 + 100;
signed int N, M, S, T;
struct Node {
  signed int u, v, w;
  bool d;
};
vector<signed int> graph[MAXV];
Node edge[MAXE];
signed int parent[MAXV];
signed int low[MAXV];
signed int disc[MAXV];
bool visited[MAXV];
bool bridge[MAXE];
signed int bidx;
signed int bw;
vector<signed int> path;
signed int timer;
void dfs(signed int u) {
  visited[u] = 1;
  disc[u] = low[u] = ++timer;
  for (typeof((graph[u]).begin()) itr = (graph[u]).begin();
       itr != (graph[u]).end(); itr++) {
    if (edge[*itr].d) continue;
    signed int v = u ^ edge[*itr].u ^ edge[*itr].v;
    if (!visited[v]) {
      parent[v] = *itr;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (low[v] > disc[u]) bridge[*itr] = 1;
    } else if (parent[u] != *itr)
      low[u] = min(low[u], disc[v]);
  }
}
void min_bridge() {
  bw = INF, bidx = -1;
  signed int n = T;
  while (parent[n] != -1) {
    signed int i = parent[n];
    if (bridge[i] && edge[i].w < bw) bw = edge[i].w, bidx = i;
    n = n ^ edge[i].u ^ edge[i].v;
  }
}
signed int main() {
  scanf("%d %d", &N, &M);
  scanf("%d %d", &S, &T);
  for (signed int i = 0; i < (M); ++i) {
    scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    if (edge[i].u != edge[i].v)
      graph[edge[i].u].push_back(i), graph[edge[i].v].push_back(i);
  }
  timer = 0;
  parent[S] = -1;
  dfs(S);
  if (!visited[T])
    printf("0\n0\n");
  else {
    signed int a = INF;
    signed int ai = -1, aj = -1;
    min_bridge();
    if (bw < a) a = bw, ai = bidx;
    signed int n = T;
    while (parent[n] != -1) {
      signed int i = parent[n];
      if (!bridge[i]) path.push_back(i);
      n = n ^ edge[i].u ^ edge[i].v;
    }
    for (typeof((path).begin()) itr = (path).begin(); itr != (path).end();
         itr++) {
      edge[*itr].d = 1;
      timer = 0;
      for (signed int i = (1); i <= (N); ++i) visited[i] = 0;
      for (signed int i = 0; i < (M); ++i) bridge[i] = 0;
      dfs(S);
      min_bridge();
      if (bw != INF && bw + edge[*itr].w < a)
        a = bw + edge[*itr].w, ai = *itr, aj = bidx;
      edge[*itr].d = 0;
    }
    if (ai == -1)
      printf("-1\n");
    else if (aj == -1)
      printf("%d\n1\n%d\n", a, ai + 1);
    else
      printf("%d\n2\n%d %d\n", a, 1 + min(ai, aj), 1 + max(ai, aj));
  }
  return 0;
}
