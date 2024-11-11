#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
  return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  os << '[';
  for (unsigned int i = 0; i < a.size(); i++)
    os << a[i] << (i < a.size() - 1 ? ", " : "");
  os << ']';
  return os;
}
int read() {
  int x;
  cin >> x;
  return x;
}
struct Edge {
  int u, v, c;
  Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c){};
};
int n, m;
vector<Edge> edge;
vector<vector<pair<int, int> > > a(N);
vector<vector<pair<int, int> > > extra(N);
struct DirectedDfs {
  vector<int> num, low, in, S;
  vector<int> label;
  int counter;
  vector<vector<int> > scc;
  DirectedDfs()
      : num(n + 5, -1),
        low(n + 5, 0),
        in(n + 5, 0),
        label(n + 5, 0),
        counter(0) {
    for (int i = (int)1; i <= (int)n; i++)
      if (num[i] == -1) dfs(i);
  }
  void dfs(int u) {
    low[u] = num[u] = counter++;
    S.push_back(u);
    in[u] = 1;
    for (auto it : a[u]) {
      int v = it.first;
      if (num[v] == -1) dfs(v);
      if (in[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
      scc.push_back(vector<int>());
      while (1) {
        int v = S.back();
        S.pop_back();
        in[v] = 0;
        scc.back().push_back(v);
        label[v] = scc.size();
        if (u == v) break;
      }
    }
  }
};
vector<int> makeAnswer(int lim) {
  a.assign(n + 5, vector<pair<int, int> >());
  vector<int> deg(n + 5, 0);
  vector<bool> visited(n + 5, 0), mark(m + 5, 0);
  vector<int> ret;
  for (int i = (int)0; i <= (int)edge.size() - 1; i++) {
    auto &it = edge[i];
    if (it.c > lim)
      a[it.u].push_back(make_pair(it.v, i)), deg[it.v]++;
    else
      extra[it.u].push_back(make_pair(it.v, i)),
          extra[it.v].push_back(make_pair(it.u, i));
  }
  queue<int> q;
  for (int _ = (int)1; _ <= (int)n; _++) {
    if (!visited[_] && deg[_] == 0) q.push(_);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      visited[u] = true;
      for (auto it : extra[u]) {
        if (mark[it.second]) continue;
        mark[it.second] = true;
        if (edge[it.second].u != u) ret.push_back(it.second);
      }
      for (auto it : a[u]) {
        deg[it.first]--;
        if (deg[it.first] == 0) q.push(it.first);
      }
    }
  }
  return ret;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  auto check = [&](int lim) {
    a.assign(n + 5, vector<pair<int, int> >());
    for (int i = (int)0; i <= (int)edge.size() - 1; i++) {
      auto &it = edge[i];
      if (it.c > lim) a[it.u].push_back(make_pair(it.v, i));
    }
    DirectedDfs Tree;
    if (Tree.scc.size() != n) return false;
    return true;
  };
  cin >> n >> m;
  for (int i = (int)1; i <= (int)m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    edge.push_back(Edge(u, v, c));
  }
  int l = 1, r = 1e9;
  while (l != r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  auto rec = makeAnswer(l);
  cout << l << ' ' << rec.size() << '\n';
  for (auto it : rec) cout << it + 1 << ' ';
  cout << '\n';
}
