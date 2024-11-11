#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, rev, cap, flow;
};
struct Dinic {
  static const int MAX_NODES = 100000, MAX_FLOW = 1 << 30;
  vector<edge> graph[MAX_NODES];
  int dist[MAX_NODES], ptr[MAX_NODES], s, t, n;
  void addNode(int a, int b, int cap) {
    edge e1 = {b, (int)graph[b].size(), cap, 0};
    edge e2 = {a, (int)graph[a].size(), 0, 0};
    graph[a].push_back(e1);
    graph[b].push_back(e2);
  }
  bool bfs() {
    queue<int> q;
    for (int i = 0; i < n; i++) dist[i] = -1;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < graph[v].size(); i++) {
        edge e = graph[v][i];
        if (dist[e.to] == -1 && e.flow < e.cap) {
          q.push(e.to);
          dist[e.to] = dist[v] + 1;
        }
      }
    }
    return dist[t] != -1;
  }
  int dfs(int v, int flow) {
    if (!flow) return 0;
    if (v == t) return flow;
    for (; ptr[v] < graph[v].size(); ptr[v]++) {
      edge &e = graph[v][ptr[v]];
      if (dist[v] + 1 != dist[e.to]) continue;
      int f = dfs(e.to, min(flow, e.cap - e.flow));
      if (f) {
        e.flow += f;
        graph[e.to][e.rev].flow -= f;
        return f;
      }
    }
    return 0;
  }
  int getMaxFlow(int src, int sink, int qtd_nodes) {
    s = src, t = sink, n = qtd_nodes;
    int flow = 0;
    while (bfs()) {
      for (int i = 0; i < n; i++) ptr[i] = 0;
      while (int f = dfs(s, MAX_FLOW)) {
        flow += f;
      }
    }
    return flow;
  }
};
vector<int> primes;
bool prime[32000 + 1];
int id[100000], qtd, edge[101][101], num[100000];
void build() {
  for (int i = 2; i <= 32000; i++) {
    if (!prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= 32000; j += i) prime[j] = true;
    }
  }
}
void add(int v, int k, int q, Dinic &d) {
  if (q > 0) {
    id[qtd] = v;
    num[qtd] = k;
    if (v % 2) {
      d.addNode(1, qtd, q);
    } else {
      d.addNode(qtd, 2, q);
    }
    qtd++;
  }
}
void make_edges(int a, int num, Dinic &d) {
  for (int i = 0; i < primes.size(); i++) {
    int k = primes[i], q = 0;
    if (k * k > num) break;
    while (num % k == 0) {
      q++;
      num /= k;
    }
    add(a, k, q, d);
  }
  if (num > 1) add(a, num, 1, d);
}
int main() {
  build();
  Dinic d;
  int n, m;
  scanf("%d %d", &n, &m);
  qtd = 3;
  for (int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &num);
    make_edges(i, num, d);
  }
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a][b] = edge[b][a] = 1;
  }
  for (int i = 3; i < qtd; i++)
    for (int j = i + 1; j < qtd; j++) {
      int a = id[i], b = id[j];
      if (edge[a][b] && num[i] == num[j])
        if (a % 2)
          d.addNode(i, j, 1 << 30);
        else
          d.addNode(j, i, 1 << 30);
    }
  printf("%d", d.getMaxFlow(1, 2, qtd));
  return 0;
}
