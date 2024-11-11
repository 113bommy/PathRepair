#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ull = unsigned long long;
template <class T>
inline T gcd(T a, T b) {
  return !a ? b : gcd(b % a, a);
}
template <class T>
inline T lcm(T a, T b) {
  return (a * b) / gcd(a, b);
}
mt19937 rnd(time(0));
const int N = 1e5 + 2;
int n, m, X, a[N];
struct node {
  long long ans;
  vector<pair<int, int>> pref, suf;
  node(int u) {
    pref.push_back({u, 1});
    suf.push_back({u, 1});
    ans = (u >= X);
  }
  node() { ans = 0; }
} T[4 * N];
node unite(const node &a, const node &b) {
  if (a.pref.empty()) {
    return b;
  }
  if (b.pref.empty()) {
    return a;
  }
  node res;
  res.pref = a.pref;
  int cntLast = res.pref.back().first;
  for (auto s : b.suf) {
    int val = (cntLast | s.first);
    if (res.pref.back().first != val) {
      res.pref.push_back({val, s.second});
    } else {
      res.pref.back().second += s.second;
    }
  }
  res.suf = b.suf;
  cntLast = res.suf.back().first;
  for (auto s : a.suf) {
    int val = (cntLast | s.first);
    if (val != res.suf.back().first) {
      res.suf.push_back({val, s.second});
    } else {
      res.suf.back().second += s.second;
    }
  }
  res.ans = a.ans + b.ans;
  int R = (int)b.pref.size() - 1, TOT = 0;
  for (auto s : a.suf) {
    while (R >= 0 && ((s.first | b.pref[R].first) >= X)) {
      TOT += b.pref[R].second;
      R -= 1;
    }
    res.ans += s.second * 1ll * TOT;
  }
  return res;
}
void build(int v, int vl, int vr) {
  if (vl == vr) {
    T[v] = node(a[vl]);
    return;
  }
  int vm = vl + (vr - vl) / 2;
  build(2 * v + 1, vl, vm);
  build(2 * v + 2, vm + 1, vr);
  T[v] = unite(T[2 * v + 1], T[2 * v + 2]);
}
void upd(int v, int vl, int vr, int pos, int val) {
  if (vl == vr) {
    T[v] = node(val);
    return;
  }
  int vm = vl + (vr - vl) / 2;
  if (pos <= vm) {
    upd(2 * v + 1, vl, vm, pos, val);
  } else {
    upd(2 * v + 2, vm + 1, vr, pos, val);
  }
  T[v] = unite(T[2 * v + 1], T[2 * v + 2]);
}
node query(int v, int vl, int vr, int L, int R) {
  if (R < vl || vr < L) {
    return node();
  }
  if (L <= vl && vr <= R) {
    return T[v];
  }
  int vm = vl + (vr - vl) / 2;
  node ql = query(2 * v + 1, vl, vm, L, R);
  node qr = query(2 * v + 2, vm + 1, vr, L, R);
  return unite(ql, qr);
}
void solve() {
  cin >> n >> m >> X;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, 0, n - 1);
  for (int i = 0; i < m; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos, val;
      cin >> pos >> val;
      pos--;
      upd(0, 0, n - 1, pos, val);
    }
    if (type == 2) {
      int L, R;
      cin >> L >> R;
      L--, R--;
      cout << query(0, 0, n - 1, L, R).ans << '\n';
    }
  }
  return;
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t = 1;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
