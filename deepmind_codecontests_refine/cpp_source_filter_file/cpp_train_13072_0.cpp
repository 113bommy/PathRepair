#include <bits/stdc++.h>
using namespace std;
class DSU {
 public:
  DSU(int n = 0) {
    parent = vector<int>(n + 1);
    for (int i = 0; i < n + 1; ++i) parent[i] = i;
    Rank = vector<int>(n + 1);
    sets_num = n;
  }
  int sets_num;
  int find_set(int v) {
    if (v == parent[v]) return v;
    return v = find_set(parent[v]);
  }
  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (Rank[a] < Rank[b]) swap(a, b);
      parent[b] = a;
      if (Rank[a] == Rank[b]) ++Rank[a];
      --sets_num;
    }
  }

 private:
  vector<int> Rank;
  vector<int> parent;
};
vector<vector<int>> graph;
vector<bool> pre;
vector<bool> post;
vector<int> parent;
int s = 0;
void dfs(int v, int p = 0) {
  pre[v] = true;
  parent[v] = p;
  for (size_t i = 0; i < graph[v].size(); ++i) {
    int to = graph[v][i];
    if (!pre[to])
      dfs(to, v);
    else {
      if (!post[to]) s = v;
    }
  }
  post[v] = true;
}
int main() {
  int n, i, item, counter = 0, answer = 0;
  scanf("%d", &n);
  DSU sets(n);
  graph = vector<vector<int>>(n + 1);
  pre = vector<bool>(n + 1, false);
  post = vector<bool>(n + 1, false);
  parent = vector<int>(n + 1, 0);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &item);
    graph[i].push_back(item);
    sets.union_sets(i, item);
  }
  for (i = 0; i < n; ++i) {
    scanf("%d", &item);
    if (item) ++counter;
  }
  answer += (!(counter % 2));
  if (sets.sets_num != 1)
    answer = sets.sets_num;
  else {
    counter = 0;
    for (i = 1; i <= n; ++i) {
      if (!pre[i]) dfs(i);
    }
    while (s) {
      s = parent[s];
      ++counter;
    }
    if (counter != n) ++answer;
  }
  printf("%d\n", answer);
  return 0;
}
