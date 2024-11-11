#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.fr >> a.sc;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.fr << " " << a.sc;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 3 * 100005;
vector<long long> adj[N];
vector<pair<long long, long long> > dog[N];
long long ans[N];
class Fenwick {
  long long bit[N];

 public:
  Fenwick() {
    for (long long i = 0; i < N; ++i) {
      bit[i] = 0;
    }
  }
  long long sum(long long x) {
    long long ret = 0;
    for (long long i = x; i >= 0; i = (i & (i + 1)) - 1) {
      ret += bit[i];
    }
    return ret;
  }
  long long sum(long long l, long long r) { return sum(r) - sum(l - 1); }
  void add(long long pos, long long val) {
    for (long long i = pos; i < N; i = i | (i + 1)) {
      bit[i] += val;
    }
  }
} ft;
void dfs(long long v, long long p = 0, long long dep = 1) {
  for (auto z : dog[v]) {
    long long l = dep;
    long long r = dep + z.first;
    long long val = z.second;
    ft.add(l, val);
    ft.add(r + 1, -val);
  }
  ans[v] = ft.sum(dep);
  for (auto u : adj[v]) {
    if (u == p) continue;
    dfs(u, v, dep + 1);
  }
  for (auto z : dog[v]) {
    long long l = dep;
    long long r = dep + z.first;
    long long val = z.second;
    ft.add(l, -val);
    ft.add(r + 1, -val);
  }
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n - 1; ++i) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long m;
  cin >> m;
  for (long long i = 0; i < m; ++i) {
    long long v, d, x;
    cin >> v >> d >> x;
    dog[v].emplace_back(d, x);
  }
  dfs(1);
  for (long long i = 0; i < n; ++i) {
    cout << ans[i + 1] << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
