#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e6 + 100;
const ll T = 4 * N;
ll tmax[T];
ll tadd[T];
ll ls(ll v) { return 2 * v + 1; }
ll rs(ll v) { return 2 * v + 2; }
void push(ll v) {
  tmax[ls(v)] += tadd[v];
  tmax[rs(v)] += tadd[v];
  tadd[ls(v)] += tadd[v];
  tadd[rs(v)] += tadd[v];
  tadd[v] = 0;
}
void upd(ll ql, ll qr, ll d, ll v = 0, ll vl = 0, ll vr = N) {
  if (ql <= vl && vr <= qr) {
    tmax[v] += d;
    tadd[v] += d;
    return;
  }
  if (qr <= vl || vr <= ql) {
    return;
  }
  ll vm = (vl + vr) / 2;
  push(v);
  upd(ql, qr, d, ls(v), vl, vm);
  upd(ql, qr, d, rs(v), vm, vr);
  tmax[v] = max(tmax[ls(v)], tmax[rs(v)]);
}
ll query(ll v = 0, ll vl = 0, ll vr = N) {
  if (tmax[v] <= 0) {
    return -1;
  }
  if (vr - vl == 1) {
    return vl;
  }
  ll vm = (vl + vr) / 2;
  push(v);
  if (tmax[rs(v)] > 0) {
    return query(rs(v), vm, vr);
  } else {
    return query(ls(v), vl, vm);
  }
}
ll inpos(ll pos, ll v = 0, ll vl = 0, ll vr = N) {
  if (vr - vl == 1) {
    return tmax[v];
  }
  ll vm = (vl + vr) / 2;
  push(v);
  if (pos < vm) {
    return inpos(pos, ls(v), vl, vm);
  } else {
    return inpos(pos, rs(v), vm, vr);
  }
}
void print() {
  for (ll i = 0; i < 10; ++i) {
    cout << inpos(i) << " ";
  }
  cout << endl;
}
void add(ll pos, ll val) {
  val *= -1;
  upd(0, pos + 1, val);
}
ll a[N];
ll b[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  ll m;
  cin >> n >> m;
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i];
    add(a[i], -1);
  }
  for (ll i = 1; i <= m; ++i) {
    cin >> b[i];
    add(b[i], +1);
  }
  ll q;
  cin >> q;
  while (q--) {
    ll t;
    ll i;
    ll first;
    cin >> t >> i >> first;
    if (t == 1) {
      add(a[i], +1);
      a[i] = first;
      add(a[i], -1);
    } else {
      add(b[i], -1);
      b[i] = first;
      add(b[i], +1);
    }
    cout << query(0, 0, N) << "\n";
  }
  return 0;
}
