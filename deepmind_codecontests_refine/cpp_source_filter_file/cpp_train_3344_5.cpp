#include <bits/stdc++.h>
using namespace std;
class solution {
 public:
  solution(int n) {
    this->n = n;
    g = vector<vector<pair<int, int>>>(n);
    id = new int[n];
    od = new int[n];
    ex = new int[n];
    memset(id, 0, sizeof(int) * (n));
    memset(od, 0, sizeof(int) * (n));
    memset(ex, 0, sizeof(int) * (n));
  }
  void addEdge(int u, int v, int c) {
    g[u].push_back({v, c});
    od[u]++;
    id[v]++;
  }
  void solve() {
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!id[i]) q.push(i);
    cout << q.size() << '\n';
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      pair<int, int> md;
      if (!ex[i]) md = dfs(i);
      if (md.first != -1) {
        cout << i + 1 << ' ' << md.first + 1 << ' ' << md.second << '\n';
      }
    }
  }
  pair<int, int> dfs(int u) {
    ex[u] = 1;
    int dm = INT_MAX;
    for (auto i : g[u]) {
      if (!ex[i.first]) {
        pair<int, int> s = dfs(i.first);
        dm = min(dm, s.second);
        dm = min(dm, i.second);
        if (!od[i.first]) return {i.first, dm};
        if (s.first != -1) return {s.first, dm};
      }
    }
    return {-1, dm};
  }

 private:
  int n;
  vector<vector<pair<int, int>>> g;
  int *id, *od;
  int *ex;
};
int main() {
  int n, m;
  cin >> n >> m;
  solution *s = new solution(n);
  for (int i = 0; i < int(m); i++) {
    int u, v, d;
    cin >> u >> v >> d;
    s->addEdge(u - 1, v - 1, d);
  }
  s->solve();
  return 0;
}
