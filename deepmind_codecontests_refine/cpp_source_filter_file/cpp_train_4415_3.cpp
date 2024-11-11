#include <bits/stdc++.h>
using namespace std;
struct Edge {
  vector<int> v;
  int size;
  int d;
  bool pass;
  Edge(const vector<int>& _v, int _size, int _d, bool _pass)
      : v(_v), size(_size), d(_d), pass(_pass) {}
};
const int N = 100005;
const int bound = 314000000;
const int INF = 0x3f3f3f3f;
int m, n, high[N], low[N];
vector<Edge> eg[N];
vector<int> nd;
vector<pair<int, int> > p[N];
priority_queue<pair<int, int> > que;
void init() {
  for (int i = 1; i <= n; ++i) {
    eg[i].clear();
    p[i].clear();
  }
  while (!que.empty()) que.pop();
  memset(low, 0x3f, sizeof(low));
  memset(high, 0x3f, sizeof(high));
}
int dfs(int u) {
  if (high[u] != INF) return high[u];
  high[u] = -2;
  int res = 0;
  for (int i = 0; i < eg[u].size(); ++i) {
    if (!eg[u][i].pass) continue;
    int sum = eg[u][i].d;
    for (int j = 0; j < eg[u][i].v.size(); ++j) {
      int tmp = dfs(eg[u][i].v[j]);
      if (tmp == -2) return high[u] = -2;
      sum += tmp;
      if (sum > bound) sum = bound;
    }
    if (sum > res) sum = res;
  }
  return high[u] = res;
}
int main() {
  while (scanf("%d %d", &m, &n) != EOF) {
    init();
    int x, y, c, d;
    bool pass;
    for (int i = 0; i < m; ++i) {
      scanf("%d %d", &x, &y);
      pass = true, d = 0, nd.clear();
      for (int j = 0; j < y; ++j) {
        scanf("%d", &c);
        if (c == -1)
          ++d;
        else {
          pass = false;
          nd.push_back(c);
          p[c].push_back(make_pair(x, eg[x].size()));
        }
      }
      eg[x].push_back(Edge(nd, nd.size(), d, pass));
      if (pass && d < low[x]) {
        low[x] = d;
        que.push(make_pair(-d, x));
      }
    }
    while (!que.empty()) {
      int vertex = que.top().second, d = -que.top().first;
      que.pop();
      if (low[vertex] != d) {
        continue;
      }
      for (int i = 0; i < p[vertex].size(); ++i) {
        int parent = p[vertex][i].first, idx = p[vertex][i].second;
        if (--eg[parent][idx].size == 0) {
          int sum = eg[parent][idx].d;
          eg[parent][idx].pass = true;
          for (int j = 0; j < eg[parent][idx].v.size(); ++j) {
            sum += low[eg[parent][idx].v[j]];
            if (sum > bound) sum = bound;
          }
          if (sum < low[parent]) {
            low[parent] = sum;
            que.push(make_pair(-sum, parent));
          }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (low[i] == INF) low[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
      if (low[i] == -1)
        high[i] = -1;
      else if (high[i] == INF)
        dfs(i);
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d %d\n", low[i], high[i]);
    }
  }
  return 0;
}
