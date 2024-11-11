#include <bits/stdc++.h>
using namespace std;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
const long double PI = 3.141592653589793;
const long long INF = 9223372036854775807ll;
const long long mod = 1e9 + 7;
const int N = 1e5 + 5;
long long tree[4 * N];
long long lazy[4 * N];
long long b[N];
void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = b[start];
    return;
  }
  int mid = (start + end) / 2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long query(int node, int start, int end, int l, int r) {
  if (lazy[node] != -INF / 2) {
    tree[node] = lazy[node] * (end - start + 1);
    if (start != end) {
      lazy[2 * node] = lazy[node];
      lazy[2 * node + 1] = lazy[node];
    }
    lazy[node] = -INF / 2;
  }
  if (l > end || r < start) return 0;
  if (l <= start && r >= end) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  return query(2 * node, start, mid, l, r) +
         query(2 * node + 1, mid + 1, end, l, r);
}
void update(int node, int start, int end, int l, int r, long long val) {
  if (lazy[node] != (-INF / 2)) {
    tree[node] = lazy[node] * (end - start + 1ll);
    if (start != end) {
      lazy[2 * node] = lazy[node];
      lazy[2 * node + 1] = lazy[node];
    }
    lazy[node] = (-INF / 2);
  }
  if (l > end || r < start) return;
  if (l <= start && r >= end) {
    tree[node] = (end - start + 1) * val;
    if (start != end) {
      lazy[2 * node] = val;
      lazy[2 * node + 1] = val;
    }
    return;
  }
  int mid = (start + end) / 2;
  update(2 * node, start, mid, l, r, val);
  update(2 * node + 1, mid + 1, end, l, r, val);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void solve() {
  fill(tree, tree + 4 * N, 0ll);
  fill(lazy, lazy + 4 * N, -INF / 2);
  long long n;
  cin >> n;
  long long a[n];
  long long t[n + 1];
  t[0] = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    long long k;
    cin >> k;
    t[i] = t[i - 1] + k;
  }
  for (int i = 0; i < n; ++i) {
    b[i] = a[i] - t[i];
  }
  for (int i = 1; i < n; ++i) {
    t[i] += t[i - 1];
  }
  b[n] = INF / 2;
  build(1, 0, n);
  int q;
  cin >> q;
  while (q--) {
    char now;
    cin >> now;
    if (now == 's') {
      int l;
      int r;
      cin >> l >> r;
      l--;
      r--;
      long long pr = query(1, 0, n, l, r);
      if (l - 1 < 0) l++;
      cout << (pr + t[r] - t[l - 1]) << '\n';
    } else {
      int i;
      long long x;
      cin >> i >> x;
      i--;
      long long val = query(1, 0, n, i, i) + x;
      int lo = i;
      int hi = n;
      while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (query(1, 0, n, mid, mid) <= val) {
          lo = mid;
        } else {
          hi = mid;
        }
      }
      update(1, 0, n, i, lo, val);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  solve();
  return 0;
}
