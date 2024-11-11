#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20100;
struct Dinic {
  struct edge {
    int a, b, cap, flow;
  };
  int n, d[MAXN], ptr[MAXN], q[MAXN];
  vector<edge> e;
  vector<int> g[MAXN];
  Dinic(int N) : n(N) {}
  void AddEdge(int a, int b, int cap) {
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    e.push_back(e2);
  }
  bool bfs(int second, int t) {
    int qh = 0, qt = 0;
    q[qt++] = second;
    memset(d, -1, n * sizeof d[0]);
    d[second] = 0;
    while (qh < qt && d[t] == -1) {
      int v = q[qh++];
      for (size_t i = 0; i < g[v].size(); ++i) {
        int id = g[v][i], to = e[id].b;
        if (d[to] == -1 && e[id].flow < e[id].cap) {
          q[qt++] = to;
          d[to] = d[v] + 1;
        }
      }
    }
    return d[t] != -1;
  }
  int dfs(int v, int flow, int t) {
    if (!flow) return 0;
    if (v == t) return flow;
    for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
      int id = g[v][ptr[v]], to = e[id].b;
      if (d[to] != d[v] + 1) continue;
      int pushed = dfs(to, min(flow, e[id].cap - e[id].flow), t);
      if (pushed) {
        e[id].flow += pushed;
        e[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
  int GetMaxFlow(int second, int t) {
    int flow = 0;
    while (bfs(second, t)) {
      memset(ptr, 0, n * sizeof ptr[0]);
      while (int pushed = dfs(second, 1000000000, t)) flow += pushed;
    }
    return flow;
  }
};
pair<int, int> arr[10005];
int main() {
  int n, b, q;
  cin >> n >> b >> q;
  Dinic solve(4 + 5 + q + b);
  for (int i = 0; i < q; i++) scanf("%d %d", &arr[i].first, &arr[i].second);
  arr[q++] = make_pair(0, 0);
  arr[q++] = make_pair(b, n);
  sort(arr, arr + q);
  for (int i = 2; i <= 6; i++) solve.AddEdge(0, i, n / 5);
  for (int i = 1; i <= b; i++) solve.AddEdge(2 + i % 5, i + 6, 1);
  int c = 7 + b;
  for (int i = 1; i < q; i++) {
    if (i && arr[i].first == arr[i - 1].first) {
      if (arr[i].second != arr[i - 1].second) {
        printf("unfair");
        return 0;
      }
      continue;
    }
    if (arr[i].second < arr[i - 1].second) {
      printf("unfair");
      return 0;
    }
    if (arr[i].second == arr[i - 1].second) continue;
    for (int j = arr[i - 1].first + 1; j <= arr[i].first; j++)
      solve.AddEdge(j + 6, c, 1);
    solve.AddEdge(c++, 1, arr[i].second - arr[i - 1].second);
  }
  if (solve.GetMaxFlow(0, 1) == n)
    printf("fair");
  else
    printf("unfair");
  return 0;
}
