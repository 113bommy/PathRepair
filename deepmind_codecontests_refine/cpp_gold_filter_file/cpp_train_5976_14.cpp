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
  for (long long i = 0; i < (long long)((v).size()); i++) in >> v[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (long long i = 0; i < (long long)((v).size()); i++) out << v[i] << " ";
  return out;
}
template <typename T>
istream& operator>>(istream& in, pair<vector<T>*, vector<T>*> v) {
  for (long long i = 0; i < (long long)((*v.first).size()); i++)
    in >> (*v.first)[i] >> (*v.second)[i];
  return in;
}
const long long inf = numeric_limits<long long>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
struct graph {
  long long n;
  vector<vector<long long> > adj;
  graph() {}
  graph(long long n_) {
    n = n_;
    adj.resize(n);
  }
  void insert(long long v, long long u) {
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
};
long long n;
graph g;
vector<long long> sub, cntr, ans;
void precalc(long long v, long long p) {
  sub[v] = 1;
  for (long long u : g.adj[v]) {
    if (u == p || cntr[u] != -1) {
      continue;
    }
    precalc(u, v);
    sub[v] += sub[u];
  }
}
long long find(long long v, long long sz, long long p) {
  for (long long u : g.adj[v]) {
    if (u == p || cntr[u] != -1) {
      continue;
    }
    if (sub[u] >= sz / 2) {
      return find(u, sz, v);
    }
  }
  return v;
}
void centroid(long long v, long long parc, long long rk) {
  precalc(v, v);
  long long c = find(v, sub[v], v);
  cntr[c] = parc;
  ans[c] = rk;
  for (long long u : g.adj[c]) {
    if (cntr[u] != -1) {
      continue;
    }
    centroid(u, c, rk + 1);
  }
}
inline void solve() {
  sub.assign(n, 0);
  cntr.assign(n, -1);
  ans.assign(n, -1);
  centroid(0, 0, 0);
  for (long long i = 0; i < n; i++) {
    cout << char('A' + ans[i]) << " ";
  }
  cout << "\n";
}
inline void read() {
  cin >> n;
  g = graph(n);
  for (long long i = 0; i < n - 1; i++) {
    long long v, u;
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
