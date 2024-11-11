#include <bits/stdc++.h>
using namespace std;
int n, m, m1, m2, a[200000], b[200000], c[200000], d[200000], e[200000],
    p[200000], ans[200000];
set<int> s;
map<int, int> mapp;
struct arr {
  int p, x, y, q;
} q[600000];
bool cmp(arr x, arr y) { return x.p == y.p ? x.q < y.q : x.p < y.p; }
struct segment_tree {
  int a[3000000];
  void update(int l, int r, int k, int x, int y) {
    if (l == r) {
      a[k] += y;
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(l, mid, k << 1, x, y);
    if (x > mid) update(mid + 1, r, (k << 1) | 1, x, y);
    a[k] = a[k << 1] + a[(k << 1) | 1];
  }
  int find(int l, int r, int k, int x, int y) {
    if (x > y) return 0;
    if (l >= x && r <= y) return a[k];
    int mid = (l + r) >> 1, ans = 0;
    if (x <= mid) ans = find(l, mid, k << 1, x, y);
    if (y > mid) ans += find(mid + 1, r, (k << 1) | 1, x, y);
    return ans;
  }
} st1, st2;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &d[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &e[i]);
  for (int i = 1; i <= n; i++) s.insert(a[i] + c[i]), s.insert(c[i] - a[i] + 1);
  for (int i = 1; i <= m; i++) s.insert(d[i] + e[i]), s.insert(e[i] - d[i]);
  for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
    p[++m1] = *it;
    mapp[*it] = m1;
  }
  for (int i = 1; i <= n; i++) {
    q[++m2] = {a[i], mapp[a[i] + c[i]], mapp[c[i] - a[i] + 1], 0};
    q[++m2] = {b[i] + 1, mapp[a[i] + c[i]], mapp[c[i] - a[i] + 1], -2};
  }
  for (int i = 1; i <= m; i++)
    q[++m2] = {d[i], mapp[d[i] + e[i]], mapp[e[i] - d[i]], i};
  sort(q + 1, q + m2 + 1, cmp);
  for (int i = 1; i <= m2; i++)
    if (q[i].q <= 0) {
      st1.update(1, m1, 1, q[i].x, q[i].q + 1);
      st2.update(1, m1, 1, q[i].y, q[i].q + 1);
    } else
      ans[q[i].q] =
          st1.find(1, m1, 1, 1, q[i].x) - st2.find(1, m1, 1, 1, q[i].y);
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
