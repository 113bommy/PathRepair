#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const double eps = 1e-7;
long long s[MAXN << 2], h[MAXN], a[MAXN], Q[MAXN][3], cnt[MAXN << 2];
int n, q, len;
struct node {
  long long s, cnt;
};
int Getpos(double x) { return upper_bound(a + 1, a + len + 1, x) - a - 1; }
void Add(int k, int l, int r, int x, long long y, long long z) {
  if (l == r) {
    cnt[k] += z;
    s[k] += z * y;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    Add(k << 1, l, mid, x, y, z);
  else
    Add(k << 1 | 1, mid + 1, r, x, y, z);
  cnt[k] = cnt[k << 1] + cnt[k << 1 | 1];
  s[k] = s[k << 1] + s[k << 1 | 1];
}
node query(int k, int l, int r, int x, int y) {
  if (x > y) return node{0, 0};
  if (y < l || x > r) return node{0, 0};
  if (x <= l && r <= y) return node{s[k], cnt[k]};
  int mid = (l + r) >> 1;
  node tmpl, tmpr;
  tmpl.cnt = tmpl.s = tmpr.cnt = tmpr.s = 0;
  if (x <= mid) tmpl = query(k << 1, l, mid, x, y);
  if (mid + 1 <= y) tmpr = query(k << 1 | 1, mid + 1, r, x, y);
  return node{tmpl.s + tmpr.s, tmpl.cnt + tmpr.cnt};
}
bool check(double mid, double v) {
  node ans = query(1, 1, len, 1, Getpos(mid));
  if (ans.cnt * mid - ans.s >= v)
    return 1;
  else
    return 0;
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &h[i]), a[++len] = h[i];
  for (int i = 1; i <= q; i++) {
    scanf("%lld", &Q[i][0]);
    if (Q[i][0] == 1) {
      scanf("%lld %lld", &Q[i][1], &Q[i][2]);
      a[++len] = Q[i][2];
    } else
      scanf("%lld", &Q[i][1]);
  }
  sort(a + 1, a + len + 1);
  len = unique(a + 1, a + len + 1) - a - 1;
  for (int i = 1; i <= n; i++) Add(1, 1, len, Getpos(h[i]), h[i], 1);
  for (int i = 1; i <= q; i++) {
    if (Q[i][0] == 1) {
      Add(1, 1, len, Getpos(h[Q[i][1]]), h[Q[i][1]], -1);
      h[Q[i][1]] = Q[i][2];
      Add(1, 1, len, Getpos(h[Q[i][1]]), h[Q[i][1]], 1);
    } else {
      double l = 0, r = Q[i][1] + 1e9;
      for (int k = 0; k <= 100; k++) {
        double mid = (l + r) / 2;
        if (check(mid, Q[i][1]))
          r = mid;
        else
          l = mid;
      }
      printf("%.8lf\n", (l + r) / 2);
    }
  }
  return 0;
}
