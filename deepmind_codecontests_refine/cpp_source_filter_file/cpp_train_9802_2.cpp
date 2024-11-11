#include <bits/stdc++.h>
using namespace std;
long long numbit(long long x) { return (1LL << x) - 1LL; }
long long getbit(long long x, long long i) { return (x >> i) & 1LL; }
long long onbit(long long x, long long i) { return x | (1LL << i); }
long long offbit(long long x, long long i) { return x & (~(1LL << i)); }
const long long Inf64 = 1e18;
const long long Inf = 1e9;
const int Nmax = 1e5;
const long long Mod9 = 1e9 + 9;
const long long Mod7 = 1e9 + 7;
struct Edge {
  int u, v;
  bool avail;
};
class Indexer {
 private:
  map<int, int> id;
  vector<int> num;

 public:
  int getId(int x) {
    if (!id.count(x)) {
      id[x] = num.size();
      num.push_back(x);
    }
    return id[x];
  }
  int getNum(int id) { return num[id]; }
  int size() { return id.size(); }
};
class Graph {
 private:
  int n;
  vector<Edge> e;
  vector<vector<int>> adj;
  vector<int> pos;
  list<int> path;
  void dfs(list<int>::iterator it, int u) {
    for (; pos[u] < adj[u].size(); ++pos[u]) {
      int id = adj[u][pos[u]];
      if (e[id].avail) {
        e[id].avail = false;
        int v = e[id].u + e[id].v - u;
        dfs(path.insert(it, v), v);
      }
    }
  }

 public:
  Graph(int n) : n(n) { adj.assign(n, vector<int>()); }
  void addEdge(int u, int v) {
    adj[u].push_back(e.size());
    adj[v].push_back(e.size());
    e.push_back({u, v, false});
  }
  vector<int> EulerPath() {
    for (Edge &p : e) p.avail = true;
    path.clear();
    pos.assign(n, 0);
    vector<int> odd;
    for (long long i = (0); i <= (n - 1); i++)
      if (adj[i].size() % 2 == 1) odd.push_back(i);
    if (odd.empty()) {
      odd.push_back(0);
      odd.push_back(0);
    }
    if (odd.size() > 2) return vector<int>();
    dfs(path.begin(), odd[0]);
    path.insert(path.begin(), odd[1]);
    return vector<int>(path.begin(), path.end());
  }
};
int main() {
  int n;
  cin >> n;
  vector<int> b(n - 1);
  for (long long i = (0); i <= (n - 2); i++) cin >> b[i];
  vector<int> c(n - 1);
  for (long long i = (0); i <= (n - 2); i++) cin >> c[i];
  Indexer ind;
  for (long long i = (0); i <= (n - 2); i++) {
    if (b[i] > c[i]) {
      cout << "-1";
      return 0;
    }
    b[i] = ind.getId(b[i]);
    c[i] = ind.getId(c[i]);
  }
  int k = ind.size();
  Graph g(k);
  for (long long i = (0); i <= (n - 2); i++) g.addEdge(b[i], c[i]);
  vector<int> a = g.EulerPath();
  if (a.size() < n)
    cout << "-1";
  else {
    for (long long i = (0); i <= (n - 1); i++) cout << ind.getNum(a[i]) << " ";
  }
  return 0;
}
