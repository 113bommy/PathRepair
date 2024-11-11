#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct segtree {
  struct node {
    long long int min, max, sum;
  };
  vector<node> st;
  long long int ans = 0;
  int n;
  template <typename M>
  segtree(vector<M> &a) {
    n = (int)a.size();
    st.resize(4 * n);
  }
  void combine(node &a, node &b, node &c) {
    a.sum = b.sum + c.sum;
    a.min = min(b.min, c.min);
    a.max = max(b.max, c.max);
  }
  template <typename M>
  void build(int v, int l, int r, vector<M> &vec) {
    if (l == r) {
      st[v].max = vec[l];
      st[v].min = vec[l];
      st[v].sum = vec[l];
    } else {
      int m = (l + r) / 2;
      build(2 * v, l, m, vec);
      build(2 * v + 1, m + 1, r, vec);
      combine(st[v], st[2 * v], st[2 * v + 1]);
    }
  }
  node query(int v, int l, int r, int l_, int r_) {
    if (l == l_ && r == r_) {
      return st[v];
    }
    int m = (l + r) / 2;
    if (r_ <= m) {
      return query(2 * v, l, m, l_, r_);
    } else if (l_ > m) {
      return query(2 * v + 1, m + 1, r, l_, r_);
    } else {
      node a, b, c;
      b = query(2 * v, l, m, l_, m);
      c = query(2 * v + 1, m + 1, r, m + 1, r_);
      combine(a, b, c);
      return a;
    }
  }
  template <typename M>
  void update(int v, int l, int r, int id, M val) {
    if (l == r) {
      st[v].min += val;
      st[v].max += val;
      st[v].sum += val;
      return;
    }
    int m = (l + r) / 2;
    if (id <= m) {
      update(2 * v, l, m, id, val);
    } else {
      update(2 * v + 1, m + 1, r, id, val);
    }
    combine(st[v], st[2 * v], st[2 * v + 1]);
  }
  long long int query(int l, int r) { return query(1, 0, n - 1, l, r).sum; }
  template <typename M>
  void update(int id, M val) {
    update(1, 0, n - 1, id, val);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, m, k, q, a, b, c, d, x, y;
  cin >> n >> k >> a >> b >> q;
  x = a;
  y = b;
  vector<long long> ff(n + 2), rr(n + 2);
  for (int i = 1; i <= n; i++) {
    ff[i] = b;
    rr[i] = a;
  }
  segtree aa(ff);
  segtree bb(ff);
  for (int i = 0; i < q; i++) {
    cin >> a;
    if (a == 1) {
      cin >> a >> b;
      if (ff[a] >= b) {
        ff[a] -= b;
        aa.update((int)a, b);
      } else {
        aa.update((int)a, ff[a]);
        ff[a] = 0;
      }
      if (rr[a] >= b) {
        rr[a] -= b;
        bb.update((int)a, b);
      } else {
        bb.update((int)a, rr[a]);
        rr[a] = 0;
      }
    } else {
      cin >> a;
      cout << aa.query(0, (int)a - 1) + bb.query((int)a + (int)k, n + 1)
           << '\n';
    }
  }
  return 0;
}
