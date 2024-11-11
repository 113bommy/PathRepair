#include <bits/stdc++.h>
using namespace std;
const int N = 2E5 + 5, M = 5;
int n, m, q, t, l, r, mx, a[N];
long long u;
struct node {
  int f[1 << M];
  node(int _b = 0) {
    for (int i = 0; i <= mx; i++) {
      f[i] = ((i << 1) & mx) | (_b == 0 || i < mx);
    }
  }
  node operator+(const node &oth) const {
    node ans = oth;
    for (int i = 0; i <= mx; i++) {
      ans.f[i] = f[ans.f[i]];
    }
    return ans;
  }
};
struct segment_tree {
  node tr[4 * N], inv[4 * N];
  int lz[4 * N];
  void apply(int i, int v) {
    if (v == 1) {
      swap(tr[i], inv[i]);
      lz[i] ^= 1;
    }
  }
  void down(int i) {
    apply(i * 2, lz[i]);
    apply(i * 2 + 1, lz[i]);
    lz[i] = 0;
  }
  void build(int l, int r, int i) {
    if (l == r) {
      tr[i] = node(a[l]);
      inv[i] = node(a[l] ^ 1);
    } else {
      build(l, (l + r) / 2, i * 2);
      build((l + r) / 2 + 1, r, i * 2 + 1);
      tr[i] = tr[i * 2] + tr[i * 2 + 1];
      inv[i] = inv[i * 2] + inv[i * 2 + 1];
    }
  }
  void update(int l, int r, int i, int L, int R, int v) {
    if (l > R || r < L || L > R) {
      return;
    } else if (L <= l && r <= R) {
      apply(i, v);
    } else {
      down(i);
      update(l, (l + r) / 2, i * 2, L, R, v);
      update((l + r) / 2 + 1, r, i * 2 + 1, L, R, v);
      tr[i] = tr[i * 2] + tr[i * 2 + 1];
      inv[i] = inv[i * 2 + 1] + inv[i * 2 + 1];
    }
  }
  node query(int l, int r, int i, int L, int R) {
    if (L <= l && r <= R) {
      return tr[i];
    } else {
      down(i);
      if (R <= (l + r) / 2) {
        return query(l, (l + r) / 2, i * 2, L, R);
      } else if (L > (l + r) / 2) {
        return query((l + r) / 2 + 1, r, i * 2 + 1, L, R);
      } else {
        return query(l, (l + r) / 2, i * 2, L, R) +
               query((l + r) / 2 + 1, r, i * 2 + 1, L, R);
      }
    }
  }
} seg;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> q;
  mx = (1 << m) - 1;
  for (int i = 1; i <= n; i++) {
    cin >> u;
    a[i] = u & 1;
  }
  seg.build(1, n, 1);
  while (q--) {
    cin >> t >> l >> r;
    if (t == 1) {
      cin >> u;
      seg.update(1, n, 1, l, r, u & 1);
    } else {
      cout << 2 - (seg.query(1, n, 1, l, r).f[mx] & 1) << '\n';
    }
  }
}
