#include <bits/stdc++.h>
using namespace std;
struct node {
  int cnt, val;
} mx[300005], mn[300005], tmp;
int tag[300005 << 2], val[300005 << 2], cnt[300005 << 2];
int n, x, y, a[300005], Mx, Mn;
void up(int k) {
  val[k] = min(val[(k << 1)], val[(k << 1 | 1)]);
  cnt[k] = cnt[(k << 1)] * (val[(k << 1)] == val[k]) +
           cnt[(k << 1 | 1)] * (val[(k << 1 | 1)] == val[k]);
}
void down(int k) {
  if (tag[k]) {
    val[(k << 1)] += tag[k];
    val[(k << 1 | 1)] += tag[k];
    tag[(k << 1)] += tag[k];
    tag[(k << 1 | 1)] += tag[k];
    tag[k] = 0;
  }
}
void modify(int k, int l, int r, int x, int y, int V) {
  if (x <= l && r <= y) {
    val[k] += V;
    tag[k] += V;
    return;
  }
  if (x > r || y < l) return;
  down(k);
  modify((k << 1), l, (l + r >> 1), x, y, V);
  modify((k << 1 | 1), (l + r >> 1) + 1, r, x, y, V);
  up(k);
}
void build(int k, int l, int r) {
  if (l == r)
    val[k] = 1e9, cnt[k] = 1;
  else
    build((k << 1), l, (l + r >> 1)), build((k << 1 | 1), (l + r >> 1) + 1, r),
        up(k);
}
int I, i;
long long ans;
int main() {
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> x >> y, a[x] = y;
  build(1, 1, n);
  for (i = 1; i <= n; ++i) {
    modify(1, 1, n, i, i, i - 1e9);
    tmp.val = a[i], tmp.cnt = 1;
    I = i - 1;
    while (Mx && mx[Mx].val < tmp.val)
      modify(1, 1, n, I - mx[Mx].cnt + 1, I, -mx[Mx].val), I -= mx[Mx].cnt,
          tmp.cnt += mx[Mx].cnt, --Mx;
    if ((++I) < i) modify(1, 1, n, I, i - 1, tmp.val);
    mx[++Mx] = tmp;
    tmp.cnt = 1, I = i - 1;
    while (Mn && mn[Mn].val > tmp.val)
      modify(1, 1, n, I - mn[Mn].cnt + 1, I, mn[Mn].val), I -= mn[Mn].cnt,
          tmp.cnt += mn[Mn].cnt, --Mn;
    mn[++Mn] = tmp;
    if ((++I) < i) modify(1, 1, n, I, i - 1, -tmp.val);
    ans += cnt[1];
  }
  cout << ans;
}
