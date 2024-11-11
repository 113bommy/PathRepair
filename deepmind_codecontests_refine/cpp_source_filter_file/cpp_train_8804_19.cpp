#include <bits/stdc++.h>
using namespace std;
const int maxn(1e5 + 5);
struct circle {
  int a, b;
  long long h;
  circle(){};
  circle(int x) : a(0), b(x), h(0) {}
  inline void input() { cin >> a >> b >> h; }
  bool operator<(const circle &t) const {
    return b == t.b ? (a < t.a) : b < t.b;
  }
} rings[maxn];
long long tree[maxn << 2];
void build(int p, int l, int r) {
  if (l == r) {
    tree[p] = rings[l].h;
    return;
  }
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}
void update(int p, int l, int r, int x) {
  if (l == r) {
    tree[p] = rings[x].h;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    update(p << 1, l, mid, x);
  else
    update(p << 1 | 1, mid + 1, r, x);
  tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}
long long query(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) return tree[p];
  int mid = l + r >> 1;
  if (y <= mid)
    return query(p << 1, l, mid, x, y);
  else if (x > mid)
    return query(p << 1 | 1, mid + 1, r, x, y);
  else {
    long long a = query(p << 1, l, mid, x, mid);
    long long b = query(p << 1 | 1, mid + 1, r, mid + 1, y);
    return max(a, b);
  }
}
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) rings[i].input();
    sort(rings + 1, rings + n + 1);
    build(1, 1, n);
    for (int i = 2, j; i <= n; i++) {
      j = upper_bound(rings + 1, rings + i, circle(rings[i].a)) - rings;
      if (j >= i) continue;
      rings[i].h += query(1, 1, n, j, i - 1);
      update(1, 1, n, i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, rings[i].h);
    cout << ans << endl;
  }
  return 0;
}
