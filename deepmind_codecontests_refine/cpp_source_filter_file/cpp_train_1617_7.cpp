#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
const long long maxn = 1e5 + 5, N = 1000 + 1, SQ = 320, base = 800287,
                mod = 1e9 + 7, INF = 1e16 + 10, lg = 20;
const double eps = 1e-4;
struct node {
  long long lazy;
  bitset<N> b;
  node() {
    lazy = 0;
    b.set(0);
  }
};
long long n, m, q, a[maxn], st[maxn], ft[maxn], tme;
vector<long long> edges[maxn];
bitset<N> prime, res;
bool notprime[maxn];
node seg[4 * maxn];
void find_primes() {
  notprime[1] = 1;
  for (long long i = 2; i <= m; ++i) {
    if (!notprime[i]) {
      prime[i] = 1;
      for (long long j = i + i; j <= m; j += i) {
        notprime[j] = 1;
      }
    }
  }
}
void dfs(long long v, long long p = -1) {
  st[v] = tme++;
  for (auto u : edges[v]) {
    if (u != p) {
      dfs(u, v);
    }
  }
  ft[v] = tme;
}
inline void shift(long long v) {
  long long x = seg[v].lazy;
  seg[2 * v].lazy += x;
  if (seg[2 * v].lazy >= m) {
    seg[2 * v].lazy -= m;
  }
  seg[2 * v + 1].lazy += x;
  if (seg[2 * v + 1].lazy >= m) {
    seg[2 * v + 1].lazy -= m;
  }
  seg[2 * v].b = (seg[2 * v].b << x) | (seg[2 * v].b >> (m - x));
  seg[2 * v + 1].b = (seg[2 * v + 1].b << x) | (seg[2 * v + 1].b >> (m - x));
  seg[v].lazy = 0;
}
void add(long long l, long long r, long long x, long long v = 1,
         long long s = 0, long long e = n) {
  if (l >= e || s >= r) {
    return;
  }
  if (l <= s && e <= r) {
    seg[v].b = (seg[v].b << x) | (seg[v].b >> (m - x));
    seg[v].lazy += x;
    if (seg[v].lazy >= m) {
      seg[v].lazy -= m;
    }
    return;
  }
  shift(v);
  add(l, r, x, 2 * v, s, (s + e) / 2);
  add(l, r, x, 2 * v + 1, (s + e) / 2, e);
  seg[v].b = seg[2 * v].b | seg[2 * v + 1].b;
}
void get(long long l, long long r, long long v = 1, long long s = 0,
         long long e = n) {
  if (l >= e || s >= r) {
    return;
  }
  if (l <= s && e <= r) {
    res |= seg[v].b;
    return;
  }
  shift(v);
  get(l, r, 2 * v, s, (s + e) / 2);
  get(l, r, 2 * v + 1, (s + e) / 2, e);
  seg[v].b = seg[2 * v].b | seg[2 * v + 1].b;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  find_primes();
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (long long i = 0; i < n - 1; ++i) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  dfs(0);
  for (long long i = 0; i < n; ++i) {
    add(st[i], st[i] + 1, a[i] % m);
  }
  cin >> q;
  while (q--) {
    long long type, v, x;
    cin >> type;
    if (type == 1) {
      cin >> v >> x;
      v--;
      add(st[v], ft[v], x % m);
    } else {
      cin >> v;
      v--;
      res.reset();
      get(st[v], ft[v]);
      res &= prime;
      cout << res.count() << '\n';
    }
  }
}
