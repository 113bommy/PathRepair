#include <bits/stdc++.h>
using namespace std;
template <class T, int SZ>
struct segtree {
  T identity = 1e9;
  T comb(T l, T r) { return min(l, r); }
  void updLeaf(T& l, T val) { l = val; }
  T tree[2 * SZ + 1];
  segtree() {
    for (int i = 0; i < 2 * SZ + 1; i++) tree[i] = identity;
  }
  void upd(int pos, T val) {
    pos += SZ + 1;
    updLeaf(tree[pos], val);
    for (pos >>= 1; pos >= 1; pos >>= 1) {
      tree[pos] = comb(tree[2 * pos], tree[2 * pos + 1]);
    }
  }
  T query(int l, int r) {
    l += SZ + 1;
    r += SZ + 1;
    T res = identity;
    while (l <= r) {
      if (l & 1) res = comb(res, tree[l++]);
      if (!(r & 1)) res = comb(res, tree[r--]);
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
};
const int N = 200000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  vector<pair<long long, long long> > ratio(n, make_pair(1e9, 1)), range(n);
  for (int i = 0; i < n; i++) {
    long long x = i + 1;
    range[i] = make_pair(max(2LL, (l + x - 1)) / x, min(m, r / x));
  }
  vector<vector<long long> > div(N + 1);
  vector<int> index(N + 1, 1);
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      div[j].push_back(i);
    }
  }
  segtree<long long, N + 1> tree;
  for (int i = 2; i <= N; i++) tree.upd(i, div[i][1]);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      pair<long long, long long> ran = range[j - 1];
      if (ran.first <= ran.second) {
        long long y = tree.query(ran.first, ran.second);
        if (y * ratio[j - 1].second < ratio[j - 1].first * i) {
          ratio[j - 1] = make_pair(y, i);
        }
      }
    }
    for (int j = i + 1; j <= N; j += i + 1) {
      if (j == i + 1)
        tree.upd(j, 1e9);
      else
        tree.upd(j, div[j][++index[j]]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (ratio[i].first < 1e9) {
      long long a = ratio[i].first;
      long long b = ratio[i].second;
      long long y1 = (range[i].second / a) * a;
      long long y2 = y1 / a * b;
      long long x2 = (i + 1) * a / b;
      if (x2 <= n)
        cout << i + 1 << " " << y1 << " " << x2 << " " << y2 << endl;
      else
        cout << -1 << endl;
    } else
      cout << -1 << endl;
  }
}
