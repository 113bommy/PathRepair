#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct line {
  long long k, b;
};
bool cmp(line a, line b) { return a.k < b.k; }
struct node {
  node *l, *r;
  line a;
  node(line nw) {
    a = nw;
    l = r = nullptr;
  }
  node(node *a, node *b) { l = a, r = b; }
};
const long long N = 1 << 20;
const long long inf = 1e9;
long long f(line a, long long x) { return (long long)a.k * x + a.b; }
long long get(node *v, long long pos, long long tl = -(1 << 17),
              long long tr = (1 << 17)) {
  if (!v) return inf;
  if (tl == tr) return f(v->a, pos);
  long long tm = (tl + tr) / 2;
  ll val = f(v->a, pos);
  if (pos <= tm)
    return min(get(v->l, pos, tl, tm), val);
  else
    return min(get(v->r, pos, tm + 1, tr), val);
}
node *add(node *v, line a, long long tl = -(1 << 17),
          long long tr = (1 << 17)) {
  if (!v) {
    v = new node(a);
    return v;
  }
  long long tm = (tl + tr) / 2;
  bool lef = f(a, tl) < f(v->a, tl);
  bool mid = f(a, tm) < f(v->a, tm);
  if (mid) swap(v->a, a);
  if (tl == tr) return v;
  if (mid != lef)
    v->l = add(v->l, a, tl, tm);
  else
    v->r = add(v->r, a, tm + 1, tr);
  return v;
}
vector<line> lol[N];
long long sz[N];
node *vert[N];
long long merge(long long a, long long b) {
  if (sz[a] > sz[b]) swap(a, b);
  sz[b] += sz[a];
  for (auto ii : lol[a]) {
    lol[b].push_back(ii);
    vert[b] = add(vert[b], ii);
  }
  return b;
}
long long a[N], b[N];
vector<long long> g[N];
long long dp[N];
long long dfs(long long v, long long p = -1) {
  long long cur = v;
  for (long long i = 0; i < g[v].size(); ++i) {
    long long to = g[v][i];
    if (to == p) continue;
    cur = merge(dfs(to, v), cur);
  }
  if (g[v].size() == 1 && p != -1)
    dp[v] = 0;
  else
    dp[v] = get(vert[cur], a[v]);
  vert[cur] = add(vert[cur], {b[v], dp[v]});
  lol[cur].push_back({b[v], dp[v]});
  sz[cur]++;
  return cur;
}
signed main() {
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n; ++i) cin >> b[i];
  for (long long i = 0; i < n; ++i) vert[i] = nullptr;
  for (long long i = 1; i < n; ++i) {
    long long v, u;
    cin >> v >> u;
    --v, --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(0);
  for (long long i = 0; i < n; ++i) cout << dp[i] << ' ';
  return 0;
}
