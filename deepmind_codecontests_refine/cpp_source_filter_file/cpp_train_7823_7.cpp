#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { return uniform_int_distribution<int>(0, x - 1)(rng); }
const int maxn = 1e6 + 7;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
bool Q;
struct Line {
  mutable long long k, m, p;
  bool operator<(const Line& o) const { return Q ? p < o.p : k < o.k; }
};
struct LineContainer : multiset<Line> {
  const long long inf = LLONG_MAX;
  long long div(long long a, long long b) {
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) {
      x->p = inf;
      return false;
    }
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(long long k, long long m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
  }
  long long query(long long x) {
    assert(!empty());
    Q = 1;
    auto l = *lower_bound({0, 0, x});
    Q = 0;
    return l.k * x + l.m;
  }
} ds;
long long gcd(long long x, long long y) {
  if (x < y) return gcd(y, x);
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long modexp(long long x, long long ex) {
  long long ans = 1ll;
  while (ex > 0) {
    if (ex & 1ll) ans = (ans * x) % mod;
    ex >>= 1ll;
    x = (x * x) % mod;
  }
  return ans;
}
long long sz[maxn];
long long f[maxn];
long long bs[maxn];
vector<int> G[maxn];
long long best = inf;
void dfs1(int x, int pi) {
  sz[x] = 1;
  for (int y : G[x]) {
    if (y == pi) continue;
    dfs1(y, x);
    sz[x] += sz[y];
  }
}
void dfs2(int x, int pi, long long T) {
  f[x] = T + ((sz[x]) * (sz[x]));
  for (int y : G[x]) {
    if (y == pi) continue;
    dfs2(y, x, T + ((sz[x] - sz[y]) * (sz[x] - sz[y])));
  }
}
void dfs3(int x, int pi) {
  bs[x] = f[x];
  for (int y : G[x]) {
    if (y == pi) continue;
    dfs3(y, x);
    if (bs[y] < bs[x]) bs[x] = bs[y];
  }
}
void dfs(int l, int pi, long long T) {
  long long c = ((T + sz[l]) * (T + sz[l])) - f[l] - f[l];
  ;
  for (int x : G[l]) {
    if (x == pi) continue;
    dfs(x, l, T + sz[l] - sz[x]);
  }
  ds.clear();
  long long curb = inf;
  for (int x : G[l]) {
    if (x == pi) continue;
    long long cx = bs[x] - 2 * T * sz[x];
    long long mx = 2 * sz[x];
    ;
    if (ds.size() > 0) {
      long long z = -ds.query(sz[x]);
      ;
      curb = min(curb, z + cx + c);
    }
    ds.add(-mx, -cx);
    long long sv = bs[x] - f[l] + ((sz[l]) * (sz[l])) -
                   ((sz[l] - sz[x]) * (sz[l] - sz[x])) +
                   ((T + sz[l] - sz[x]) * (T + sz[l] - sz[x]));
    ;
    curb = min(curb, sv);
  };
  best = min(best, curb);
}
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
  };
  int n;
  cin >> n;
  for (int j = 1; j < n; j++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs1(1, -1);
  dfs2(1, -1, 0);
  dfs3(1, -1);
  dfs(1, -1, 0);
  ;
  ;
  long long N = 1ll * n * (n - 1) / 2ll;
  N += (n * n - best) / 2;
  cout << N << "\n";
}
