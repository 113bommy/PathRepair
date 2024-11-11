#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long linf = 1LL << 62;
const int MAX = 510000;
long long dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
long long dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const double pi = acos(-1);
const double eps = 1e-7;
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
inline void print2(T1 a, T2 b) {
  cout << a << " " << b << endl;
}
template <typename T1, typename T2, typename T3>
inline void print3(T1 a, T2 b, T3 c) {
  cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;
struct UnionFind {
  vector<long long> p;
  vector<long long> rank;
  vector<long long> cnt;
  UnionFind(long long n) {
    rank.resize(n, 0);
    p.resize(n, 0);
    cnt.resize(n, 0);
    for (long long i = 0; i < (n); i++) {
      p[i] = i;
      rank[i] = 0;
      cnt[i] = 1;
    }
  }
  long long find(long long x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
  }
  bool same(long long x, long long y) { return find(x) == find(y); }
  void unite(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] > rank[y]) {
      p[y] = x;
      cnt[x] += cnt[y];
    } else {
      p[x] = y;
      cnt[y] += cnt[x];
      if (rank[x] == rank[y]) rank[y]++;
    }
  }
  long long size(long long x) { return cnt[find(x)]; }
};
void solve() {
  long long n, q;
  cin >> n >> q;
  vector<tuple<long long, long long, long long> > a(n - 1);
  for (long long i = 0; i < (n - 1); i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    a[i] = tie(w, u, v);
  }
  sort((a).begin(), (a).end());
  vector<pair<long long, long long> > query(q);
  vector<long long> ans(q, 0);
  for (long long i = 0; i < (q); i++) {
    cin >> query[i].first;
    query[i].second = i;
  }
  sort((query).begin(), (query).end());
  long long now = 0;
  long long edge = 0;
  UnionFind uf(n);
  for (long long i = 0; i < (q); i++) {
    long long id = query[i].second;
    if (now == query[i].first)
      ans[id] = ans[query[i - 1].second];
    else {
      if (i > 0) ans[id] = ans[query[i - 1].second];
      now = query[i].first;
      while (edge < n - 1) {
        long long u, v, w;
        tie(w, u, v) = a[edge];
        if (w > now) break;
        long long uu = uf.size(u);
        long long vv = uf.size(v);
        ans[id] -= uu * (uu - 1) / 2 + vv * (vv - 1) / 2;
        uf.unite(u, v);
        long long nu = uf.size(u);
        ans[id] += nu * (nu - 1) / 2;
        edge++;
      }
    }
  }
  for (long long i = 0; i < (q); i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
