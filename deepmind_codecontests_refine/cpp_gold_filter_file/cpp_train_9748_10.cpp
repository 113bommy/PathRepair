#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, m, q, a[N], b[N];
long long seg[4 * N], bst[4 * N], lazy[4 * N];
struct edge {
  int u, v, cap;
  edge(int a = 0, int b = 0, int c = 0) {
    u = a;
    v = b;
    cap = c;
  }
  bool operator<(const edge &a) const { return u < a.u; }
};
vector<edge> v;
void fix(int c, int l, int r) {
  seg[c] += lazy[c];
  if (l != r) {
    lazy[2 * c + 1] += lazy[c];
    lazy[2 * c + 2] += lazy[c];
  }
  lazy[c] = 0;
}
void update(int c, int l, int r, int s, int e, long long val) {
  fix(c, l, r);
  if (l > e || r < s) return;
  if (l >= s && r <= e) {
    lazy[c] = val;
    fix(c, l, r);
    return;
  }
  update(2 * c + 1, l, (l + r) / 2, s, e, val);
  update(2 * c + 2, (l + r) / 2 + 1, r, s, e, val);
  seg[c] = min(seg[2 * c + 1], seg[2 * c + 2]);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n - 1; i++)
    scanf("%d%d", a + i, b + i), update(0, 0, n - 1, i + 1, i + 1, b[i]);
  for (int i = 0, a, b, c; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    v.push_back(edge(a - 1, b - 1, c));
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n; i++) {
    while (v.size() && v.back().u == i) {
      update(0, 0, n - 1, 0, v.back().v, v.back().cap);
      v.pop_back();
    }
    bst[i] = seg[0];
  }
  memset(seg, 0, sizeof seg);
  memset(lazy, 0, sizeof lazy);
  for (int i = 0; i < n; i++) update(0, 0, n - 1, i, i, bst[i] + a[i]);
  printf("%lld\n", seg[0]);
  for (int i = 0, x, y; i < q; i++) {
    scanf("%d%d", &x, &y);
    x--;
    update(0, 0, n - 1, x, x, -a[x] + y);
    a[x] = y;
    printf("%lld\n", seg[0]);
  }
}
