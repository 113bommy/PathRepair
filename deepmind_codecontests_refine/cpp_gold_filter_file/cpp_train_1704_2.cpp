#include <bits/stdc++.h>
using namespace std;
const long long INF = 9223372036854775807;
const long long N = 600005;
const long long mod = 1e9 + 7;
const long long M = 30;
struct segment_tree {
  vector<long long> a;
  vector<long long> tree;
  vector<long long> lazy;
  void init(long long n) {
    a.resize(n, 0);
    tree.resize(4 * n + 1, 0);
    lazy.resize(4 * n + 1, 0);
  }
  void build_tree(long long s, long long e, long long index) {
    if (s == e) {
      tree[index] = a[s];
      return;
    }
    long long mid = (s + e) / 2;
    build_tree(s, mid, 2 * index);
    build_tree(mid + 1, e, 2 * index + 1);
    tree[index] = tree[index * 2] + tree[2 * index + 1];
  }
  long long query(long long s, long long e, long long qs, long long qe,
                  long long index) {
    if (lazy[index] != 0) {
      tree[index] = ((e - s + 1) * lazy[index]) - tree[index];
      if (s != e) {
        lazy[2 * index] ^= lazy[index];
        lazy[2 * index + 1] ^= lazy[index];
      }
      lazy[index] = 0;
    }
    if (s > qe || e < qs) return 0;
    if (s >= qs && e <= qe) {
      return tree[index];
    }
    long long mid = (s + e) / 2;
    long long l = query(s, mid, qs, qe, 2 * index);
    long long r = query(mid + 1, e, qs, qe, 2 * index + 1);
    return (l + r);
  }
  void update(long long s, long long e, long long l, long long r,
              long long increment, long long index) {
    if (lazy[index] != 0) {
      tree[index] = ((e - s + 1) * lazy[index]) - tree[index];
      if (s != e) {
        lazy[2 * index] ^= lazy[index];
        lazy[2 * index + 1] ^= lazy[index];
      }
      lazy[index] = 0;
    }
    if (s > r || e < l) return;
    if (s >= l && e <= r) {
      tree[index] = ((e - s + 1) * increment) - tree[index];
      if (s != e) {
        lazy[2 * index] ^= increment;
        lazy[2 * index + 1] ^= increment;
      }
      return;
    }
    long long mid = (s + e) / 2;
    update(s, mid, l, r, increment, 2 * index);
    update(mid + 1, e, l, r, increment, 2 * index + 1);
    tree[index] = tree[index * 2] + tree[2 * index + 1];
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  segment_tree s[21];
  long long n;
  cin >> n;
  for (long long i = 0; i <= 20; i++) s[i].init(n);
  long long arr[n + 3];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    for (long long j = 0; j <= 20; j++) {
      if (arr[i] & (1 << j))
        s[j].a[i] = 1;
      else
        s[j].a[i] = 0;
    }
  }
  for (long long i = 0; i <= 20; i++) s[i].build_tree(0, n - 1, 1);
  long long m;
  cin >> m;
  while (m--) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long l, r;
      cin >> l >> r;
      l--, r--;
      long long ans = 0;
      for (long long i = 0; i <= 20; i++) {
        ans += ((1 << i) * (s[i].query(0, n - 1, l, r, 1)));
      }
      cout << ans << "\n";
    } else {
      long long l, r, x;
      cin >> l >> r >> x;
      l--, r--;
      for (long long i = 0; i <= 20; i++) {
        if (x & (1 << i)) {
          s[i].update(0, n - 1, l, r, 1, 1);
        }
      }
    }
  }
}
