#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
template <class T>
struct RangeST {
  const int n, h;
  vector<T> V, D;
  vector<char> B;
  function<T(T, T)> op;
  function<T(T, T, int)> al;
  RangeST(
      const vector<T>& A, function<T(T, T)> op = plus<T>(),
      function<T(T, T, int)> al = [](T v, T d, int k) { return v + d * k; })
      : n(A.size()),
        h(32 - __builtin_clz(n)),
        V(n * 2),
        D(n),
        B(n),
        op(op),
        al(al) {
    copy(A.begin(), A.end(), V.begin() + n), build(0, n);
  }
  void calc(int p, int k) {
    T t = op(V[p << 1], V[p << 1 | 1]);
    V[p] = B[p] ? al(t, D[p], k) : t;
  }
  void apply(int p, T val, int k) {
    V[p] = al(V[p], val, k);
    if (p < n) D[p] = B[p] ? al(D[p], val, 1) : val, B[p] = true;
  }
  void build(int l, int r) {
    l += n, r += n - 1;
    for (int k = 2; l > 1; k <<= 1) {
      l >>= 1, r >>= 1;
      for (int i = r; i >= l; i--) calc(i, k);
    }
  }
  void push(int l, int r) {
    int s = h, k = 1 << (h - 1);
    for (l += n, r += n - 1; s > 0; --s, k >>= 1)
      for (int i = l >> s; i <= r >> s; i++)
        if (B[i])
          apply(i << 1, D[i], k), apply(i << 1 | 1, D[i], k), B[i] = false;
  }
  void modify(int l, int r, T val) {
    assert(l < r), push(l, l + 1), push(r - 1, r);
    int l0 = l, r0 = r, k = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
      if (l & 1) apply(l++, val, k);
      if (r & 1) apply(--r, val, k);
    }
    build(l0, l0 + 1), build(r0 - 1, r0);
  }
  T query(int l, int r) {
    assert(l < r), push(l, l + 1), push(r - 1, r);
    T left, right;
    bool b1 = false, b2 = false;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) left = b1 ? op(left, V[l++]) : V[l++], b1 = true;
      if (r & 1) right = b2 ? op(V[--r], right) : V[--r], b2 = true;
    }
    return !b1 ? right : !b2 ? left : op(left, right);
  }
};
const int N = 1e6 + 2;
int main() {
  vector<LL> a;
  for (int i = 0; i < N; i++) a.push_back(i);
  RangeST<LL> st1(
      a, [](LL x, LL y) { return max(x, y); },
      [](LL x, LL d, int k) { return x + d; });
  RangeST<LL> st2(
      vector<LL>(N), [](LL x, LL y) { return x + y; },
      [](LL x, LL d, int k) { return x + d * k; });
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  vector<pair<int, int>> queries(q + 1);
  for (int i = 1; i <= q; i++) {
    string s;
    cin >> s;
    switch (s[0]) {
      case '+': {
        int t, d;
        cin >> t >> d;
        st1.modify(0, t + 1, d);
        st2.modify(t, t + 1, d);
        queries[i] = {t, d};
      }; break;
      case '-': {
        int i, t, d;
        cin >> i;
        t = queries[i].first, d = queries[i].second;
        if (d == 0) break;
        queries[i] = {0, 0};
        st1.modify(0, t + 1, -d);
        st2.modify(t, t + 1, -d);
      }; break;
      case '?': {
        int t;
        cin >> t;
        LL x = st1.query(0, t + 1) - st2.query(t + 1, N);
        cout << x - t << endl;
      }
    }
  }
}
