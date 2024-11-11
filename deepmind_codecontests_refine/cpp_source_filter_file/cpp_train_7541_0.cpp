#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void mine(T1 &x, const T2 &y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &b) {
  for (auto &k : b) os << k << ' ';
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &b) {
  for (auto &k : b) is >> k;
  return is;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 200100;
const long long INF = 1e18 + 228;
struct edge {
  long long id;
  long long to;
  long long cost;
  long long flow;
  edge(long long _id, long long _to, long long _cost, long long _flow) {
    id = _id;
    to = _to;
    cost = _cost;
    flow = _flow;
  }
};
vector<edge> g[N];
long long phi[N];
long long used[N];
bool ok;
long long mid;
long long minphi;
long long maxphi;
vector<long long> cur;
void dfs(long long v) {
  cur.push_back(v);
  used[v] = 1;
  maxe(maxphi, phi[v]);
  mine(minphi, phi[v]);
  for (auto [id, to, cost, flow] : g[v]) {
    if (id < mid) {
      long long must = phi[v] + flow * cost;
      if (!used[to]) {
        phi[to] = must;
        dfs(to);
      }
      ok &= phi[to] == must;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; ++i) {
    long long f, t, w, b;
    cin >> f >> t >> w >> b;
    --f, --t;
    g[f].push_back(edge(i, t, w, b));
    g[t].push_back(edge(i, f, w, -b));
  }
  long long L = 0;
  long long R = m + 1;
  long long U;
  while (R - L > 1) {
    ok = 1;
    mid = (L + R) / 2;
    memset(used, 0, sizeof(used));
    U = INF;
    for (long long i = 0; i < n && ok; ++i) {
      if (used[i]) continue;
      phi[i] = 0;
      maxphi = -INF;
      minphi = INF;
      cur.clear();
      dfs(i);
      ok &= maxphi - minphi < U;
      if (i == 0 && used[n - 1]) {
        U = phi[n - 1];
      }
      if (i == 0) {
        for (auto &v : cur) {
          ok &= v == 0 || phi[v] > 0;
        }
      }
      if (used[n - 1] == 1) {
        used[n - 1]++;
        for (auto &v : cur) {
          ok &= v == n - 1 || phi[v] < phi[n - 1];
        }
      }
    }
    if (ok)
      L = mid;
    else
      R = mid;
  }
  if (L < m) {
    cout << "BAD " << L + 1 << '\n';
    return 0;
  }
  if (U == INF) {
    cout << "UNKNOWN\n";
  } else {
    cout << U << '\n';
  }
}
