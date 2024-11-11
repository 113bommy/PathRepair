#include <bits/stdc++.h>
using namespace std;
static inline void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
static inline int ctz(unsigned x) { return __builtin_ctz(x); }
static inline int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
static inline int clz(unsigned x) { return __builtin_clz(x); }
static inline int clzll(unsigned long long x) { return __builtin_clzll(x); }
static inline int popcnt(unsigned x) { return __builtin_popcount(x); }
static inline int popcntll(unsigned long long x) {
  return __builtin_popcountll(x);
}
static inline int bsr(unsigned x) { return 31 ^ clz(x); }
static inline int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
int a[200008];
int id[200008];
int sz[200008];
int rk[200008];
void rst(int x) {
  id[x] = x;
  sz[x] = 1;
  rk[x] = 0;
}
int fin(int x) { return id[x] == x ? x : id[x] = fin(id[x]); }
void uni(int x, int y) {
  if (rk[x] < rk[y]) {
    id[x] = y;
    sz[y] += sz[x];
  } else {
    id[y] = x;
    sz[x] += sz[y];
    rk[x] = max(rk[x], rk[y] + 1);
  }
}
vector<int> vs[200008];
vector<pair<int, int> > es[200008];
long long ans[200008];
int main() {
  canhazfast();
  int n, amx = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    amx = max(amx, a[i]);
    vs[a[i]].push_back(i);
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    es[gcd(a[x], a[y])].push_back(make_pair(x, y));
  }
  for (int i = amx; i > 0; --i) {
    long long res = 0;
    for (int j = i; j <= amx; j += i) {
      res += (long long)vs[j].size();
      for (int v : vs[j]) rst(v);
      if (j > i) res -= ans[j];
    }
    for (int j = i; j <= amx; j += i) {
      for (pair<int, int> e : es[j]) {
        int x = fin(e.first), y = fin(e.second);
        res += (long long)sz[x] * sz[y];
        uni(x, y);
      }
    }
    ans[i] = res;
  }
  for (int i = 1; i <= amx; ++i)
    if (ans[i]) cout << i << ' ' << ans[i] << '\n';
  return 0;
}
