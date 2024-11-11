#include <bits/stdc++.h>
using namespace std;
const int NN = 1e6 + 10, mod = 1e9 + 7, N = 2e5 + 10;
int n, m, a[N], p[NN], ans[N], dd[NN], D[NN], t[N], vt[NN], s[N], _s[N];
vector<int> e[N], sv[N];
vector<pair<int, int> > ad[N];
int pw(int a, int i) {
  int b = 1;
  for (; i; i >>= 1, a = 1ll * a * a % mod)
    if (i & 1) b = 1ll * b * a % mod;
  return b;
}
void read(int& x) {
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
}
void snt() {
  for (int i = 2, _c = NN - 10; i <= _c; ++i)
    if (!p[i])
      for (int j = i; j <= NN - 10; j += i) p[j] = i;
}
void update(int i, int x) {
  for (; i <= n; i += i & -i) t[i] = (1ll * t[i] * x) % mod;
}
int get(int i) {
  int g = 1;
  for (; i; i -= i & -i) g = (1ll * g * t[i]) % mod;
  return g;
}
void Update(int i, int x) { update(i, 1ll * (x - 1) * D[x] % mod); }
void unUpdate(int i, int x) { update(i, 1ll * D[x - 1] * x % mod); }
int S(int i, int j) { return 1ll * s[j] * _s[i - 1] % mod; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  read(n);
  for (int i = 1, _c = 1e6; i <= _c; ++i) D[i] = pw(i, mod - 2);
  snt();
  for (int i = 1, _c = n; i <= _c; ++i) t[i] = 1;
  s[0] = _s[0] = 1;
  for (int i = 1, _c = n; i <= _c; ++i) {
    read(a[i]);
    s[i] = (1ll * s[i - 1] * a[i]) % mod;
    _s[i] = pw(s[i], mod - 2);
    int x = a[i];
    while (x != 1) {
      e[i].push_back(p[x]);
      x /= p[x];
    }
    sort(e[i].begin(), e[i].end());
    e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
  }
  for (int i = n, _c = 1; i >= _c; --i) {
    for (auto& x : e[i]) {
      sv[i].push_back(vt[x]);
      vt[x] = i;
    }
  }
  read(m);
  for (int i = 1, _c = m; i <= _c; ++i) {
    int u, v;
    read(u), read(v);
    ad[u].push_back({v, i});
  }
  for (int i = 1, _c = n; i <= _c; ++i) {
    for (int j = 0, _c = int(e[i].size()) - 1; j <= _c; ++j) {
      if (!dd[e[i][j]]) Update(i, e[i][j]);
      dd[e[i][j]] = 1;
    }
  }
  for (auto& x : ad[1])
    ans[x.second] = 1ll * get(x.first) * S(1, x.first) % mod;
  for (int i = 2, _c = n; i <= _c; ++i) {
    for (int j = 0, _c = int(e[i - 1].size()) - 1; j <= _c; ++j) {
      int x = e[i - 1][j];
      unUpdate(i - 1, x);
      if (sv[i - 1][j]) Update(sv[i - 1][j], x);
      for (auto& o : ad[i])
        ans[o.second] = 1ll * get(o.first) * S(i, o.first) % mod;
    }
  }
  for (int i = 1, _c = m; i <= _c; ++i) cout << ans[i] << "\n";
}
