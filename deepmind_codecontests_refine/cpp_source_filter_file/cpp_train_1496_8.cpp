#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const unordered_set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const unordered_map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
int power(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y / 2, x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
struct twoSAT {
  int n;
  vector<int> sol, vis;
  vector<int> order, comp;
  vector<vector<int> > g, gt;
  void init(int n) {
    this->n = n;
    g.resize(n);
    gt.resize(n);
  }
  void addEdge(int u, int v) {
    g[u].push_back(v);
    gt[v].push_back(u);
  }
  void dfs1(int nn) {
    vis[nn] = 1;
    for (auto v : g[nn])
      if (!vis[v]) dfs1(v);
    order.push_back(nn);
  }
  void dfs2(int nn, int cc) {
    comp[nn] = cc;
    for (auto v : gt[nn]) {
      if (comp[v] == -1) dfs2(v, cc);
    }
  }
  bool solver() {
    vis.assign(n, 0);
    for (int i = 0; i < (n); ++i)
      if (!vis[i]) dfs1(i);
    comp.assign(n, -1);
    int cc = 0;
    for (int i = 0; i < (n); ++i)
      if (comp[order[n - 1 - i]] == -1) dfs2(order[n - 1 - i], cc++);
    sol.assign(n / 2, 0);
    for (int i = 0; i < n; i += 2) {
      if (comp[i] == comp[i + 1]) return 0;
      sol[i / 2] = comp[i] > comp[i + 1];
    }
    return 1;
  }
} g;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, i;
  cin >> n >> m;
  g.init(2 * n);
  for (i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    if (c) {
      int door1 = a * 2;
      int door2 = b * 2;
      g.addEdge(door1, door2);
      g.addEdge(door2, door1);
      g.addEdge(door1 + 1, door2 + 1);
      g.addEdge(door2 + 1, door1 + 1);
    } else {
      int door1 = a * 2;
      int door2 = b * 2;
      g.addEdge(door1, door2 + 1);
      g.addEdge(door2, door1 + 1);
      g.addEdge(door1 + 1, door2);
      g.addEdge(door2 + 1, door1);
    }
  }
  if (!g.solver())
    cout << "Impossible";
  else {
    vector<int> res;
    for (int i = 0; i < m; i++) {
      if (g.sol[i]) res.push_back(i);
    }
    cout << res.size() << "\n";
    for (int x : res) cout << x + 1 << " ";
  }
}
