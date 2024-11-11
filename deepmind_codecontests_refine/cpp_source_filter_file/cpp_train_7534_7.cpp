#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const int LIM = 1e5 + 5, MOD = 1e9 + 7;
int t, n, m, k, x, y;
struct segtree {
  vector<int> lazy, lazytm;
  int N;
  void clear(int n) {
    N = n;
    lazy.assign(4 * N, MOD);
    lazytm.assign(4 * N, -1);
  }
  void push(int v) {
    int lf = v << 1, rt = lf ^ 1;
    if (lazytm[v] > lazytm[lf]) {
      lazytm[lf] = lazytm[v];
      lazy[lf] = lazy[v];
    }
    if (lazytm[v] > lazytm[rt]) {
      lazytm[rt] = lazytm[v];
      lazy[rt] = lazy[v];
    }
  }
  void update(int v, int tl, int tr, int l, int r, int val, int tm) {
    if (l > r) return;
    if (l == tl && tr == r) {
      lazy[v] = val;
      lazytm[v] = tm;
    } else {
      push(v);
      int tm = (tl + tr) >> 1, lf = v << 1, rt = lf ^ 1;
      ;
      update(lf, tl, tm, l, min(r, tm), val, tm);
      update(rt, tm + 1, tr, max(l, tm + 1), r, val, tm);
    }
  }
  int query(int v, int tl, int tr, int pos) {
    if (tl == tr) return lazy[v];
    push(v);
    int tm = (tl + tr) >> 1, lf = v << 1, rt = lf ^ 1;
    if (pos > tm)
      return query(rt, tm + 1, tr, pos);
    else
      return query(lf, tl, tm, pos);
  }
  int q(int l) { return query(1, 0, N - 1, l); }
  int u(int l, int r, int val, int tm) { update(1, 0, N - 1, l, r, val, tm); }
} st;
int a[LIM], b[LIM];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  st.clear(n + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < m; i++) {
    cin >> t >> x;
    if (t & 1) {
      cin >> y >> k;
      st.u(y, y + k - 1, x - y, i);
    } else {
      int in = st.q(x);
      if (in < 3e5) {
        cout << a[x - 1 + in] << "\n";
      } else
        cout << b[x - 1] << "\n";
    }
  }
  return 0;
}
