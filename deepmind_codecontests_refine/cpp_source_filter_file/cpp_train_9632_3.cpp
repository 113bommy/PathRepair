#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 5;
const int INF = 1e9 + 7;
int v[maxn], c[maxn];
struct segtree {
  int maxnode[maxn << 2], minnode[maxn << 2];
  void pushup(int rt) {
    maxnode[rt] = max(maxnode[rt << 1], maxnode[rt << 1 | 1]);
    minnode[rt] = min(minnode[rt << 1], minnode[rt << 1 | 1]);
  }
  void build(int rt, int l, int r) {
    if (l == r) {
      maxnode[rt] = v[l];
      minnode[rt] = c[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
  }
  void query(int rt, int l, int r, int x, int y, int &mx, int mn) {
    if (x <= l && r <= y) {
      mx = max(mx, maxnode[rt]);
      mn = min(mn, minnode[rt]);
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) query(rt << 1, l, mid, x, y, mx, mn);
    if (mid < y) query(rt << 1 | 1, mid + 1, r, x, y, mx, mn);
  }
} tree;
int b[maxn];
int main() {
  int n, k;
  while (~scanf("%d%d", &n, &k)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", v + i);
      v[i] *= 100;
    }
    for (int i = 1; i <= n; ++i) scanf("%d", c + i);
    v[n + 1] = c[n + 1] = 0;
    tree.build(1, 1, n + 1);
    int j = n;
    for (int i = n; i; --i) {
      if (c[i] <= v[i]) {
        b[i] = c[i];
        j = i - 1;
      } else {
        int mx = 0, mn = INF;
        tree.query(1, 1, n + 1, i, j, mx, mn);
        int tmp = min(mx, mn);
        mx = 0, mn = INF;
        tree.query(1, 1, n + 1, i, j + 1, mx, mn);
        if (tmp > min(mx, mn)) {
          b[i] = tmp;
        } else {
          b[i] = min(mx, mn);
        }
      }
    }
    sort(b + 1, b + n + 1);
    long double t = 1.0 * k / n, ans = 0;
    for (int i = 1; i <= n - k + 1; ++i) {
      ans += b[i] * t;
      t *= 1.0 * (n - i - k + 1) / (n - i);
    }
    printf("%.10f\n", (double)ans);
  }
  return 0;
}
