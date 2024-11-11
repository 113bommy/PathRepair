#include <bits/stdc++.h>
using namespace std;
struct edge {
  int b;
  long long w;
};
int dfs1(const vector<vector<edge>> &adj, int par, int node,
         vector<int> &leftmost_leaf, vector<int> &next_sibling) {
  leftmost_leaf[node] = node;
  vector<int> children;
  bool first_child = true;
  for (int i = 0; i < adj[node].size(); ++i) {
    int child = adj[node][i].b;
    if (child == par) continue;
    children.push_back(child);
    int leaf = dfs1(adj, node, child, leftmost_leaf, next_sibling);
    if (first_child) leftmost_leaf[node] = leaf;
    first_child = false;
  }
  for (int i = 0; i < children.size(); ++i) {
    next_sibling[children[i]] = children[(i + 1) % children.size()];
  }
  return leftmost_leaf[node];
}
void dfs2(const vector<vector<edge>> &adj, const vector<int> &leftmost_leaf,
          const vector<int> &next_sibling, int par, int node, int par_leaf,
          long long delta, long long w,
          vector<tuple<int, int, long long>> &ops) {
  if (par == -1) {
    for (edge e : adj[node]) {
      dfs2(adj, leftmost_leaf, next_sibling, node, e.b, par_leaf, delta, e.w,
           ops);
    }
    return;
  }
  int my_leaf = leftmost_leaf[node];
  int sibling_leaf = leftmost_leaf[next_sibling[node]];
  if (par_leaf == -1) {
    par_leaf = leftmost_leaf[next_sibling[next_sibling[node]]];
  }
  long long need_to_add = w - delta;
  ops.push_back({my_leaf, sibling_leaf, need_to_add / 2});
  ops.push_back({my_leaf, par_leaf, need_to_add / 2});
  ops.push_back({sibling_leaf, par_leaf, -need_to_add / 2});
  delta += need_to_add;
  bool first_child = true;
  for (int i = 0; i < adj[node].size(); ++i) {
    int child = adj[node][i].b;
    if (child == par) continue;
    dfs2(adj, leftmost_leaf, next_sibling, node, child, par_leaf,
         first_child ? delta : 0, adj[node][i].w, ops);
    first_child = false;
  }
}
int main() {
  int N;
  scanf("%d", &N);
  vector<vector<edge>> adj(N + 1, vector<edge>());
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    long long w;
    scanf("%d %d %lld", &u, &v, &w);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  if (N == 2) {
    printf("YES\n1\n");
    printf("1 2 %lld\n", adj[1][0].w);
    return 0;
  }
  int root = -1;
  for (int i = 1; i <= N; ++i) {
    if (adj[i].size() == 2) {
      printf("NO\n");
      return 0;
    } else if (adj[i].size() > 1) {
      root = i;
      break;
    }
  }
  assert(root >= 1);
  vector<int> leftmost_leaf(N + 1, -1);
  vector<int> next_sibling(N + 1, -1);
  dfs1(adj, -1, root, leftmost_leaf, next_sibling);
  ;
  vector<tuple<int, int, long long>> ops;
  dfs2(adj, leftmost_leaf, next_sibling, -1, root, -1, 0, 0, ops);
  printf("YES\n");
  printf("%d\n", (int)ops.size());
  for (tuple<int, int, long long> op : ops) {
    printf("%d %d %lld\n", get<0>(op), get<1>(op), get<2>(op));
  }
  return 0;
}
