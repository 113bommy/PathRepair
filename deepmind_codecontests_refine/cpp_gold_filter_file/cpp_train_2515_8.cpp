#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 5;
int mins[4 * N], lazy[4 * N], a[N], b[N];
int n, m;
void down(int node) {
  if (lazy[node] == 0) {
    return;
  }
  mins[node * 2] += lazy[node];
  mins[node * 2 + 1] += lazy[node];
  lazy[node * 2] += lazy[node];
  lazy[node * 2 + 1] += lazy[node];
  lazy[node] = 0;
}
void update(int node, int l, int r, int d, int c, int val) {
  if (l > c || r < d) {
    return;
  }
  if (d <= l && r <= c) {
    mins[node] += val;
    lazy[node] += val;
    return;
  }
  down(node);
  int mid = (l + r) / 2;
  update(node * 2, l, mid, d, c, val);
  update(node * 2 + 1, mid + 1, r, d, c, val);
  mins[node] = min(mins[node * 2], mins[node * 2 + 1]);
}
int find(int node, int l, int r) {
  if (l == r) {
    return l;
  }
  down(node);
  int mid = (l + r) / 2;
  if (mins[node * 2 + 1] < 0) {
    return find(node * 2 + 1, mid + 1, r);
  }
  return find(node * 2, l, mid);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(1, 1, N - 1, 1, a[i], -1);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    update(1, 1, N - 1, 1, b[i], 1);
  }
  int q;
  cin >> q;
  while (q--) {
    int type, pos, x;
    cin >> type >> pos >> x;
    if (type == 1) {
      update(1, 1, N - 1, 1, a[pos], 1);
      update(1, 1, N - 1, 1, x, -1);
      a[pos] = x;
    } else {
      update(1, 1, N - 1, 1, b[pos], -1);
      update(1, 1, N - 1, 1, x, 1);
      b[pos] = x;
    }
    if (mins[1] >= 0) {
      cout << -1 << endl;
    } else {
      cout << find(1, 1, N - 1) << endl;
    }
  }
}
