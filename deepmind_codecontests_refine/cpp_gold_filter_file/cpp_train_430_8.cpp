#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
typedef int mang[N];
mang a, b;
int n, m;
struct IT {
  vector<int> tree, lazy;
  IT(int n) {
    tree.assign(4 * n + 1, 0);
    lazy.assign(4 * n + 1, 0);
  }
  void down(int node, int l, int r) {
    if (lazy[node]) {
      tree[node] += lazy[node];
      if (l != r) {
        lazy[node << 1] += lazy[node];
        lazy[(node << 1) | 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    return;
  }
  void update(int node, int l, int r, int u, int v, int val) {
    down(node, l, r);
    if (l > r || l > v || r < u) return;
    if (l >= u && r <= v) {
      tree[node] += val;
      if (l != r) {
        lazy[node << 1] += val;
        lazy[(node << 1) | 1] += val;
      }
      return;
    }
    int mid = (l + r) >> 1;
    update((node << 1), l, mid, u, v, val);
    update((node << 1) | 1, mid + 1, r, u, v, val);
    tree[node] = max(tree[node << 1], tree[(node << 1) | 1]);
  }
  int get(int node, int l, int r, int u, int v) {
    down(node, l, r);
    if (l > r || l > v || r < u) return -1e9;
    if (l >= u && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return max(get(node << 1, l, mid, u, v),
               get((node << 1) | 1, mid + 1, r, u, v));
  }
  int res(int node, int l, int r) {
    down(node, l, r);
    if (l == r) return l;
    int mid = (l + r) >> 1;
    down(node << 1, l, mid);
    down((node << 1) | 1, mid + 1, r);
    if (tree[(node << 1) | 1] > 0) return res((node << 1) | 1, mid + 1, r);
    return res(node << 1, l, mid);
  }
};
IT it(N);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    it.update(1, 1, N, 1, a[i], 1);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    it.update(1, 1, N, 1, b[i], -1);
  }
  int q;
  cin >> q;
  while (q--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      it.update(1, 1, N, 1, a[l], -1);
      a[l] = r;
      it.update(1, 1, N, 1, a[l], 1);
    } else {
      it.update(1, 1, N, 1, b[l], +1);
      b[l] = r;
      it.update(1, 1, N, 1, b[l], -1);
    }
    if (it.get(1, 1, N, 1, N) <= 0)
      cout << -1 << endl;
    else
      cout << it.res(1, 1, N) << endl;
  }
}
