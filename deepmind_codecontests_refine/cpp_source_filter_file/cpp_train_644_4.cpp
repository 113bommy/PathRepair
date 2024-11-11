#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
using vi = vector<long long>;
using vvi = vector<vi>;
using P = pair<long long, long long>;
template <class T>
class BinaryIndexedTree {
 public:
  long long n;
  vector<T> bit;
  BinaryIndexedTree() : n(-1) {}
  BinaryIndexedTree(long long n_, T d) : n(n_), bit(n_ + 1, d) {}
  T sum(long long i) {
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void add(long long i, T x) {
    if (i == 0) return;
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
  }
  T sum0(long long i) { return sum(i + 1); }
  void add0(long long i, T x) { add(i + 1, x); }
  T query(long long l, long long r) { return sum(r - 1) - sum(l - 1); }
  T query0(long long l, long long r) { return sum(r) - sum(l); }
  long long lower_bound(long long w) {
    if (w <= 0) return 0;
    long long x = 0, r = 1;
    while (r < n) r <<= 1;
    for (long long k = r; k > 0; k >>= 1) {
      if (x + k <= n && bit[x + k] < w) {
        w -= bit[x + k];
        x += k;
      }
    }
    return x;
  }
};
signed main() {
  long long n, x;
  cin >> n >> x;
  vi y(n);
  for (long long i = (long long)(0); i < (long long)(n); i++) cin >> y[i];
  const long long MAX = 101010;
  BinaryIndexedTree<long long> bit(MAX, 0);
  for (long long i = (long long)(0); i < (long long)(MAX); i++) bit.add0(i, 1);
  vi cnt(x);
  for (long long i = (long long)(0); i < (long long)(n); i++) {
    long long r = y[i] % x;
    if (cnt[r] * x + r < MAX) {
      bit.add0(cnt[r] * x + r, -1);
    }
    cnt[r]++;
    long long ans = bit.lower_bound(1);
    cout << ans << endl;
  }
  return 0;
}
