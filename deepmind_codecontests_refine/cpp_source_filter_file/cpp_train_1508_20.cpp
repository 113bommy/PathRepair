#include <bits/stdc++.h>
using namespace std;
struct Edge {
  long long to, flow, capacity;
  Edge* res;
  Edge(int to, long long capacity, long long cost = 0)
      : to(to), flow(0), capacity(capacity) {}
  void addFlow(long long flow) {
    this->flow += flow;
    this->res->flow -= flow;
  }
};
struct Dinic {
  vector<vector<Edge*>> adjList;
  vector<int> pos, dist, value;
  vector<bool> visited;
  long long N;
  long long limit = 1;
  bool scaling;
  const long long INF = numeric_limits<long long>::max();
  Dinic(long long N, bool withScaling = false) : N(N), scaling(withScaling) {
    adjList.resize(N);
    pos.resize(N);
    dist.resize(N);
    visited.resize(N);
    value.resize(N);
  }
  void addEdge(int u, int v, long long capacity, bool directed = false) {
    Edge* uv = new Edge(v, capacity);
    Edge* vu = new Edge(u, directed ? 0 : capacity);
    uv->res = vu;
    vu->res = uv;
    adjList[u].push_back(uv);
    adjList[v].push_back(vu);
  }
  long long BlockingFlow(int u, int t, long long flow) {
    if (u == t) return flow;
    for (int& i = pos[u]; i < (int)adjList[u].size(); i++) {
      Edge* E = adjList[u][i];
      if (E->capacity > E->flow && dist[E->to] == dist[u] + 1) {
        long long f = BlockingFlow(E->to, t, min(flow, E->capacity - E->flow));
        if (f > 0) {
          E->addFlow(f);
          return f;
        }
      }
    }
    return 0;
  }
  bool bfs(int s, int t) {
    fill(dist.begin(), dist.end(), -1);
    queue<long long> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
      long long u = q.front();
      q.pop();
      for (Edge* E : adjList[u]) {
        if (dist[E->to] == -1 && E->capacity > E->flow &&
            (!scaling || E->capacity - E->flow >= limit)) {
          dist[E->to] = dist[u] + 1;
          q.push(E->to);
        }
      }
    }
    return dist[t] != -1;
  }
  long long StartDinic(int s, int t) {
    long long maxFlow = 0;
    for (limit = (scaling ? 1 << 30 : 1); limit > 0; limit >>= 1) {
      dist[t] = 0;
      while (bfs(s, t)) {
        int f = 0;
        fill(pos.begin(), pos.end(), 0);
        while ((f = BlockingFlow(s, t, INF))) {
          maxFlow += f;
        }
      }
    }
    return maxFlow;
  }
  void dfs(int u, vector<int>& cycle) {
    cycle.push_back(u);
    visited[u] = true;
    for (auto e : adjList[u]) {
      if (visited[e->to]) continue;
      if (e->flow == 1 || e->res->flow == 1) dfs(e->to, cycle);
    }
  }
};
const int MAXN = 205;
int A[MAXN], id[MAXN];
set<int> ps;
vector<int> primes, lowest_prime;
void sieve(int n) {
  lowest_prime.resize(n + 1);
  for (int i = 2; i <= n; ++i) {
    if (lowest_prime[i] == 0) {
      primes.push_back(i);
      ps.insert(i);
      lowest_prime[i] = i;
    }
    for (int p : primes) {
      int d = i * p;
      if (d > n) break;
      lowest_prime[d] = p;
      if (p == lowest_prime[i]) {
        break;
      }
    }
  }
}
bool is_prime(int x) { return ps.count(x); }
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  sieve(1e4 + 5);
  int N;
  cin >> N;
  int id_odd, id_even;
  id_odd = id_even = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] & 1)
      id[i] = id_odd++;
    else
      id[i] = id_even++;
  }
  if (id_odd != id_even) {
    cout << "Impossible\n";
    return 0;
  }
  Dinic dinic(2 * (id_even + 1), true);
  for (int i = 0; i < N; i++) {
    dinic.value[id[i] + 1 + (A[i] & 1 ? id_odd : 0)] = i + 1;
    if (A[i] & 1) continue;
    for (int j = 0; j < N; j++) {
      if (!is_prime(A[i] + A[j])) continue;
      dinic.addEdge(id[i] + 1, id[j] + id_odd + 1, 1, true);
    }
  }
  for (int i = 0; i < id_odd; i++) {
    dinic.addEdge(0, i + 1, 2, true);
    dinic.addEdge(i + 1 + id_odd, 2 * id_odd + 1, 2, true);
  }
  int mx_flow = dinic.StartDinic(0, 2 * id_odd + 1);
  if (mx_flow != 2 * id_odd) {
    cout << "Impossible\n";
    return 0;
  }
  vector<vector<int>> cycles;
  for (int i = 1; i <= 2 * id_odd; i++) {
    if (dinic.visited[i]) continue;
    vector<int> cycle;
    dinic.dfs(i, cycle);
    cycles.push_back(cycle);
  }
  cout << cycles.size() << '\n';
  for (auto cycle : cycles) {
    cout << cycle.size() << ' ';
    for (auto i : cycle) cout << dinic.value[i] << ' ';
    cout << '\n';
  }
  return 0;
}
