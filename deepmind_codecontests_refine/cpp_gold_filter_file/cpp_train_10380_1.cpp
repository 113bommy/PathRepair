#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
int n;
int hx[N], hy[N], cntx, cnty, cnt;
struct sq {
  int x, y1, y2, col, op;
} q[N << 1];
int vis[N];
bool cmp(sq a, sq b) { return a.x < b.x; }
set<int, greater<int> > s[N << 2];
int mn[N << 2], mx[N << 2], tmp, ps[N << 1];
void upd(int k) {
  mn[k] = mx[k] = (s[k].empty() ? -1 : *s[k].begin());
  mn[k] = max(min(mn[(k << 1)], mn[(k << 1 | 1)]), mn[k]);
  mx[k] = max(max(mx[(k << 1)], mx[(k << 1 | 1)]), mx[k]);
  if (mx[k] != -1 && vis[mx[k]]) mx[k] = -1;
  if (mx[k] < mn[k]) mx[k] = -1;
}
void add(int l, int r, int L, int R, int k, int x, int op) {
  if (L > R) return;
  if (L <= l && r <= R) {
    if (op) {
      if (!vis[x]) s[k].insert(x);
    } else
      s[k].erase(x);
    upd(k);
    return;
  }
  int mid = l + r >> 1;
  if (L <= mid) add(l, mid, L, R, (k << 1), x, op);
  if (R > mid) add(mid + 1, r, L, R, (k << 1 | 1), x, op);
  upd(k);
}
int main() {
  scanf("%d", &n);
  int x, y, xx, yy;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &x, &y, &xx, &yy);
    hx[++cntx] = x;
    hx[++cntx] = xx;
    hy[++cnty] = y;
    hy[++cnty] = yy;
    q[++cnt] = (sq){x, y, yy, i, 1};
    q[++cnt] = (sq){xx, y, yy, i, 0};
  }
  sort(hx + 1, hx + cntx + 1);
  sort(hy + 1, hy + cnty + 1);
  cntx = unique(hx + 1, hx + cntx + 1) - hx - 1;
  cnty = unique(hy + 1, hy + cnty + 1) - hy - 1;
  for (int i = 1; i <= cnt; i++) {
    q[i].x = lower_bound(hx + 1, hx + cntx + 1, q[i].x) - hx;
    q[i].y1 = lower_bound(hy + 1, hy + cnty + 1, q[i].y1) - hy;
    q[i].y2 = lower_bound(hy + 1, hy + cnty + 1, q[i].y2) - hy;
  }
  sort(q + 1, q + cnt + 1, cmp);
  for (int i = 1; i <= cnt; i++) ps[q[i].col] = i;
  memset(mx, -1, sizeof(mx));
  memset(mn, -1, sizeof(mn));
  int ans = 0, now = 1;
  for (int i = 1; i <= cntx; i++) {
    for (; q[now].x == i; now++)
      add(1, cnty, q[now].y1, q[now].y2 - 1, 1, q[now].col, q[now].op);
    int tmp = mx[1];
    while (~tmp) {
      vis[tmp] = 1;
      ans++;
      add(1, cnty, q[ps[tmp]].y1, q[ps[tmp]].y2 - 1, 1, tmp, 1);
      tmp = mx[1];
    }
  }
  printf("%d\n", ans + 1);
  return 0;
}
