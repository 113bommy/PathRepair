#include <bits/stdc++.h>
using namespace std;
vector<int64_t> p;
vector<int64_t> sz;
void build() {
  int64_t n = p.size();
  for (int64_t i = 0; i < n; ++i) {
    p[i] = i;
    sz[i] = 1;
  }
}
int64_t getp(int64_t v) {
  if (p[v] == v)
    return v;
  else
    return p[v] = getp(p[v]);
}
void upd(int64_t a, int64_t b) {
  a = getp(a);
  b = getp(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
  }
}
const int64_t inf = 1e9 + 7;
int64_t bin_pow(int64_t x) {
  if (x == 0) {
    return 1;
  }
  if (x % 2 == 0) {
    int64_t y = bin_pow(x / 2);
    return (y * y) % inf;
  } else {
    int64_t y = bin_pow(x / 2);
    return (2 * y * y) % inf;
  }
}
int main() {
  int64_t n, m;
  cin >> n >> m;
  p.resize(n);
  sz.resize(n);
  build();
  vector<vector<int64_t>> g(n);
  for (int64_t i = 0; i < m; ++i) {
    int64_t a, b, t;
    cin >> a >> b >> t;
    --a, --b;
    if (t == 1)
      upd(a, b);
    else {
      g[a].push_back(b);
      g[b].push_back(a);
    }
  }
  vector<vector<int64_t>> g0(n);
  for (int64_t i = 0; i < n; ++i) {
    for (auto u : g[i]) {
      g0[getp(i)].push_back(getp(u));
      g0[getp(u)].push_back(getp(i));
    }
  }
  int64_t cnt = 0;
  bool ok = true;
  vector<int64_t> used(n);
  vector<int64_t> col(n);
  for (int64_t i = 0; i < n; ++i) {
    if (used[getp(i)] == 0) {
      cnt++;
      queue<int64_t> q;
      int64_t v0 = getp(i);
      used[v0] = 1;
      col[v0] = 1;
      q.push(v0);
      while (!q.empty()) {
        int64_t v = q.front();
        used[v] = 1;
        q.pop();
        for (auto u : g0[v]) {
          if (used[u] == 0) {
            col[u] = 3 - col[v];
            q.push(u);
            used[u] = 1;
          } else {
            if (col[u] == col[v]) ok = false;
          }
        }
      }
    }
  }
  if (!ok) {
    cout << 0;
    return 0;
  }
  cout << bin_pow(cnt - 1);
}
