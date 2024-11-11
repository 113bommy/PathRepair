#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
class stree {
 public:
  std::vector<std::pair<long long, long long>> t;
  int s;
  void build(int n, int v, int tl, int tr) {
    if (v == 1) {
      t.resize(n * 4);
      s = n;
    }
    if (tl == tr)
      t[v] = make_pair(0, 1);
    else {
      int tm = (tl + tr) / 2;
      build(n, v * 2, tl, tm);
      build(n, v * 2 + 1, tm + 1, tr);
      t[v].first = t[v * 2].first + t[v * 2 + 1].first;
      t[v].second = (t[v * 2].second * t[v * 2 + 1].second) % mod;
    }
  }
  void set(int v, int tl, int tr, int pos, std::pair<long long, long long> to) {
    if (pos == tl && tr == pos) {
      t[v].first += to.first;
      t[v].second = (to.second * t[v].second) % mod;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        set(v * 2, tl, tm, pos, to);
      else
        set(v * 2 + 1, tm + 1, tr, pos, to);
      t[v].first = t[v * 2].first + t[v * 2 + 1].first;
      t[v].second = (t[v * 2].second * t[v * 2 + 1].second) % mod;
    }
  }
  std::pair<long long, long long> get(int v, int tl, int tr, int l, int r) {
    if (l > r) return make_pair(0, 1);
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    std::pair<long long, long long> t1 = get(v * 2, tl, tm, l, min(r, tm));
    std::pair<long long, long long> t2 =
        get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return make_pair(t1.first + t2.first, (t1.second * t2.second) % mod);
  }
};
int n;
std::vector<long long> x, xinv;
std::vector<int> c, ban, s;
vector<std::vector<std::pair<int, int>>> nb;
vector<std::vector<std::pair<int, int>>> ch;
int root;
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long invmod(long long a, long long modulo) {
  long long x, y;
  gcd(a, modulo, x, y);
  return (x % modulo + modulo) % modulo;
}
void dfs(int v, int p, int sz) {
  s[v] = 1;
  ch[v].clear();
  for (auto u : nb[v]) {
    if (ban[u.first] || u.first == p) continue;
    ch[v].push_back(u);
    dfs(u.first, v, sz);
    s[v] += s[u.first];
  }
  if (2 * s[v] >= sz && root == -1) root = v;
}
vector<vector<pair<std::pair<int, int>, long long>>> e;
int cnt[2];
long long cur;
void dfse(int v, vector<pair<std::pair<int, int>, long long>>& to) {
  to.push_back(make_pair(make_pair(cnt[0], cnt[1]), cur));
  for (auto u : ch[v]) {
    cur = (cur * x[u.second]) % mod;
    cnt[c[u.second]]++;
    dfse(u.first, to);
    cur = (cur * xinv[u.second]) % mod;
    cnt[c[u.second]]--;
  }
}
stree vu2, uv2;
long long powM(long long k, long long n, long long modulo) {
  if (n == 0) return 1;
  if (n == 1) return k;
  long long x = powM(k, n / 2, modulo);
  return (((x * x) % modulo) * powM(k, n % 2, modulo)) % modulo;
}
long long ans = 1;
void proc(int v) {
  dfs(v, -1, 0);
  root = -1;
  dfs(v, -1, s[v]);
  dfs(root, -1, 0);
  std::pair<long long, long long> total = make_pair(0, 1);
  for (auto u : ch[root]) {
    e[u.first].clear();
    cur = x[u.second];
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[c[u.second]]++;
    dfse(u.first, e[u.first]);
    for (auto ex : e[u.first]) {
      int p = ex.first.first;
      int q = ex.first.second;
      long long val = ex.second;
      std::pair<long long, long long> bad1 =
          uv2.get(1, 0, 3 * n, 2 * q - p + 1 + 2 * n, 3 * n);
      std::pair<long long, long long> bad2 =
          vu2.get(1, 0, 3 * n, 2 * p - q + 1 + 2 * n, 3 * n);
      ans = (ans * powM(val, total.first - bad1.first - bad2.first, mod)) % mod;
      ans = (ans * total.second) % mod;
      ans = (ans * invmod(bad1.second, mod)) % mod;
      ans = (ans * invmod(bad2.second, mod)) % mod;
    }
    for (auto ex : e[u.first]) {
      int p = ex.first.first;
      int q = ex.first.second;
      long long val = ex.second;
      total.first++;
      total.second = (total.second * val) % mod;
      uv2.set(1, 0, 3 * n, p - 2 * q + 2 * n, make_pair(1, val));
      vu2.set(1, 0, 3 * n, q - 2 * p + 2 * n, make_pair(1, val));
    }
  }
  std::pair<long long, long long> bad1 = uv2.get(1, 0, 3 * n, 1 + 2 * n, 3 * n);
  std::pair<long long, long long> bad2 = vu2.get(1, 0, 3 * n, 1 + 2 * n, 3 * n);
  ans = (ans * total.second) % mod;
  ans = (ans * invmod(bad1.second, mod)) % mod;
  ans = (ans * invmod(bad2.second, mod)) % mod;
  for (auto u : ch[root]) {
    for (auto ex : e[u.first]) {
      int p = ex.first.first;
      int q = ex.first.second;
      long long val = ex.second;
      long long ival = invmod(val, mod);
      uv2.set(1, 0, 3 * n, p - 2 * q + 2 * n, make_pair(-1, ival));
      vu2.set(1, 0, 3 * n, q - 2 * p + 2 * n, make_pair(-1, ival));
    }
  }
  ban[root] = 1;
  for (auto x : nb[v])
    if (!ban[x.first]) proc(x.first);
}
int main() {
  scanf("%d", &n);
  vu2.build(3 * n + 1, 1, 0, 3 * n);
  uv2.build(3 * n + 1, 1, 0, 3 * n);
  x.resize(n);
  c.resize(n);
  ban.resize(n);
  nb.resize(n);
  e.resize(n);
  s.resize(n);
  ch.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d %lld %d", &u, &v, &x[i], &c[i]);
    u--;
    v--;
    nb[v].push_back(make_pair(u, i));
    nb[u].push_back(make_pair(v, i));
  }
  for (auto u : x) xinv.push_back(invmod(u, mod));
  proc(0);
  cout << ans;
}
