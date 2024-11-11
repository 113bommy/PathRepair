#include <bits/stdc++.h>
using namespace std;
const signed int MAX = 1e5 + 5;
signed int N;
signed int M;
struct Node {
  signed int w;
  signed int p;
  signed int id;
  Node(signed int w, signed int p, signed int id) : w(w), p(p), id(id) {}
  Node() {}
};
Node edges[MAX];
pair<signed int, signed int> graph_edge[MAX];
bool comp(const Node& left, const Node& right) {
  if (left.w == right.w) {
    if (left.p == right.p) return 0;
    return left.p == 1;
  }
  return left.w < right.w;
}
bool find_graph() {
  signed int free_vertex = 2;
  signed int u = 2;
  signed int v = 3;
  signed int id;
  for (signed int i = 0; i < (M); ++i) {
    id = edges[i].id;
    if (edges[i].p == 1) {
      graph_edge[id].first = 1;
      graph_edge[id].second = free_vertex++;
    } else {
      if (free_vertex <= v) return false;
      graph_edge[id].first = u;
      graph_edge[id].second = v;
      u++;
      if (u == v) {
        v++;
        u = 2;
      }
    }
  }
  return true;
}
signed int main() {
  scanf("%d %d", &N, &M);
  signed int w, p;
  for (signed int i = 0; i < (M); ++i) {
    scanf("%d %d", &w, &p);
    edges[i].w = w;
    edges[i].p = p;
    edges[i].id = i;
  }
  sort(edges, edges + N, comp);
  if (find_graph()) {
    for (signed int i = 0; i < (M); ++i)
      printf("%d %d\n", graph_edge[i].first, graph_edge[i].second);
  } else
    printf("-1\n");
  return 0;
}
