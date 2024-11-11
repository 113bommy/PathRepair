#include <bits/stdc++.h>
using namespace std;
const long N = 5 * 10000 + 7;
const long INF = 1000000000 + 7;
const long MODULE = 1000000000 + 7;
class TwosatSolver {
 public:
  int nov;
  int cnt;
  bool Invalid;
  int *color, *num, *low;
  vector<int> *edges;
  stack<int> s;
  unordered_set<long long> cedges;
  TwosatSolver(int n) {
    this->nov = n;
    edges = double_calloc<vector<int> >(n * 2 + 5);
    color = double_calloc<int>(n * 2 + 5);
    num = double_calloc<int>(n * 2 + 5);
    low = double_calloc<int>(n * 2 + 5);
    clear_color();
  }
  void clear_color() {
    cnt = 0;
    Invalid = false;
    while (!s.empty()) s.pop();
    for (int i = -nov; i <= nov; i++) {
      num[i] = low[i] = color[i] = 0;
    }
  }
  int no_edges() { return cedges.size(); }
  void display_edges() {
    cout << "----Begin show edges----\n";
    for (unordered_set<long long>::iterator it = cedges.begin();
         it != cedges.end(); ++it)
      cout << *it << endl;
    cout << "----End show edges----\n";
  }
  void shrink(int n) { this->nov = n; }
  template <class T>
  T *double_calloc(int n) {
    return ((T *)calloc(n, sizeof(T))) + (n) / 2;
  }
  long long hash_pair(int u, int v) {
    return 1ll * (u + 100007) * 100007 + (v + 100007);
  }
  void add_clause(int u, int v) {
    assert((u >= -nov) and (u <= nov));
    assert((v >= -nov) and (v <= nov));
    if (!cedges.count(hash_pair(-u, v)))
      edges[-u].push_back(v), cedges.insert(hash_pair(-u, v));
    if (!cedges.count(hash_pair(-v, u)))
      edges[-v].push_back(u), cedges.insert(hash_pair(-v, u));
  }
  void add_implication(int u, int v) {
    assert((u >= -nov) and (u <= nov));
    assert((v >= -nov) and (v <= nov));
    if (!cedges.count(hash_pair(u, v)))
      edges[u].push_back(v), cedges.insert(hash_pair(u, v));
  }
  void set_color(int u, int x) {
    if (color[u] == (x ^ 3))
      Invalid = true;
    else
      color[u] = x;
    if (color[-u] == x)
      Invalid = true;
    else
      color[-u] = (x ^ 3);
  }
  void dfs(int u) {
    num[u] = low[u] = ++cnt;
    s.push(u);
    for (auto v : edges[u]) {
      if (num[v]) {
        low[u] = min(low[u], num[v]);
      } else {
        dfs(v);
        low[u] = min(low[u], low[v]);
      }
      if (color[v] == 1) set_color(u, 1);
    }
    if (low[u] == num[u]) {
      int v = 0;
      if (color[u] == 0) set_color(u, 2);
      do {
        v = s.top();
        s.pop();
        set_color(v, color[u]);
        num[v] = low[v] = 0x33334444;
      } while (u != v);
    }
  }
  bool solve(vector<int> &ret) {
    for (int i = 1; i <= nov; i++)
      if (!num[i]) dfs(i);
    for (int i = 1; i < nov; i++)
      if (!num[i]) dfs(-i);
    if (Invalid) return false;
    for (int i = 1; i <= nov; i++)
      if (color[i] == 2) {
        ret.push_back(i);
      }
    return true;
  }
};
struct Edge {
  int v, c, t, id;
  Edge(int v, int c, int t, int id) {
    this->v = v;
    this->c = c;
    this->t = t;
    this->id = id;
  }
};
int n, m;
vector<Edge> a[N];
unordered_map<int, int> mc;
bool check(int mt, vector<int> &res, TwosatSolver &twosat) {
  twosat.clear_color();
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < a[u].size(); i++) {
      Edge e = a[u][i];
      if (e.t > mt) {
        twosat.set_color(e.id, 1);
      }
    }
  }
  res.clear();
  bool ret = twosat.solve(res);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, c, t;
    cin >> u >> v >> c >> t;
    a[u].push_back(Edge(v, c, t, i));
    a[v].push_back(Edge(u, c, t, i));
  }
  TwosatSolver twosat = TwosatSolver(3 * m);
  int curp = m + 1;
  for (int u = 1; u <= n; u++) {
    mc.clear();
    bool chose = false;
    for (int i = 0; i < a[u].size(); i++) {
      Edge e = a[u][i];
      if (!mc.count(e.c)) {
        mc[e.c] = e.id;
      } else {
        if (chose) {
          cout << "No" << endl;
          return 0;
        }
        chose = true;
        twosat.add_clause(e.id, mc[e.c]);
      }
      twosat.add_clause(curp, -e.id);
      if (i != 0) twosat.add_clause(-(curp - 1), curp);
      if (i != a[u].size() - 1) twosat.add_clause(-curp, -a[u][i + 1].id);
      ++curp;
    }
  }
  vector<int> res;
  int l = -1, r = INF;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (check(mid, res, twosat))
      r = mid;
    else
      l = mid;
  }
  if (!check(r, res, twosat)) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    cout << r << " ";
    int cnt = 0;
    for (auto e : res)
      if (e <= m) ++cnt;
    cout << cnt << endl;
    for (auto e : res)
      if (e <= m) cout << e << " ";
  }
  return 0;
}
