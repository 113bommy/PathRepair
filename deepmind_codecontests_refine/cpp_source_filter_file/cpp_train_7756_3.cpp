#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100;
const long long M = 20;
const long long SQ = 320;
const long long INF = 1e16;
const long long MOD = 1e9 + 7;
int q;
long long a[N];
vector<int> v[N];
pair<long long, long long> qu[N];
int id[N];
int cnt, st[N], ft[N];
int d[N];
long long f[N];
int par[N];
void dfs(int x, int p) {
  par[x] = p;
  st[x] = cnt++;
  for (int i = 0; i < v[x].size(); i++) dfs(v[x][i], x);
  ft[x] = cnt;
}
pair<long long, long long> seg[4 * N];
long long lazy[4 * N];
pair<long long, long long> merge(pair<long long, long long> a,
                                 pair<long long, long long> b) {
  return make_pair((a.first + b.first) % MOD, (a.second + b.second) % MOD);
}
void upd(int v, long long val) {
  seg[v].first = (seg[v].first * val) % MOD;
  seg[v].second = (seg[v].second * val) % MOD;
  lazy[v] = (lazy[v] * val) % MOD;
}
void shift(int v) {
  upd(2 * v, lazy[v]);
  upd(2 * v + 1, lazy[v]);
  lazy[v] = 1;
}
void Set(int v, int l, int r, int x, pair<long long, long long> val) {
  if (x < l || x >= r) return;
  if (r - l < 2) {
    seg[v] = val;
    return;
  }
  shift(v);
  int mid = (l + r) / 2;
  Set(2 * v, l, mid, x, val);
  Set(2 * v + 1, mid, r, x, val);
  seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}
void mul(int v, int l, int r, int s, int e, long long val) {
  if (e <= l || s >= r) return;
  if (s <= l && e >= r) {
    upd(v, val);
    return;
  }
  shift(v);
  int mid = (l + r) / 2;
  mul(2 * v, l, mid, s, e, val);
  mul(2 * v + 1, mid, r, s, e, val);
  seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}
pair<long long, long long> sum(int v, int l, int r, int s, int e) {
  if (e <= l || s >= r) return make_pair(0, 0);
  if (s <= l && e >= r) return seg[v];
  shift(v);
  int mid = (l + r) / 2;
  return merge(sum(2 * v, l, mid, s, e), sum(2 * v + 1, mid, r, s, e));
}
long long POW(long long a, long long b) {
  if (b == 1) return a;
  long long ans = POW(a, b / 2);
  ans = ans * ans % MOD;
  if (b % 2)
    return ans * a % MOD;
  else
    return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a[0] >> q;
  int n = 1;
  for (int i = 0; i < q; i++) {
    cin >> qu[i].first >> qu[i].second;
    qu[i].second--;
    if (qu[i].first == 1) {
      int x;
      cin >> x;
      v[qu[i].second].push_back(n);
      id[i] = n;
      a[n++] = x;
    }
  }
  dfs(0, -1);
  fill(lazy, lazy + 4 * n, 1);
  Set(1, 0, n, 0, make_pair(1, 1 * a[0]));
  for (int i = 0; i < q; i++) {
    int u = qu[i].second;
    if (qu[i].first == 1) {
      mul(1, 0, n, st[u], ft[u], POW(d[u] + 1, MOD - 2));
      d[u]++;
      mul(1, 0, n, st[u], ft[u], d[u] + 1);
      long long t = sum(1, 0, n, st[u], st[u] + 1).first;
      Set(1, 0, n, st[id[i]], make_pair(t, t * a[id[i]]));
    } else {
      long long ans = sum(1, 0, n, st[u], ft[u]).second;
      long long h =
          (u == 0 ? 1 : sum(1, 0, n, st[par[u]], st[par[u]] + 1).first);
      ans = ans * POW(h, MOD - 2) % MOD;
      cout << ans << '\n';
    }
  }
  return 0;
}
