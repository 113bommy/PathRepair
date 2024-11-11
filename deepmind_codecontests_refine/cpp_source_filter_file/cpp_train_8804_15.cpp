#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct segment_tree {
  int n;
  vector<T> t, lazy, a;
  T neutral, lazy_neutral;
  function<T(const T &, const T &)> merge;
  function<T(const T &, const T &)> upd;
  bool range_modif = false;
  segment_tree(int _n, T _neutral, T _lazy_neutral,
               const function<T(const T &, const T &)> &_merge,
               const function<T(const T &, const T &)> &_upd,
               bool _range_modif) {
    range_modif = _range_modif;
    init(_n, _neutral, _lazy_neutral, _merge, _upd);
  }
  segment_tree(vector<T> _a, T _neutral, T _lazy_neutral,
               const function<T(const T &, const T &)> &_merge,
               const function<T(const T &, const T &)> &_upd,
               bool _range_modif) {
    range_modif = _range_modif;
    a = _a;
    int _n = (int)a.size();
    init(_n, _neutral, _lazy_neutral, _merge, _upd);
    build(1, 0, n - 1);
  }
  void init(int _n, T _neutral, T _lazy_neutral,
            const function<T(const T &, const T &)> &_merge,
            const function<T(const T &, const T &)> &_upd) {
    n = _n;
    neutral = _neutral;
    lazy_neutral = _lazy_neutral;
    merge = _merge;
    upd = _upd;
    t.assign(4 * n, neutral);
    lazy.assign(4 * n, lazy_neutral);
  }
  void build(int i, int l, int r) {
    if (l == r) {
      t[i] = a[l];
      return;
    }
    int mid = l + r >> 1;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i] = merge(t[2 * i], t[2 * i + 1]);
  }
  void push(int i, int l, int r) {
    if (lazy[i] == lazy_neutral) return;
    t[i] = upd(t[i], lazy[i] * (range_modif ? (r - l + 1) : 1));
    if (l != r) {
      lazy[2 * i] = upd(lazy[2 * i], lazy[i]);
      lazy[2 * i + 1] = upd(lazy[2 * i + 1], lazy[i]);
    }
    lazy[i] = lazy_neutral;
  }
  void modif(int i, int l, int r, int tl, int tr, T val) {
    push(i, l, r);
    if (l > tr || r < tl) return;
    if (l >= tl && r <= tr) {
      lazy[i] = upd(lazy[i], val);
      push(i, l, r);
      return;
    }
    int mid = l + r >> 1;
    modif(2 * i, l, mid, tl, tr, val);
    modif(2 * i + 1, mid + 1, r, tl, tr, val);
    t[i] = merge(t[2 * i], t[2 * i + 1]);
  }
  T query(int i, int l, int r, int tl, int tr) {
    push(i, l, r);
    if (l > tr || r < tl) return neutral;
    if (l >= tl && r <= tr) return t[i];
    int mid = l + r >> 1;
    T left = query(2 * i, l, mid, tl, tr);
    T right = query(2 * i + 1, mid + 1, r, tl, tr);
    return merge(left, right);
  }
  void modif(int l, int r, T val) { modif(1, 0, n - 1, l, r, val); }
  void modif(int poz, T val) { modif(1, 0, n - 1, poz, poz, val); }
  T query(int l, int r) { return query(1, 0, n - 1, l, r); }
  T query(int poz) { return query(1, 0, n - 1, poz, poz); }
};
const int N = 1e5 + 10;
long long MG(long long a, long long b) { return max(a, b); }
long long UPD(long long a, long long b) { return a = b; }
void solve() {
  int n;
  cin >> n;
  vector<array<int, 3>> a(n);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i][1] >> a[i][0] >> a[i][2];
    v.push_back(a[i][0]);
    v.push_back(a[i][1]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  sort(a.rbegin(), a.rend());
  segment_tree<long long> st(N, 0, 0, MG, UPD, 1);
  st.modif(lower_bound(v.begin(), v.end(), a[0][1]) - v.begin() + 1, N - 1,
           a[0][2]);
  vector<long long> dp(n, 0);
  dp[0] = a[0][2];
  for (int i = 1; i < n; i++) {
    long long A = lower_bound(v.begin(), v.end(), a[i][1]) - v.begin();
    long long B = lower_bound(v.begin(), v.end(), a[i][0]) - v.begin();
    long long H = a[i][2];
    long long c = st.query(B) + H;
    dp[i] = c;
    if (st.query(A + 1) < c) {
      st.modif(A + 1, N - 1, c);
    }
  }
  cout << *max_element(dp.begin(), dp.end());
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
}
