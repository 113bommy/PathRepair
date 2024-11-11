#include <bits/stdc++.h>
using namespace std;
struct UF {
  vector<int> e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
template <class T>
struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T>& V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= (int)(V).size(); pw *= 2, ++k) {
      jmp.emplace_back((int)(V).size() - pw * 2 + 1);
      for (int j = 0; j < ((int)(jmp[k]).size()); ++j)
        jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int a, int b) {
    assert(a < b);
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};
struct LCA {
  int T = 0;
  vector<int> time, path, ret;
  RMQ<int> rmq;
  LCA(vector<vector<int>>& C)
      : time((int)(C).size()), rmq((dfs(C, 0, -1), ret)) {}
  void dfs(vector<vector<int>>& C, int v, int par) {
    time[v] = T++;
    for (int y : C[v])
      if (y != par) {
        path.push_back(v), ret.push_back(time[v]);
        dfs(C, y, v);
      }
  }
  int lca(int a, int b) {
    if (a == b) return a;
    tie(a, b) = minmax(time[a], time[b]);
    return path[rmq.query(a, b)];
  }
};
pair<int, int> makeEdge(int a, int b) {
  return pair<int, int>(min(a, b), max(a, b));
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  UF uf(n);
  vector<vector<int>> edges(n);
  int cnt = 0;
  for (int _ = 0; _ < (m); ++_) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    if (!uf.sameSet(u, v)) {
      uf.join(u, v);
      edges[u].push_back(v);
      edges[v].push_back(u);
      cnt++;
    }
  }
  assert(cnt == n - 1);
  vector<int> dad(n, -2);
  dad[0] = -1;
  queue<int> q;
  q.push(0);
  while ((int)(q).size()) {
    int u = q.front();
    q.pop();
    for (auto& v : edges[u])
      if (dad[v] == -2) {
        dad[v] = u;
        q.push(v);
      }
  }
  vector<vector<int>> paths;
  set<pair<int, int>> activeEdges;
  LCA lca(edges);
  int queries;
  cin >> queries;
  for (int _ = 0; _ < (queries); ++_) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int p = lca.lca(a, b);
    vector<int> tempPath(1, a);
    while (a != p) {
      int temp = dad[a];
      pair<int, int> e = makeEdge(a, temp);
      if (activeEdges.count(e))
        activeEdges.erase(e);
      else
        activeEdges.insert(e);
      a = temp;
      tempPath.push_back(a);
    }
    vector<int> tempPath2(1, b);
    if (p == b) tempPath2.pop_back();
    while (b != p) {
      int temp = dad[b];
      pair<int, int> e = makeEdge(b, temp);
      if (activeEdges.count(e))
        activeEdges.erase(e);
      else
        activeEdges.insert(e);
      b = temp;
      if (b != p) tempPath2.push_back(b);
    }
    reverse(begin(tempPath2), end(tempPath2));
    for (auto& elem : tempPath2) tempPath.push_back(elem);
    paths.push_back(tempPath);
  }
  if ((int)(activeEdges).size()) {
    cout << "NO" << endl;
    vector<int> valency(n);
    vector<vector<int>> edgesToUse(n);
    for (auto& e : activeEdges) {
      valency[e.first]++;
      valency[e.second]++;
      edgesToUse[e.first].push_back(e.second);
      edgesToUse[e.second].push_back(e.first);
    }
    for (int i = 0; i < (n); ++i)
      if (valency[i] == 1) {
        q.push(i);
      }
    int ans = 0;
    while ((int)(q).size()) {
      int u = q.front();
      q.pop();
      if (valency[u] != 1) continue;
      ans++;
      while ((int)(edgesToUse[u]).size()) {
        int v = edgesToUse[u].back();
        edgesToUse[u].pop_back();
        pair<int, int> e = makeEdge(u, v);
        if (activeEdges.count(e)) {
          activeEdges.erase(e);
          valency[u]--;
          valency[v]--;
          if (valency[u] == 1) q.push(u);
          u = v;
        }
      }
    }
    cout << ans << endl;
  } else {
    cout << "YES" << endl;
    for (auto& v : paths) {
      cout << (int)(v).size() << endl;
      for (auto& elem : v) cout << elem + 1 << " ";
      cout << endl;
    }
  }
}
