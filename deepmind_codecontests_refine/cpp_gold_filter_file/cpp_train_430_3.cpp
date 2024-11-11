#include <bits/stdc++.h>
using namespace std;
int a[1000009], seg[3 * 1000009], lazy[3 * 1000009];
int n, m, q;
int b[1000009];
void upd1(int node, int start, int end) {
  if (lazy[node] != 0) {
    seg[node] += lazy[node];
    if (start != end) {
      lazy[node << 1] += lazy[node];
      lazy[node << 1 | 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}
void update(int node, int start, int end, int l, int r, int val) {
  upd1(node, start, end);
  if (start > end || start > r || end < l) return;
  if (l <= start && end <= r) {
    seg[node] += val;
    if (start != end) {
      lazy[node << 1] += val;
      lazy[node << 1 | 1] += val;
    }
    return;
  }
  int mid = (start + end) >> 1;
  update(node << 1, start, mid, l, r, val);
  update(node << 1 | 1, mid + 1, end, l, r, val);
  seg[node] = max(seg[node << 1], seg[node << 1 | 1]);
}
int query(int node, int l, int r) {
  upd1(node, l, r);
  if (l == r) {
    if (seg[node] > 0)
      return l;
    else
      return 0;
  }
  int mid = (l + r) >> 1;
  upd1(2 * node + 1, mid + 1, r);
  if (seg[2 * node + 1] > 0)
    return query(node << 1 | 1, mid + 1, r);
  else
    return query(node << 1, l, mid);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    update(1, 1, 1000009, 1, a[i], 1);
  }
  for (long long int i = 0; i < m; i++) {
    cin >> b[i];
    update(1, 1, 1000009, 1, b[i], -1);
  }
  cin >> q;
  while (q--) {
    long long t, i, x;
    cin >> t >> i >> x;
    i--;
    if (t == 1) {
      update(1, 1, 1000009, 1, a[i], -1);
      a[i] = x;
      update(1, 1, 1000009, 1, a[i], 1);
    } else {
      update(1, 1, 1000009, 1, b[i], 1);
      b[i] = x;
      update(1, 1, 1000009, 1, b[i], -1);
    }
    long long z = query(1, 1, 1000009);
    if (z <= 0)
      cout << "-1" << '\n';
    else
      cout << z << '\n';
  }
}
