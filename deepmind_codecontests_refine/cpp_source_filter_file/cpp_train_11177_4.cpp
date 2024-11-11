#include <bits/stdc++.h>
using namespace std;
int n, vx, vy, a[1010][1010];
int uni[1100010];
int lzy[4400010], mn[4400010];
pair<int, pair<int, int> > p[1000010];
void pushnow(int p, int v) {
  if (v > mn[p]) {
    mn[p] = v;
    lzy[p] = v;
    return;
  }
}
void pushdown(int p) {
  if (lzy[p] != -1) {
    pushnow((p << 1), lzy[p]);
    pushnow(((p << 1) | 1), lzy[p]);
    lzy[p] = -1;
  }
}
void pushup(int p) { mn[p] = min(mn[(p << 1)], mn[((p << 1) | 1)]); }
int query(int p, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) {
    int ret = mn[p];
    pushnow(p, v);
    return ret;
  }
  pushdown(p);
  int mid = (l + r) >> 1, ret = 0x3f3f3f3f;
  if (ql <= mid) ret = min(ret, query((p << 1), l, mid, ql, qr, v));
  if (qr > mid) ret = min(ret, query(((p << 1) | 1), mid + 1, r, ql, qr, v));
  pushup(p);
  return ret;
}
int main() {
  memset(lzy, 255, sizeof(lzy));
  scanf("%d%d%d", &n, &vx, &vy);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  if (vx < 0) {
    vx = -vx;
    for (int i = 0; i < (n >> 1); i++)
      for (int j = 0; j < n; j++) swap(a[i][j], a[n - 1 - i][j]);
  }
  if (vy < 0) {
    vy = -vy;
    for (int i = 0; i < n; i++) reverse(a[i], a[i] + n);
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      uni[i * (n + 1) + j + 1] = i * vy - j * vx;
    }
  }
  sort(uni + 1, uni + (n + 1) * (n + 1) + 1);
  int End = unique(uni + 1, uni + (n + 1) * (n + 1) + 1) - uni;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      p[i * n + j] = make_pair(i * vx + j * vy, make_pair(i, j));
    }
  }
  sort(p, p + n * n);
  long long ans = 0;
  for (int i = 0; i < n * n; i++) {
    pair<int, int> pos = p[i].second;
    int L = lower_bound(uni + 1, uni + End,
                        pos.first * vy - (pos.second + 1) * vx) -
            uni;
    int R = lower_bound(uni + 1, uni + End,
                        (pos.first + 1) * vy - pos.second * vx) -
            uni;
    int v = query(1, 1, End, L, R, a[pos.first][pos.second]);
    if (v < a[pos.first][pos.second]) ans += a[pos.first][pos.second] - v;
  }
  printf("%lld\n", ans);
  return 0;
}
