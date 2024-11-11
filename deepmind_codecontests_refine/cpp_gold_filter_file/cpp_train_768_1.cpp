#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 100;
const int MAXL = 25;
const int INF = 2e17 + 14 + 92;
long long p[MAXN][MAXL], arcst[MAXN], st[MAXN], fn[MAXN], h[MAXN], hd[MAXN],
    T = 0;
vector<pair<long long, long long> > ver[MAXN];
void pre_dfs(long long v, long long par = 0) {
  p[v][0] = par;
  arcst[T] = v;
  st[v] = T++;
  for (long long i = 1; i < MAXL; i++) p[v][i] = p[p[v][i - 1]][i - 1];
  for (auto u : ver[v])
    if (u.first != par)
      h[u.first] = h[v] + 1, hd[u.first] = hd[v] + u.second,
      pre_dfs(u.first, v);
  fn[v] = T;
}
long long ipar(long long v, long long x) {
  for (long long i = 0; x > 0; i++) {
    if (x % 2) v = p[v][i];
    x /= 2;
  }
  return v;
}
long long lca(long long a, long long b) {
  if (h[a] > h[b]) swap(a, b);
  b = ipar(b, h[b] - h[a]);
  if (b == a) return a;
  for (long long i = MAXL - 1; i >= 0; i--)
    if (p[b][i] != p[a][i]) a = p[a][i], b = p[b][i];
  return p[a][0];
}
long long seg[MAXN * 4], lazy[4 * MAXN];
pair<long long, long long> temp[MAXN * 4];
inline void shift(long long id) {
  long long qv = lazy[id];
  lazy[id] = 0;
  seg[2 * id + 1] += qv;
  lazy[2 * id + 1] += qv;
  seg[2 * id + 2] += qv;
  lazy[2 * id + 2] += qv;
}
void upd(long long ql, long long qr, long long qv, long long xl = 0,
         long long xr = MAXN, long long id = 0) {
  if (ql == qr) return;
  if (xr - xl == 1) {
    temp[id].first = temp[id].second = xl;
  }
  if (ql <= xl && xr <= qr) {
    seg[id] += qv;
    lazy[id] += qv;
    return;
  }
  if (qr <= xl || xr <= ql) return;
  shift(id);
  long long mid = (xl + xr) / 2;
  upd(ql, qr, qv, xl, mid, 2 * id + 1);
  upd(ql, qr, qv, mid, xr, 2 * id + 2);
  if (seg[2 * id + 1] != seg[2 * id + 2]) {
    if (seg[2 * id + 1] > seg[2 * id + 2]) temp[id] = temp[2 * id + 1];
    if (seg[2 * id + 1] < seg[2 * id + 2]) temp[id] = temp[2 * id + 2];
  } else {
    temp[id].first = min(temp[2 * id + 1].first, temp[2 * id + 2].first);
    temp[id].second = max(temp[2 * id + 1].second, temp[2 * id + 2].second);
  }
  seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
}
long long get(long long ql, long long qr, long long xl = 0, long long xr = MAXN,
              long long id = 0) {
  if (ql <= xl && xr <= qr) return seg[id];
  if (qr <= xl || xr <= ql) return 0;
  shift(id);
  long long mid = (xl + xr) / 2;
  return max(get(ql, qr, xl, mid, 2 * id + 1),
             get(ql, qr, mid, xr, 2 * id + 2));
}
long long ps[MAXN];
void calc(long long a, long long b) {
  if (h[a] > h[b]) swap(a, b);
  ps[a]++, ps[b]++, ps[p[lca(a, b)][0]]--, ps[lca(a, b)]--;
}
bool piligrim[MAXN];
bool check(long long v, long long h) {
  long long u = ipar(v, h);
  if (get(st[u], fn[u]) == seg[0]) return false;
  return true;
}
long long n;
void dfs(long long v, long long par = 0, long long w = 0) {
  for (auto u : ver[v])
    if (u.first != par) {
      upd(st[u.first], fn[u.first], -u.second);
      upd(st[1], st[u.first], u.second);
      upd(fn[u.first], fn[1], u.second);
      dfs(u.first, v, u.second);
      upd(st[u.first], fn[u.first], u.second);
      upd(st[1], st[u.first], -u.second);
      upd(fn[u.first], fn[1], -u.second);
    }
  if (piligrim[v]) {
    long long d = seg[0];
    long long cut = lca(arcst[temp[0].first], arcst[temp[0].second]);
    if (st[cut] < st[v] && fn[v] <= fn[cut]) {
      if (get(st[v], fn[v]) != d) {
        long long l = 0, r = h[v] - h[cut];
        while (r - l > 1) {
          long long mid = (r + l) / 2;
          if (check(v, mid))
            l = mid;
          else
            r = mid;
        }
        calc(ipar(v, r), v);
      }
    } else
      calc(v, cut);
  }
}
long long mx = 0, num = 0;
void solve(long long v, long long par = 0) {
  for (auto u : ver[v])
    if (u.first != par) {
      solve(u.first, v);
      ps[v] += ps[u.first];
    }
  if (piligrim[v]) return;
  if (ps[v] > mx) mx = ps[v], num = 0;
  if (ps[v] == mx) num++;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    piligrim[x] = true;
  }
  for (long long i = 1; i < n; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    ver[x].push_back({y, z});
    ver[y].push_back({x, z});
  }
  pre_dfs(1);
  for (long long i = 0; i < n; i++) {
    if (piligrim[arcst[i]])
      upd(i, i + 1, hd[arcst[i]]);
    else
      upd(i, i + 1, -INF);
  }
  dfs(1);
  solve(1);
  cout << mx << ' ' << num;
}
