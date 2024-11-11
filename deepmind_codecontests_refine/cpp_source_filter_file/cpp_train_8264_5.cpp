#include <bits/stdc++.h>
#pragma GCC optimize "03"
using namespace std;
const long long int inf = 1e15;
const long long int MOD = 1e9 + 7;
const long long int N = 2e5 + 5;
struct SegTree {
  struct data {
    long long int val;
    data() : val(0){};
    template <typename T>
    void apply(T v) {
      val = v;
    }
  };
  long long int N;
  vector<data> st;
  SegTree() {}
  SegTree(long long int _N) : N(_N) { st.resize(4 * N + 5); }
  inline void merge(data &cur, const data &l, const data &r,
                    long long int flag) {
    if (flag == 1)
      cur.val = l.val | r.val;
    else
      cur.val = l.val ^ r.val;
  }
  template <typename T>
  long long int build(long long int node, long long int l, long long int r,
                      vector<T> &v) {
    if (l == r) {
      if (l < (long long int)v.size())
        st[node].apply(v[l]);
      else
        st[node].apply(0);
      return 1;
    }
    long long int mid = (l + r) / 2;
    long long int f = build(node * 2, l, mid, v);
    build(node * 2 + 1, mid + 1, r, v);
    merge(st[node], st[node * 2], st[node * 2 + 1], f);
    return !f;
  }
  long long int pupdate(long long int node, long long int l, long long int r,
                        long long int pos, long long int val) {
    if (l == r) {
      st[node].val = val;
      return 1;
    }
    long long int mid = (l + r) / 2;
    long long int f;
    if (pos <= mid)
      f = pupdate(node * 2, l, mid, pos, val);
    else
      f = pupdate(node * 2 + 1, mid + 1, r, pos, val);
    merge(st[node], st[node * 2], st[node * 2 + 1], f);
    return !f;
  }
  template <typename T>
  void build(vector<T> &v) {
    build(1, 1, N, v);
  }
  void update(long long int pos, long long int val) {
    pupdate(1, 1, N, pos, val);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int n, q;
  cin >> n >> q;
  vector<long long int> v((1 << n) + 1);
  for (long long int i = 1; i <= (1 << n); i++) {
    cin >> v[i];
  }
  SegTree st(140005);
  st.build(v);
  ;
  while (q--) {
    long long int a, b;
    cin >> a >> b;
    st.update(a, b);
    cout << st.st[1].val << '\n';
  }
  return 0;
}
