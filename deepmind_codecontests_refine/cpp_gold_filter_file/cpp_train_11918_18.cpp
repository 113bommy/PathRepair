#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long long MOD = 1e+9 + 7;
const long long INF = LLONG_MAX;
const int INFi = INT_MAX;
const long long N = 3e+5 + 8;
vector<long long> adj[N];
long long vis[N];
long long dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};
long long test_cases = 1;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
;
long long n, m, h[N], d[N], p[N], first[N], g[N], a, b;
struct nd {
  long long first, second, id;
};
pair<nd, nd> seg[4 * N + 8];
long long left(long long nd) { return nd << 1; }
long long right(long long nd) { return (nd << 1) + 1; }
nd merge(nd a, nd b) {
  nd p;
  if (a.first >= b.first) {
    p.first = a.first;
    p.id = a.id;
    p.second = max({a.second, b.first, b.second});
  } else {
    p.first = b.first;
    p.id = b.id;
    p.second = max({b.second, a.first, a.second});
  }
  return p;
}
pair<nd, nd> combine(pair<nd, nd> a, pair<nd, nd> b) {
  pair<nd, nd> p;
  p.first = merge(a.first, b.first);
  p.second = merge(a.second, b.second);
  return p;
}
void build(long long node, long long st, long long en) {
  if (st == en) {
    seg[node] = {{first[st], -INF, st}, {g[st], -INF, st}};
    return;
  }
  long long mid = (st + en) / 2;
  build(left(node), st, mid);
  build(right(node), mid + 1, en);
  seg[node] = combine(seg[left(node)], seg[right(node)]);
}
pair<nd, nd> query(long long node, long long st, long long en, long long l,
                   long long r) {
  if (l <= st && en <= r) return seg[node];
  if (st > r || en < l) return {{-INF, -INF, -1}, {-INF, -INF, -1}};
  long long mid = (st + en) / 2;
  pair<nd, nd> lq = query(left(node), st, mid, l, r);
  pair<nd, nd> rq = query(right(node), mid + 1, en, l, r);
  return combine(lq, rq);
}
void MAIN(long long tc) {
  cin >> n >> m;
  for (long long i = (1); i <= n; i++) cin >> d[i], d[n + i] = d[i];
  for (long long i = (1); i <= n; i++) cin >> h[i], h[n + i] = h[i];
  for (long long i = (1); i <= 2 * n; i++) p[i] = p[i - 1] + d[i];
  for (long long i = (1); i <= 2 * n; i++) first[i] = 2 * h[i] + p[i - 1];
  for (long long i = (1); i <= 2 * n; i++) g[i] = 2 * h[i] - p[i - 1];
  build(1, 1, 2 * n);
  for (long long i = (1); i <= m; i++) {
    pair<nd, nd> p;
    long long best = -INF;
    cin >> a >> b;
    if (a <= b)
      p = query(1, 1, 2 * n, b + 1, n + a - 1);
    else
      p = query(1, 1, 2 * n, b + 1, a - 1);
    if (p.first.id == p.second.id)
      best =
          max(p.first.first + p.second.second, p.first.second + p.second.first);
    else
      best = p.first.first + p.second.first;
    cout << best;
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  for (long long i = (1); i <= test_cases; i++) {
    MAIN(i);
  }
}
