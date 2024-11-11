#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
class segtree {
  using Binop = function<T(T, T)>;

 public:
  segtree(int n, Binop op, T id) : f(op), id(id) {
    N = 1 << (int)ceil(log2(n));
    A.resize(2 * N, id);
  }
  T query(int i, int j) { return query(1, 0, N - 1, max(i, 0), min(j, N - 1)); }
  void update(int i, T x) {
    for (A[i += N] = x, i = parent(i); i > 0; i = parent(i))
      A[i] = f(A[lc(i)], A[rc(i)]);
  }

 private:
  int N;
  vector<T> A;
  Binop f;
  T id;
  static inline int lc(int i) { return 2 * i; }
  static inline int rc(int i) { return 2 * i + 1; }
  static inline int parent(int i) { return i / 2; }
  T query(int v, int i, int j, int ql, int qr) {
    if (ql > qr) return id;
    if (ql == i && qr == j) return A[v];
    int m = i + (j - i) / 2;
    return f(query(lc(v), i, m, ql, min(m, qr)),
             query(rc(v), m + 1, j, max(m + 1, ql), qr));
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> A(n);
  set<ll> S;
  for (int i = 0; i < n; ++i) {
    int a_i;
    scanf("%d", &a_i);
    A[i] = a_i;
    S.insert(a_i);
  }
  vector<ll> B;
  for (ll x : S) {
    B.push_back(x);
  }
  segtree<int> T(
      n, [](int x, int y) { return max(x, y); }, 0);
  auto x = A.begin();
  auto y = A.begin();
  int ans = 0;
  while (1) {
    if (T.query(0, n - 1) >= k) {
      ans += A.end() - y + 1;
      int i = lower_bound(B.begin(), B.end(), *x) - B.begin();
      T.update(i, T.query(i, i) - 1);
      ++x;
    } else {
      if (y == A.end()) break;
      int i = lower_bound(B.begin(), B.end(), *y) - B.begin();
      T.update(i, T.query(i, i) + 1);
      ++y;
    }
  }
  cout << ans;
  return 0;
}
