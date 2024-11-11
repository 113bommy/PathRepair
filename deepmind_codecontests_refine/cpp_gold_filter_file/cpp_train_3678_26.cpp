#include <bits/stdc++.h>
using namespace std;
struct unionfind {
  vector<int64_t> par;
  vector<int64_t> sz;
  unionfind(int64_t n) : par(vector<int64_t>(n)), sz(vector<int64_t>(n, 1)) {
    iota(par.begin(), par.end(), 0);
  }
  void unite(int64_t a, int64_t b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (rand() % 2) swap(a, b);
    par[a] = b;
    sz[b] += sz[a];
  }
  int64_t find(int64_t v) {
    if (par[v] == v) return v;
    return par[v] = find(par[v]);
  }
};
int64_t fastpowmod(int64_t bs, int64_t ex, int64_t md) {
  int64_t rs = 1;
  for (; ex > 0; ex /= 2) {
    if (ex & 1) rs = (rs * bs) % md;
    bs = (bs * bs) % md;
  }
  return rs;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int64_t n, m, mod;
  cin >> n >> m >> mod;
  unionfind uf(n);
  for (int64_t i = 0; i < m; i++) {
    int64_t a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.unite(a, b);
  }
  int64_t rs = 1;
  int64_t cnt = 0;
  for (int64_t i = 0; i < n; i++) {
    if (uf.find(i) == i) {
      rs = (rs * uf.sz[i]) % mod;
      cnt++;
    }
  }
  rs *= fastpowmod(n, cnt - 2, mod);
  rs %= mod;
  cout << (cnt == 1 ? (1 % mod) : rs) << "\n";
}
