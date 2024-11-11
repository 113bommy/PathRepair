#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long seg[4 * maxn], lazy[4 * maxn];
int a[maxn];
void build(int l, int r, int node) {
  if (l == r) {
    seg[node] = a[l];
  } else {
    int mid = l + (r - l) / 2;
    build(l, mid, 2 * node + 1);
    build(mid + 1, r, 2 * node + 2);
    seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
  }
}
void propagar(int node, int l, int r) {
  seg[node] += lazy[node];
  if (l != r) {
    lazy[2 * node + 1] += lazy[node];
    lazy[2 * node + 2] += lazy[node];
  }
  lazy[node] = 0;
}
void update(int ql, int qr, int x, int l, int r, int node) {
  if (lazy[node] != 0) {
    propagar(node, l, r);
  }
  if (l > qr || r < ql) return;
  if (l >= ql && r <= qr) {
    seg[node] += x;
    if (l != r) {
      lazy[2 * node + 1] += x;
      lazy[2 * node + 2] += x;
    }
    return;
  }
  int mid = l + (r - l) / 2;
  update(ql, qr, x, l, mid, 2 * node + 1);
  update(ql, qr, x, mid + 1, r, 2 * node + 2);
  seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
}
int query(int ql, int qr, int l, int r, int node) {
  if (lazy[node] != 0) {
    propagar(node, l, r);
  }
  if (l > qr || r < ql) return 1e9;
  if (l >= ql && r <= qr) return seg[node];
  int mid = l + (r - l) / 2;
  return min(query(ql, qr, l, mid, 2 * node + 1),
             query(ql, qr, mid + 1, r, 2 * node + 2));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, n - 1, 0);
  int q;
  cin >> q >> ws;
  while (q--) {
    string t;
    getline(cin, t);
    istringstream token(t);
    int s, e, m;
    token >> s >> e;
    if (token >> m) {
      if (s > e) {
        update(s, n - 1, m, 0, n - 1, 0);
        update(0, e, m, 0, n - 1, 0);
      } else {
        update(s, e, m, 0, n - 1, 0);
      }
    } else {
      if (s > e) {
        cout << min(query(s, n - 1, 0, n - 1, 0), query(0, e, 0, n - 1, 0))
             << '\n';
      } else {
        cout << query(s, e, 0, n - 1, 0) << '\n';
      }
    }
  }
  return 0;
}
