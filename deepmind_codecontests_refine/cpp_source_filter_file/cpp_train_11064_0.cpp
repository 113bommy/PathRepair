#include <bits/stdc++.h>
using namespace std;
template <typename TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <typename TH, typename... TA>
void _dbg(const char* sdbg, TH h, TA... t) {
  while (*sdbg != ',') {
    cerr << *sdbg++;
  }
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, t...);
}
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class A, class B, class C>
struct Triple {
  A first;
  B second;
  C third;
  bool operator<(const Triple& t) const {
    if (first != t.first) return first < t.first;
    if (second != t.second) return second < t.second;
    return third < t.third;
  }
};
template <class T>
void ResizeVec(T&, vector<long long>) {}
template <class T>
void ResizeVec(vector<T>& vec, vector<long long> sz) {
  vec.resize(sz[0]);
  sz.erase(sz.begin());
  if (sz.empty()) {
    return;
  }
  for (T& v : vec) {
    ResizeVec(v, sz);
  }
}
template <class A, class B, class C>
ostream& operator<<(ostream& out, Triple<A, B, C> t) {
  return out << "(" << t.first << ", " << t.second << ", " << t.third << ")";
}
template <class T>
ostream& operator<<(ostream& out, vector<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
template <class T>
ostream& operator<<(ostream& out, set<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
template <class L, class R>
ostream& operator<<(ostream& out, map<L, R> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
class MinCostFlow {
  struct MCEdge {
    long long to, cost, flow;
    MCEdge* ____next;
    MCEdge() {}
    MCEdge(long long t, long long c, long long f) : to(t), cost(c), flow(f) {}
  };
  const long long Infty = 1010101010;
  vector<vector<MCEdge*>> adjList;
  long long N, Source, Sink;
  vector<long long> dist;
  vector<MCEdge*> ____prev, Edges;
  void spfa() {
    queue<long long> Q;
    vector<bool> onQueue(N);
    fill((dist).begin(), (dist).end(), Infty);
    Q.push(Source);
    onQueue[Source] = true;
    dist[Source] = 0;
    while (!Q.empty()) {
      long long v = Q.front();
      Q.pop();
      onQueue[v] = false;
      for (MCEdge* E : adjList[v]) {
        long long s = E->to;
        if (E->flow == 0) {
          continue;
        }
        long long newDist = dist[v] + E->cost;
        if (newDist < dist[s]) {
          dist[s] = newDist;
          ____prev[s] = E->____next;
          if (!onQueue[s]) {
            Q.push(s);
            onQueue[s] = true;
          }
        }
      }
    }
  }
  long long reduce_cost() {
    long long result = dist[Sink];
    for (long long v = 0; v < N; v++) {
      for (MCEdge* E : adjList[v]) {
        E->cost += dist[v] - dist[E->to];
      }
    }
    return result;
  }
  void dijkstra_shortest_path() {
    fill(dist.begin(), dist.end(), Infty);
    dist[Source] = 0;
    priority_queue<pair<long long, long long>> Q;
    Q.push(make_pair(0, Source));
    while (!Q.empty()) {
      long long dst, v;
      tie(dst, v) = Q.top();
      Q.pop();
      dst = -dst;
      if (dst != dist[v]) continue;
      for (MCEdge* E : adjList[v]) {
        long long s = E->to;
        if (E->flow == 0) continue;
        long long newDist = dist[v] + E->cost;
        if (newDist < dist[s]) {
          dist[s] = newDist;
          ____prev[s] = E->____next;
          Q.push(make_pair(-newDist, s));
        }
      }
    }
  }

 public:
  MinCostFlow() { N = 0; }
  ~MinCostFlow() {
    for (MCEdge* E : Edges) delete E;
  }
  long long numEdges = 0;
  void fit(long long size) {
    if (size > N) {
      N = size;
      dist.resize(size);
      ____prev.resize(size);
      adjList.resize(size);
    }
  }
  void add_edge(long long u, long long v, long long flow, long long cost,
                long long bi_dir = 0) {
    fit(max(u, v) + 1);
    numEdges++;
    MCEdge *E1, *E2;
    E1 = new MCEdge(v, cost, flow);
    if (bi_dir == 0) {
      E2 = new MCEdge(u, -cost, 0);
    } else {
      E2 = new MCEdge(u, -cost, flow);
    }
    Edges.push_back(E1);
    Edges.push_back(E2);
    E1->____next = E2;
    E2->____next = E1;
    adjList[u].push_back(E1);
    adjList[v].push_back(E2);
  }
  pair<long long, pair<long long, long long>> get_min_cost_flow(long long s,
                                                                long long t) {
    fit(max(s, t) + 1);
    Source = s;
    Sink = t;
    long long cost = 0, flow = 0;
    spfa();
    if (dist[Sink] > Infty / 2) return {0, {0, 0}};
    long long sinkCost = reduce_cost();
    long long best_cost = 0;
    while (true) {
      dijkstra_shortest_path();
      if (dist[Sink] > Infty / 2) break;
      sinkCost += reduce_cost();
      if (sinkCost >= 0) {
        break;
      }
      long long maxSend = Infty;
      for (long long v = Sink; v != Source; v = ____prev[v]->to) {
        maxSend = min(maxSend, ____prev[v]->____next->flow);
      }
      for (long long v = Sink; v != Source; v = ____prev[v]->to) {
        MCEdge* E1 = ____prev[v];
        MCEdge* E2 = E1->____next;
        E1->flow += maxSend;
        E2->flow -= maxSend;
      }
      flow += maxSend;
      cost += maxSend * sinkCost;
      mini(best_cost, cost);
    }
    return {flow, {cost, best_cost}};
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  if (0) cout << fixed << setprecision(10);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<vector<long long>> a(n + 2, vector<long long>(n + 2));
  vector<vector<long long>> id(n + 2, vector<long long>(n + 2));
  for (long long i = (1); i <= (n); ++i) {
    for (long long j = (1); j <= (n); ++j) {
      cin >> a[i][j];
    }
  }
  long long sum = 0;
  for (long long i = (1); i <= (n); ++i) {
    for (long long j = (1); j <= (n); ++j) {
      id[i][j] = n * (i - 1) + j;
      for (long long ni = (i - 1); ni <= (i + 1); ++ni) {
        for (long long nj = (j - 1); nj <= (j + 1); ++nj) {
          if (ni >= 1 && ni <= n && nj <= n && nj >= 1 &&
              abs(i - ni) + abs(j - nj) == 1 &&
              make_pair(i, j) < make_pair(ni, nj) && a[i][j] > 0 &&
              a[ni][nj] > 0) {
            sum += abs(a[i][j] - a[ni][nj]);
          }
        }
      }
    }
  }
  (sum);
  MinCostFlow flow;
  long long s = n * n + 1;
  long long t = n * n + 2;
  for (long long i = (2); i <= (n - 1); ++i) {
    if (a[2][i] == 0) {
      flow.add_edge(s, id[2][i], 1, -a[1][i]);
      flow.add_edge(id[2][i], t, 1, a[1][i]);
    }
    if (a[n - 1][i] == 0) {
      flow.add_edge(s, id[n - 1][i], 1, -a[n][i]);
      flow.add_edge(id[n - 1][i], t, 1, a[n][i]);
    }
    if (a[i][2] == 0) {
      flow.add_edge(s, id[i][2], 1, -a[i][1]);
      flow.add_edge(id[i][2], t, 1, a[i][1]);
    }
    if (a[i][n - 1] == 0) {
      flow.add_edge(s, id[i][n - 1], 1, -a[i][n]);
      flow.add_edge(id[i][n - 1], t, 1, a[i][n]);
    }
  }
  for (long long i = (2); i <= (n - 1); ++i) {
    for (long long j = (2); j <= (n - 1); ++j) {
      for (long long tr = 0; tr < (2); ++tr) {
        long long ni = i;
        long long nj = j;
        if (tr == 0) {
          ni++;
        } else {
          nj++;
        }
        if (a[i][j] == 0 && a[ni][nj] == 0) {
          flow.add_edge(id[i][j], id[ni][nj], 1, 0, 1);
        }
      }
    }
  }
  auto heh = flow.get_min_cost_flow(s, t);
  (heh);
  cout << sum - heh.second.second << endl;
  return 0;
}
