#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int oo = 1e9 + 7;
const int N = 2e5;
int a[N + 1], len[N + 1];
ll f[N + 1];
int n, q;
set<int> s;
struct fenwick_tree {
  ll bit[N + 1];
  void update(int i, ll x) {
    for (; i <= n; i += i & -i) bit[i] += x;
  }
  ll get(int i) {
    ll res = 0;
    for (; i; i -= i & -i) res += bit[i];
    return res;
  }
} bit;
ll query(int l, int r) {
  ll res = bit.get(r) - bit.get(l - 1);
  int l_1 = *(--s.lower_bound(l)) + 1, r_1 = *s.lower_bound(l);
  if (l_1 <= l && r_1 > r) {
    res += f[r - l + 1];
    return res;
  }
  if (l_1 <= r_1 && l_1 < l && r_1 <= r) {
    res -= f[len[r_1]];
    res += f[r_1 - l + 1];
  }
  int l_2 = *(--s.lower_bound(r)) + 1, r_2 = *s.lower_bound(r);
  ;
  if (l_1 == l_2 && r_1 == r_2) return res;
  if (l_2 <= r_2 && r_2 > r && l_2 >= l) {
    res += f[r - l_2 + 1];
  }
  return res;
}
void erase(int i) {
  auto u = s.lower_bound(i);
  int r = *u, l = *(--u) + 1;
  if (l == r) {
    bit.update(r, -f[len[r]]);
    len[r] = 0;
    s.erase(r);
  } else if (i == l) {
    bit.update(r, -f[len[r]] + f[len[r] - 1]);
    len[r] = len[r] - 1;
  } else if (i == r) {
    bit.update(r, -f[len[r]]);
    bit.update(r - 1, -f[len[r - 1]] + f[len[r] - 1]);
    len[r - 1] = len[r] - 1;
    len[r] = 0;
    s.erase(r);
    s.insert(r - 1);
  } else {
    bit.update(r, -f[len[r]] + f[len[r] - i + l - 1]);
    len[r] = len[r] - i + l - 1;
    bit.update(i - 1, -f[len[i - 1]] + f[i - l]);
    len[i - 1] = i - l;
    s.insert(i - 1);
  }
}
void insert(int i, int x) {
  a[i] = x;
  if (a[i - 1] <= a[i] && a[i] <= a[i + 1]) {
    int r = *s.upper_bound(i);
    bit.update(r, -f[len[r]] + f[len[r] + len[i - 1] + 1]);
    len[r] = len[r] + len[i - 1] + 1;
    bit.update(i - 1, -f[len[i - 1]]);
    len[i - 1] = 0;
    s.erase(i - 1);
  } else if (a[i - 1] <= a[i] && a[i] > a[i + 1]) {
    len[i] = len[i - 1] + 1;
    bit.update(i, f[len[i]]);
    s.insert(i);
    bit.update(i - 1, -f[len[i - 1]]);
    len[i - 1] = 0;
    s.erase(i - 1);
  } else if (a[i - 1] > a[i] && a[i] <= a[i + 1]) {
    int r = *s.upper_bound(i);
    bit.update(r, -f[len[r]] + f[len[r] + 1]);
    len[r] = len[r] + 1;
  } else {
    len[i] = 1;
    bit.update(i, f[len[i]]);
    s.insert(i);
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  int l, r, t, i, x;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i], f[i] = i * (i + 1) / 2;
  a[0] = oo;
  a[n + 1] = -oo;
  s.insert(0);
  for (int i = 2; i <= n + 1; ++i)
    if (a[i] < a[i - 1]) {
      l = *s.rbegin() + 1, r = i - 1;
      s.insert(r);
      len[r] = r - l + 1;
      bit.update(r, f[len[r]]);
    }
  for (auto &_ : s) {
    cerr << _ << ' ';
  }
  cerr << endl;
  ;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> i >> x;
      erase(i);
      insert(i, x);
    } else {
      cin >> l >> r;
      cout << query(l, r) << '\n';
    }
  }
  return 0;
}
