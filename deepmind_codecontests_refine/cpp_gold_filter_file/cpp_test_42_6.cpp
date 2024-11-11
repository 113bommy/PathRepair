#include <bits/stdc++.h>
using namespace std;
istream& operator>>(istream& in, pair<long long, long long>& b) {
  in >> b.first >> b.second;
  return in;
}
ostream& operator<<(ostream& out, const pair<long long, long long>& b) {
  out << "{" << b.first << ", " << b.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& a) {
  for (auto k : a) out << k << " ";
  return out;
}
template <typename T1, typename T2>
inline bool chkmin(T1& x, const T2& y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool chkmax(T1& x, const T2& y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
const long long INF = 1e18;
const long double PI = 4 * atan(1);
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
const long long N = 2e5 + 10;
const long long mod = 1e9 + 7;
long long add(long long a, long long b) {
  long long res = a + b;
  if (res >= mod) res -= mod;
  return res;
}
long long sub(long long a, long long b) {
  long long res = a - b;
  if (res < 0) res += mod;
  return res;
}
struct SegTree {
  vector<long long> t;
  SegTree(long long n) { t.assign(4 * n, 0); }
  void update(long long v, long long l, long long r, long long pos,
              long long val) {
    if (l + 1 == r) {
      t[v] = val;
      if (t[v] < 0) t[v] += mod;
      return;
    }
    long long m = (l + r) / 2;
    if (pos < m)
      update(2 * v + 1, l, m, pos, val);
    else
      update(2 * v + 2, m, r, pos, val);
    t[v] = add(t[2 * v + 1], t[2 * v + 2]);
  }
  long long ask(long long v, long long l, long long r, long long askl,
                long long askr) {
    if (l >= askr || r <= askl) return 0;
    if (askl <= l && r <= askr) return t[v];
    long long m = (l + r) / 2;
    return add(ask(2 * v + 1, l, m, askl, askr),
               ask(2 * v + 2, m, r, askl, askr));
  }
};
long long n, m;
long long a[N], b[N], s[N];
long long order[N];
long long ans[N], take[N];
bool comp(long long lhs, long long rhs) {
  return b[lhs] - a[lhs] < b[rhs] - a[rhs];
}
bool comp1(long long lhs, long long rhs) { return a[lhs] > a[rhs]; }
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  cin >> m;
  for (long long i = 0; i < m; i++) {
    cin >> s[i];
    s[i]--;
  }
  iota(order, order + n, 0);
  sort(order, order + n, comp);
  sort(s, s + m, comp);
  SegTree tree(n + n), L(n + n), R(n + n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    ans[order[i]] = sum;
    ans[order[i]] = sub(ans[order[i]], tree.ask(0, 0, n + n, 0, a[order[i]]));
    ans[order[i]] =
        add(ans[order[i]], tree.ask(0, 0, n + n, b[order[i]] + 1, n + n));
    ans[order[i]] = sub(ans[order[i]], L.ask(0, 0, n + n, 0, a[order[i]]));
    ans[order[i]] =
        sub(ans[order[i]], R.ask(0, 0, n + n, b[order[i]] + 1, n + n));
    ans[order[i]] = add(ans[order[i]], 1);
    sum = add(sum, ans[order[i]]);
    tree.update(0, 0, n + n, a[order[i]], ans[order[i]]);
    tree.update(0, 0, n + n, b[order[i]], -ans[order[i]]);
    L.update(0, 0, n + n, b[order[i]], ans[order[i]]);
    R.update(0, 0, n + n, a[order[i]], ans[order[i]]);
  }
  long long mxa = 0, mxb = 0;
  for (long long i = 0; i < m; i++) {
    chkmax(mxa, a[s[i]]);
    chkmax(mxb, b[s[i]]);
  }
  SegTree have(n + n);
  for (long long i = 0; i < m; i++) {
    take[s[i]] = 1;
  }
  sort(order, order + n, comp1);
  for (long long i = 0; i < n; i++) {
    if (take[order[i]]) {
      have.update(0, 0, n + n, a[order[i]], 1);
      have.update(0, 0, n + n, b[order[i]], -1);
    } else {
      if (have.ask(0, 0, n + n, a[order[i]] + 1, b[order[i]]) > 0) {
        take[order[i]] = 1;
      }
    }
  }
  long long valans = 0;
  for (long long i = 0; i < n; i++) {
    take[i] |= (b[i] <= mxa);
    valans = add(valans, take[i] * ans[i] % mod);
  }
  cout << valans << "\n";
}
