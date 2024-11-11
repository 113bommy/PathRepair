#include <bits/stdc++.h>
const int MOD = 1E9 + 7;
const long long N = 1e5 + 15;
const int maxn = 5e5 + 15;
const int letter = 130;
const int INF = 1e17;
const double pi = acos(-1.0);
const double eps = 1e-10;
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, ps[maxn];
double laz[maxn << 2], ans[maxn << 2];
struct node {
  int zb, h, l, r;
  int l1, r1, l2, r2;
} que[N], mg[1015];
bool fb(double x) {
  if (x <= eps) return 1;
  return 0;
}
void pushdown(int lr) {
  if (fb(laz[lr] - 1.0)) {
    laz[lr << 1] *= laz[lr];
    laz[lr << 1 | 1] *= laz[lr];
    ans[lr << 1] *= laz[lr];
    ans[lr << 1 | 1] *= laz[lr];
    laz[lr] = 1;
  }
}
void update(int ll, int rr, double v, int lr, int l, int r) {
  if (ll <= l && r <= rr) {
    ans[lr] *= v;
    laz[lr] *= v;
    return;
  }
  pushdown(lr);
  int mid = (l + r) >> 1;
  if (ll <= mid) update(ll, rr, v, lr << 1, l, mid);
  if (rr > mid) update(ll, rr, v, lr << 1 | 1, mid + 1, r);
}
double query(int id, int lr, int l, int r) {
  if (l == r) return ans[lr];
  pushdown(lr);
  int mid = (l + r) >> 1;
  if (id <= mid)
    return query(id, lr << 1, l, mid);
  else
    return query(id, lr << 1 | 1, mid + 1, r);
}
void build(int lr, int l, int r) {
  if (l > r) return;
  ans[lr] = laz[lr] = 1.0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(lr << 1, l, mid);
  build(lr << 1 | 1, mid + 1, r);
}
int main() {
  scanf("%d%d", &n, &m);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    que[i].zb = read(), que[i].h = read(), que[i].l = read(), que[i].r = read();
    ps[++cnt] = que[i].zb - 1;
    ps[++cnt] = que[i].zb - que[i].h;
    ps[++cnt] = que[i].zb + 1;
    ps[++cnt] = que[i].zb + que[i].h;
  }
  for (int i = 0; i < m; i++) {
    mg[i].zb = read(), mg[i].h = read();
    ps[++cnt] = mg[i].zb;
  }
  sort(ps + 1, ps + cnt + 1);
  cnt = unique(ps + 1, ps + cnt + 1) - (ps + 1);
  for (int i = 0; i < n; i++) {
    que[i].l1 = lower_bound(ps + 1, ps + cnt + 1, que[i].zb - que[i].h) - ps;
    que[i].r1 = lower_bound(ps + 1, ps + cnt + 1, que[i].zb - 1) - ps;
    que[i].l2 = lower_bound(ps + 1, ps + cnt + 1, que[i].zb + 1) - ps;
    que[i].r2 = lower_bound(ps + 1, ps + cnt + 1, que[i].zb + que[i].h) - ps;
  }
  for (int i = 0; i < m; i++) {
    mg[i].zb = lower_bound(ps + 1, ps + cnt + 1, mg[i].zb) - ps;
  }
  build(1, 1, cnt);
  for (int i = 0; i < n; i++) {
    update(que[i].l1, que[i].r1, 1.0 - 1.0 * que[i].l / 100, 1, 1, cnt);
    update(que[i].l2, que[i].r2, 1.0 - 1.0 * que[i].r / 100, 1, 1, cnt);
  }
  double sum = 0;
  for (int i = 0; i < m; i++) {
    sum += 1.0 * mg[i].h * query(mg[i].zb, 1, 1, cnt);
  }
  printf("%.10f\n", sum);
  return 0;
}
