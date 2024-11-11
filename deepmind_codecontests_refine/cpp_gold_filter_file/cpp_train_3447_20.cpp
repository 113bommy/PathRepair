#include <bits/stdc++.h>
#pragma comment(linker, "/stack:500000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("arch=corei7-avx")
#pragma GCC optimize("-fno-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,tune=native")
#pragma GCC optimize("-ffast-math")
using namespace std;
const long long MAXN = 1e5 + 7, MAX_LOG = 20, inf = 1e9, mod = 1e9 + 7;
const long double eps = 1e-17;
long long n, m, p[MAXN], h[MAXN], tin[MAXN], tout[MAXN], timer = 0;
vector<long long> g[MAXN];
long long SP[MAX_LOG][MAXN], go[MAX_LOG][MAXN];
long long Log[MAXN];
pair<long long, long long> t[4 * MAXN];
pair<long long, long long> recalc(pair<long long, long long> a,
                                  pair<long long, long long> b) {
  pair<long long, long long> ans;
  if (tin[a.first] < tin[b.first])
    ans.first = a.first;
  else
    ans.first = b.first;
  if (tout[a.second] > tout[b.second])
    ans.second = a.second;
  else
    ans.second = b.second;
  return ans;
}
void ST_build(long long v, long long vl, long long vr) {
  if (vl == vr) {
    t[v] = {vl, vl};
    return;
  }
  long long m = (vl + vr) / 2;
  ST_build(v + v + 1, vl, m);
  ST_build(v + v + 2, m + 1, vr);
  t[v] = recalc(t[v + v + 1], t[v + v + 2]);
}
pair<long long, long long> get_mm(long long v, long long vl, long long vr,
                                  long long l, long long r) {
  if (vl >= l && vr <= r) return t[v];
  if (vl > r || vr < l) return {MAXN - 1, MAXN - 1};
  long long m = (vl + vr) / 2;
  return recalc(get_mm(v + v + 1, vl, m, l, r),
                get_mm(v + v + 2, m + 1, vr, l, r));
}
pair<long long, long long> get_min_max(long long l, long long r) {
  return get_mm(0, 0, n - 1, l, r);
}
void dfs(long long v = 0) {
  go[0][v] = p[v], tin[v] = timer++;
  for (long long i = 1; i < MAX_LOG; i++) go[i][v] = go[i - 1][go[i - 1][v]];
  for (long long to : g[v]) {
    h[to] = h[v] + 1;
    dfs(to);
  }
  tout[v] = timer++;
}
bool is_par(long long a, long long b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}
long long lca(long long a, long long b) {
  if (is_par(a, b)) return a;
  if (is_par(b, a)) return b;
  for (long long i = MAX_LOG - 1; i >= 0; i--)
    if (!is_par(go[i][a], b)) a = go[i][a];
  return p[a];
}
void SP_build() {
  for (long long i = 2; i < MAX_LOG; i++) Log[i] = 1 + Log[i / 2];
  for (long long i = 0; i < n; i++) SP[0][i] = i;
  for (long long k = 1; k < MAX_LOG; k++)
    for (long long i = 0; i + (1 << k) - 1 < n; i++)
      SP[k][i] = lca(SP[k - 1][i], SP[k - 1][i + (1 << k - 1)]);
}
long long get_lca(long long l, long long r) {
  long long k = 0;
  while ((1 << k + 1) < r - l + 1) k++;
  return lca(SP[k][l], SP[k][r - (1 << k) + 1]);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long q;
  cin >> n >> q;
  for (long long i = 1; i < n; i++) {
    cin >> p[i];
    g[--p[i]].push_back(i);
  }
  tin[MAXN - 1] = inf;
  tout[MAXN - 1] = -inf;
  dfs();
  SP_build();
  ST_build(0, 0, n - 1);
  while (q--) {
    long long l, r;
    cin >> l >> r;
    --l, --r;
    auto p = get_min_max(l, r);
    long long pos1 = p.first, pos2 = p.second, l1 = -1, l2 = -1;
    if (pos1 == l) l1 = get_lca(l + 1, r);
    if (pos1 == r) l1 = get_lca(l, r - 1);
    if (pos1 > l && pos1 < r)
      l1 = lca(get_lca(l, pos1 - 1), get_lca(pos1 + 1, r));
    if (pos2 == l) l2 = get_lca(l + 1, r);
    if (pos2 == r) l2 = get_lca(l, r - 1);
    if (pos2 > l && pos2 < r)
      l2 = lca(get_lca(l, pos2 - 1), get_lca(pos2 + 1, r));
    if (h[l1] > h[l2]) {
      cout << pos1 + 1 << " " << h[l1] << "\n";
    } else {
      cout << pos2 + 1 << " " << h[l2] << "\n";
    }
  }
  return 0;
}
