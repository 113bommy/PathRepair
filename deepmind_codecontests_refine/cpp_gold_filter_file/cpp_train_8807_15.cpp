#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MAXN = 5000 * 1000;
long long S, T;
struct edge {
  long long to, id, flow, capacity;
  edge(long long _to = 0, long long _id = 0, long long _flow = 0,
       long long _capacity = 0) {
    to = _to;
    id = _id;
    flow = _flow;
    capacity = _capacity;
  }
};
long long n;
vector<vector<long long> > graph;
vector<edge> edgelist;
long long dist[MAXN], start[MAXN];
void add_edge(long long v, long long u, long long capacity, long long id) {
  graph[v].push_back(edgelist.size());
  edgelist.push_back(edge(u, id, 0, capacity));
  graph[u].push_back(edgelist.size());
  edgelist.push_back(edge(v, -1, 0, 0));
}
bool bfs(long long v) {
  queue<long long> Q;
  fill(dist, dist + n, -1);
  dist[v] = 0;
  Q.push(v);
  while (!Q.empty()) {
    v = Q.front();
    Q.pop();
    for (auto id : graph[v]) {
      if (dist[edgelist[id].to] == -1 &&
          (edgelist[id].capacity - edgelist[id].flow) > 0) {
        Q.push(edgelist[id].to);
        dist[edgelist[id].to] = dist[v] + 1;
      }
    }
  }
  return dist[T] != -1;
}
long long flow = 0;
long long dfs(long long v, long long cmin) {
  if (v == T) {
    return cmin;
  }
  for (; start[v] < (long long)graph[v].size(); start[v]++) {
    long long id = graph[v][start[v]];
    if (dist[v] + 1 == dist[edgelist[id].to] &&
        (edgelist[id].capacity - edgelist[id].flow) > 0) {
      long long tmp = dfs(edgelist[id].to,
                          min(cmin, edgelist[id].capacity - edgelist[id].flow));
      if (tmp) {
        edgelist[id].flow += tmp;
        edgelist[id ^ 1].flow -= tmp;
        return tmp;
      }
    }
  }
  return 0;
}
long long dfs(long long v) {
  long long tmp = dfs(v, INF);
  flow += tmp;
  return tmp;
}
vector<edge> ans;
void ans_dfs(long long v) {
  dist[v] = 1;
  for (auto id : graph[v]) {
    if (dist[edgelist[id].to] == 0) {
      if (edgelist[id].capacity - edgelist[id].flow == 0) {
        ans.push_back(edgelist[id]);
      } else {
        ans_dfs(edgelist[id].to);
      }
    }
  }
}
long long m, num;
long long l[MAXN], r[MAXN];
long long dinic(long long k) {
  graph.clear();
  n = 2 + m + num;
  graph.resize(n);
  edgelist.clear();
  for (long long i = 0; i < num; i++) {
    add_edge(m + 1 + i, m + num + 1, k, -1);
  }
  for (long long i = 0; i < m; i++) {
    add_edge(i + 1, m + 1 + l[i], 1, 0);
    add_edge(i + 1, m + 1 + r[i], 1, 0);
    add_edge(0, i + 1, 1, 0);
  }
  S = 0;
  T = n - 1;
  long long ans = 0;
  while (bfs(S)) {
    fill(start, start + n, 0);
    while (true) {
      long long tmp = dfs(S);
      ans += tmp;
      if (tmp == 0) break;
    }
  }
  return ans;
}
signed main() {
  cin >> num >> m;
  for (long long i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }
  long long left = -1, right = num;
  while (left + 1 < right) {
    long long me = (left + right) / 2;
    if (m == dinic(me)) {
      right = me;
    } else {
      left = me;
    }
  }
  dinic(right);
  cout << right << endl;
  for (long long i = 1; i <= m; i++) {
    if (edgelist[graph[i][0]].flow == 1) {
      cout << l[i - 1] + 1 << " " << r[i - 1] + 1;
    } else {
      cout << r[i - 1] + 1 << " " << l[i - 1] + 1;
    }
    cout << "\n";
  }
}
