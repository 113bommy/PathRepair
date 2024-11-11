#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
struct Edge {
  Edge() { x = y = c = f = 0; }
  Edge(long long _x, long long _y, long long _c, long long _f)
      : x(_x), y(_y), c(_c), f(_f) {}
  long long x, y, c, f;
};
struct MaxFlow {
  long long n, m, s, t, maxFlow;
  vector<long long> excess, cnt, seen, h;
  vector<vector<long long>> adj;
  vector<Edge> EdgeList;
  queue<long long> ex_vertex;
  MaxFlow() {}
  MaxFlow(int n) {
    this->n = n;
    excess.assign(n + 5, 0);
    cnt.assign(2 * n + 10, 0);
    seen.assign(n + 5, 0);
    h.assign(n + 5, 0);
    adj.assign(n + 5, vector<long long>(0, 0));
    EdgeList.clear();
    while (!ex_vertex.empty()) ex_vertex.pop();
    maxFlow = -0;
  }
  void addEdge(int u, int v, int c) {
    adj[u].push_back(1LL * EdgeList.size());
    EdgeList.push_back(Edge(u, v, c, 0));
    adj[v].push_back(1LL * EdgeList.size());
    EdgeList.push_back(Edge(v, u, 0, 0));
  }
  void push(int index) {
    int Delta =
        min(EdgeList[index].c - EdgeList[index].f, excess[EdgeList[index].x]);
    EdgeList[index].f += Delta;
    EdgeList[index ^ 1].f -= Delta;
    excess[EdgeList[index].x] -= Delta;
    excess[EdgeList[index].y] += Delta;
  }
  void setH(int u, int newH) {
    cnt[h[u]]--;
    h[u] = newH;
    cnt[newH]++;
  }
  void Lift(int u) {
    long long minH = 2 * n + 10;
    for (int index : adj[u])
      if (EdgeList[index].c > EdgeList[index].f) {
        minH = min(minH, h[EdgeList[index].y]);
      }
    int OldH = h[u];
    setH(u, minH + 1);
    if (OldH > 0 && OldH < n && cnt[OldH] == 0) {
      for (int v = 1; v <= n; ++v)
        if (v != s && OldH < h[v] && h[v] <= n) {
          setH(v, n + 1);
          seen[v] = 0;
        }
    }
  }
  void init() {
    for (long long i = 1; i <= n; ++i) h[i] = 1;
    h[s] = n;
    h[t] = 0;
    cnt[n] = 1;
    cnt[0] = 1;
    cnt[1] = n - 2;
    for (long long id : adj[s]) {
      long long sf = EdgeList[id].c;
      EdgeList[id].f += sf;
      EdgeList[id ^ 1].f = -sf;
      excess[EdgeList[id].y] += sf;
      excess[s] -= sf;
    }
    for (long long i = 1; i <= n; ++i)
      if (i != s && i != t && excess[i] > 0) ex_vertex.push(i);
  }
  void Push_Relabel_GapHeuristic() {
    init();
    while (!ex_vertex.empty()) {
      int z = ex_vertex.front();
      ex_vertex.pop();
      while (seen[z] < adj[z].size()) {
        Edge e = EdgeList[adj[z][seen[z]]];
        if (e.c > e.f && h[e.x] > h[e.y]) {
          bool NeedQueue = (e.y != s && e.y != t && excess[e.y] == 0);
          push(adj[z][seen[z]]);
          if (NeedQueue) ex_vertex.push(e.y);
          if (excess[z] == 0) break;
        }
        seen[z]++;
      }
      if (excess[z] > 0) {
        Lift(z);
        seen[z] = 0;
        ex_vertex.push(z);
      }
    }
    maxFlow = excess[t];
  }
} Solver;
const int M = 55;
vector<pair<int, int>> rSet, rSeg;
vector<pair<pair<int, int>, int>> lSet;
int n, m;
bool mark[M * M + 5];
pair<int, int> rPairs[M];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  clock_t tStart = clock();
  cin >> n >> m;
  for (int i = (1), _b = (m); i <= _b; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lSet.push_back(pair<pair<int, int>, int>(pair<int, int>(x1, 1), i));
    lSet.push_back(pair<pair<int, int>, int>(pair<int, int>(x2 + 1, -1), i));
    rSet.push_back(pair<int, int>(y1, 1));
    rSet.push_back(pair<int, int>(y2 + 1, -1));
    rPairs[i] = pair<int, int>(y1, y2);
  }
  lSet.push_back(pair<pair<int, int>, int>(pair<int, int>(-1, -1), -1));
  rSet.push_back(pair<int, int>(-1, -1));
  rSet.push_back(pair<int, int>(oo, -1));
  sort(lSet.begin(), lSet.end());
  sort(rSet.begin(), rSet.end());
  int curR = rSet[1].first;
  for (int i = (1), _b = (2 * m); i <= _b; i++) {
    if (rSet[i].first != rSet[i + 1].first) {
      rSeg.push_back(pair<int, int>(curR, rSet[i + 1].first - 1));
      curR = rSet[i + 1].first;
    }
  }
  lSet.push_back(pair<pair<int, int>, int>(pair<int, int>(oo, -1), -1));
  int curL = lSet[1].first.first;
  int index = 0, nn = rSeg.size();
  Solver = MaxFlow(nn + 4 * m * m + 2);
  Solver.s = nn + 4 * m * m + 1;
  Solver.t = Solver.s + 1;
  multiset<int> S;
  for (int i = (1), _b = (2 * m); i <= _b; i++) {
    pair<pair<int, int>, int> d = lSet[i];
    int l = rPairs[d.second].first, r = rPairs[d.second].second;
    int id = (lower_bound(rSeg.begin(), rSeg.end(), pair<int, int>(l, 0)) -
              rSeg.begin());
    if (d.first.second == 1) {
      for (int j = (id), _b = (rSeg.size() - 1); j <= _b; j++) {
        if (rSeg[j].first > r) break;
        S.insert(j + 1);
      }
    } else {
      for (int j = (id), _b = (rSeg.size() - 1); j <= _b; j++) {
        if (rSeg[j].first > r) break;
        S.erase(S.find(j + 1));
      }
    }
    if (lSet[i].first.first != lSet[i + 1].first.first &&
        lSet[i + 1].first.first != oo) {
      memset(mark, 0, sizeof mark);
      ++index;
      Solver.addEdge(Solver.s, nn + index, lSet[i + 1].first.first - curL);
      for (int c : S)
        if (!mark[c]) {
          mark[c] = 1;
          Solver.addEdge(nn + index, c, oo);
        }
      curL = lSet[i + 1].first.first;
    }
  }
  for (int i = 0, _n = (rSeg.size()); i < _n; i++) {
    Solver.addEdge(i + 1, Solver.t, rSeg[i].second - rSeg[i].first + 1);
  }
  Solver.Push_Relabel_GapHeuristic();
  cout << Solver.maxFlow << '\n';
  fprintf(stderr, "Time taken: %.2fs\n",
          (double)(clock() - tStart) / CLOCKS_PER_SEC);
  return 0;
}
