#include <bits/stdc++.h>
using namespace std;
struct Graph {
  Graph() {}
  Graph(int N) : N_(N) {
    cap.clear();
    cap.resize(N);
    for (int i = 0; i < N; i++) {
      cap[i].resize(N);
    }
    flow = cap;
  }
  Graph makeContractedGraph(vector<int>& myComponent,
                            vector<vector<int>>& otherComponents) {
    Graph newGraph(N_ + otherComponents.size());
    vector<int> idxValue(N_);
    for (int i = 0; i < N_; i++) {
      idxValue[i] = i;
    }
    for (int i = 0; i < otherComponents.size(); i++) {
      for (auto x : otherComponents[i]) {
        idxValue[x] = N_ + i;
      }
    }
    for (int i = 0; i < N_; i++) {
      for (int j = 0; j < N_; j++)
        if (cap[i][j] > 0) {
          int u = idxValue[i], v = idxValue[j];
          if (u != v) {
            newGraph.addEdge(u, v, cap[i][j]);
          }
        }
    }
    return newGraph;
  }
  void addEdge(int u, int v, int val) {
    cap[u][v] += val;
    flow[u][v] = 0;
  }
  tuple<int, vector<vector<int>>> maxFlow(int source, int sink) {
    int flowValue = 0;
    while (true) {
      queue<int> q;
      vector<int> trace(N_);
      for (int i = 0; i < N_; i++) {
        trace[i] = -1;
      }
      trace[source] = -2;
      q.push(source);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < N_; v++)
          if (cap[u][v] > flow[u][v] && trace[v] == -1) {
            trace[v] = u;
            q.push(v);
          }
      }
      if (trace[sink] == -1) {
        vector<int> csource, csink;
        for (int i = 0; i < N_; i++) {
          if (trace[i] != -1) {
            csource.push_back(i);
          } else {
            csink.push_back(i);
          }
        }
        vector<vector<int>> components;
        components.push_back(csource);
        components.push_back(csink);
        return make_tuple(flowValue, components);
      } else {
        int minValue = -1;
        for (int v = sink, u = trace[v]; v != source; v = u, u = trace[v]) {
          if (minValue < 0 || minValue > cap[u][v] - flow[u][v]) {
            minValue = cap[u][v] - flow[u][v];
          }
        }
        flowValue += minValue;
        for (int v = sink, u = trace[v]; v != source; v = u, u = trace[v]) {
          flow[u][v] += minValue;
          flow[v][u] -= minValue;
        }
      }
    }
    return make_tuple(flowValue, vector<vector<int>>());
  }
  vector<vector<int>> cap, flow;
  int N_;
};
struct GomoryHu {
  GomoryHu(Graph& original) {
    edges.resize(original.N_);
    N_ = original.N_;
    remainings.clear();
    int flow, source, sink;
    vector<vector<int>> comps;
    bool started = false;
    while (!started || !remainings.empty()) {
      vector<bool> inComponent(N_);
      if (!started) {
        started = true;
        for (int i = 0; i < N_; i++) {
          inComponent[i] = true;
        }
        source = 0;
        sink = 1;
        tie(flow, comps) = original.maxFlow(source, sink);
      } else {
        auto v = remainings.back();
        remainings.pop_back();
        if (v.empty()) {
          cout << "Bad component" << endl;
          assert(false);
        }
        if (v.size() == 1) {
          continue;
        }
        for (auto x : v) {
          inComponent[x] = true;
        }
        auto contracted = original.makeContractedGraph(v, remainings);
        source = v[0];
        sink = v[1];
        tie(flow, comps) = contracted.maxFlow(source, sink);
      }
      addEdge(source, sink, flow);
      for (auto z : comps) {
        vector<int> newComp;
        for (auto x : z)
          if (x < N_ && inComponent[x]) {
            newComp.push_back(x);
          }
        remainings.push_back(newComp);
      }
    }
  }
  void addEdge(int u, int v, int c) {
    edges[u].push_back(make_pair(v, c));
    edges[v].push_back(make_pair(u, c));
  }
  tuple<int, vector<int>> findTour() { return findTourRecursive(0, -1); }
  tuple<int, vector<int>> findTourRecursive(int u, int par) {
    int nc = 0, xc = -1, yc = -1, minCost = -1;
    vector<bool> vis(N_);
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      nc++;
      for (auto p : edges[x]) {
        int y = p.first;
        if (y == par) {
          continue;
        }
        if (usedEdges.find(make_pair(x, y)) != usedEdges.end()) {
          continue;
        }
        if (minCost < 0 || minCost > p.second) {
          minCost = p.second;
          xc = x;
          yc = y;
        }
        if (!vis[y]) {
          vis[y] = true;
          q.push(y);
        }
      }
    }
    if (nc == 1) {
      vector<int> singleton = {u};
      return make_tuple(0, singleton);
    } else {
      usedEdges.insert(make_pair(xc, yc));
      usedEdges.insert(make_pair(yc, xc));
      auto leftTree = findTourRecursive(xc, yc);
      auto rightTree = findTourRecursive(yc, xc);
      int finalCost = get<0>(leftTree) + get<0>(rightTree);
      auto finalTour = get<1>(leftTree);
      for (auto v : get<1>(rightTree)) {
        finalTour.push_back(v);
      }
      return make_tuple(finalCost + minCost, finalTour);
    }
  }
  vector<vector<int>> remainings;
  vector<vector<pair<int, int>>> edges;
  set<pair<int, int>> usedEdges;
  int N_;
};
int n, m;
Graph original;
int main() {
  scanf("%d %d", &n, &m);
  original = Graph(n);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    u--;
    v--;
    original.addEdge(u, v, c);
    original.addEdge(v, u, c);
  }
  GomoryHu tree = GomoryHu(original);
  auto ret = tree.findTour();
  printf("%d\n", get<0>(ret));
  for (auto x : get<1>(ret)) {
    printf("%d ", x + 1);
  }
  printf("\n");
  return 0;
}
