#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
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
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long INF = 0x3f3f3f3f;
const long long mod = (119 << 23) + 1;
const long long M = 1e9 + 7;
const long long N = 2505;
const long long L = 13;
long long n;
long long a[N][N];
bool vs[N];
long long minv[N];
vector<long long> g[N];
void prim() {
  for (long long i = 0; i < n; ++i) {
    long long v = -1;
    for (long long j = 1; j <= n; ++j) {
      if (!vs[j] && (v == -1 || a[v][minv[v]] > a[j][minv[j]])) {
        v = j;
      }
    }
    if (minv[v] != 0) {
      g[v].push_back(minv[v]);
      g[minv[v]].push_back(v);
    }
    vs[v] = true;
    for (long long j = 1; j <= n; ++j) {
      if (!vs[j] && (minv[j] == 0 || a[j][minv[j]] > a[j][v])) {
        minv[j] = v;
      }
    }
  }
}
long long up[N][L];
long long he[N][L];
long long timer;
long long tin[N];
long long tout[N];
void tour(long long z, long long p) {
  tin[z] = timer++;
  up[z][0] = p;
  he[z][0] = a[z][p];
  for (long long i = 0; up[z][i] != 0; ++i) {
    up[z][i + 1] = up[up[z][i]][i];
    he[z][i + 1] = max(he[z][i], he[up[z][i]][i]);
  }
  for (long long y : g[z])
    if (y != p) tour(y, z);
  tout[z] = timer;
}
inline bool is_up(long long u, long long v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}
long long query(long long u, long long v) {
  long long ret = 0;
  for (long long i = 0; i < 2; ++i) {
    for (long long j = L - 1; j >= 0; --j) {
      if (up[u][j] == 0) continue;
      if (!is_up(up[u][j], v)) {
        ret = max(ret, he[u][j]);
        u = up[u][j];
      }
    }
    if (!is_up(u, v)) ret = max(ret, he[u][0]);
    swap(u, v);
  }
  return ret;
}
bool check() {
  for (long long i = 1; i <= n; ++i)
    if (a[i][i] != 0) return false;
  for (long long i = 1; i <= n; ++i)
    for (long long j = i + 1; j <= n; ++j) {
      if (a[i][j] != a[j][i]) return false;
    }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(15);
  cin >> n;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= n; ++j) cin >> a[i][j];
  if (!check()) {
    cout << "NOT MAGIC" << '\n';
    return 0;
  }
  prim();
  tour(1, 0);
  for (long long i = 1; i <= n; ++i)
    for (long long j = i + 1; j <= n; ++j) {
      if (query(i, j) != a[i][j]) {
        cout << "NOT MAGIC" << '\n';
        return 0;
      }
    }
  cout << "MAGIC" << '\n';
}
