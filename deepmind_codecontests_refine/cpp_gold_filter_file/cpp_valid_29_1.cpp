#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 1e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int LOG = 18;
template <typename T>
void dout(const T& x) {
  cout << x << ' ';
}
template <typename T, typename... Ts>
void dout(const T& v, const Ts&... args) {
  dout(v);
  dout(args...);
}
template <typename... Ts>
void vout(const Ts&... args) {
  dout(args...);
  cout << "\n";
  exit(0);
}
struct seg_tree {
  seg_tree(int n) : t(n << 2){};
  void upd(int pos, int i, int l, int r) {
    if (l + 1 == r) {
      t[i] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    if (pos < mid)
      upd(pos, (i << 1) + 1, l, mid);
    else
      upd(pos, (i << 1) + 2, mid, r);
    t[i] = t[(i << 1) + 1] + t[(i << 1) + 2];
  }
  int get(int l, int r, int i, int cl, int cr) {
    if (l >= r) return 0;
    if (l == cl && r == cr) return t[i];
    int mid = (cl + cr) >> 1;
    return (get(l, min(mid, r), (i << 1) + 1, cl, mid) +
            get(max(l, mid), r, (i << 1) + 2, mid, cr));
  }
  void upd(int l, int r, ll val, int i, int cl, int cr) {
    if (l >= r) return;
    if (l == cl && r == cr) {
      t[i] += val;
      return;
    }
    int mid = (cl + cr) >> 1;
    upd(l, min(mid, r), val, (i << 1) + 1, cl, mid);
    upd(max(l, mid), r, val, (i << 1) + 2, mid, cr);
  }
  ll get(int pos, int i, int l, int r) {
    if (l + 1 == r) return t[i];
    int mid = (l + r) >> 1;
    return (t[i] + (pos < mid ? get(pos, (i << 1) + 1, l, mid)
                              : get(pos, (i << 1) + 2, mid, r)));
  }

 private:
  vector<ll> t;
};
int n;
vector<int> a;
void solve() {
  cin >> n;
  a.resize(n);
  for (int& v : a) cin >> v;
  ll pref_sum = 0;
  ll f = 0;
  ll s = 0;
  int m = *max_element(a.begin(), a.end());
  m++;
  seg_tree tr1(m);
  seg_tree tr2(m);
  int cnt = 0;
  for (int v : a) {
    pref_sum += v;
    f += pref_sum;
    cnt++;
    s += ll(v) * (cnt - 1);
    for (int i = 0, j = 0; i < m; i += v, j++) {
      f -= tr1.get(i, min(m, i + v), 0, 0, m) * ll(v) * j;
      tr2.upd(i, min(m, i + v), -j * ll(v), 0, 0, m);
    }
    s += tr2.get(v, 0, 0, m);
    tr1.upd(v, 0, 0, m);
    cout << f + s << ' ';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
