#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << '(' << p.first << "," << p.second << ')';
}
const int N = 500005;
long long c[N];
map<long long, vector<pair<int, int>>> ed;
struct DSU {
  vector<int> p, r;
  int n;
  int components;
  DSU(int _) : n(_), components(_) {
    p.resize(n + 1);
    r.resize(n + 1);
    for (int i = 0; i <= _; ++i) p[i] = i, r[i] = 0;
  }
  int parent(int i) { return p[i] = (p[i] == i) ? i : parent(p[i]); }
  void merge(int x, int y) {
    x = parent(x);
    y = parent(y);
    if (x == y) return;
    if (r[x] > r[y])
      p[y] = x;
    else
      p[x] = y;
    if (r[x] == r[y]) ++r[y];
    --components;
  }
};
int _runtimeTerror_() {
  long long ans = 0;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  ans += power(2, n, M) * ((1LL << k) % M) % M;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    ed[c[x] ^ c[y]].push_back({x, y});
  }
  DSU dsu(n);
  for (auto &j : ed) {
    int cnt = 0;
    for (auto &k : j.second)
      dsu.p[k.first] = k.first, dsu.p[k.second] = k.second;
    dsu.components = n;
    for (auto &k : j.second) {
      dsu.merge(k.first, k.second);
    }
    ans -= power(2, n, M);
    ans %= M;
    ans += power(2, dsu.components, M);
    ans = (ans + M) % M;
  }
  cout << ans << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
