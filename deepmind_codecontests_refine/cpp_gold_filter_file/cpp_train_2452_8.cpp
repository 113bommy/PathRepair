#include <bits/stdc++.h>
struct edge {
  int id;
  int src;
  int dest;
  int cost;
};
int n, m;
int s, t;
std::vector<edge> graph[1000 + 1];
bool bridge[30000 + 1];
bool blocked[30000 + 1];
bool mark[1000 + 1];
std::vector<edge> path;
bool find_path(int v) {
  if (v == s) {
    path.clear();
    memset(mark, 0, sizeof(mark));
  }
  mark[v] = true;
  if (v == t) {
    return true;
  } else {
    for (auto adj : graph[v]) {
      if (!mark[adj.dest] && !blocked[adj.id]) {
        path.push_back(adj);
        if (find_path(adj.dest)) return true;
        path.pop_back();
      }
    }
  }
  return false;
}
void dfs(int *low, int *num, int *parent, int *counter,
         std::vector<edge> &result, int u);
void bridges(void) {
  int low[1000 + 1] = {};
  int num[1000 + 1] = {};
  int leading_edge[1000 + 1] = {};
  int counter = 1;
  std::vector<edge> result;
  dfs(low, num, leading_edge, &counter, result, s);
  for (auto b : result) {
    fprintf(stderr, "Edge (%d, %d) is a bridge\n", b.src, b.dest);
  }
  fputs("And that's all\n", stderr);
  memset(bridge, 0, sizeof(bridge));
  for (auto e : result) bridge[e.id] = true;
}
void dfs(int *low, int *num, int *leading_edge, int *counter,
         std::vector<edge> &result, int u) {
  fprintf(stderr, "dfs at %d\n", u);
  low[u] = num[u] = ++(*counter);
  for (auto adj : graph[u]) {
    if (blocked[adj.id]) continue;
    if (!num[adj.dest]) {
      leading_edge[adj.dest] = adj.id;
      dfs(low, num, leading_edge, counter, result, adj.dest);
      if (low[adj.dest] > num[u]) result.push_back(adj);
      low[u] = std::min(low[u], low[adj.dest]);
    } else if (adj.id != leading_edge[u]) {
      low[u] = std::min(low[u], num[adj.dest]);
    }
  }
}
int main(void) {
  scanf("%d %d %d %d", &n, &m, &s, &t);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    edge e;
    e.id = i;
    e.src = x;
    e.dest = y;
    e.cost = w;
    graph[x].push_back(e);
    e.src = y;
    e.dest = x;
    graph[y].push_back(e);
  }
  if (!find_path(s)) {
    fputs("No initial path\n", stderr);
    puts("0\n0");
    return 0;
  }
  fprintf(stderr, "Path between %d and %d:\n", s, t);
  for (auto v : path) fprintf(stderr, "- (%d, %d)\n", v.src, v.dest);
  bridges();
  auto initial_path = path;
  int best = INT_MAX;
  int best_x = 0;
  int best_y = 0;
  for (auto pb : initial_path) {
    blocked[pb.id] = true;
    fprintf(stderr, "Having removed edge (%d, %d) with cost %d:\n", pb.src,
            pb.dest, pb.cost);
    bridges();
    if (!find_path(s)) {
      fprintf(stderr,
              "Having removed edge (%d, %d) with cost %d, the breakup is "
              "complete\n",
              pb.src, pb.dest, pb.cost);
      if (pb.cost < best) {
        best = pb.cost;
        best_x = pb.id;
        best_y = 0;
      }
    } else {
      fprintf(stderr,
              "Having removed edge (%d, %d), there remains a path from s to t "
              "of length %d\n",
              pb.src, pb.dest, (int)path.size());
      for (auto v : path) fprintf(stderr, "- (%d, %d)\n", v.src, v.dest);
      for (auto qb : path) {
        if (bridge[qb.id]) {
          fprintf(stderr,
                  "Having removed edge (%d, %d) with cost %d, the edge (%d, "
                  "%d) with cost %d becomes a path bridge\n",
                  pb.src, pb.dest, pb.cost, qb.src, qb.dest, qb.cost);
          if (pb.cost + qb.cost < best) {
            best = pb.cost + qb.cost;
            best_x = pb.id;
            best_y = qb.id;
          }
        }
      }
    }
    blocked[pb.id] = false;
  }
  if (best >= INT_MAX) {
    puts("-1");
  } else {
    printf("%d\n%d\n", best, (!!best_x) + (!!best_y));
    if (best_x && best_y)
      printf("%d %d\n", best_x, best_y);
    else
      printf("%d\n", best_x + best_y);
  }
  return 0;
}
