#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <typename T, typename U>
pair<T, U> operator+(const pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}
const long long int mod = 1e9 + 7;
const int maxn = 100005;
struct DSU {
  vector<long long int> par, sz;
  DSU(long long int n) {
    par.resize(n);
    sz = vector<long long int>(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  long long int find(long long int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
  }
  void unite(long long int a, long long int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int m, n;
  cin >> m >> n;
  long long int a[n + 1], b[m + 1];
  DSU dsu(n + m + 2);
  for (long long int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (long long int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  long long int sum = 0;
  vector<tuple<long long int, long long int, long long int>> edges;
  for (long long int i = 1; i <= m; i++) {
    long long int k;
    cin >> k;
    while (k--) {
      long long int x;
      cin >> x;
      sum += a[i] + b[x];
      edges.push_back({a[i] + b[x], i, m + x});
    }
  }
  sort((edges).begin(), (edges).end());
  reverse((edges).begin(), (edges).end());
  for (long long int i = 0; i < edges.size(); i++) {
    long long int w, u, v;
    tie(w, u, v) = edges[i];
    if (dsu.find(u) == dsu.find(v))
      continue;
    else {
      sum -= w;
      dsu.unite(u, v);
    }
  }
  cout << sum << '\n';
}
