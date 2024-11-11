#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
template <typename T>
istream& operator>>(istream& in, pair<T, T>& v) {
  in >> v.first >> v.second;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, pair<T, T>& v) {
  out << v.first << " " << v.second;
  return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (int i = 0; i < (int)((v).size()); i++) in >> v[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (int i = 0; i < (int)((v).size()); i++) out << v[i] << " ";
  return out;
}
template <typename T>
istream& operator>>(istream& in, pair<vector<T>*, vector<T>*> v) {
  for (int i = 0; i < (int)((*v.first).size()); i++)
    in >> (*v.first)[i] >> (*v.second)[i];
  return in;
}
const int inf = numeric_limits<int>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
const int MAXN = 1e5 + 10;
struct graph {
  int n;
  vector<vector<int> > adj;
  graph() {}
  graph(int n_) {
    n = n_;
    adj.resize(n);
  }
  inline void insert(int v, int u) {
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
};
int n;
graph g;
vector<int> sub, ans;
bitset<MAXN> cntr;
inline void precalc(int v, int p) {
  sub[v] = 1;
  for (int u : g.adj[v]) {
    if (u == p || cntr[u]) {
      continue;
    }
    precalc(u, v);
    sub[v] += sub[u];
  }
}
inline int find(int v, int sz, int p) {
  for (int u : g.adj[v]) {
    if (u == p || cntr[u]) {
      continue;
    }
    if (sub[u] > sz * 20 / 10) {
      return find(u, sz, v);
    }
  }
  return v;
}
inline void centroid(int v, int rk) {
  precalc(v, v);
  int c = find(v, sub[v], v);
  cntr[c] = 1;
  ans[c] = rk;
  for (int u : g.adj[c]) {
    if (cntr[u]) {
      continue;
    }
    centroid(u, rk + 1);
  }
}
inline void solve() {
  sub.assign(n, 0);
  ans.assign(n, -1);
  centroid(0, 0);
  for (int i = 0; i < n; i++) {
    cout << char('A' + ans[i]) << " ";
  }
  cout << "\n";
}
inline void read() {
  cin >> n;
  g = graph(n);
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    g.insert(v, u);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  solve();
  return 0;
}
