#include <bits/stdc++.h>
const int maxn = 200000 + 5;
const int maxm = 200000 + 5;
std::vector<int> nG[maxn];
std::vector<int> rG[maxn];
void add_edge(int u, int v, bool rev = 0) {
  auto &G = (rev ? rG : nG);
  G[u].push_back(v);
}
void init_edge() {
  for (int i = 0; i < maxn; i++) {
    nG[i].clear();
    rG[i].clear();
  }
}
int n, m, k;
int in[maxn];
int min_rank[maxn], max_rank[maxn], r[maxn];
struct Node {
  int min_rank;
  int id;
  const bool operator<(const Node &rhs) const {
    return min_rank < rhs.min_rank;
  }
};
std::vector<Node> s[maxn];
std::vector<int> topo;
void toposort() {
  std::queue<int> Q;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      Q.push(i);
      topo.push_back(i);
    }
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < rG[u].size(); i++) {
      int v = rG[u][i];
      in[v]--;
      if (!in[v]) {
        Q.push(v);
        topo.push_back(v);
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", r + i);
    max_rank[i] = r[i] ? r[i] : k;
    min_rank[i] = r[i] ? r[i] : 1;
  }
  init_edge();
  int u, v;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    in[u]++;
    add_edge(v, u, 1);
  }
  toposort();
  if (topo.size() != n) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < topo.size(); i++) {
    u = topo[i];
    for (int j = 0; j < nG[u].size(); j++) {
      v = nG[u][j];
      max_rank[v] = std::min(max_rank[v], max_rank[u] - 1);
    }
  }
  for (int i = topo.size() - 1; i >= 0; i--) {
    u = topo[i];
    for (int j = 0; j < rG[u].size(); j++) {
      v = rG[u][j];
      min_rank[v] = std::max(min_rank[v], min_rank[u] + 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (max_rank[i] < min_rank[i]) {
      puts("-1");
      return 0;
    } else {
      s[max_rank[i]].push_back((Node){min_rank[i], i});
    }
  }
  std::priority_queue<Node> Q;
  for (int i = k; i > 0; i--) {
    for (int j = 0; j < s[i].size(); j++) {
      Q.push(s[i][j]);
    }
    if (Q.empty()) {
      puts("-1");
      return 0;
    }
    int x = Q.top().id;
    Q.pop();
    r[x] = i;
    while (!Q.empty() && Q.top().min_rank == i) {
      r[Q.top().id] = i;
      Q.pop();
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", r[i]);
  }
  printf("\n");
}
