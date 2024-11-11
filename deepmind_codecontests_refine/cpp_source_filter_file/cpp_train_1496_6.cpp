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
const int MAXN = 262144;
class TwoSat {
 public:
  int n, mark[MAXN];
  int stk[MAXN], stkIdx;
  vector<int> g[MAXN];
  void impl(int u, int v) { g[u].push_back(v); }
  void V(int x, int y) {
    impl(x ^ 1, y);
    impl(y ^ 1, x);
  }
  void eq(int x, int y) {
    impl(x, y);
    impl(y, x);
    impl(x ^ 1, y ^ 1);
    impl(y ^ 1, x ^ 1);
  }
  void tru(int x) { impl(x ^ 1, x); }
  int dfs(int u) {
    if (mark[u ^ 1]) return 0;
    if (mark[u]) return 1;
    mark[u] = 1, stk[++stkIdx] = u;
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (!dfs(v)) return false;
    }
    return true;
  }
  int solvable() {
    for (int i = 0; i < n; i += 2) {
      if (mark[i] == 0 && mark[i + 1] == 0) {
        stkIdx = -1;
        if (!dfs(i)) {
          while (stkIdx >= 0) mark[stk[stkIdx]] = 0, stkIdx--;
          if (!dfs(i + 1)) return 0;
        }
      }
    }
    return 1;
  }
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; i++) g[i].clear(), mark[i] = 0;
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
      g.impl(door1, door2);
      g.impl(door2, door1);
      g.impl(door1 + 1, door2 + 1);
      g.impl(door2 + 1, door1 + 1);
    } else {
      int door1 = a * 2;
      int door2 = b * 2;
      g.impl(door1, door2 + 1);
      g.impl(door2, door1 + 1);
      g.impl(door1 + 1, door2);
      g.impl(door2 + 1, door1);
    }
  }
  if (!g.solvable())
    cout << "Impossible";
  else {
    vector<int> res;
    for (int i = 0; i < 2 * m; i += 2) {
      if (g.mark[i]) res.push_back(i / 2);
    }
    cout << res.size() << "\n";
    for (int x : res) cout << x + 1 << " ";
  }
}
