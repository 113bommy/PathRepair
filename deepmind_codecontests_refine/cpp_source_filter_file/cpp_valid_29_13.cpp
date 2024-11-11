#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
  if (x < y) x = y;
}
mt19937 rnd(time(0));
const int MAXN = 3e5 + 1337;
ll f[MAXN];
void upd(int i, ll x) {
  for (; i < MAXN; i |= (i + 1)) f[i] += x;
}
ll get(int r) {
  ll ans = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) ans += f[r];
  return ans;
}
ll get(int l, int r) { return get(r) - get(l - 1); }
int f2[MAXN];
void u2(int i, int x) {
  for (; i < MAXN; i |= (i + 1)) f2[i] += x;
}
int get2(int r) {
  int ans = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) ans += f2[r];
  return ans;
}
int get2(int l, int r) { return get2(r) - get2(l - 1); }
pair<ll, int> t[4 * MAXN];
pair<ll, int> add[4 * MAXN];
pair<int, int> operator+(pair<ll, int> a, pair<ll, int> b) {
  return {a.first + b.first, a.second + b.second};
}
void push(int v, int l, int r) {
  if (l != r - 1) {
    add[2 * v + 1] = add[2 * v + 1] + add[v],
                add[2 * v + 2] = add[2 * v + 2] + add[v];
  }
  t[v] = t[v] + make_pair(add[v].first * (r - l), add[v].second * (r - l));
  add[v] = {0, 0};
}
void upd(int v, int l, int r, int ql, int qr, pair<ll, int> x) {
  push(v, l, r);
  if (l >= qr || ql >= r) return;
  if (l >= ql && r <= qr) {
    add[v] = add[v] + x;
    push(v, l, r);
    return;
  }
  upd(2 * v + 1, l, (l + r) / 2, ql, qr, x);
  upd(2 * v + 2, (l + r) / 2, r, ql, qr, x);
  t[v] = t[2 * v + 1] + t[2 * v + 2];
}
pair<ll, int> get(int v, int l, int r, int ql, int qr) {
  push(v, l, r);
  if (l >= qr || ql >= r) return {0, 0};
  if (l >= ql && r <= qr) return t[v];
  auto g1 = get(2 * v + 1, l, (l + r) / 2, ql, qr);
  auto g2 = get(2 * v + 2, (l + r) / 2, r, ql, qr);
  return g1 + g2;
}
ll a[MAXN];
ll ans[MAXN];
ll sadd[MAXN];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.precision(20), cout.setf(ios::fixed);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    ll xx = get(a[i] - 1);
    sadd[i] += xx;
    upd(a[i], a[i]);
  }
  fill(f, f + MAXN, 0);
  for (int i = 0; i < n; ++i) {
    sadd[i] += (get(MAXN) - get(a[i])) * a[i];
    upd(a[i], 1);
  }
  fill(f, f + MAXN, 0);
  for (int i = 0; i < n; ++i) {
    ll sm = 0;
    for (int cnt = 1;; ++cnt) {
      int r = (cnt + 1) * a[i] - 1;
      if (r >= MAXN) r = MAXN - 1;
      ll gg = get(cnt * a[i], r);
      ll cunt = get2(cnt * a[i], r);
      sm += gg - cunt * cnt * a[i];
      if (r == MAXN - 1) break;
    }
    sadd[i] += sm;
    upd(a[i], a[i]);
    u2(a[i], 1);
  }
  for (int i = 0; i < n; ++i) {
    auto now = get(0, 0, MAXN, a[i], a[i] + 1);
    sadd[i] += a[i] * now.second + now.first;
    for (int cnt = 1;; ++cnt) {
      int r = cnt * a[i] + a[i];
      if (r > MAXN) r = MAXN;
      upd(0, 0, MAXN, cnt * a[i], r, make_pair(-cnt * a[i], 1));
      if (r == MAXN) break;
    }
  }
  ll go = 0;
  for (int i = 0; i < n; ++i) {
    go += sadd[i];
    ans[i] = go;
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}
